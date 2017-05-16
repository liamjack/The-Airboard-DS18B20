#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(3);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);

  sensors.begin();
  sensors.setResolution(10);
}

void loop() {
  sensors.requestTemperatures();
  
  float temperature = sensors.getTempCByIndex(0);

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  delay(1000);
}
