const int vertRoute = 11;
const int orangeRoute = 12;
const int rougeRoute = 13;

const int rougePieton = 5;
const int vertPieton = 6;
const int orangePieton = 7;

int etatBoutonVert = 0;
int etatPrecedentVert = 3;

int etatBoutonOrange = 0;
int etatPrecedentOrange = 3;

int etatBoutonRouge = 0;
int etatPrecedentRouge = 3;


const int boutonVert = 2;
const int boutonOrange = 3;
const int boutonRouge = 4;

long heureActuelle = 0;
long heureBoutonAction = 0;
int tempsLimiteFeuRouge = 5000;
 
void setup() {
  Serial.begin(9600);
  pinMode(boutonVert, INPUT);
  pinMode(boutonOrange, INPUT);
  pinMode(boutonRouge, INPUT);
  //pinMode(bip, OUTPUT);
  pinMode(vertRoute, OUTPUT);
  pinMode(orangeRoute, OUTPUT);
  pinMode(rougeRoute, OUTPUT);
  pinMode(vertPieton, OUTPUT);
  pinMode(rougePieton, OUTPUT);
  pinMode(orangePieton, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  heureActuelle = millis();
  etatPrecedentRouge = etatBoutonRouge;
  etatBoutonRouge = digitalRead(boutonRouge);
  etatBoutonVert = digitalRead(boutonVert);
  etatBoutonOrange = digitalRead(boutonOrange);
  //if (etatPrecedentRouge != etatBoutonRouge) {
    Serial.print(etatBoutonRouge);
    Serial.print(" ");
    Serial.print(etatBoutonOrange);
    Serial.print(" ");
    Serial.println(etatBoutonVert);  
  //}
  if (etatBoutonRouge) {
    heureBoutonAction = millis();
    reset_feux();
    allume(rougeRoute);
    allume(rougePieton);
  }
  else if(etatBoutonVert) {
    reset_feux();
    allume(vertRoute);
    allume(vertPieton);
  }
  else if (etatBoutonOrange) {
    reset_feux();
    allume(orangeRoute);
    allume(orangePieton);
  }

}

void reset_feux() {
  eteint(vertRoute);
  eteint(orangeRoute);
  eteint(rougeRoute);
  eteint(vertPieton);
  eteint(rougePieton);
  eteint(orangePieton);
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
