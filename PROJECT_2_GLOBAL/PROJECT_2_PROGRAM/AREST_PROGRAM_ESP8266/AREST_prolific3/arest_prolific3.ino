//this is final program for arest with website 

/*
https://cloud.arest.io/prolific3/mode/5/o //output direction
https://cloud.arest.io/prolific3/digital/5/1 //high logic "on"
https://cloud.arest.io/prolific3/digital/5/0 //low logic  "off"

https://cloud.arest.io/prolific2/analog/A0  //analog input sensor

https://cloud.arest.io/prolific2/mode/4/i   //input mode for direction
https://cloud.arest.io/prolific2/digital/4 //reading status of digital pin for feedback


https://cloud.arest.io/prolific2/analog/0/100 //pwm - analog write(0-1023)
*/

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <aREST.h>

WiFiClient espClient;
PubSubClient client(espClient);

aREST arestVar = aREST(client);

/*Enter an Unique ID to identify the device for arest.io
A Maximum of 6 characters are supported. Must be unique.*/

char* device_id = "prolific3"; // Do not use this device_id. Create your own id. 

/* Enter SSID and Password of your 
WiFi Network*/
const char* ssid = "IOT_SSD_CNT"; // Name of WiFi Network. 
const char* password = "123456789"; // Password of your WiFi Network.

void callback(char* topic, byte* payload, unsigned int length);

void setup(void)
{
  Serial.begin(115200);

  client.setCallback(callback);
  
  // Give name and ID to device
  arestVar.set_id(device_id);
  arestVar.set_name("MyESP"); //name 

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print("*");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  char* out_topic = arestVar.get_topic();
}

void loop() 
{
  arestVar.loop(client);
}

void callback(char* topic, byte* payload, unsigned int length) 
{
  arestVar.handle_callback(client, topic, payload, length);
}
