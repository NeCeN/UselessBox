#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int servo_pin=8; //set servo address
int servo_switch=2; //set servo switch off address
int bouton=3; //set user switch address


int pos_stby=163; //position on standby
int pos_max=0; //position to switch off the user switch
int way=0; //movement way
int timeout=0; //timeout for servo switch off 

void setup() {
  // setup of all input and output
  myservo.attach(servo_pin);  
  myservo.write(pos_stby); 
  pinMode(servo_switch, OUTPUT);
  digitalWrite(servo_switch,LOW);
  pinMode(bouton, INPUT_PULLUP);
}

void loop() {
  //if user switch is switched on
  if (digitalRead(bouton)==false && way != -1)
  {
    digitalWrite(servo_switch,HIGH);
    way=-1;
    myservo.write(pos_max);
    timeout=70;
  }

  //if user switch has been switched off
  if ((digitalRead(bouton)==true && way==-1))
  {
    digitalWrite(servo_switch,HIGH);
    way=1;
    myservo.write(pos_stby);
    timeout=70;
  }
  
  if (timeout>0){timeout--;}
  
  //On timeout switch off the servo
  if (timeout==1){digitalWrite(servo_switch,LOW);}
  delay(10);          
}

