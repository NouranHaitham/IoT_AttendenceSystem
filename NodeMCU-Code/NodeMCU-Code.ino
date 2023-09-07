#include <EMailSender.h>
#include <SPI.h>
#include <MFRC522.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define my_email "write your email"
#define password "password of your email"
//#define reci_email1 "knkmmnk@gmail.com"fatmhshybh514@gmail.com
#define reci_email2 "email of employee"
//#define reci_email3 "mennaashraf200312@gmail.com"
#define reci_email_manager "email of manager"
#define server "smtp.gmail.com"
#define port 465
EMailSender sender_2(my_email,password,reci_email2,server,port);
EMailSender sender_manager(my_email,password,reci_email_manager,server,port);
#define SS_PIN D4
#define RST_PIN D3   
MFRC522 mfrc522(SS_PIN, RST_PIN);  
const char* host = "script.google.com";
const int httpsPort = 443;
LiquidCrystal_I2C lcd(0x27,16,2);
const char* ssid = "your wifi name";
const char* password1 = "password of your wifi";
String GOOGLE_SCRIPT_ID = "AKfycbzeDMVAi7LNmQp94Xow5Y9BZ7O1tTLVWKrZuTVCZ4ctNi4mP73KNWFmkokgJLxAOVmeJQ"; 
WiFiClientSecure client;
void setup() {
  Serial.begin(115200); 
  WiFi.begin(ssid, password1);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  while (!Serial);    
  Wire.begin();
  lcd.init();
  lcd.setBacklight(1);
  SPI.begin();      
  mfrc522.PCD_Init(); 
  delay(4);      
  mfrc522.PCD_DumpVersionToSerial();  
   lcd.clear();
  lcd.print(" Access Control :");
  lcd.setCursor(0, 1);
  lcd.print("Scan Your Card>>");
}
byte readCard[4];
void loop() {
  if (!mfrc522.PICC_IsNewCardPresent()) {
    return;
  }
  if (!mfrc522.PICC_ReadCardSerial()) {
    return;
  }
  Serial.println(F("Scanned card"));
  String uid = "";
  for (uint8_t i = 0; i < 4; i++) {  //
    readCard[i] = mfrc522.uid.uidByte[i];
    Serial.print(readCard[i], HEX);
    uid += String(readCard[i],HEX);
  }
  Serial.println("");
   if(uid=="c3fcb392"){
       while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
       EMailSender::EMailMessage msg_to_employees;
   msg_to_employees.subject =" Emergency notification ";
    msg_to_employees.message="An intruder with unknown intentions and an ID number c3fcb392 is inside.Be aware of your surroundings, secure yourself behind lockeddoors, find other shelter or leave immediately.Please limit phone use so phone lines are available for emergency messaging. Standby for additional messages regarding this incident.If you find the intruder please report to security ASAP." ;
    EMailSender::Response resp2=sender_2.send(reci_email2,msg_to_employees);
   EMailSender::EMailMessage msg_to_manager;
    msg_to_manager.subject =" Emergency notification ";
    msg_to_manager.message="An intruder with unknown intentions used a banned ID card number c3fcb392.We advice that you follow procedurces ASAP to handle the situation." ;
    EMailSender::Response resp4=sender_manager.send(reci_email_manager,msg_to_manager);//rec_email,msg
    Serial.print("Sending the Emails:");
    Serial.println(resp2.desc); 
   Serial.println(resp4.desc); 
  }
  String data = sendData( "&uid=" + uid,NULL,uid);
  if(uid=="c3fcb392"){
     Serial.print("banned");
      delay(1000);
  banned();
  }
  else if(uid=="f16d961c"){
      Serial.print("manager");
      delay(1000);
manager();
  }
  else{
     Serial.print("employee");
      delay(1000);
 employee();
  }
 
  mfrc522.PICC_HaltA();
}
String sendData(String params, char* domain,String uid) {
  bool needRedir = false;
  if (domain == NULL)
  {
    domain=(char*)host;
    needRedir = true;
    params = "/macros/s/" + GOOGLE_SCRIPT_ID + "/exec?" + "uid=" + uid;
  }
  Serial.println(*domain);
  String result = "";
  client.setInsecure();
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return "";
  }
  Serial.print("requesting URL: ");
  Serial.println(params);
  client.print(String("GET ") + params + " HTTP/1.1\r\n" +
    "Host: " + domain + "\r\n" +
    "Connection: close\r\n\r\n");
  Serial.println("request sent");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (needRedir) {
    int ind = line.indexOf("/macros/echo?user");
    if (ind > 0)
    {
      Serial.println(line);
      line = line.substring(ind);
      ind = line.lastIndexOf("\r");
      line = line.substring(0, ind);
      Serial.println(line);
      result = line;
    }
    }
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  while (client.available()) {
    String line = client.readStringUntil('\n');
    if(!needRedir)
    if (line.length() > 5)
      result = line;
    }
  if (needRedir)
    return sendData(result, "script.googleusercontent.com","");
  else return result;
}
void banned(){
    lcd.clear();
  lcd.print(" ALERT! ");
  lcd.setCursor(0, 1);
  lcd.print("Intruder got in!");
  delay(2000); 
  lcd.clear();
  lcd.print(" Access Control :");
  lcd.setCursor(0, 1);
  lcd.print("Scan Your Card>>");
}
void manager(){
 lcd.clear();                              
  lcd.print("Loading..."); 
  delay(2000);
    lcd.clear();
   lcd.setCursor(0, 0);
    lcd.print("Welcome ");
    lcd.setCursor(0, 1);
    lcd.print("Manager Nora");
  delay(2000);
  /// return everything back
  lcd.clear();
  lcd.print(" Access Control :");
  lcd.setCursor(0, 1);
  lcd.print("Scan Your Card>>");
}
void employee(){
 lcd.clear();                              
  lcd.print("Loading..."); 
    delay(2000);
   lcd.setCursor(0, 1);
   lcd.clear();
  lcd.print("Welcome Layla  ");
  delay(2000);
  lcd.clear();
  lcd.print(" Access Control :");
  lcd.setCursor(0, 1);
  lcd.print("Scan Your Card>>");
}
