#include <AFMotor.h>
//#include <Servo.h>

// Crie objetos para os motores conectados às portas M1 e M2
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
//Servo servo1;

void setup() {
  // Inicia a comunicação serial para receber comandos do ESP8266
  Serial.begin(9600);
  
  // Define a velocidade inicial dos motores (0 a 255)
  motor1.setSpeed(150);
  motor2.setSpeed(150);
  motor3.setSpeed(150);

  // Servo motor (garra)
  //servo1.attach(9);
  
  // Garante que os motores estão parados no início
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  
}

void loop() {
  // Verifica se há dados disponíveis na porta serial
  if (Serial.available() > 0) {
    // Lê o comando de um único caractere
    char command = Serial.read();

    switch (command) {
      case 'F': // Frente
        motor1.run(BACKWARD);
        motor2.run(BACKWARD);
        break;
      case 'B': // Trás
        motor1.run(FORWARD);
        motor2.run(FORWARD);
        break;
      case 'L': // Esquerda
        motor1.run(BACKWARD);
        motor2.run(FORWARD);
        break;
      case 'R': // Direita
        motor1.run(FORWARD);
        motor2.run(BACKWARD);
        break;
      case 'S': // Parar (Stop)
        motor1.run(RELEASE);
        motor2.run(RELEASE);
        break;
      case 'E':
        motor3.run(FORWARD);
        delay(1000);
        motor3.run(RELEASE);
        break;
      case 'C':
        motor3.run(BACKWARD);
        delay(1000);
        motor3.run(RELEASE);
        break;
      
    }
  }
}