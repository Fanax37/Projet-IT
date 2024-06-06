void selection(){ 
    while(TRANS_SERIAL.available()) {
        uint8_t data = TRANS_SERIAL.read(); 

    switch(data){ 
      case 0xE1: // 1
        roomNumber = 1;
        Serial.println("ca marche");
        lcd.print("Chambre 1");
        lcd.setCursor(0, 1);
        lcd.print("Valider avec *");
        waitForValidation = true;
        i + 1;
        break;
      case 0xE2: // 2
        roomNumber = 2;
        lcd.print("Chambre 2");
        lcd.setCursor(0, 1);
        lcd.print("Valider avec *");
        waitForValidation = true;
        i + 2;
        break;
      case 0xE3: // 3
        roomNumber = 3;
        lcd.print("Chambre 3");
        lcd.setCursor(0, 1);
        lcd.print("Valider avec *");
        waitForValidation = true;
        i + 3;
        break;
      case 0xE4: // 4
        roomNumber = 4;
        lcd.print("Chambre 4");
        lcd.setCursor(0, 1);
        lcd.print("Valider avec *");
        waitForValidation = true;
        i + 4;
        break;
      case 0xE5: // 5
        roomNumber = 5;
        lcd.print("Chambre 5");
        lcd.setCursor(0, 1);
        lcd.print("Valider avec *");
        waitForValidation = true;
        i + 5;
        break;
      case 0xEA: // * 
        if(waitForValidation == true){
          lcd.print("Demande validee");
          lcd.setCursor(0, 1);
          lcd.print("pour chambre ");
          lcd.print(roomNumber+0);                    
          waitForValidation = false;
          delay(5000);
          lcd.clear();
          
        } else {
          lcd.clear();
          lcd.print("Pas de demande");
          lcd.setCursor(0, 1);
          lcd.print("a valider");
        } 
        break;  

      default:
        if(waitForValidation == false){
          lcd.print("choisir chambre");
          roomNumber = -1;
          break;
        }
    }
  }
}
