/*
 * very basic sketch for PLX DAQ test
 * for new "Version 2" of PLX DAQ
 */

int i = 0;
int pirPin = D7;
int val;

void setup() {

  // open serial connection
    Serial.begin(9600);

  // define 2 rows: first named "Counter", second named "millis"
    Serial.println("CLEARDATA");
    Serial.println("LABEL,Time,Number,Sense");
}

void loop() {
val = digitalRead(pirPin);
//low = no motion, high = motion
if (val == LOW)
{
  Serial.println("No motion");
}
else
{
  Serial.println("Motion detected  ALARM");
}

delay(1000);


  // simple print out of number and millis
  // output "DATA,TIME,4711,13374"
    Serial.print("DATA,TIME,");
    Serial.print(i); Serial.print(",");
    Serial.println("No motion");
}
