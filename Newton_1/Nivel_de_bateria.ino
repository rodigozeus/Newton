void checar_bateria(int intervalo) {
  if (millis()-tempo_bateria>intervalo) {
          tempo_bateria=millis();
          if (analogRead(bateria)>660) {
              lcd.setCursor(0,0);
              lcd.write(3);
              lcd.write(3);
              lcd.write(3);
              lcd.write(3);
              lcd.write(3);
          }
          else if (analogRead(bateria)>=650) {
              lcd.setCursor(0,0);
              lcd.write(3);
              lcd.write(3);
              lcd.write(3);
              lcd.write(3);
              lcd.print(" ");
              }
          else if (analogRead(bateria)>=640) {
              lcd.setCursor(0,0);
              lcd.write(3);
              lcd.write(3);
              lcd.write(3);
              lcd.print(" ");
              lcd.print(" ");
              }
           else if (analogRead(bateria)>=630) {
              lcd.setCursor(0,0);
              lcd.write(3);
              lcd.write(3);
              lcd.print(" ");
              lcd.print(" ");
              lcd.print(" ");
              } 
           else if (analogRead(bateria)>=620) {
              lcd.setCursor(0,0);
              lcd.write(3);
              lcd.print(" ");
              lcd.print(" ");
              lcd.print(" ");
              lcd.print(" ");
              }                        
          if (analogRead(bateria)<600) {
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Bateria Esgotada");
            while (true) {
              para();
            }
          }
      }      
}
