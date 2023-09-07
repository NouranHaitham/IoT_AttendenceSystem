#include<SoftwareSerial.h>
#define Redled    3  //digital pins
#define Greenled1 4 //digital pins
#define Greenled2 5 //digital pins
#define Greenled3 6 //digital pins
#define buzzer  9   //digital pins
SoftwareSerial node_serial(0,1); //rx_0, tx_1 in arduino that will recieve data from nodeMCU
void setup() 
{
   Serial.begin(115200);
   node_serial.begin(115200);
  Serial.setTimeout(5);
  node_serial.setTimeout(5);
   pinMode(Greenled1,OUTPUT);
   pinMode(Greenled2,OUTPUT); 
   pinMode(Greenled3,OUTPUT);
   pinMode(Redled,OUTPUT);
   pinMode(buzzer,OUTPUT);
digitalWrite(Greenled1,HIGH);  // led that says Project is working
  
}


void loop(){
  
if(Serial.available()>0){
String msg = Serial.readString();

// manager --> 2nd G_led/lcd("loading") delay() /// 3rd G_led/lcd("welocme manager name");
// employee --> 2nd G_led/lcd("loading") delay() /// 3rd G_led/ lcd("welocme name"); 
// banned --> red light (on and off)/ buzzer / lcd (ALERT! intruder got in!);   

if(msg=="manager"){
  digitalWrite(Greenled2,HIGH);
  delay(2000);
  digitalWrite(Greenled3,HIGH);
delay(2000);
digitalWrite(Greenled2,LOW);
  digitalWrite(Greenled3,LOW);
}
else if(msg=="employee")
{
digitalWrite(Greenled2,HIGH);
  delay(2000);
  digitalWrite(Greenled3,HIGH);
  delay(2000);
digitalWrite(Greenled2,LOW);
  digitalWrite(Greenled3,LOW);
}
else if(msg=="banned"){
  digitalWrite(buzzer,HIGH);   
  digitalWrite(Redled,HIGH);
  delay(200);
  digitalWrite(Redled,LOW);
  delay(200);
  digitalWrite(Redled,HIGH);
  delay(200);
  digitalWrite(Redled,LOW);
  delay(200);
  digitalWrite(Redled,HIGH);
  delay(200);
  digitalWrite(Redled,LOW);
  delay(200);
  digitalWrite(Redled,HIGH);
  delay(200);  
  delay(2000);
digitalWrite(buzzer,LOW);
  digitalWrite(Redled,LOW);

}
}
}