#include <ArduinoJson.h>
/* 

Calculo aproximado da temperatura usando o a equação de Steinhart–Hart

Referencia sobre o calculo https://en.wikipedia.org/wiki/Thermistor#NTC
http://sin.lyceeleyguescouffignal.fr/make-an-arduino-temperature-sensor-thermistor-tutorial

*/

const int TAMANHO = 100;
int TermistorPin=A0; //Local do Pino que mede a temperatura
int LDRpin= A2; //porta do pino ldr
int VentoPin = 2;   // Local do Pino do frequencimetro que mede a velocidade do Vento
float frequencia = 0; //Recebe valor da frequencia do frequencimetro
float w = 0; //variavel de calculo da voltagem da velocidade do vento
float v_ms = 0; // váriavel que recebe a velocidade do vento em m/s
float v_kmh = 0; // váriavel que recebe a velocidade do vento em km/h
float R1=10000;//valor r1 para calcular a fórmula
float Vcc=1023;//
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
  pinMode(TermistorPin, INPUT);
  pinMode(LDRpin, INPUT);
  pinMode(VentoPin, INPUT);
  Serial.begin(9600); // abre a porta serial a 9600 bps:
}

void loop() {

lux = readLux(LDRpin);
//printLux(L);
delay(500);

readTemp(TermistorPin);
//printTemp(Tc);

delay(500);

vento = ReadF(VentoPin);
//printVento(v_kmh);
delay(500);

 StaticJsonDocument<TAMANHO> json; //cria o objeto Json

    
  int sensorValue = Tc;
  float sensorValue2 = L;
  int sensorValue3 = v_kmh; 


//formato de leitura no node-red
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

float ReadF( int VentoPin ) {
  frequencia = digitalRead(VentoPin);
  w = frequencia * (2 * 3.14);
  v_ms = w * 4;
  v_kmh = v_ms * 3.6;

}

void printVento(float v_kmh) {
  Serial.print("Velocidade do Vento: ");
  Serial.print(v_kmh);
  Serial.println("km/h");   
} 
