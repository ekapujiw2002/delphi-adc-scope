void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  
}

void loop() {
  String dtx = "";
  dtx += "#"+String(analogRead(A0),DEC)+","+String(analogRead(A1),DEC)+","+String(analogRead(A2),DEC);
  Serial.println(dtx);
}
