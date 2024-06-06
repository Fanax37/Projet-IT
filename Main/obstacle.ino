void obstacle() {
  delay(200);
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
//réception de l'echo
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
// Calcul de la distance
  distance = (duration/2) / 29;
     lcd.setCursor(0, 1);
    if (distance >= 400 || distance <= 0){
      Serial.println("Hors plage");
      lcd.println("hors plage      ");
      
      lcd.clear();
    } else if (distance <=30){
      //écran
      Serial.print("distance = ");
      Serial.print(distance);
      Serial.println(" cm");
      lcd.print("d = ");
      lcd.print(distance);
      lcd.println(" cm        ");
      buzzer();
      
      lcd.clear(); 
      arreter(); 
      
   }else{
      Serial.print("distance = ");
      Serial.print(distance);
      Serial.println(" cm");
      lcd.print("d = ");
      lcd.print(distance);
      lcd.println(" cm        ");
      
      lcd.clear();
     
   }
}
