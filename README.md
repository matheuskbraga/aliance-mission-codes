# Robô Controlado por Wi-Fi com Arduino Uno WiFi

Este repositório contém o código para construir um robô de duas rodas controlado remotamente via Wi-Fi. O projeto utiliza a placa de desenvolvimento "Arduino Uno WiFi", que possui dois processadores: um ATmega328P para o controle dos motores e um ESP8266 para a conectividade de rede e para servir uma interface web de controle.

Arquitetura do Projeto

A lógica do projeto é dividida entre os dois processadores para máxima eficiência:

    ESP8266: Atua como o servidor. Ele cria um ponto de acesso Wi-Fi e serve uma página da web com botões de controle (Frente, Trás, Esquerda, Direita, Parar). Ao receber um comando da página, ele o envia para o ATmega328P via comunicação serial.

    ATmega328P: Atua como o controlador dos motores. Ele recebe comandos simples do ESP8266 e utiliza a biblioteca do Motor Shield L293D para acionar os motores DC com precisão.

Hardware Necessário

    1x Placa Arduino Uno WiFi (ATmega328P + ESP8266)

    1x Motor Shield L293D

    1x Chassi de robô com 2 motores DC

    1x Fonte de alimentação externa para os motores (ex: pack de baterias 7-9V)

    1x Cabo de dados Micro USB

Software e Bibliotecas

    (https://www.arduino.cc/en/software)

    Biblioteca Adafruit Motor Shield V1:

        No Arduino IDE, vá para Sketch > Include Library > Manage Libraries....

        Procure por Adafruit Motor Shield V1.

        Instale a biblioteca da Adafruit.

Montagem

    Encaixe o Motor Shield L293D sobre a placa Arduino Uno WiFi.

    Conecte os dois motores DC aos terminais M1 e M2 do shield.

    Conecte a fonte de alimentação externa ao terminal de alimentação azul do shield. Não alimente os motores pela porta USB.

Instruções de Uso

O processo de upload é dividido em etapas, pois cada processador deve ser programado separadamente.

Atenção: Sempre desconecte a placa da alimentação antes de alterar a posição dos interruptores DIP.

Passo 1: Carregar o Código no Controlador do Motor (ATmega328P)

    Coloque os interruptores 3 e 4 na posição ON. Todos os outros devem estar em OFF.

    Conecte a placa ao computador.

    No Arduino IDE, selecione a placa "Arduino/Genuino Uno" em Ferramentas > Placa.

    Abra o ficheiro controlador_motor_atmega328p.ino e carregue-o para a placa.

Passo 2: Carregar o Código no Servidor Web (ESP8266)

    Desconecte a placa.

    Coloque os interruptores 5, 6 e 7 na posição ON. Todos os outros devem estar em OFF.

    Conecte a placa novamente.

    No Arduino IDE, selecione a placa "Generic ESP8266 Module" em Ferramentas > Placa.

    Abra o ficheiro servidor_web_esp8266.ino e carregue-o para a placa.

Passo 3: Ativar o Modo de Operação

    Desconecte a placa.

    Coloque os interruptores 1 e 2 na posição ON. Todos os outros devem estar em OFF. Esta configuração permite que o ATmega328P e o ESP8266 comuniquem entre si.   

    Ligue a fonte de alimentação externa dos motores e, em seguida, conecte a placa à alimentação USB.

Passo 4: Controlar o Robô

    No seu telemóvel ou computador, procure e conecte-se à rede Wi-Fi com o nome (SSID) "RoboControl" e a senha "robo12345".

    Abra um navegador de internet e acesse o endereço: http://192.168.4.1

    A interface de controle com os botões de movimento aparecerá. Agora você pode controlar o seu robô!
