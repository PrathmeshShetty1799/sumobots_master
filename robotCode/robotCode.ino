//Copyright Code by Botty Mons (Dont steal our stuff) -> Taught By My Dawg Habib

//Sensor Variables
#define trigSensorFront 13
#define echoSensorFront 12
#define trigSensorRight 11
#define echoSensorRight 10
#define trigSensorLeft 9
#define echoSensorLeft 8

//Motor Variables
#define motorB1A 5
#define motorB1B 4
#define motorA1A 3
#define motorA1B 2

long durationFront;
int distanceFront;
long durationRight;
int distanceRight;
long durationLeft;
int distanceLeft;

//QRD Sensor Variables
const int QRD1114_PIN = A0; // Sensor output voltage

//Functions
int ultrasonicFront(void){
    //Code to run Ultrasonic Sensor
  digitalWrite (trigSensorFront, LOW);
  delayMicroseconds (2);
  digitalWrite(trigSensorFront, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigSensorFront, LOW);
  durationFront = pulseIn(echoSensorFront, HIGH);
  distanceFront = durationFront*0.034/2;
  return distanceFront;
}

int ultrasonicRight(void){
    //Code to run Ultrasonic Sensor
  digitalWrite (trigSensorRight, LOW);
  delayMicroseconds (2);
  digitalWrite(trigSensorRight, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigSensorRight, LOW);
  durationRight = pulseIn(echoSensorRight, HIGH);
  distanceRight = durationRight*0.034/2;
  return distanceRight;
}

int ultrasonicLeft(void){
    //Code to run Ultrasonic Sensor
  digitalWrite (trigSensorLeft, LOW);
  delayMicroseconds (2);
  digitalWrite(trigSensorLeft, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigSensorLeft, LOW);
  durationLeft = pulseIn(echoSensorLeft, HIGH);
  distanceLeft = durationLeft*0.034/2;
  return distanceLeft;
}

int qrdSensor(void){
   // Read in the ADC and convert it to a voltage:
  int proximityADC = analogRead(QRD1114_PIN);
  float proximityV = (float)proximityADC * 5.0 / 1023.0;
  if(proximityV > 4.98)
    return 1; //Black
  else
    return 0; //White
}

void drive(int direction){
  switch(direction){
    case(0): //straight
      digitalWrite(motorA1A, HIGH);
      digitalWrite(motorA1B, LOW);
      digitalWrite(motorB1A, HIGH);
      digitalWrite(motorB1B, LOW);
      break;
      case(1): //left
      digitalWrite(motorA1A, HIGH);
      digitalWrite(motorA1B, LOW);
      digitalWrite(motorB1A, LOW);
      digitalWrite(motorB1B, HIGH);
      break;
      case(2): //right
      digitalWrite(motorA1A, LOW);
      digitalWrite(motorA1B, HIGH);
      digitalWrite(motorB1A, HIGH);
      digitalWrite(motorB1B, LOW);
      break;
  }
}

void setup() {
  Serial.begin(9600);
  //Set Up
  Serial.println("Setting Up");
  delay(5000);
  
  //Trig outputs data while Echo inputs data
  pinMode (trigSensorFront, OUTPUT);
  pinMode (echoSensorFront, INPUT);
  pinMode (trigSensorRight, OUTPUT);
  pinMode (echoSensorRight, INPUT);
  pinMode (trigSensorLeft, OUTPUT);
  pinMode (echoSensorLeft, INPUT);
  pinMode (motorA1A, OUTPUT);
  pinMode (motorA1B, OUTPUT);
  pinMode (motorB1A, OUTPUT);
  pinMode (motorB1B, OUTPUT);
  
  //QRD Pin Setup - AO  
  pinMode(QRD1114_PIN, INPUT);
}

void loop() {
  //Taking Readings
  //Serial.println("Front Sensor Value:");
  //Serial.println(ultrasonicFront());
  //Serial.println("Right Sensor Value:");
  //Serial.println(ultrasonicRight());
  //Serial.println("Left Sensor Value:");
  //Serial.println(ultrasonicLeft());
  Serial.println("QRD Sensor Value:");
  Serial.println(qrdSensor());
  
  delay(500); 
  //Movement Algorithms(Using UL Sensors)
  //Defense Algorithms(Using QRD Sensors)
}