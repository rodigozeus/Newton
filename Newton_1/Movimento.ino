void gira_parado(int velocidade) {
  if (velocidade < (centro_curva-30)) {
      girar_esquerda(abs(velocidade));
      informar_leituras();     
  }
  else if (velocidade > (centro_curva+30)) {
      girar_direita(abs(velocidade));
      informar_leituras();
      
  }
  else {
      para();
      lcd.setCursor(0,1);
      lcd.print("     Newton      ");
      
  }
}


void acelerar(int velocidade) {
  
  //Frente esquerda
  if (leitura_curva < (centro_curva-30)) {
            
      if (abs(leitura_curva)<=velocidade) {
        digitalWrite(direito_Invertido, LOW);
        digitalWrite(esquerdo_Invertido, LOW);
        digitalWrite(direito, HIGH);
        digitalWrite(esquerdo, HIGH);
        analogWrite(vel_direito, abs(velocidade));
        analogWrite(vel_esquerdo, abs(velocidade)-abs(leitura_curva));
             }
      else {
        digitalWrite(direito_Invertido, LOW);
        digitalWrite(esquerdo_Invertido, HIGH);
        digitalWrite(direito, HIGH);
        digitalWrite(esquerdo, LOW);
        analogWrite(vel_direito, abs(velocidade));
        analogWrite(vel_esquerdo, abs(leitura_curva)/fator_reverso);
              }
  }

  //Frente esquerda
  else if (leitura_curva > (centro_curva+30)) {
      if (abs(leitura_curva)<=velocidade) {
        digitalWrite(direito_Invertido, LOW);
        digitalWrite(esquerdo_Invertido, LOW);
        digitalWrite(direito, HIGH);
        digitalWrite(esquerdo, HIGH);
        analogWrite(vel_direito, abs(velocidade)-abs(leitura_curva));
        analogWrite(vel_esquerdo, abs(velocidade));
      }
      else {
        digitalWrite(direito_Invertido, HIGH);
        digitalWrite(esquerdo_Invertido, LOW);
        digitalWrite(direito, LOW);
        digitalWrite(esquerdo, HIGH);
        analogWrite(vel_direito, abs(leitura_curva)/fator_reverso);
        analogWrite(vel_esquerdo, abs(velocidade));
      }
  }
  
  //Frente reto
  else {
     digitalWrite(direito_Invertido, LOW);
     digitalWrite(esquerdo_Invertido, LOW);
     digitalWrite(direito, HIGH);
     digitalWrite(esquerdo, HIGH);
     analogWrite(vel_direito, abs(velocidade));
     analogWrite(vel_esquerdo, abs(velocidade)); 
  }
}

void voltar(int velocidade) {
  //tras esquerda
  if (leitura_curva < (centro_curva-30)) {
            
      if (abs(leitura_curva)<=velocidade) {
        digitalWrite(direito_Invertido, LOW);
        digitalWrite(esquerdo_Invertido, LOW);
        digitalWrite(direito, HIGH);
        digitalWrite(esquerdo, HIGH);
        analogWrite(vel_direito, abs(velocidade));
        analogWrite(vel_esquerdo, abs(velocidade)-abs(leitura_curva));
             }
      else {
        digitalWrite(direito_Invertido, LOW);
        digitalWrite(esquerdo_Invertido, HIGH);
        digitalWrite(direito, HIGH);
        digitalWrite(esquerdo, LOW);
        analogWrite(vel_direito, abs(velocidade));
        analogWrite(vel_esquerdo, abs(leitura_curva)/fator_reverso);
              }
  }

  //tras esquerda
  else if (leitura_curva > (centro_curva+30)) {
      if (abs(leitura_curva)<=velocidade) {
        digitalWrite(direito_Invertido, LOW);
        digitalWrite(esquerdo_Invertido, LOW);
        digitalWrite(direito, HIGH);
        digitalWrite(esquerdo, HIGH);
        analogWrite(vel_direito, abs(velocidade)-abs(leitura_curva));
        analogWrite(vel_esquerdo, abs(velocidade));
      }
      else {
        digitalWrite(direito_Invertido, HIGH);
        digitalWrite(esquerdo_Invertido, LOW);
        digitalWrite(direito, LOW);
        digitalWrite(esquerdo, HIGH);
        analogWrite(vel_direito, abs(leitura_curva)/fator_reverso);
        analogWrite(vel_esquerdo, abs(velocidade));
      }
  }
  
  //tras reto
  else {
     digitalWrite(direito_Invertido, HIGH);
     digitalWrite(esquerdo_Invertido, HIGH);
     digitalWrite(direito, LOW);
     digitalWrite(esquerdo, LOW);
     analogWrite(vel_direito, abs(velocidade));
     analogWrite(vel_esquerdo, abs(velocidade)); 
  }
}




void para(){

     digitalWrite(direito_Invertido, LOW);
     digitalWrite(esquerdo_Invertido, LOW);
     
     analogWrite(vel_direito, 0);
     analogWrite(vel_esquerdo, 0);
    
     digitalWrite(direito, LOW);
     digitalWrite(esquerdo, LOW);

}


void girar_direita(int velocidade){

     digitalWrite(direito, LOW);
     digitalWrite(esquerdo_Invertido, LOW);
     
     analogWrite(vel_direito, velocidade);
     analogWrite(vel_esquerdo, velocidade);
    
     digitalWrite(direito_Invertido, HIGH);
     digitalWrite(esquerdo, HIGH);
     }

void girar_esquerda(int velocidade){
    
     digitalWrite(direito_Invertido, LOW);
     digitalWrite(esquerdo, LOW);  
     
     analogWrite(vel_direito, velocidade);
     analogWrite(vel_esquerdo, velocidade);
    
     digitalWrite(direito, HIGH);
     digitalWrite(esquerdo_Invertido, HIGH);
     }
