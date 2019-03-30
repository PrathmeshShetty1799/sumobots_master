//Copyright Code by Botty Mons (Dont steal our stuff) -> Taught By My Dawg Habib

//Sensor Variables
#define trigSensorFront 13
#define echoSensorFront 12
#define trigSensorRight 11
#define echoSensorRight 10
#define trigSensorLeft 9
#define echoSensorLeft 8
#define motorB1A 5
#define motorB1B 4
#define motorA1A 3
#define motorA1B 2

//UL Sensor Varaibles
int leftDistance;
int rightDistance;
int frontDistance;

//QRD Sensor Variables
const int QRD1114_PIN = A0; // Sensor output voltage

//Functions
int ultrasonicRead(int trig, int echo){
  digitalWrite (trig, LOW);
  delayMicroseconds (2);
  digitalWrite(trig, HIGH);
  delayMicroseconds (10);
  digitalWrite (trig, LOW);
  long duration= pulseIn(echo, HIGH);
  int distance = duration*0.034/2;
  return distance;
}

int qrdSensor(void){
   // Read in the ADC and convert it to a voltage:
  int proximityADC = analogRead(QRD1114_PIN);
  float proximityV = (float)proximityADC * 5.0 / 1023.0;
  if(proximityV < 2.00)
    return 1; //White
  else
    return 0; //Black
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
  frontDistance = ultrasonicRead(trigSensorFront,echoSensorFront);
  leftDistance = ultrasonicRead(trigSensorLeft,echoSensorLeft);
  rightDistance = ultrasonicRead(trigSensorRight,echoSensorRight);

  Serial.println("Front Sensor Value: " + frontDistance);
  //Serial.println("Left Sensor Value:" + leftDistance);
  //Serial.println("Right Sensor Value:" + rightDistance);
  
  Serial.println("QRD Sensor Value:");
  Serial.println(qrdSensor());

  //Movement Algorithms(Using UL Sensors)
   drive(0);
  //Defense Algorithms(Using QRD Sensors)

   delay(1000); 
}

