//Copyright Code by Botty Mons (Dont steal our stuff) -> Taught By My Dawg Habib

//12 is echo, 13 is trigger
#define trigSensorFront 13
#define echoSensorFront 12
#define trigSensorRight 11
#define echoSensorRight 10
#define trigSensorLeft 9
#define echoSensorLeft 8

long durationFront;
int distanceFront;
long durationRight;
int distanceRight;
long durationLeft;
int distanceLeft;

int ultrasonicFront(void){
    //Code to run Ultrasonic Sensor
  digitalWrite (trigSensorFront, LOW);
  delayMicroseconds (2);

  digitalWrite(trigSensorFront, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigSensorFront, LOW);
  durationFront = pulseIn(echoSensorFront, HIGH);
  distanceFront = durationFront*0.034/2;
  
  //Serial.println(distance);
  //delay(100);

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
  
  //Serial.println(distance);
  //delay(100);

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
  
  //Serial.println(distance);
  //delay(100);

  return distanceLeft;
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  //Trig outputs data while Echo inputs data
  pinMode (trigSensorFront, OUTPUT);
  pinMode (echoSensorFront, INPUT);
  pinMode (trigSensorRight, OUTPUT);
  pinMode (echoSensorRight, INPUT);
  pinMode (trigSensorLeft, OUTPUT);
  pinMode (echoSensorLeft, INPUT);  


}

void loop() {
  
  Serial.println("Front Sensor Value:");
  Serial.println(ultrasonicFront());
  Serial.println("Right Sensor Value:");
  Serial.println(ultrasonicRight());
  Serial.println("Left Sensor Value:");
  Serial.println(ultrasonicLeft());
  delay(200);
  
}
