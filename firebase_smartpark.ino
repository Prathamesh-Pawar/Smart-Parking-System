

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "samy-dacc6.firebaseio.com"  //should not have http:// and the end /
#define FIREBASE_AUTH "6MtMdSlU0HEaWx5zaCx6vSS8MygeBgA0OcrRfMWD"  // go to settings in firebase,select project settings and service account, secrets auth key
#define WIFI_SSID "Xperia Z1_100c"
#define WIFI_PASSWORD "sweenruby"
int pins[4] = {D5, D6, D7, D8};

void setup() {
  Serial.begin(115200);
  
    for (int i = 0; i < 4; i++) {
    pinMode(pins[i], INPUT_PULLUP);
  }

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.set("slot_1",1);
  Firebase.set("slot_2",1);
  Firebase.set("slot_3",1);
  Firebase.set("slot_4",1);
}
void firebasereconnect(){
  Serial.println("Trying to reconnect");
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  }

void loop() {
  // set value
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting number failed:");
      Serial.println(Firebase.error());  
      firebasereconnect();
      return;
  }
    static int pinvalues[4];
  for (int i = 0 ; i < 4; i++ )
  {
    if ( pinvalues[i] != digitalRead(pins[i]))
    {
      pinvalues[i] = digitalRead(pins[i]);
      Firebase.set("slot_1",pinvalues[0]);
      Firebase.set("slot_2",pinvalues[1]);
      Firebase.set("slot_3",pinvalues[2]);
      Firebase.set("slot_4",pinvalues[3]);

  
    }
  }
}
