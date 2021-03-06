int etatBouton = 0;
const int vertRoute = 11;
const int orangeRoute = 12;
const int rougeRoute = 13;
const int rougePieton = 4;
const int vertPieton = 5;
const int bip = 3;
const int bouton = 2;
long heureActuelle = 0;
long heureBoutonAction = 0;
int tempsLimiteFeuRouge = 5000;
int etatPrecedent = 3;
 
void setup() {
  Serial.begin(9600);
  pinMode(bouton, INPUT);
  //pinMode(bip, OUTPUT);
  pinMode(vertRoute, OUTPUT);
  pinMode(orangeRoute, OUTPUT);
  pinMode(rougeRoute, OUTPUT);
  pinMode(vertPieton, OUTPUT);
  pinMode(rougePieton, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  heureActuelle = millis();
  etatPrecedent = etatBouton;
  etatBouton = digitalRead(bouton);
  if (etatPrecedent != etatBouton) {
    Serial.println(etatBouton);  
  }
  if (etatBouton) {
    heureBoutonAction = millis();
    feu_rouge();
  }
  else {
    feu_vert();
  }

}

void reset_feux() {
  eteint(vertRoute);
  eteint(orangeRoute);
  eteint(rougeRoute);
  eteint(vertPieton);
  eteint(rougePieton);
}

void allume(int feu) {
  digitalWrite(feu, HIGH);
}

void eteint(int feu) {
  digitalWrite(feu, LOW);
}

void feu_vert() {
  reset_feux();
  allume(vertRoute);
  allume(rougePieton);
}

void feu_rouge() {
  long duree = heureActuelle - heureBoutonAction;
  while (duree < 5000) {
    heureActuelle = millis();
    duree = heureActuelle - heureBoutonAction;
    reset_feux();
    if (duree < 1000) {
      allume(rougePieton);
      allume(orangeRoute);
    }
    else if (duree < 2000) {
      allume(rougePieton);
      allume(rougeRoute);
    }
    else if (duree < 5000) {
      allume(vertPieton);
      allume(rougeRoute);
    }
  }
  reset_feux();
  allume(rougeRoute);
  allume(rougePieton);
  delay(1000);
}
