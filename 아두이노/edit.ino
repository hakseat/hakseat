int pirPins[] = {D5, D6, D7};  // 배열로 여러 개의 PIR 핀을 관리
int numPirs = sizeof(pirPins) / sizeof(pirPins[0]);  // 사용된 PIR 센서의 개수
int vals[3];  // PIR 센서의 상태를 저장하는 배열

void setup() {
  Serial.begin(9600);
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Time,Sensor 1,Sensor 2,sensor 3");

  for (int i = 0; i < numPirs; i++) {
    pinMode(pirPins[i], INPUT);
  }
}

void loop() {
  Serial.print("DATA,TIME");

  for (int i = 0; i < numPirs; i++) {
    vals[i] = digitalRead(pirPins[i]);

    Serial.print(",");
    if (vals[i] == LOW) {
      Serial.print("0");  // No motion일 때 0 출력
    } else {
      Serial.print("1");  // Motion detected일 때 1 출력
    }
  }

  Serial.println();
  delay(1000);
}
