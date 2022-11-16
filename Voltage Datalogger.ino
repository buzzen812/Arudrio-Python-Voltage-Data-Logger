#define HOUR (60 * 60 * 1000L)
#define tensec (1 * 1000L)
unsigned long oldtime = 0L ;
static unsigned long lasttime ;
const float scalefactor = .004975; // my scalefactor: yours will be different


void setup() {
  pinMode (LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // initialize serial communication at 9600 bits per second:
}


void loop (){
    if ( (millis()-oldtime) > 1000) {
       oldtime = millis();

      collect();

    }
}

void collect() {
  // read the input on analog pin 0:
  int sensorValue0 = analogRead(A0);
  int sensorValue1 = analogRead(A1);
  int sensorValue2 = analogRead(A2);
  int sensorValue3 = analogRead(A3);
  int sensorValue4 = analogRead(A4);
  int sensorValue5 = analogRead(A5);
  
  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage0 = sensorValue0 * scalefactor;
  float voltage1 = sensorValue1 * scalefactor;
  float voltage2 = sensorValue2 * scalefactor;
  float voltage3 = sensorValue3 * scalefactor;
  float voltage4 = sensorValue4 * scalefactor;
  float voltage5 = sensorValue5 * scalefactor;
  // print out the value you read:
  Serial.print(voltage0,3);
   Serial.print(",");  
  Serial.print(voltage1,3);
    Serial.print(",");
  Serial.print(voltage2,3);
    Serial.print(",");
  Serial.print(voltage3,3);
    Serial.print(",");
  Serial.print(voltage4,3);
    Serial.print(",");
  Serial.println(voltage5,3);

}