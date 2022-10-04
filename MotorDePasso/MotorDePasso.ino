/*
   AUTOR:   Andre Lumesi
   Adaptado do exemplo: BrincandoComIdeias, Usando Motor de Passo
   LINK do exemplo original:    https://www.youtube.com/brincandocomideias ; https://cursodearduino.net/
   DATA:    04/09/2022
   Mudanças introduzidas:  Remoção dos pushbuttons, controle via teclas g e c do teclado.
*/
#include <Stepper.h>
const int stepsPerRevolution = 2050;  // VALOR DE PASSOS PARA UMA VOLTA
byte numeroHoras = 0;
int botao;

// INSTANCIANDO O MOTOR DE PASSO E CONFIGURANDO OS PINOS
Stepper myStepper(stepsPerRevolution, 6, 7, 8, 9);

void setup() {
  // DEFININDO ROTAÇÕES POR MINUTO, NOS TESTES A VELOCIDADE MÁXIMA DO MEU MOTOR 28BYJ-48 FOI DE 7 RPM
  myStepper.setSpeed(5);
  // INCIANDO MONITOR SERIAL
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    // AÇÕES PARA CADA CONDIÇÃO
    int readKey = Serial.read();

    // Se 'g' for pressionado, inicia rotação
    if (readKey == 103) {
      if (numeroHoras == 0) {
        Serial.println("Girando 1 Revolução");
        myStepper.step(stepsPerRevolution);
      } else {
        Serial.print("Girando "); Serial.print(numeroHoras); Serial.println(" Horas");
        myStepper.step( numeroHoras * (stepsPerRevolution / 12) );
      }

      // Se 'c' for pressionado, atualiza o tamanho da rotação
      if (readKey = 99) {
        numeroHoras++;
        if (numeroHoras > 11)
          numeroHoras = 0;
        Serial.print("Configurado para: "); Serial.print(numeroHoras); Serial.println(" Horas");
      }
    }
  }
}