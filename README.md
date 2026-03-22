# IoT-Based Intelligent Godown Automation and Safety System

> An IoT-enabled smart warehouse monitoring and control system for cotton storage godowns — integrating real-time environmental sensing, automated lighting, fire detection, and moisture monitoring via the Blynk mobile application.

---

## Table of Contents

- [Project Description](#project-description)
- [Objectives](#objectives)
- [Key Features](#key-features)
- [System Architecture](#system-architecture)
- [Hardware Components](#hardware-components)
- [Software Requirements](#software-requirements)
- [Pin Configuration](#pin-configuration)
- [Blynk Virtual Pin Mapping](#blynk-virtual-pin-mapping)
- [Working Logic](#working-logic)
- [Advantages](#advantages)
- [Applications](#applications)
- [Future Enhancements](#future-enhancements)
- [License](#license)

---

## Project Description

The **IoT-Enabled Intelligent Cotton Warehouse Monitoring and Control System** is a smart automation and safety solution designed for cotton storage godowns. Cotton is highly susceptible to fire hazards and moisture damage, necessitating continuous environmental supervision.

This project leverages Internet of Things technology to provide real-time monitoring, automated control, and remote supervision of warehouse environments. Built around the **ESP8266 NodeMCU** microcontroller, the system integrates multiple sensors to monitor room occupancy, fire presence, and water leakage — with all operations accessible through the **Blynk IoT mobile application**.

---

## Objectives

1. Ensure fire safety in cotton storage godowns through continuous automated monitoring and instant alert generation.
2. Detect water leakage or elevated moisture levels in real-time to prevent damage to stored cotton bales.
3. Implement smart, sensor-driven lighting control for improved energy efficiency across all warehouse rooms.
4. Enable complete remote monitoring and manual override control through an IoT-connected mobile application.
5. Improve overall warehouse safety posture and operational efficiency through centralized, automated supervision.

---

## Key Features

### Smart Multi-Room Lighting Control
- IR sensors detect human presence in each room independently
- Lights activate automatically upon motion detection
- Manual ON/OFF override available through the mobile application
- Combined sensor-based and app-based control logic

### Flame Detection System
- Continuous monitoring using a dedicated flame sensor
- Instant push notification alert on fire detection
- Critical protection layer for highly flammable cotton storage

### Water and Moisture Detection
- Analog water sensor with configurable threshold logic
- Alert triggered when moisture level exceeds the defined limit
- Prevents inventory damage from leakage or ambient humidity

### IoT-Based Remote Monitoring
- Real-time sensor dashboard on the Blynk mobile application
- Remote light switch control per room via virtual pins
- Instant push notifications for all safety-critical events

---

## System Architecture
```
[ IR Sensors ]  [ Flame Sensor ]  [ Water Sensor ]
        |               |                |
        +---------------+-----------------+
                        |
               [ ESP8266 NodeMCU ]
                        |
                   (Wi-Fi / TCP)
                        |
                 [ Blynk Cloud ]
                        |
            [ Mobile Application ]
          (Monitor / Control / Alerts)
```

**Flow Summary:**

1. ESP8266 connects to Wi-Fi and establishes a session with the Blynk Cloud server.
2. IR sensors monitor human movement across three individual rooms.
3. LEDs are actuated automatically based on occupancy or manually via the app.
4. Flame and water sensors provide continuous safety monitoring.
5. Threshold events trigger instant push alert notifications to the mobile device.

---

## Hardware Components

| No. | Component               | Quantity |
|-----|-------------------------|----------|
| 01  | ESP8266 NodeMCU         | 1        |
| 02  | IR Sensor Module        | 3        |
| 03  | LED Indicator           | 3        |
| 04  | Flame Sensor            | 1        |
| 05  | Water / Moisture Sensor | 1        |
| 06  | Breadboard / PCB        | 1        |
| 07  | 5V DC Power Supply      | 1        |

---

## Software Requirements

| Tool                     | Purpose                          |
|--------------------------|----------------------------------|
| Arduino IDE              | Firmware development environment |
| ESP8266 Board Package    | NodeMCU board support            |
| Blynk IoT Mobile App     | Remote monitoring and control    |
| Embedded C / C++         | Firmware programming language    |

---

## Pin Configuration

### IR Sensors (Input)

| Sensor      | GPIO Pin |
|-------------|----------|
| IR Sensor 1 | D5       |
| IR Sensor 2 | D6       |
| IR Sensor 3 | D7       |

### LED Indicators (Output)

| LED   | GPIO Pin |
|-------|----------|
| LED 1 | D1       |
| LED 2 | D2       |
| LED 3 | D4       |

### Safety Sensors

| Sensor        | GPIO Pin | Signal Type |
|---------------|----------|-------------|
| Flame Sensor  | D0       | Digital     |
| Water Sensor  | A0       | Analog      |

---

## Blynk Virtual Pin Mapping

| Virtual Pin | Function               | Type   |
|-------------|------------------------|--------|
| V1          | Room 1 Light Control   | Output |
| V2          | Room 2 Light Control   | Output |
| V3          | Room 3 Light Control   | Output |
| V4          | Flame Alert Indicator  | Alert  |
| V5          | Water Alert Indicator  | Alert  |

---

## Working Logic

| Trigger                   | Action                                              |
|---------------------------|-----------------------------------------------------|
| Motion detected (IR)      | Corresponding room LED switches ON automatically    |
| No occupancy detected     | LED extinguished automatically — energy conserved   |
| App command received      | Manual light toggle override via virtual pin        |
| Flame sensor triggered    | V4 updated — emergency push notification dispatched |
| Water threshold exceeded  | V5 updated — moisture alert pushed to mobile device |
| System polling interval   | 300 ms — all sensors read, all outputs refreshed    |

---

## Advantages

- **Enhanced Safety** — Continuous automated sensing eliminates reliance on periodic manual inspection.
- **Energy Efficiency** — Occupancy-based lighting reduces unnecessary power consumption.
- **Remote Supervision** — Full monitoring and control from any location via the Blynk app.
- **Scalable Architecture** — Easily extended to accommodate more rooms, sensors, or alert channels.
- **Cost-Effective** — Built on widely available, low-cost hardware with open-source software.
- **Instant Alerts** — Push notifications ensure safety events reach personnel within milliseconds.

---

## Applications

- Cotton storage godowns
- Textile warehouses
- Agricultural storage units
- Industrial warehouses
- Smart factory environments
- Cold storage and pharmaceutical stores

---

## Future Enhancements

| Phase   | Enhancement                                                                 |
|---------|-----------------------------------------------------------------------------|
| Phase 2 | Temperature and humidity monitoring using DHT22 sensor                      |
| Phase 2 | Automatic fire suppression via relay-controlled sprinkler system            |
| Phase 3 | GSM-based SMS alerts as a redundant notification pathway                    |
| Phase 3 | Cloud-based data analytics dashboard with trend visualization               |
| Phase 4 | AI-based fire prediction model trained on historical sensor patterns        |

---

## License

This project is open-source and intended for **educational and academic use**.

---

## Author

**IoT-Based Smart Cotton Warehouse Project**
Built with ESP8266 NodeMCU and Blynk IoT Platform
