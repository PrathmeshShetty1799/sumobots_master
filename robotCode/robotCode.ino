//Copyright Code by Botty Mons (Dont steal our stuff) -> Taught By My Dawg Habib

//Sensor Variables
#define trigSensorFront 13
#define echoSensorFront 12
#define trigSensorRight 11
#define echoSensorRight 10
#define trigSensorLeft 9
#define echoSensorLeft 8

long duration;
int distance;

int distanceFront;
int distanceRight;
int distanceLeft;

//Motor Variables
#define motorB1A 5
#define motorB1B 4
#define motorA1A 3
#define motorA1B 2

//QRD Sensor Variables
const int QRD1114_PIN = A0; // Sensor output voltage
int currentLoc;

//Functions

int ultrasonicRead(int trig, int echo){
   //Code to run Ultrasonic Sensor
  digitalWrite (trig, LOW);
  delayMicroseconds (2);
  digitalWrite(trig, HIGH);
  delayMicroseconds (10);
  digitalWrite (trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = duration*0.034/2;
  return distance;
}

int qrdSensor(void){
   // Read in the ADC and convert it to a voltage:
  int proximityADC = analogRead(QRD1114_PIN);
  float proximityV = (float)proximityADC * 5.0 / 1023.0;
  if(proximityV > 4.68)
    return 1; //Black
  else
    return 0; //White
}

void drive(int direction){
  switch(direction){
    case(0): //straight
      digitalWrite(motorA1A, LOW);
      digitalWrite(motorA1B, HIGH);
      digitalWrite(motorB1A, HIGH);
      digitalWrite(motorB1B, LOW);
      break;
      case(1): //left
      digitalWrite(motorA1A, HIGH);
      digitalWrite(motorA1B, LOW);
      digitalWrite(motorB1A, HIGH);
      digitalWrite(motorB1B, LOW);
      break;
      case(2): //backwards
      digitalWrite(motorA1A, HIGH);
      digitalWrite(motorA1B, LOW);
      digitalWrite(motorB1A, LOW);
      digitalWrite(motorB1B, HIGH);
      break;
      case(3): //right
      digitalWrite(motorA1A, LOW);
      digitalWrite(motorA1B, HIGH);
      digitalWrite(motorB1A, LOW);
      digitalWrite(motorB1B, HIGH);
      break;
      case(4): //stop
      digitalWrite(motorA1A, LOW);
      digitalWrite(motorA1B, LOW);
      digitalWrite(motorB1A, LOW);
      digitalWrite(motorB1B, LOW);
      break;
     }
}

void setup() {
  Serial.begin(9600);
  
  //Set Up
  Serial.println("Setting Up");
  delay(5000);
  
  //Sensor Variables
  pinMode (trigSensorFront, OUTPUT);
  pinMode (echoSensorFront, INPUT);
  pinMode (trigSensorRight, OUTPUT);
  pinMode (echoSensorRight, INPUT);
  pinMode (trigSensorLeft, OUTPUT);
  pinMode (echoSensorLeft, INPUT);

  //Motor Variables
  pinMode (motorA1A, OUTPUT);
  pinMode (motorA1B, OUTPUT);
  pinMode (motorB1A, OUTPUT);
  pinMode (motorB1B, OUTPUT);
  
  //QRD Pin Setup - AO  
  pinMode(QRD1114_PIN, INPUT);
}

void loop() {
   //Defense Algorithms(Using QRD Sensors)
  currentLoc = qrdSensor();
  Serial.println("QRD Sensor Value: ");
  Serial.println(currentLoc);

  if(currentLoc == 0){ //If the robot is close to the end of the ring, it drops everything and saves itself
    drive(2); // Reverses
    delay(1000);   

    drive(1); //Turns Around
    delay(2000);

    drive(0);
    delay(1000);
  }

  else{ 
  //If the robot is clear to attack the enemy
  distanceFront = ultrasonicRead(trigSensorFront,echoSensorFront);
  Serial.println("Front Sensor Value: ");
  Serial.println(distanceFront);
  
  distanceLeft = ultrasonicRead(trigSensorLeft,echoSensorLeft);
  Serial.println("Left Sensor Value: ");
  Serial.println(distanceLeft);

  distanceRight = ultrasonicRead(trigSensorRight,echoSensorRight);
  Serial.println("Right Sensor Value: ");
  Serial.println(distanceRight);   
}  
  delay(500);  
}
