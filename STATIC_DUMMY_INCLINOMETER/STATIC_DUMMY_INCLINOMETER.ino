char incomingByte;
#define inclinometer  Serial2
#define inputSerial Serial3
#define outputSerial Serial
int led = 13;
void setup() {
  outputSerial.begin(115200);
  inclinometer.begin(115200);

}

void loop() {
  inclinometerangle();
  if(inputSerial.available()){
    outputSerial.print("get data = ");
    outputSerial.println(inputSerial.read());
  }
  pinMode(led, OUTPUT);
  delay(100);
}

void inclinometerangle() {
  digitalWrite(led, HIGH);
  inclinometer.write(0x77);
  inclinometer.write(0x0D);
  inclinometer.write(0x00);
  inclinometer.write(0x84);
  inclinometer.write(0x10);
  inclinometer.write(0x01);
  inclinometer.write(0x97);
  inclinometer.write(0x10);
  inclinometer.write(0x00);
  inclinometer.write(0x77);
  inclinometer.write(0x00);
  inclinometer.write(0x00);
  inclinometer.write(0x00);
  inclinometer.write(0xC0);

  inclinometer.write(0x77);
  inclinometer.write(0x0D);
  inclinometer.write(0x00);
  inclinometer.write(0x84);
  inclinometer.write(0x10);
  inclinometer.write(0x02);
  inclinometer.write(0x05);
  inclinometer.write(0x10);
  inclinometer.write(0x00);
  inclinometer.write(0x85);
  inclinometer.write(0x00);
  inclinometer.write(0x00);
  inclinometer.write(0x00);
  inclinometer.write(0x3D);

  inclinometer.write(0x77);
  inclinometer.write(0x0D);
  inclinometer.write(0x00);
  inclinometer.write(0x84);
  inclinometer.write(0x10);
  inclinometer.write(0x02);
  inclinometer.write(0x01);
  inclinometer.write(0x10);
  inclinometer.write(0x00);
  inclinometer.write(0x79);
  inclinometer.write(0x00);
  inclinometer.write(0x00);
  inclinometer.write(0x00);
  inclinometer.write(0x2D);

  inclinometer.write(0x77);
  inclinometer.write(0x0D);
  inclinometer.write(0x00);
  inclinometer.write(0x84);
  inclinometer.write(0x10);
  inclinometer.write(0x01);
  inclinometer.write(0x94);
  inclinometer.write(0x10);
  inclinometer.write(0x00);
  inclinometer.write(0x68);
  inclinometer.write(0x00);
  inclinometer.write(0x00);
  inclinometer.write(0x00);
  inclinometer.write(0xAE);

  digitalWrite(led, LOW);
}
