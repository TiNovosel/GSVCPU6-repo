byte message[] = {0xAA, 0x90, 0x23, 0x85};

void setup() {
Serial.begin(230400);
}

void loop() {
Serial.write(message, sizeof(message)); 
delay(500);

byte readmessage = Serial.read();
Serial.print(readmessage);

}

int GetValue(){
  byte messageGV[] = {0xAA, 0x90, 0x3B, 0x85};
  Serial.write(messageGV, sizeof(message)); 
  delay(100);
}

int StopTransmission(){
  byte messageStopT[] = {0xAA, 0x90, 0x23, 0x85};
  Serial.write(messageST, sizeof(message)); 
  delay(100);
}

int StartTransmission(){
  byte messageStartT[] = {0xAA, 0x90, 0x24, 0x85};
  Serial.write(messageStT, sizeof(message)); 
  delay(100);
  }
