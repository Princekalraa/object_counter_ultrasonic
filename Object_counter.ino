const int trigPin = 2;
const int echoPin = 3;
const int ledPin = 13;

unsigned long previousMillis = 0;
const long interval = 1000;

int distanceThreshold = 20;
int objectCount = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    
    int distance = measureDistance();
    
    if (distance < distanceThreshold) {
      objectCount++;
      digitalWrite(ledPin, HIGH);
      Serial.print("Object detected! Total count: ");
      Serial.println(objectCount);
    } else {
      digitalWrite(ledPin, LOW);
    }
  }
}

int measureDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  int duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  
  return distance;
}
