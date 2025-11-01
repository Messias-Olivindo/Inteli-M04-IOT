// Definição dos pinos dos leds
#define VERDE 7
#define AMARELO 9
#define VERMELHO 8

unsigned long ultimaLeitura = 0;
int estado = 0;  // variável para armazenar em que etapa o semáforo está

void setup() {
  pinMode(VERDE, OUTPUT);
  pinMode(AMARELO, OUTPUT);
  pinMode(VERMELHO, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Uso do millis
  unsigned long tempoAtual = millis();

  if (estado == 0) {
    digitalWrite(VERMELHO, 1);
    if (tempoAtual - ultimaLeitura >= 6000) {
      digitalWrite(VERMELHO, 0);
      ultimaLeitura = tempoAtual;
      estado = 1;
    }
  }

  if (estado == 1) {
    digitalWrite(VERDE, 1);
    if (tempoAtual - ultimaLeitura >= 4000) {
      digitalWrite(VERDE, 0);
      ultimaLeitura = tempoAtual;
      estado = 2;
    }
  }

  if (estado == 2) {
    digitalWrite(AMARELO, 1);
    if (tempoAtual - ultimaLeitura >= 2000) {
      digitalWrite(AMARELO, 0);
      ultimaLeitura = tempoAtual;
      estado = 0;
    }
  }
}
