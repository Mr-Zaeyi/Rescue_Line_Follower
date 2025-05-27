void setup(){
    //Pins
pinMode(9, OUTPUT);
pinMode(8, OUTPUT);
pinMode(7, OUTPUT);
pinMode(6, OUTPUT);
}
void loop(){

int speed = 60;

analogWrite(9, speed);
analogWrite(6, speed);
delay(1000);
analogWrite(9, 0);
analogWrite(6, 0);
delay(10000);


}
