int button=A0;

void setup() {
  // put your setup code here, to run once:
  pinMode(button,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState = analogRead(button);
  Serial.println(buttonState);
}
