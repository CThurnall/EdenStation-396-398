// Simple analog read example on ESP32 (GPIO32)

int sensorPin = 32;   // ADC1 channel 4
int sensorValue = 0;
int maxVal = 1050;    // calibration max (adjust to your sensor)
int pump = 33;

void setup() {
  Serial.begin(115200);   // start serial monitor
  pinMode(pump, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);  // returns 0–4095 (12-bit ADC)

  // Convert to percentage using float math
  float percent = (float(sensorValue) / maxVal) * 100.0;

  Serial.print("Analog value on GPIO32: ");
  Serial.print(percent, 1);   // print with 1 decimal place
  Serial.println("%");

  digitalWrite(pump, HIGH);
  delay(500);

}