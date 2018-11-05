int led=13;

void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(led,HIGH);
  Serial.println('1');
  delay(2000);
  digitalWrite(led,LOW);
  Serial.println('0');
  delay(2000);
  
}
