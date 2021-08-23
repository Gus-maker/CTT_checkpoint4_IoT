# Template para desenvolvimento e entrega de NAC

# Nome do projeto

**nome dos alunos:** 

**Gustavo Gonçalves de Araujo - RM85569** 

**Henrique Sartal Santos - RM82172** 

**Iago Manholetti Alexandrino - RM84314**

**João Carlos Melo Azevedo - RM85744** 

**José Dijalbas Francisco dos Santos Bezerra - RM84254**

**Leonardo Andrade Antunes de Bem - RM86062** 

**Martin David Valdes Olcese - RM85521**

**Turma:**
**2TDSJ**

**Ano:**
**2021**

## Objetivo / descrição do Projeto

O objetivo deste trabalho é fazer a própria rede meterológica, acompanhando a temperatura, velocidade do  vento e a luminosidade, com base no nosso circuito feito no simulador SimulIDE, códigos arduino e node red, com um banco de dados em cloud da ibm, comunicação MQTT e publicação de mensagens no Twitter.


## Descrição Passo a Passo

1 - Nós recebemos os valores do SimulIde passamos via serial e mandamos o valor da serial em json do node, dívidido cada valor por tópico.

2 - Em seguida pegamos cada valor dos tópicos e colocamos em nosso Dashboard.

3 - A velocidade do vento quando está acima de 80km/h realizamos um tweet através de uma função em nosso Tweeter de desenvovlvedor @trash_turn

4 - Printamos esse Tweet no nosso nó debug.

5 - Pegamos os tweets feitos e salvamos em um banco de dados da IBM cloud.

6 - Ao pressionar o injection recebemos os objetos presentes no banco de dados que tem os valores dos sensores.


## Diagrama do projeto

![image](https://user-images.githubusercontent.com/59034973/130476794-7d2303e5-d70e-48b6-b505-f6d1b32cf414.png)
![image](https://user-images.githubusercontent.com/59034973/130490316-1c7010ea-7d6e-421a-acb2-6582a2856ab9.png)


## Como usar 



* Pode ser utilizado marcadores
* Para ajudar na formatação

Ou qualquer outra tabulação:

- [x] Youtube

Pode adicionar algum trecho de código, por exemplo para clonar esse repositório:

    cd /home/iot
    git clone https://github.com/arnaldojr/templatenac
    cd templatenac
    ls


## Link de vídeo demonstração

Adicione o link para assistir ao vídeo do projeto funcionando.

[https://youtu.be/8IRPscfgNbw]()


### Referências 

* [mastering-markdown](https://guides.github.com/features/mastering-markdown/)
* [Basic writing and formatting syntax](https://docs.github.com/en/github/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)
