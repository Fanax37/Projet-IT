void parcours(){    
    d1 = digitalRead(47);    //gauche
    d2 = digitalRead(46);  //droite
   
    if ((d1 == LOW && d2 == LOW)) { //deux switch en position haute    
      Serial.println ("avancer"); 
      avancer();   
      delay (200); 
   
    }else if ((d1 == LOW && d2 == HIGH)) { // switch gauche (d1) en position basse, switch droit en position haute    
      Serial.println ("tourner legerement a droite");  
      Vgauche();  
      delay (200);
  
    }else if ((d1 == HIGH && d2 == LOW)){  //siwtch gauche en position hautre, switch droit en position basse    
      Serial.println ("tourner legerment a gauche");
      Vdroite();
      delay(200); 
      
    }else {   //les deux switch en position basse    
      Serial.println ("arret");
      arreter();
      delay (200);  
      //ajouter un demitour sauf si dans une chambre a voir si on a le temps 

 }
}
