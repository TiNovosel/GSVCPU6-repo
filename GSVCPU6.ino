//pin za ledicu
int ledPin1=13;

//pinovi za gumbe
int btnPinStart=32;
int btnPinStop=33;
int btnPinGetValue=25;

//Stanja gumbadi
int btnStateStart=LOW;
int btnStatStop=LOW;
int btnStatGetValue=LOW;

void setup()
{

//Definiranje pinova svi ulazi su napravljeni s unutranjim pullup-om
  pinMode(ledPin1, OUTPUT);
  pinMode(btnPinStart, INPUT_PULLUP);
  pinMode(btnPinStop, INPUT_PULLUP);
  pinMode(btnPinGetValue, INPUT_PULLUP);

  Serial.begin(230400);
}

void loop()
{
  
//Ocitavanje stanja gumbadi
 btnStateStart = digitalRead(btnPinStart);
 btnStatStop = digitalRead(btnPinStop);
 btnStatGetValue = digitalRead(btnPinGetValue);

   if(btnStateStart == LOW)
   {
    digitalWrite(ledPin1, HIGH);
    StartTransmission();
   }
   else if(btnStatStop == LOW)
   {
    digitalWrite(ledPin1, HIGH);
    StopTransmission();
   }
   else if(btnStatGetValue == LOW)
   {
    digitalWrite(ledPin1, HIGH);
    GetValue();
   }
   else
   {
    digitalWrite(ledPin1, LOW);
   }

}


void StartTransmission(){
  byte messageStartT[] = {0xAA, 0x90, 0x24, 0x85};
  Serial.write(messageStartT, sizeof(messageStartT)); 
  delay(100);
  }

void StopTransmission(){
  byte messageStopT[] = {0xAA, 0x90, 0x23, 0x85};
  Serial.write(messageStopT, sizeof(messageStopT)); 
  delay(100);
}

int GetValue(){
  byte messageGV[] = {0xAA, 0x90, 0x3B, 0x85};
  Serial.write(messageGV, sizeof(messageGV)); 
  delay(100);
}