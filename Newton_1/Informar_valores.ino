

void imprime_valores() {
  Serial.print("Curva: ");
  Serial.print(leitura_curva);
  Serial.print("        Acelerador: ");
  Serial.print(leitura_acelerador);
  Serial.print("        Bateria: ");
  Serial.println(analogRead(bateria));
}




void informar_leituras() {
      if (millis()-tempo>500) {
          tempo=millis();
          lcd.setCursor(0,1);
          lcd.print("Ac:     Dir:     ");
          lcd.setCursor(3,1);
          lcd.print(leitura_acelerador);
          lcd.setCursor(12,1);
          lcd.print(leitura_curva);  
       }
}
