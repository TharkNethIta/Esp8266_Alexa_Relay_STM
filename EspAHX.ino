#define ESPALEXA_ASYNC //it is important to define this before #include <Espalexa.h>!
#include <Espalexa.h>

#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#else
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>
//#include <WiFiManager.h>  
#include "webpage.h"



#define ESPALEXA_MAXDEVICES 3   //added for save memory

/*
IMPORTANT: MODIFY THE GATEWAY AND IP FOR YOUR NETWORK
*/

IPAddress local_IP(192,168,1,200);
IPAddress gateway(192,168,1,254);  
IPAddress subnet(255,255,255,0);

const byte rel1ON[] = {0xA0, 0x01, 0x01, 0xA2};  //Hex command to send to serial for open relay
const byte rel1OFF[] = {0xA0, 0x01, 0x00, 0xA1}; //Hex command to send to serial for close relay
const byte rel2ON[] = {0xA0, 0x02, 0x01, 0xA3};
const byte rel2OFF[] = {0xA0, 0x02, 0x00, 0xA2};

/*you can add more relay: 0xA0<--same for all, 0x02<--relay count(rel 1, 2, 3 or 4), 0x01<--01=ON, 00=OFF, 0xA3 <-- SUM of previews number
const byte rel3ON[] = {0xA0, 0x03, 0x01, 0xA4};  
const byte rel3OFF[] = {0xA0, 0x03, 0x00, 0xA3}; 
const byte rel4ON[] = {0xA0, 0x04, 0x01, 0xA5};
const byte rel4OFF[] = {0xA0, 0x04, 0x00, 0xA4};
*/


// Change this!!
const char* ssid = "*******";
const char* password = "*******";


bool staterel0 = false;
bool staterel1 = false;


Espalexa espalexa;

EspalexaDevice* d;  //global device for get updates of rel0 sttae for alexa app



void toggle_rel0(){
  if(staterel0 == false){
    Serial.write(rel1ON, sizeof(rel1ON));
    staterel0 = true; 
    d->setValue(255);
    Serial.print("ON");
  }
  else if(staterel0 == true){
    Serial.write(rel1OFF, sizeof(rel1OFF));
    staterel0 = false;
    d->setValue(0);
    Serial.print("OFF");
  }

  
}

//Function for trigger relay in base of the previous command

void toggle_rel1(){
  if(staterel1 == false){
    Serial.write(rel2ON, sizeof(rel2ON));
    //fauxmo.setState(unsigned char 1, bool ON, unsigned char 200);
    staterel1 = true; 
    Serial.print("ON");
  }
  else if(staterel1 == true){
    Serial.write(rel2OFF, sizeof(rel2OFF));
    //fauxmo.setState(unsigned char 1, bool OFF, unsigned char 200);
    staterel1 = false;
    Serial.print("OFF");
  }
}

// prototypes
boolean connectWifi();

//callback functions
void firstLightChanged(uint8_t brightness);
void secondLightChanged(uint8_t brightness);



boolean wifiConnected = false;




AsyncWebServer server(80);


void setup()
{


  Serial.begin(115200);
  // Initialise wifi connection

  wifiConnected = connectWifi();
  
  if(wifiConnected){
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/html", webpage);
        
    });
  
    

    server.on("/rel0", HTTP_GET, [](AsyncWebServerRequest *request){
        toggle_rel0();
        request->redirect("/");

    });

    server.on("/rel1", HTTP_GET, [](AsyncWebServerRequest *request){
        toggle_rel1();      
        request->redirect("/");
    });

    

    server.on("/getrel0", HTTP_GET, [](AsyncWebServerRequest *request){
        if(staterel0 == true)
          request->send(200);
        else if(staterel0 == false){
          request->send(403);
        }
        else{
          request->send(403);
        }
     //Send 200 if rel0 is triggered, 403 if it isn't
    });
    
    

    server.on("/reboot", HTTP_GET, [](AsyncWebServerRequest *request){
        request->redirect("/");
        Serial.write(rel1OFF, sizeof(rel1OFF));
        Serial.write(rel2OFF, sizeof(rel2OFF));
        ESP.restart();      
        
    });

    server.onNotFound([](AsyncWebServerRequest *request){
      if (!espalexa.handleAlexaApiCall(request)) //if you don't know the URI, ask espalexa whether it is an Alexa control request
      {
        //whatever you want to do with 404s
        request->send(404, "text/plain", "Not found");
      }
    });

    // Define your devices here.
    
    //espalexa.addDevice("ciabattaprova3", firstLightChanged); //simplest definition, default state off
    d = new EspalexaDevice("STM_RELAY1", firstLightChanged);
    espalexa.addDevice(d);
    espalexa.addDevice("STM_RELAY2", secondLightChanged);
    AsyncElegantOTA.begin(&server);

    espalexa.begin(&server); 
    
  } else
  {
    while (1)
    {
      Serial.println("Cannot connect to WiFi. Please check data and reset the ESP.");
      delay(2500);
    }
  }
}
 
void loop()
{
   espalexa.loop();

  static unsigned long last = millis();
  if (millis() - last > 15000) {
      last = millis();
      Serial.printf("[MAIN] Free heap: %d bytes\n", ESP.getFreeHeap());
  }
 
  if(WiFi.status() != WL_CONNECTED){
    WiFi.softAP("EspAHX", "fibonacci");  //Default wifi password if network is not avaiable is 'fibonacci' like ESPurna
  }
  else
    WiFi.softAPdisconnect (true);


  delay(1);
}

//our callback functions
void firstLightChanged(uint8_t brightness) {
    Serial.print("Device 1 changed to ");
    
    //do what you need to do here

    //EXAMPLE
    if (brightness >= 1) {
      Serial.println("ON");
      Serial.write(rel1ON, sizeof(rel1ON));
      staterel0 = true;
    }
    else if (brightness == 0) {
      Serial.println("OFF");
      Serial.write(rel1OFF, sizeof(rel1OFF));
      staterel0 = false;
    }
    else {
      Serial.print("DIM "); Serial.println(brightness);
    }
}

void secondLightChanged(uint8_t brightness) {
    Serial.print("Device 2 changed to ");
    if (brightness == 255) {
      Serial.println("ON");
      toggle_rel1();
    }
    else if (brightness == 0) {
      Serial.println("OFF");
      toggle_rel1();
    }
    
}

// connect to wifi – returns true if successful or false if not
boolean connectWifi(){
  boolean state = true;
  int i = 0;
  
  WiFi.mode(WIFI_AP_STA);
  
  if (WiFi.config(local_IP, gateway, subnet)) {
      Serial.println("Static IP Configured");
    }
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("Connecting to WiFi");

  // Wait for connection
  Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (i > 20){
      state = false; break;
    }
    i++;
  }
  Serial.println("");
  if (state){
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
  else {
    Serial.println("Connection failed.");
  }
  delay(100);
  return state;
}