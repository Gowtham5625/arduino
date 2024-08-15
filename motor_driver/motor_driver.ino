const int potPin=A0;
const int fwdbuttonPin=13;
const int bckbuttonPin=12;
const int ICpin2=11;
const int ICpin7=10;
int potValue=0;
int motorValue=0;
int fwdbuttonState=0;
int bckbuttonState=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(fwdbuttonPin,INPUT_PULLUP);
  pinMode(bckbuttonPin,INPUT_PULLUP);
  pinMode(ICpin2,OUTPUT);
  pinMode(ICpin7,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(potPin);
  motorValue = map(potValue,0,1023,0,255);
  fwdbuttonState=digitalRead(fwdbuttonPin);
  bckbuttonState=digitalRead(bckbuttonPin);
  delay(500);
  if(fwdbuttonState==LOW||bckbuttonState==LOW){
    analogWrite(fwdbuttonState==LOW ? ICpin2:ICpin7,motorValue);
    digitalWrite(fwdbuttonState==LOW ? ICpin7:ICpin2,motorValue);
  }
  else{
    digitalWrite(ICpin2,HIGH);
    digitalWrite(ICpin7,HIGH);
}
}