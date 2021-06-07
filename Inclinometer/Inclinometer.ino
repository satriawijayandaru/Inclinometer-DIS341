char incomingByte;
#define inclinometer  Serial2
#define outputSerial Serial
int led = 13;
void setup() {
  outputSerial.begin(115200);
  inclinometer.begin(115200);
  pinMode(led, OUTPUT);

}

void loop() {
  inclinometerangle();
  recvWithEndMarker();
  showNewData();
  
  delay(100);
}

void inclinometerangle() {
  digitalWrite(led, HIGH);
  inclinometer.write(0x77);
  inclinometer.write(0x04);
  inclinometer.write(0x00);
  inclinometer.write(0x04);
  inclinometer.write(0x08);
  if (inclinometer.available()) {
    incomingByte = inclinometer.read();
    outputSerial.print("Inclinometer = ");
    outputSerial.println();
  }
  digitalWrite(led, LOW);
}

#define END_MARKER '\n'
void recvWithEndMarker() {
  static byte ndx = 0;
  char rc;

  while (sensorSerial.available() > 0 && !newData) {
    rc = sensorSerial.read();

    if (rc != END_MARKER) {
      receivedChars[ndx++] = rc;
      if (ndx >= numChars) {
        ndx = numChars - 1;
      }
    } else {
      receivedChars[ndx] = '\0'; // terminate the string
      ndx = 0;
      newData = true;
    }
  }
}

void showNewData() {
  if (newData) {
    Serial.print("data ");
    for (unsigned int i = 0; i < numChars; i++) {
      Serial.print(receivedChars[i], HEX);
    }
    Serial.println();
    newData = false;
  }
}
