const int trigPinRight = 8; //white: A1, D7: 7
const int echoPinRight = 9; //grey: A2, D6: 6
const int trigPinLeft = 7; //orange: A3, D5: 5
const int echoPinLeft = 6; //yellow: A4, D4: 4
const int vibPinLeft = 13; //purple: A6, D2: 2
const int vibPinRight = 12; //green: A5, D3: 3

long durationRight, cmRight;
long durationLeft, cmLeft;

void setup() {
    Serial.begin (9600);
    pinMode(trigPinRight, OUTPUT);
    pinMode(echoPinRight, INPUT);
    pinMode(trigPinLeft, OUTPUT);
    pinMode(echoPinLeft, INPUT);
    pinMode(vibPinLeft, OUTPUT);
    pinMode(vibPinRight, OUTPUT);
}


void loop() {
    digitalWrite(trigPinRight, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPinRight, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinRight, LOW);
    durationRight = pulseIn(echoPinRight, HIGH);
    cmRight = round(durationRight/58.2);
    
    digitalWrite(trigPinLeft, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPinLeft, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPinLeft, LOW);
    durationLeft = pulseIn(echoPinLeft, HIGH);
    cmLeft = round(durationLeft/58.2);
    
    Serial.print(cmRight);
    Serial.print("cm - Right side");
    Serial.println();
    delay(10);                       //ms
    Serial.print(cmLeft);
    Serial.print("cm - Left side");
    Serial.println();
    
    
    if (cmRight <= 105) {
      digitalWrite(vibPinRight, HIGH);
    }
    if (cmLeft <= 105) {
      digitalWrite(vibPinLeft, HIGH);
    }
    if (cmRight > 105) {
      digitalWrite(vibPinRight, LOW);
    }
    if (cmLeft > 105) {
      digitalWrite(vibPinLeft, LOW);
    }
    
    delay(800);                       //ms
} 
