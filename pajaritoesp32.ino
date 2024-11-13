/**
 * PajaritoESP32, Este schech genera un raton bluethoot que se mueve cada 5m para generar presencia.
 * Realizado en un ESP32 WROOM32D 
 * OJO Usar con las ESP32 boards (espressif) 2.0.17   no funciona con las versiones 3.X.X
 */
#include <BleMouse.h>
#include <Arduino.h>

BleMouse bleMouse;

#define LED_PIN 02 ///En el wroom32 es el led 

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("Iniciando raton Bluetooht");
  bleMouse.begin();
}

void blink() {
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  delay(1000);
  digitalWrite(LED_PIN, !digitalRead(LED_PIN));

}


void loop() {
  if(bleMouse.isConnected()) {

    unsigned long startTime;
    
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Move mouse pointer up");
    startTime = millis();
    while(millis()<startTime+2000) {
      bleMouse.move(0,-1);
      delay(100);
    }
    delay(500);

    Serial.println("Move mouse pointer down");
    startTime = millis();
    while(millis()<startTime+2000) {
      bleMouse.move(0,1);
      delay(100);
    }
    delay(500);

    Serial.println("Move mouse pointer left");
    startTime = millis();
    while(millis()<startTime+2000) {
      bleMouse.move(-1,0);
      delay(100);
    }
    delay(500);

    Serial.println("Move mouse pointer right");
    startTime = millis();
    while(millis()<startTime+2000) {
      bleMouse.move(1,0);
      delay(100);
    }
    delay(500);

  } else {
      digitalWrite(LED_PIN, LOW);
      Serial.println("¡¡SIN CONEXION!!");
      blink();
  }

  Serial.println("Esperamos 5min (300seg)...");
  delay(300000);
}