/*
    This sketch demonstrates how to scan WiFi networks.
    The API is almost the same as with the WiFi Shield library,
    the most obvious difference being the different file you need to include:
*/
int ledPin = 2;
#include "WiFi.h"

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);

  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup done");
}

void loop()
{
  Serial.println("scanning start");

  ////// Setting light to beep //////////
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  
  delay(100);
  
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  
  delay(100);
  
  digitalWrite(ledPin, HIGH);
  delay(100);
  digitalWrite(ledPin, LOW);
  
  delay(1000);
  //////////////////**************///////////////
  
  // WiFi.scanNetworks will return the number of networks found
  int totalWifis = WiFi.scanNetworks();
  Serial.println("scan done");
  if (totalWifis == 0) {
    Serial.println("no networks found");
  } else {
    Serial.print(totalWifis);
    Serial.println(" networks found");
    for (int i = 0; i < totalWifis; ++i) {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");

      //Received Signal Strength Indicator
      Serial.print(WiFi.RSSI(i));

      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");
      delay(10);
    }
  }
  Serial.println("");

  // Wait a bit before scanning again
  delay(5000);
}
