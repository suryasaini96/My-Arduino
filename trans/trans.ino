int iPin=2;
int tPin=4;
int input=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(iPin,INPUT);
  pinMode(tPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  input=digitalRead(iPin);
  if(input==1){
    digitalWrite(tPin,HIGH);
    Serial.println("Sending");
  }
  else if (input==0){
    digitalWrite(tPin,LOW);
    Serial.println("NOT Sending");
  }
  
}
