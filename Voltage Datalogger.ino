//Monitors all anolog inputs every x seconds 

int sec = 1000 // time in millseconds
const byte ainputs[] = {A0, A1, A2, A3, A4, A5};
unsigned long oldtime = 0L ;
static unsigned long lasttime ;
const float scalefactor = .004975; // my scalefactor: yours will be different

void setup() {
  pinMode (LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // initialize serial communication at 9600 bits per second:
}

void loop (){
    if ( (millis()-oldtime) > sec) {
       oldtime = millis();
       collect();
    }
}

void collect() {
   for (int pin = 0; pin < 5; pin++)
    {
      int dummy = analogRead(ainputs[pin]);  //read values twice as advised
      int sensorvalue = analogRead(ainputs[pin]);
      float floatvoltage = sensorvalue * scalefactor;
      Serial.print(flotvoltage,3);  //do whatever you want with the value
      Serial.print(",");
    }
  Serial.println("")
}
