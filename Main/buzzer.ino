void buzzer(){
  analogWrite (speakerPin, 150);
  delay(1000);
  analogWrite (speakerPin, 0);
}
