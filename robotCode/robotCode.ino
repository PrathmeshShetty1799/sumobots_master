//Copyright Code by Botty Mons (Dont steal our stuff) -> Taught By My Dawg Habib

//define LED PIN on arduino
#define LED_PIN 13

//12 is echo, 13 is trigger
#define Trig 13
#define Echo 12

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  //Set LED_PIN to output mode
  pinMode (LED_PIN, OUTPUT);
  
  //Trig outputs data while Echo inputs data
  pinMode (Trig, OUTPUT);
  pinMode (Echo, INPUT);

  

}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("Hello World!");


  //Turning the LED on and off
  
  /*
  digitalWrite(LED_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  delay(1000);
  */

  //Code to run Ultrasonic Sensor
  digitalWrite (Trig, LOW);
  delayMicroseconds (2);

  digitalWrite(Trig, HIGH);
  delayMicroseconds (10);
  digitalWrite (Trig, LOW);
  duration = pulseIn(Echo, HIGH);
  distance = duration*0.034/2;
  
  Serial.println(distance);
  delay(500);
  
}
