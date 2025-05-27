#include <QTRSensors.h>
QTRSensors qtr;

// Définition des capteurs QTR-MD-04A

const uint8_t SensorCount = 4;
uint16_t sensorValues[SensorCount];

const int ENA = 9;
const int IN1 = 8;
const int IN2 = 7;
const int ENB = 10;
const int IN3 = 6;
const int IN4 = 5;

int speedMotor = 180;  // Vitesse moteur (0-255)

void setup()
{
  Serial.begin(9600);
  // Optional: wait for some input from the user, such as a button press.
  // Initialize the sensors.
  // In this example we have three sensors on pins A0 - A2.
  qtr.setTypeRC(); // or setTypeAnalog()
  qtr.setSensorPins((const uint8_t[]) {
    A1, A2, A3, A4
  }, 4);
  qtr.setEmitterPin(2);

  // Optional: change parameters like RC timeout, set an emitter control pin...
  // Then start the calibration phase and move the sensors over both reflectance
  // extremes they will encounter in your application. This calibration should
  // take about 5 seconds (250 iterations * 20 ms per iteration).
  //
  // Passing a QTRReadMode to calibrate() is optional; it should match the mode
  // you plan to use when reading the sensors.
  for (uint8_t i = 0; i < 250; i++)
  {
    qtr.calibrate();
    delay(20);
  }
  // Optional: signal that the calibration phase is now over and wait for
  // further input from the user, such as a button press.



  // Configuration des moteurs
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);


  int speedMotorGauche = 180;  // Vitesse moteur gauche (0-255)
  int speedMotorDroit = 180 + 80;  // Compensation de 80 unités



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


void loop()
{

  uint16_t sensors[4];
  // Get calibrated sensor values returned in the sensors array, along with the
  // line position, which will range from 0 to 2000, with 1000 corresponding to
  // a position under the middle sensor.
  int16_t position = qtr.readLineBlack(sensors);
  Serial.println(position);
  // If all three sensors see very low reflectance, take some appropriate action
  // for this  situation.
  if ((sensors[0] > 750) && (sensors[1] > 750) && (sensors[2] > 750))
  {
    // Do something. Maybe this means we're at the edge of a course or about to
    // fall off a table, in which case we might want to stop moving, back up,
    // and turn around.
    return;
  }


  Serial.print("Position ligne: ");
  Serial.println(position);

  // Suivi de ligne en fonction de la position détectée
  if (position < 600) {
    tournerGauche();  // Ligne à gauche → tourner à gauche
  }
  else if (position > 2400) {
    tournerDroite();  // Ligne à droite → tourner à droite
  }
  else {
    avancer();  // Ligne au centre → avancer
  }

  delay(100);
}
