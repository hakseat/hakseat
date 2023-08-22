#include <WiFiNINA.h>  // Wi-Fi 라이브러리를 포함합니다.

int i = 0;
int pirPin = D7;
int val;

char ssid[] = "olleh_WiFi_FF7B";      // Wi-Fi 네트워크 이름
char pass[] = "0000009680";  // Wi-Fi 네트워크 비밀번호

IPAddress serverIP(192, 168, 1, 100);  // 서버의 IP 주소
WiFiClient client;

void setup() {
  // open serial connection
  Serial.begin(9600);
  // initialize Wi-Fi connection
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // define 2 rows: first named "Counter", second named "millis"
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Time,Number,Sense");
}

void loop() {
  val = digitalRead(pirPin);
  // low = no motion, high = motion
  if (val == LOW) {
    Serial.println("No motion");
  } else {
    Serial.println("Motion detected  ALARM");
  }

  delay(1000);

  // simple print out of number and millis
  // output "DATA,TIME,4711,13374"
  Serial.print("DATA,TIME,");
  Serial.print(i); Serial.print(",");
  Serial.println(val);

  // Send data to web server
  if (client.connect(serverIP, 80)) {
    client.print("GET /update?value=");
    client.print(val);
    client.println(" HTTP/1.1");
    client.println("Host: your_server_ip");
    client.println("Connection: close");
    client.println();
    client.stop();
  } else {
    Serial.println("Connection failed");
  }

  i++;
}
