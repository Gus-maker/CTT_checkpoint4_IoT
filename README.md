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

Ter os seguintes Progamas:

- SimulIDE (Carregue o arquivo *".ino"* e o arquivo *".hex".*)
- Node.js
- Arduino IDE
- lib ArduinoJson

Usar esse comando no command prompt do Node.js:
**npm install -g --unsafe-perm node-red**

Esse comando garante a instalação do node-red, caso não tenha instalado.

Baixar as seguintes extensões no node-red:

1) Clique no Menu Hamburguer
2) Manage Palette
3) E pesquise:

- node-red-dashboard
- node-red-node-serialport
- node-red-node-twitter
- node-red-contrib-cloundantplus


Importe o arquivo *.json*:

1) Clique no Menu Hamburguer
2) Import para importar o nó.

E clique em Deploy.

Ao lado da *"/"* da URL digite *ui* para vizualizar o Dashboard.

Ex:

XXX.X.X.X:XXXX/ui

Para vizualizar os tweets de aviso sobre a velocidade do vento acesse:

@trash_turn

## Link de vídeo demonstração

Adicione o link para assistir ao vídeo do projeto funcionando.

[https://youtu.be/8IRPscfgNbw]()


### Referências 

[pdf Prof. Hellynson Node-Red with Twitter / Saving values in DB](https://fiapcom.sharepoint.com/sites/msteams_4b4b48/Documentos%20Compartilhados/Forms/AllItems.aspx?FolderCTID=0x01200050722CA271EDFD4C8EE81671575BBBB9&id=%2Fsites%2Fmsteams%5F4b4b48%2FDocumentos%20Compartilhados%2FDisruptive%20Architectures%20IOT%20e%20IA%2F2semestre%20%2D%20NAC4%2FDisruptiveArchitecturesIOTeIA%5FAula%2002%2Epdf&parent=%2Fsites%2Fmsteams%5F4b4b48%2FDocumentos%20Compartilhados%2FDisruptive%20Architectures%20IOT%20e%20IA%2F2semestre%20%2D%20NAC4)
