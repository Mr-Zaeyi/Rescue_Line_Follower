void setup(){
    //Pins
pinMode(9, OUTPUT);
pinMode(8, OUTPUT);
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
}
void loop(){

int speed = 60;

digitalWrite(9, speed);
delay(2000);
digitalWrite(9, 0);
delay(200);
digitalWrite(8, speed);
delay(2000);
digitalWrite(8, 0);


digitalWrite(7, speed);
delay(2000);
digitalWrite(7, 0);
delay(200);
digitalWrite(6, speed);
delay(2000);
digitalWrite(6, 0);
}
