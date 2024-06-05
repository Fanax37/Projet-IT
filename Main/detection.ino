void detection(int i, int z){
 if (i == z && i!=0 && z !=0){
    Serial.println("rentrer dans la chambre");
    Vgauche();
    delay(300);
    arreter();
    avancer();
    delay(300);// ca va faire bugger le reste donc trouver un moyen mais pas la prioritée 
    arreter();
 }
}
