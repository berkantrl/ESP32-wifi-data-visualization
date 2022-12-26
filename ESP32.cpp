#include <WiFi.h>

const char* ssid = "Wifi_ssid";
const char* password = "Wifi_password";

float deger = 0;
int DACDeger = 255; 
float DACGerilim = 0;
float akim = 0;

void setup()
{
    Serial.begin(115200);
    WiFi.begin(ssid, password);
      while (WiFi.status() != WL_CONNECTED) {
          delay(500);
          Serial.print(".");
      }
      Serial.println("");
      Serial.println("WiFi connected");
}

void loop()
{
  for (int i = 0;i<256;i++)
  {
  
  dacWrite (DAC1, i); //DAC'a verilen 0-3.3V arası gerilim 0-255 arasında verilir
  int pin = 27;
  int adcValue = analogRead(pin);
  float voltage = adcValue * 3.3/4096;
  DACGerilim = DACDeger * 3.3/255;
 //DAC'a verilen 0-255 arası değer, 0-3.3V arası gerilime çevriliyor
  akim = (DACGerilim - deger); 
  Serial.print ("vk = ");
  Serial.print (DACGerilim); 
  Serial.print("V");
  Serial.print (", Vf = ");
  Serial.print (voltage);
  Serial.print("V");
  Serial.print (", I = ");
  Serial.print (akim);
  Serial.println(" mA");
  WiFiClient client;
  client.connect("192.168.50.75", 1235);
  if (client.connect("192.168.50.75", 1235)) {
    std::string data = std::to_string(akim) + ";" + std::to_string(deger);
    char dataCharArray[data.length() + 1];
    strcpy(dataCharArray, data.c_str());
    client.println(dataCharArray);
    //client.write((uint8_t*)&dataCharArray, sizeof(dataCharArray));
    client.stop();
      }
      delay(500);
    }

    }
