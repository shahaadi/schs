
const int trig1 = 7;
const int trig2 = 8;
const int echo1 = 6;
const int echo2 = 9;
const int vibPin = 13;
const int vibPin2 = 12;
char value;
char value2;
void setup() {
  // initialize serial communication:
  Serial.begin(9600);
}

void loop() {
  // establish variables for duration of the ping, and the distance result
  // in inches and centimeters:
  long duration, inches, cm;
  long duration2, inches2, cm2;
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trig1, OUTPUT);
  pinMode(trig2, OUTPUT);
  pinMode(echo1, OUTPUT);
  pinMode(echo2, OUTPUT);
  pinMode(vibPin, OUTPUT);
  pinMode(vibPin2, OUTPUT);

  //shooting u1
  digitalWrite(trig1, LOW);
  digitalWrite(echo1, LOW);
  delayMicroseconds(2);
  digitalWrite(trig1, HIGH);
  digitalWrite(echo1, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig1, LOW);
  digitalWrite(echo1, LOW);
 
  //shooting u2
  digitalWrite(trig2, LOW);
  digitalWrite(echo2, LOW);
  delayMicroseconds(2);
  digitalWrite(trig2, HIGH);
  digitalWrite(echo2, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig2, LOW);
  digitalWrite(echo2, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
 
  //setting u1
  pinMode(trig1, INPUT);
  pinMode(echo1, INPUT);
  duration = pulseIn(trig1, HIGH);
  duration = pulseIn(echo1, HIGH);
  //setting u2
  pinMode(trig2, INPUT);
  pinMode(echo2, INPUT);
  duration2 = pulseIn(trig2, HIGH);
  duration2 = pulseIn(echo2, HIGH);
 
  // convert the time into a distance u1
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
 
  //convert the time into a distance u2
  inches2 = microsecondsToInches(duration2);
  cm2 = microsecondsToCentimeters(duration2);
 
  //print out for u1
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.print(value);
  Serial.println();
 
  //print out for u2
  Serial.print(inches2);
  Serial.print("in2, ");
  Serial.print(cm2);
  Serial.print("cm2");
  Serial.print(value2);
  Serial.println();
 
  delay(10);
 
  //logic for u1
  if (cm > 150) {
    digitalWrite(vibPin, HIGH);
  }
  if (cm < 150) {
    digitalWrite(vibPin, LOW);
  }
 
  //logic for u2
  if (cm2 > 150) {
    digitalWrite(vibPin2, HIGH);
  }
  if (cm2 < 150) {
    digitalWrite(vibPin2, LOW);
  }
}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

long compare(long centimeter, char letter) {
  if (centimeter > 150) {
    value='T';
  }
  else {
    value='F';
  }
}

long compare2(long centimeter2, char letter2) {
  if (centimeter2 > 150) {
    value2='T';
  }
  else {
    value2='F';
  }
}


