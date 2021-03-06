/*
 * Código para controlar carrinho com dois motores (esquerdo e direito)ativado com ponte-H L298N ou smilares 
 * através de radio-controle de automodelo (transmissor tipo pistola e receptor).
 * Inclui Farol e lanterna traseira e também um display LCD para informarções diversas e nível da bateria.
 * 
 * Projeto de conclusão de curso da Disciplina de Robótica Educacional oferecido Secretária de Educação
 * do Distrito Federeal, ministrado pela Professora/Orientadora: Renata
 * 
 * Desenvolvido por: Rodrigo Damaceno
 */

/*
==============================================================================================================
BIBLIOTECAS:
==============================================================================================================*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>


/*
==============================================================================================================
MAPEAMENTO DE HARDWARE:
==============================================================================================================*/
//Leitura da carga da bateria
#define bateria A0

//Receptor de rádio
#define luzes 11
#define acelerador 12
#define curva 13

//Luzes
#define farol 9
#define freio 10

//Motor do lado direito
#define direito 2                                                                                                 
#define direito_Invertido 4
#define vel_direito 3 //Precisa ser PWM

//Motor do lado esquerdo
#define esquerdo 7
#define esquerdo_Invertido 6
#define vel_esquerdo 5 //Precisa ser PWM

//Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,16,2);

/*
==============================================================================================================
CONSTANTES:
==============================================================================================================*/
#define centro_curva -18
#define centro_acelerador 11
#define fator_giro 1.3 //ajusta a velocidade de giro parado
#define fator_reverso 3 //ajusta o reverso fazendo curvas

//Caracteres especiais para Display LCD
uint8_t bell[8]  = {0x4, 0xe, 0xe, 0xe, 0x1f, 0x0, 0x4};
uint8_t note[8]  = {0x2, 0x3, 0x2, 0xe, 0x1e, 0xc, 0x0};
uint8_t clock[8] = {0x0, 0xe, 0x15, 0x17, 0x11, 0xe, 0x0};
uint8_t heart[8] = {0x0, 0xa, 0x1f, 0x1f, 0xe, 0x4, 0x0};
uint8_t duck[8]  = {0x0, 0xc, 0x1d, 0xf, 0xf, 0x6, 0x0};
uint8_t check[8] = {0x0, 0x1 ,0x3, 0x16, 0x1c, 0x8, 0x0};
uint8_t cross[8] = {0x0, 0x1b, 0xe, 0x4, 0xe, 0x1b, 0x0};
uint8_t retarrow[8] = {  0x1, 0x1, 0x5, 0x9, 0x1f, 0x8, 0x4};

/*
==============================================================================================================
VARIÁVEIS:
==============================================================================================================*/
long leitura_curva = 0;
long leitura_acelerador = 0;
long leitura_luzes = 0;
unsigned long tempo=0;
unsigned long tempo_bateria=0;


/*
==============================================================================================================
CONFIGURAÇÃO:
==============================================================================================================*/
void setup() {
  //iniciando portas
  pinMode(bateria, INPUT);
  pinMode(direito, OUTPUT);
  pinMode(direito_Invertido, OUTPUT);
  pinMode(esquerdo, OUTPUT);
  pinMode(esquerdo_Invertido, OUTPUT);
  pinMode(vel_direito, OUTPUT);
  pinMode(vel_esquerdo, OUTPUT);
  pinMode(farol, OUTPUT);
  pinMode(freio, OUTPUT);

  //iniciando LCD
  lcd.begin();
  lcd.setBacklight(HIGH);
  lcd.createChar(0, bell);
  lcd.createChar(1, note);
  lcd.createChar(2, clock);
  lcd.createChar(3, heart);
  lcd.createChar(4, duck);
  lcd.createChar(5, check);
  lcd.createChar(6, cross);
  lcd.createChar(7, retarrow);
  lcd.clear();
  checar_bateria(0);
  lcd.setCursor(0,1);
  lcd.print("Inicializando...");
  delay(500);
  //Serial.begin(9600);

  testa_radio();

}


/*
==============================================================================================================
PROGRAMA PRINCIPAL:
==============================================================================================================*/
void loop() {
checar_bateria(10000);  
//imprime_valores();

//Obtem leituras do radio e remapeia
leitura_curva = (pulseIn(curva, HIGH, 30000));
leitura_acelerador = (pulseIn(acelerador, HIGH, 30000));

if (leitura_acelerador < 500) {
  testa_radio();
}
leitura_luzes = (pulseIn(luzes, HIGH, 30000));
leitura_curva = map(leitura_curva, 1000, 2000, -255, 255);
leitura_acelerador = map(leitura_acelerador, 930, 2030, -255, 255);
leitura_curva = constrain(leitura_curva, -255, 255);
leitura_acelerador = constrain(leitura_acelerador, -255, 255);


//Controla as luzes
if (leitura_luzes>1500) {
  analogWrite(farol, 130);
  analogWrite(freio, 100);
  lcd.setCursor(13,0);
  lcd.write(4);
  }
else {
  analogWrite(farol, LOW);
  analogWrite(freio, LOW);
  lcd.setCursor(13,0);
  lcd.print(" ");   
  }

//acelerador solto
if ((abs(leitura_acelerador)-abs(centro_acelerador))<50) {
  gira_parado(leitura_curva/fator_giro);
}


//Ir pra frente
else if (leitura_acelerador>centro_acelerador) {
  acelerar(leitura_acelerador);
  informar_leituras();
}

//ir pra tras
else if (leitura_acelerador<centro_acelerador) {
  voltar(leitura_acelerador);
  informar_leituras();
}
} //fecha loop
