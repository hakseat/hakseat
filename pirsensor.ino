int Led = 8;
int SensorOut = 7;
int val;

void setup() {
  pinMode(Led, OUTPUT);
  pinMode(SensorOut, INPUT);
  
}
void loop() {
  val = digitalRead(SensorOut);  // 적외선 센서값 읽어 저장
  if (val == HIGH)  {
    digitalWrite(Led, HIGH);
  }  
  else  {
    digitalWrite(Led, LOW);
  }
  delay(100);  
}
