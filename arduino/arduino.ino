#include <AFMotor.h>
#include <Servo.h> // Biblioteca do Servo agora está ativa

// Crie objetos para os motores DC
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);

// Crie o objeto para o servo motor
Servo garraServo; 

void setup() {
  // Inicia a comunicação serial
  Serial.begin(9600);
  
  // Define a velocidade inicial dos motores DC (0 a 255)
  motor1.setSpeed(150);
  motor2.setSpeed(150);
  motor3.setSpeed(150);

  // Anexa o objeto do servo à porta 9 do Motor Shield
  // O Motor Shield V1/V2 usa os pinos 9 e 10 para os servos
  garraServo.attach(9); 
  
  // Garante que os motores DC estão parados no início
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);

  // Define uma posição inicial para a garra (ex: fechada)
  garraServo.write(0); // Posição 0 graus
  delay(500); // Pequeno delay para o servo chegar na posição
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
      case 'H': // 'H' para Soltar/Abrir a garra
        garraServo.write(90); // Move o servo para 90 graus (posição aberta)
        break;
      case 'G': // 'G' para Pegar/Fechar a garra
        garraServo.write(0);  // Move o servo para 0 graus (posição fechada)
        break;
    }
  }
}