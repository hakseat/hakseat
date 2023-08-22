#include <ESP8266WiFi.h>

const char* ssid = "AndroidHotspot0448";
const char* password = "01053290448";
 
//int ledPin = 14;
WiFiServer server(80);
IPAddress ip(192, 168, 0, 64); 
IPAddress gateway(192, 168, 0, 64); 

int pirPin = 7; // Define PIR sensor pin
int pirState; // Variable to store PIR sensor state
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
 
  // PIR sensor pin setup
  pinMode(pirPin, INPUT);
 
  Serial.print(F("Setting static ip to : "));
  Serial.println(ip);
 
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  IPAddress subnet(255, 255, 255, 0); // set subnet mask to match your network
  WiFi.config(ip, gateway, subnet); 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println(".");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL : ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
 
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
  int value = LOW;

  // Read PIR sensor state
  pirState = digitalRead(pirPin);
 
  if (request.indexOf("/LED=ON") != -1) {
    digitalWrite(LED_BUILTIN, LOW);
    value = HIGH;
  } 
  if (request.indexOf("/LED=OFF") != -1){
    digitalWrite(LED_BUILTIN, HIGH);
    value = LOW;
  }
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");

  // Display PIR sensor state
  client.print("PIR Sensor: ");
  if (pirState==LOW) {
    client.println("o");
  } else if (pirState==HIGH) {
    client.println("x");
  }
  delay(1000);
  
  client.println("<br><br>");

  client.print("LED pin is now: ");
  if(value == HIGH) {
    client.print("On");  
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("Click <a href=\"/LED=ON\">here</a> turn the LED on Arduino ON<br>");
  client.println("Click <a href=\"/LED=OFF\">here</a> turn the LED on Arduino OFF<br>");
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
 
}
