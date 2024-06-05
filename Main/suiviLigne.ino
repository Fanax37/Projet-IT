void parcours(){    
  d1 = digitalRead(3);    
  d2 = digitalRead(4);  
   
if ((d1 == LOW && d2 == LOW0000..00000000.0.0.)) {        //deux switch en position haute    
  Serial.println ("avancer"); 
  avancer();   
  delay (200); 
   
}  
else if ((d1 == LOW && d2 == HIGH)) {        // switch gauche en position basse, switch droit en position haute    
  Serial.println ("tourner legerement a droite");  
  Vgauche();  
  delay (200);
  
}   
else if ((d1 == HIGH && d2 == LOW)){        //siwtch gauche en position hautre, switch droit en position basse    
  Serial.println ("tourner legerment a gauche");
  Vdroite();
      delay(200); 
      
}else {                        //les deux switch en position basse    
  Serial.println ("arret");
  arreter();
  delay (200);  
}
}
