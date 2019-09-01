

const int doorPin = 2;
const int lightsPin = 13;

void setup() {
  pinMode(doorPin, INPUT);
  pinMode(lightsPin, OUTPUT);

  digitalWrite(lightsPin, HIGH);
  
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  Serial.println("Started");
}

void loop() {
  int doorState = digitalRead(doorPin);

  if (doorState == LOW) {
    Serial.println("Door Opened");
    digitalWrite(lightsPin, LOW);
  } else {
    digitalWrite(lightsPin, HIGH);
  }
}
