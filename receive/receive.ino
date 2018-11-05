int rPin=4;
void setup() {
  // put your setup code here, to run once:
  pinMode(rPin,INPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int var=digitalRead(rPin);
  //int freq= var*(1023/433);
  if(var==1){
    Serial.println("Received");
    digitalWrite(LED_BUILTIN,HIGH);
  }
  else{
    Serial.println("Not Received");
    digitalWrite(LED_BUILTIN,LOW);
  }
}
