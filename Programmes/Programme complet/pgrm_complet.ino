#include <QTRSensors.h>

// Définition des capteurs QTR-MD-04A
QTRSensors qtr;
const uint8_t SensorCount = 4;
uint16_t sensorValues[SensorCount];

// Définition des moteurs (L298N)
const int ENA = 9;
const int IN1 = 8;
const int IN2 = 7;
const int ENB = 10;
const int IN3 = 6;
const int IN4 = 5;

int speedMotor = 180;  // Vitesse moteur (0-255)

// Initialisation
void setup() {
  Serial.begin(115200);

  // Configuration du capteur QTR
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]) {
    A1, A2, A3, A4
  }, SensorCount);
  qtr.setEmitterPin(2);

  // Calibration du capteur (déplacer le robot sur la ligne pendant cette phase)
  for (uint8_t i = 0; i < 250; i++) {
    qtr.calibrate();
    delay(20);
  }

  // Configuration des moteurs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);


  int speedMotorGauche = 50;  // Vitesse moteur gauche (0-255)
  int speedMotorDroit = 50;  // Vitesse moteur droit (0-255)
  
  analogWrite(ENA, speedMotorGauche);
  analogWrite(ENB, speedMotorDroit);

}

// Fonction pour lire la position de la ligne
int lirePositionLigne() {
  return qtr.readLineBlack(sensorValues);
}

// Fonctions de mouvement
void avancer() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void tournerGauche() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void tournerDroite() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void arreter() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Boucle principale
void loop() {
  int position = lirePositionLigne();

  Serial.print("Position ligne: ");
  Serial.println(position);

  // Suivi de ligne en fonction de la position détectée
  if (position < 900) {
    tournerGauche();  // Ligne à gauche → tourner à
    Serial.print("G");
    
  }
  else if (position > 1100) {
    tournerDroite();  // Ligne à droite → tourner à droite
        Serial.print("D");

  }
  else {
    avancer();  // Ligne au centre → avancer
        Serial.print("=");

  }
  delay(500);
}
