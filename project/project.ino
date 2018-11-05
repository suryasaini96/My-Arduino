int rPin=8;
int gPin=10;
int bPin=12;
int sensor1=2;
int sensor2=4;


void setup() {
  // put your setup code here, to run once:
  pinMode(rPin,OUTPUT);
  pinMode(gPin,OUTPUT);
  pinMode(bPin,OUTPUT);
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorState1=digitalRead(sensor1);
  int sensorState2=digitalRead(sensor2);
   
  if(sensorState1==0&&sensorState2==0)
  {
    digitalWrite(rPin,HIGH);
    digitalWrite(gPin,LOW);
    digitalWrite(bPin,LOW);
    Serial.println("RED");
  }
  if(sensorState1==1&&sensorState2==0)
  {
    digitalWrite(gPin,HIGH);
    digitalWrite(rPin,LOW);
    digitalWrite(bPin,LOW);
    Serial.println("Green");
  }
  if(sensorState1==1&&sensorState2==1)
  {
    delay(100);
    digitalWrite(bPin,HIGH);
    digitalWrite(rPin,HIGH);
    digitalWrite(gPin,HIGH);
    Serial.println("ALL 3");
  }
}  
