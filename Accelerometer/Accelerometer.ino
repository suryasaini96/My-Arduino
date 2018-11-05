// Sensor calibration

const int xPin=12;
const int yPin=13;

void setup() {
 Serial.begin(9600);
 pinMode(xPin,INPUT);
 pinMode(yPin,INPUT);
}

void loop() {
  int xval=analogRead(xPin);
  int yval=analogRead(yPin);
  
  Serial.print("X=");
  Serial.print(xval);
  Serial.print("   Y=");
  Serial.println(yval);
  //delay(3000);
}
