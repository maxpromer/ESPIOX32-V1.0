#define BUZZER_PIN 23

void setup() {
  ledcSetup(0, 5000, 8); // CH0 2kHz 8bit
  ledcAttachPin(BUZZER_PIN, 0);
}
 
void loop() {
  ledcWriteTone(0, 255);
  delay(500);
  ledcWriteTone(0, 0);
  delay(500);
}
