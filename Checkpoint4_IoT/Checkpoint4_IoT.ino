#include <ArduinoJson.h>


const int TAMANHO = 100;
int TermistorPin=A0; //Local do Pino que mede a temperatura
int LDRpin= A2; //porta do pino ldr
int VentoPin = 2;   // Local do Pino do frequencimetro que mede a velocidade do Vento
float frequencia = 0; //Recebe valor da frequencia do frequencimetro
volatile unsigned long tempo = 0; // váriavel de tempo feita para medir a diferença entre ela e o cont no laço de decisão
volatile unsigned long cont = 0; // contador para medir a frequencia da onda
float w = 0; //variavel de calculo da frequencia da velocidade do vento
float v_ms = 0; // váriavel que recebe a velocidade do vento em m/s
float v_kmh = 0; // váriavel que recebe a velocidade do vento em km/h
float R1=10000; 
float Vcc=1023;
float Vout = 0; 
float Rldr= 0;
float Rdark = 127410;
float alpha=0.858;
float L= 0;
float lux = 0;
float potenc = 0;
int Vo;
float R3= 10000;
float logR4, R4, T, Tc, Tf, temp,Lfim,vento;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07; //valores constante para calculo

void setup() {
  pinMode(TermistorPin, INPUT); //pino de temperatura
  pinMode(LDRpin, INPUT); // pino de lux
  pinMode(VentoPin, INPUT); // pino de frequencimetro
  Serial.begin(9600); // abre a porta serial a 9600 bps:
  attachInterrupt(digitalPinToInterrupt(2), interrupcao, RISING); // interrompe a porta 2 quanto, acrescenta e ascrescenta o contador 
}

void loop() {
if( (millis() - tempo) > 999){ // if para fazer a medição do tempo da onda 
  tempo = millis ();
  lux = readLux(LDRpin);
  readTemp(TermistorPin);
  vento = ReadF();
  cont=0;
}
 StaticJsonDocument<TAMANHO> json; //cria o objeto Json

    
  int sensorValue = Tc;
  float sensorValue2 = L;
  int sensorValue3 = v_kmh; 


//mensagem em json no objeto "json"
  json["Temperatura"] = sensorValue;
  json["Luminosidade"] = sensorValue2;
  json["Vento"] = sensorValue3;
  
  serializeJson(json, Serial);
  Serial.println();


}

//função que faz leitura da temperatura e retorna o valor em graus celcius
float readTemp(int ThermistorPin){
  
  Vo = analogRead(ThermistorPin);
  R4 = R3 * (1023.0 / (float)Vo - 1.0); //calculo R2, demonstração no arquivo pdf da aula
  logR4 = log(R4);
  T = (1.0 / (c1 + c2*logR4 + c3*logR4*logR4*logR4));// Equação de Steinhart–Hart 
  Tc = T - 273.15; //temp em Graus celcius
  Tf = (Tc * 9.0)/ 5.0 + 32.0; // temp em fahrenheit
  return Tc;
}


// função que faz a leitura de lux e retorna o valor 

float readLux(int LDRpin){
  float Vout = analogRead(LDRpin);
  Rldr = R1/(Vcc/Vout-1);
  potenc= 1/alpha;
  L= Rdark/Rldr;
  L= pow(L, potenc);
  return L;
  }

//função que printa o valor da temperatura na serial
void printLux(float L){
  Serial.print("Valor de Lux: ");
  Serial.print(L);
}
  //Serial.println(" C");   

//função que printa o valor da temperatura na serial
void printTemp(float Tc){
  
  Serial.print("Temperatura: ");
  Serial.print(Tc);
  Serial.println(" C");   

}

// Função que calcula o valor da velocidade do vento

float ReadF() {
  w = cont * (2 * 3.14);
  v_ms = w * 0.25; // transforma f em hz em m/s usando o raio de 0.25
  v_kmh = v_ms * 3.6; // transforma em km/h

}

void printVento(float v_kmh) {
  Serial.print("Velocidade do Vento: ");
  Serial.print(v_kmh);
  Serial.println("km/h");   
} 

void interrupcao(){
  cont++;// aumenta o contador de acordo com a interrupção
}

/*

Calculo aproximado da temperatura usando o a equação de Steinhart–Hart

Referencia sobre o calculo https://en.wikipedia.org/wiki/Thermistor#NTC
http://sin.lyceeleyguescouffignal.fr/make-an-arduino-temperature-sensor-thermistor-tutorial

Referência para criação da frequência e demais funções
https://www.youtube.com/watch?v=oPLCOFkpYmM&feature=youtu.be

*/ 
