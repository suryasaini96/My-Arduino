int rPin=8;
int g1Pin=10;
int g2Pin=12;
int buzzer=6;
int sensor1=2;
int sensor2=4;
int count=0;
int previousCount=0;
int counterChange=0; // Declaring a variable to define a condition to print the count value only when it has changed.
int goingR=0,goingG1=0,goingG2=0,goingGG=0;
int backR=0,backG1=0,backG2=0,backGG=0;


void setup() {
  /*NPN TRANSISTOR - BC547B
  PNP TRANSISTOR - BC557
  Resistors Used :-
  Orange Orange Brown Gold - 330 Ohm with tol 5%
  Brown Black Red Gold - 1K ohm with tol 5%
  */
  pinMode(rPin,OUTPUT);
  pinMode(g1Pin,OUTPUT);
  pinMode(g2Pin,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  //pinMode(relayPin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorState1=digitalRead(sensor1);
  int sensorState2=digitalRead(sensor2);
  if(count!=previousCount)
  {
      counterChange++;
      Serial.print("Persons currently inside: ");
      Serial.println(count);
      //Serial.print("The counter has changed: ");
      //Serial.print(counterChange);
      //Serial.println(" times");
      delay(50);
  }
  previousCount=count;
  if(sensorState1==0&&sensorState2==0)
  {
    digitalWrite(rPin,HIGH);
    digitalWrite(g1Pin,LOW);
    digitalWrite(g2Pin,LOW);
    digitalWrite(buzzer,LOW);
    //Serial.println("RED");
    goingR=1;
    backR=1;
    if(backR==1&&backG1==1&&backG2==1&&backGG==1&&count!=0)
    {
      //Since person has come back sucessfully so clearing the variables.
      backR=0;
      backG1=0;
      backG2=0;
      backGG=0;
      count-=1;
    }
  }
  if(sensorState1==1&&sensorState2==0)
  {
    digitalWrite(g1Pin,HIGH);
    digitalWrite(g2Pin,LOW);
    digitalWrite(rPin,LOW);
    digitalWrite(buzzer,LOW);
    //Serial.println("Green1");
    goingG1=1;
    backG1=1;
  }
  if(sensorState1==0&&sensorState2==1)
  {
    digitalWrite(g1Pin,LOW);
    digitalWrite(g2Pin,HIGH);
    digitalWrite(rPin,LOW);
    digitalWrite(buzzer,LOW);
    //Serial.println("Green2");
    goingG2=1;
    backG2=1;
  }
  if(sensorState1==1&&sensorState2==1)
  {
    digitalWrite(g1Pin,HIGH);
    digitalWrite(g2Pin,HIGH);
    digitalWrite(buzzer,HIGH);
    digitalWrite(rPin,LOW);
    //Serial.println("2 GREENS and BUZZER");
    goingGG=1;
    backGG=1;
    if(goingR==1&&goingG1==1&&goingG2==1&&goingGG==1)
    {
      count+=1;
      //Clearing th+ariables
      goingR=0;
      goingG1=0;
      goingG2=0;
      goingGG=0;
    }
  }
}  
