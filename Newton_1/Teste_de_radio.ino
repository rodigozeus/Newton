void testa_radio() {
    while(true) {
      leitura_acelerador = (pulseIn(acelerador, HIGH, 30000));
      para();
      lcd.setCursor(0,1);
      lcd.print("    Radio OFF   ");
      lcd.setCursor(15,0);
      lcd.write(6);
      if ((abs(leitura_acelerador))>10) {
        lcd.setCursor(0,1);
        lcd.print("                ");
        lcd.setCursor(15,0);
        lcd.write(5);
        break;
      }
  }
}
