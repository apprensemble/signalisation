int etatBouton = 0;
const int vertRoute = 11;
const int orangeRoute = 12;
const int rougeRoute = 13;
const int rougePieton = 4;
const int vertPieton = 5;
const int bip = 3;
const int bouton = 2;
 
void setup() {
  Serial.begin(9600);
  pinMode(bouton, INPUT);
  pinMode(bip, OUTPUT);
  pinMode(vertRoute, OUTPUT);
  pinMode(orangeRoute, OUTPUT);
  pinMode(rougeRoute, OUTPUT);
  pinMode(vertPieton, OUTPUT);
  pinMode(rougePieton, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  etatBouton = digitalRead(bouton);
  Serial.println(etatBouton);
  if (etatBouton) {
    feu_rouge();
  }
  else {
    feu_vert();
  }

}

void reset_feux() {
  digitalWrite(vertRoute,LOW);
  digitalWrite(orangeRoute,LOW);
  digitalWrite(rougeRoute,LOW);
  digitalWrite(vertPieton,LOW);
  digitalWrite(rougePieton,LOW);
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
  reset_feux();
  allume(rougePieton);
  allume(orangeRoute);
  delay(1000);
  eteint(orangeRoute);
  allume(rougeRoute);
  delay(1000);
  eteint(rougePieton);
  allume(vertPieton);
  delay(5000);
  eteint(vertPieton);
  allume(rougePieton);
  delay(1000);
}
