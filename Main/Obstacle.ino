void obstacle() {
 // Envoie de l'onde
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
// RÃ©ception de l'Ã©cho
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
// Calcul de la distance
  distance = (duration/2) / 29;
     lcd.setCursor(0, 1);
    if (distance >= 400 || distance <= 0){
      Serial.println("Hors plage");
      lcd.println("hors plage      ");
      delay(500);
      lcd.clear();
    } else if (distance <=30){
      //Ã©cran
      Serial.print("distance = ");
      Serial.print(distance);
      Serial.println(" cm");
      lcd.print("d = ");
      lcd.print(distance);
      lcd.println(" cm        ");
      buzzer1();
      delay(500);
      
      lcd.clear();
      
      
     } else if(distance <= 60) {
      //Ã©cran
      Serial.print("distance = ");
      Serial.print(distance);
      Serial.println(" cm");
      lcd.print("d = ");
      lcd.print(distance);
      lcd.println(" cm        ");
      delay(500);
      lcd.clear();
       
     } else if(distance <= 120) {

      //Ã©cran
      Serial.print("distance = ");
      Serial.print(distance);
      Serial.println(" cm");
      lcd.print("d = ");
      lcd.print(distance);
      lcd.println(" cm        ");
      delay(500);
      lcd.clear();
      
   }else{
      Serial.print("distance = ");
      Serial.print(distance);
      Serial.println(" cm");
      lcd.print("d = ");
      lcd.print(distance);
      lcd.println(" cm        ");
      delay(500);
      lcd.clear();
     
   }
   
    delay(500); ;
}
