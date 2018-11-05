int rPin=8;
int g1Pin=10;
int g2Pin=12;
int buzzer=6;
int sensor1=2;
int sensor2=4;
int count=0;
int previousCount=0;
int counterChange=0; // Declaring a variable to define a condition to print the count value only when it has changed.
//int relayPin=13;


void setup() {
  /*NPN TRANSISTOR - BC547B
  PNP TRANSISTOR - BC557
  Resistors Used :-
  Orange Orange Brown Gold - 330 Ohm with tol 5%
  Brown Black Red Gold - 1K ohm with tol 5%

  Relay Pin diagram

  
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
  /*int Going=0;
  int Returned=0;
  */ 
  //int relayState=digitalRead(relayPin);
  //Serial.println(relayState);
  if (count != previousCount) 
  {
      // if the counter has changed, then display the counter
      counterChange++;
      Serial.println("Persons currently inside: " +count);
      Serial.println("The counter has changed: " + counterChange + " times");
      delay(50);
  }
  //save the current count as the last count
  //for next time through the loop
  previousCount = count ;

  //if(relayState>0)
  //{
      if(sensorState1==0&&sensorState2==0)
      {
        digitalWrite(rPin,HIGH);
        digitalWrite(g1Pin,LOW);
        digitalWrite(g2Pin,LOW);
        digitalWrite(buzzer,LOW);
        Serial.println("RED");
        goingR=1;
        backR=1;
        if(backR==1&&backG1==1&&backG2==1&&backGG==1&&count!=0)
        {
          //Returned=1; // The person has come back so we can increment the counter for the next person
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
        Serial.println("Green1");
        goingG1=1;
        backG1=1;
      }
      if(sensorState1==0&&sensorState2==1)
      {
        digitalWrite(g1Pin,LOW);
        digitalWrite(g2Pin,HIGH);
        digitalWrite(rPin,LOW);
        digitalWrite(buzzer,LOW);
        Serial.println("Green2");
        goingG2=1;
        backG2=1;
      }
      if(sensorState1==1&&sensorState2==1)
      {
        digitalWrite(g1Pin,HIGH);
        digitalWrite(g2Pin,HIGH);
        digitalWrite(buzzer,HIGH);
        digitalWrite(rPin,LOW);
        Serial.println("2 GREENS and BUZZER");
        goingGG=1;
        backGG=1;
        /*if(Returned==1)
        {
        count+=1;
        Returned=0; //Don't execute this if statement again to increase the counter since sensor keeps sending values continuously.
        }*/
        if(goingR==1&&goingG1==1&&goingG2==1&&goingGG==1)
        {
          count+=1;
          //Clearing the variables
          goingR=0;
          goingG1=0;
          goingG2=0;
          goingGG=0;
          //Going=0;
        }
      }
       
  //}
  /*else
  {
        digitalWrite(g1Pin,LOW);
        digitalWrite(g2Pin,LOW);
        digitalWrite(rPin,LOW);
        digitalWrite(buzzer,LOW);
        Serial.println("Relay Off");
  }*/
}  
