const int soilMoisturePin = 2;
const int ledPin = 10;


volatile bool sensorState = false;
volatile bool sensor2State = false;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(A0,INPUT);
  pinMode(3,INPUT_PULLUP);
  pinMode(soilMoisturePin, INPUT);

  attachInterrupt(digitalPinToInterrupt(soilMoisturePin), handleInterrupt, CHANGE);
   attachInterrupt(digitalPinToInterrupt(3), handleInterrupt2, RISING);

}


void loop() {
  int tempValue = analogRead(A0);

  if(sensor2State)
  {
    Serial.println(tempValue);
    delay(2000);
    sensor2State = false;
  }
  if (sensorState) {

    Serial.println("WET");
    sensorState = false;
    digitalWrite(ledPin, 0);
    delay(1000);
  } else {

    Serial.println("DRY");
  }


  delay(100);
}

void handleInterrupt() {
  sensorState = true;
  digitalWrite(ledPin, HIGH);
}

void handleInterrupt2() {
  sensor2State = true;
}
