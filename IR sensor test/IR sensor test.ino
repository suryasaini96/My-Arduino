int inPin=4;

void setup() {
  // put your setup code here, to run once:
  pinMode(inPin,INPUT);
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
int var = digitalRead(inPin);
Serial.println(var);
}
