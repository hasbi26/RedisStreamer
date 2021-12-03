
const int relay1 = 2; //pin2
int relayON = LOW; //relay nyala
int relayOFF = HIGH; //relay mati

void setup() {
  Serial.begin(19200);
  pinMode(relay1, OUTPUT);
  digitalWrite(relay1, relayOFF);
}
void loop() {
    delay(1000);
}
void serialEvent() 
{
   char inChar;
  while (Serial.available()) 
  { 
        inChar = (char)Serial.read();
        if(inChar == '1') {
        digitalWrite(relay1, relayON);  
        delay(1000);
         } else {
            digitalWrite(relay1, relayOFF);  
          }
    
  }
  
  
}
