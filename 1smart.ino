/************************************************************
 * Project: IoT-Enabled Intelligent Cotton Warehouse
 * Description:
 * Smart Godown system for cotton storage using ESP8266.
 * Features include:
 *  - Multi-room smart lighting using IR sensors
 *  - Manual control via Blynk app
 *  - Flame detection with alert
 *  - Water/moisture detection with alert
 *  - Real-time IoT monitoring
 ************************************************************/

#define BLYNK_TEMPLATE_ID "TMPL3I2NfqIlc"
#define BLYNK_TEMPLATE_NAME "Smart Godown"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

/* -------- WiFi Credentials --------
   Replace with your WiFi details */
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

/* -------- Pin Definitions -------- */
// IR Sensors
#define IR1_PIN D5
#define IR2_PIN D6
#define IR3_PIN D7

// LEDs (Room Lights)
#define LED1_PIN D1
#define LED2_PIN D2
#define LED3_PIN D4

// Safety Sensors
#define FLAME_PIN D0
#define WATER_PIN A0

/* -------- Blynk Virtual Pins -------- */
#define V_LED1 V1
#define V_LED2 V2
#define V_LED3 V3
#define V_FLAME_ALERT V4
#define V_WATER_ALERT V5

BlynkTimer timer;

/* -------- Control Variables -------- */
bool blynkLedCmd[3] = {false, false, false};
bool sensorLedState[3] = {false, false, false};
bool finalLedState[3] = {false, false, false};

/* -------- Water Sensor Threshold -------- */
int WATER_THRESHOLD = 400;

/* -------- Blynk LED Control -------- */
BLYNK_WRITE(V_LED1) { blynkLedCmd[0] = param.asInt(); }
BLYNK_WRITE(V_LED2) { blynkLedCmd[1] = param.asInt(); }
BLYNK_WRITE(V_LED3) { blynkLedCmd[2] = param.asInt(); }

/* -------- Blynk Connection -------- */
BLYNK_CONNECTED() {
  Blynk.syncAll();
}

/* -------- Sensor Reading Function -------- */
void readSensors() {

  // Read IR Sensors (LOW = object detected)
  sensorLedState[0] = (digitalRead(IR1_PIN) == LOW);
  sensorLedState[1] = (digitalRead(IR2_PIN) == LOW);
  sensorLedState[2] = (digitalRead(IR3_PIN) == LOW);

  // Combine Sensor + Blynk Control
  for (int i = 0; i < 3; i++) {
    finalLedState[i] = sensorLedState[i] || blynkLedCmd[i];
  }

  // Control LEDs
  digitalWrite(LED1_PIN, finalLedState[0]);
  digitalWrite(LED2_PIN, finalLedState[1]);
  digitalWrite(LED3_PIN, finalLedState[2]);

  /* -------- Flame Detection -------- */
  bool flameDetected = (digitalRead(FLAME_PIN) == LOW);
  if (flameDetected) {
    Blynk.logEvent("flame_detected", "🔥 Flame detected in cotton godown!");
  }

  /* -------- Water Detection -------- */
  int waterValue = analogRead(WATER_PIN);
  bool waterDetected = waterValue > WATER_THRESHOLD;

  if (waterDetected) {
    Blynk.logEvent("water_detected", "💧 Water leakage detected!");
  }

  // Send status to Blynk app
  Blynk.virtualWrite(V_FLAME_ALERT, flameDetected);
  Blynk.virtualWrite(V_WATER_ALERT, waterDetected);
}

void setup() {
  Serial.begin(9600);

  // Pin Modes
  pinMode(IR1_PIN, INPUT);
  pinMode(IR2_PIN, INPUT);
  pinMode(IR3_PIN, INPUT);

  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);

  pinMode(FLAME_PIN, INPUT);
  pinMode(WATER_PIN, INPUT);

  // Turn OFF all LEDs initially
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);

  // Connect to Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Read sensors every 300 ms
  timer.setInterval(300L, readSensors);
}

void loop() {
  Blynk.run();
  timer.run();
}