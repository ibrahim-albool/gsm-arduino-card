
void setup() {
  // initialize serial:
  Serial.begin(115200);




  pinMode(2, INPUT);
  pinMode(13, OUTPUT);

  delay(10000);
  Serial.println("AT+CMGF=1");
  delay(100);
  Serial.println("ATE0");

}

void loop() {
  double reading = digitalRead(2);
  double y;
  static double y1 = 100, out;
  static int messageSent = 0;
  reading *= 100;
  y = (reading + y1 * 99) / 100.0;
  y1 = y;
  if (y > 75) {
    out = 1;
    messageSent=0;
  } else if (y < 25) {
    out = 0;
    if (!messageSent) {
	  //replace NUMBER with the cellphone number with the country code. 
	  //Pump is off message will be sent to the +NUMBER
      Serial.print("AT+CMGS=\"+NUMBER\"\nPump is off\x1A");
      messageSent = 1;
    }
  }

  digitalWrite(13, out == 1 ? HIGH : LOW);
  delay(10);

}


