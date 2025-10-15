#include <ESP8266WiFi.h>

// Credenciais da rede Wi-Fi que o ESP8266 irá criar
const char* ssid = "Robo_Apolo";
const char* password = "robo12345";

// Cria um servidor na porta 80 (padrão HTTP)
WiFiServer server(80);

void setup() {
  // Inicia a comunicação serial para enviar comandos para o ATmega328P
  Serial.begin(9600);
  
  // Configura o ESP8266 como um Ponto de Acesso (Access Point)
  WiFi.softAP(ssid, password);

  // Inicia o servidor web
  server.begin();
}

void loop() {
  // Aguarda por um cliente (navegador) se conectar
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Aguarda até que o cliente envie dados
  while (!client.available()) {
    delay(1);
  }

  // Lê a primeira linha da requisição HTTP
  String req = client.readStringUntil('\r');
  client.flush();

  // Envia o comando para o ATmega328P com base na URL da requisição
  if (req.indexOf("/forward")!= -1) {
    Serial.print('F');
  } else if (req.indexOf("/backward")!= -1) {
    Serial.print('B');
  } else if (req.indexOf("/left")!= -1) {
    Serial.print('L');
  } else if (req.indexOf("/right")!= -1) {
    Serial.print('R');
  } else if (req.indexOf("/stop")!= -1) {
    Serial.print('S');
  } else if (req.indexOf("/garra-esticada")!= -1) {
    Serial.print('E');
  } else if (req.indexOf("/garra-comprimida")!= -1) {
    Serial.print('C');
  }
  // Resposta HTTP para o navegador
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); // Linha em branco obrigatória

  // A página web com os botões de controle
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head><title>Controle do Robo</title>");
  client.println("<meta name='viewport' content='width=device-width, initial-scale=1'>");
  client.println("<style>html {font-family: Arial; display: inline-block; text-align: center;}");
  client.println(".btn {background-color: #4CAF50; border: none; color: white; padding: 16px 40px;");
  client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}</style></head>");
  client.println("<body><h1>Controle Wi-Fi do Robo</h1>");
  client.println("<p><a href='/forward'><button class='btn'>Frente</button></a></p>");
  client.println("<p><a href='/left'><button class='btn'>Esquerda</button></a>");
  client.println("<a href='/stop'><button class='btn'>Parar</button></a>");
  client.println("<a href='/right'><button class='btn'>Direita</button></a></p>");
  client.println("<p><a href='/backward'><button class='btn'>Tras</button></a></p>");
  client.println("<p></p>");
  client.println("<p><a href='/garra-esticada'><button class='btn'>Esticar</button></a></p>");
  client.println("<p><a href='/garra-comprimida'><button class='btn'>Comprimir</button></a></p>");
  client.println("</body></html>");

  delay(1);
}