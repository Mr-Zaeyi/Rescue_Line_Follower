void setup(){
    //Pins
pinMode(9, OUTPUT);
pinMode(8, OUTPUT);
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
}
void loop(){

int speed1 = 120;
int speed2 = 60;

analogWrite(9, speed1);
analogWrite(6, speed2);
delay(500);
analogWrite(9, 0);
analogWrite(6, 0);
delay(100000);


}
