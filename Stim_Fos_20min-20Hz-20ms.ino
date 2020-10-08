// GG for Peters Lab (7-18-2019)
// Stimulation protocol: 20min, 20Hz-20ms (Laser: 20ms ON - 30ms OFF)

#define stimulation 4               // pin 4 on arduino as stimulation pin
#define led 13                      // built-in led
unsigned long startMillis;
unsigned long currentMillis;
const unsigned long stimTime = 20*60000;  // Stimulation Time (60s = 60000ms X 20min)

void setup() {
  Serial.begin(115200);
  pinMode(stimulation,OUTPUT);       
  pinMode(led, OUTPUT);
  digitalWrite(stimulation, LOW);   // force laser OFF before starting
  digitalWrite(led, LOW);
  Serial.println("Standby:");
  Serial.println("Press any key to start stimulation");
  while (!Serial.available()){}     // do absolutely nothing until serial input received
  startMillis = millis();           // time (ms) when input received
  Serial.println("Now you wait 20min :)");       
}  
void loop() {
  currentMillis = millis();         // time (ms) beginning of the loop
  if (currentMillis - startMillis <= stimTime) {  
  digitalWrite(stimulation, HIGH);  // Laser ON
  digitalWrite(led, HIGH);          // Internal Led ON 
  delay(20);                        // Keep laser ON for 20ms
  digitalWrite(stimulation, LOW);   // Laser OFF
  digitalWrite(led, LOW);           // Internal Led OFF
  delay(30);                        // Keep laser OFF for 30ms
}   
  else {                            // After 20min do nothing (stop stimulation)
    }                          
}
