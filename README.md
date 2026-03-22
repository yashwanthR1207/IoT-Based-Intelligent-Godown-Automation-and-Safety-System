<div align="center">

<img width="100%" src="https://capsule-render.vercel.app/api?type=waving&color=0:ff6600,50:ffaa00,100:ff6600&height=200&section=header&text=IoT%20Intelligent%20Godown&fontSize=38&fontColor=ffffff&fontAlignY=35&desc=Automation%20%26%20Safety%20System%20%7C%20ESP8266%20%2B%20Blynk%20IoT&descAlignY=55&descColor=ffffff" />

<br>

<img src="https://img.shields.io/badge/Platform-ESP8266-FF6F00?style=for-the-badge&logo=arduino&logoColor=white" />
<img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" />
<img src="https://img.shields.io/badge/IDE-Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white" />
<img src="https://img.shields.io/badge/App-Blynk%20IoT-00E5FF?style=for-the-badge&logo=blynk&logoColor=white" />
<img src="https://img.shields.io/badge/Sensors-IR%20%7C%20Flame%20%7C%20Water-EF5350?style=for-the-badge" />
<img src="https://img.shields.io/badge/Status-Active-00E676?style=for-the-badge" />
<img src="https://img.shields.io/badge/Use-Academic%20%7C%20Open%20Source-AB47BC?style=for-the-badge" />

<br><br>

> ### An IoT-enabled intelligent warehouse monitoring and control system for cotton storage godowns — integrating real-time environmental sensing, automated lighting, fire detection, and moisture monitoring via the Blynk mobile application.

<br>

</div>

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

---

## Project Description

The **IoT-Enabled Intelligent Cotton Warehouse Monitoring and Control System** is a smart automation and safety solution designed specifically for cotton storage godowns. Cotton is highly susceptible to fire hazards and moisture damage, necessitating continuous and reliable environmental supervision.

This project leverages Internet of Things technology to provide real-time monitoring, automated control, and remote supervision of warehouse environments. Built around the **ESP8266 NodeMCU** microcontroller, the system integrates multiple sensors to monitor room occupancy, fire presence, and water leakage — with all operations accessible through the **Blynk IoT mobile application**.

---

## Objectives

| No. | Objective |
|:---:|:---|
| 01 | Ensure fire safety in cotton storage godowns through continuous automated monitoring and instant alert generation |
| 02 | Detect water leakage or elevated moisture levels in real-time to prevent damage to stored cotton bales |
| 03 | Implement smart, sensor-driven lighting control for improved energy efficiency across all warehouse rooms |
| 04 | Enable complete remote monitoring and manual override control through an IoT-connected mobile application |
| 05 | Improve overall warehouse safety posture and operational efficiency through centralized automated supervision |

---

## Key Features

<div align="center">

| Feature | Description | Status |
|:---|:---|:---:|
| Smart Multi-Room Lighting | IR sensors detect occupancy and auto-control LEDs per room | Active |
| Manual App Override | Control each room light remotely via Blynk virtual pins | Active |
| Flame Detection | Continuous flame sensor monitoring with instant push alert | Active |
| Water and Moisture Detection | Analog threshold-based water sensor with alert dispatch | Active |
| IoT Remote Dashboard | Real-time Blynk app dashboard for all sensor states | Active |
| Instant Push Notifications | Critical safety alerts delivered to mobile within milliseconds | Active |

</div>

---

## System Architecture
```
+------------------+     +------------------+     +------------------+
|   IR Sensor 1    |     |   Flame Sensor   |     |   Water Sensor   |
|   IR Sensor 2    |     |   (Digital D0)   |     |   (Analog  A0)   |
|   IR Sensor 3    |     +--------+---------+     +--------+---------+
|  (D5 / D6 / D7)  |              |                        |
+--------+---------+              |                        |
         |                        |                        |
         +------------------------+------------------------+
                                  |
                       +----------+----------+
                       |   ESP8266 NodeMCU   |
                       |                     |
                       |  - Read all sensors |
                       |  - Control LEDs     |
                       |  - Connect Wi-Fi    |
                       |  - Push to Cloud    |
                       +----------+----------+
                                  |
                             (Wi-Fi / TCP)
                                  |
                       +----------+----------+
                       |     Blynk Cloud     |
                       +----------+----------+
                                  |
                       +----------+----------+
                       |   Mobile Application|
                       |  Monitor / Control  |
                       |  Alerts / Dashboard |
                       +---------------------+
```

**Flow Summary:**

1. ESP8266 connects to Wi-Fi and establishes a session with the Blynk Cloud server
2. IR sensors monitor human movement across three individual rooms at 300 ms intervals
3. LEDs are actuated automatically based on occupancy or manually via the Blynk app
4. Flame and water sensors provide continuous safety monitoring
5. Threshold events trigger instant push alert notifications to the mobile device

---

## Hardware Components

<div align="center">

| No. | Component | Description | Quantity |
|:---:|:---|:---|:---:|
| 01 | ESP8266 NodeMCU | Main microcontroller with built-in Wi-Fi | 1 |
| 02 | IR Sensor Module | Room occupancy and motion detection | 3 |
| 03 | LED Indicator | Room lighting output | 3 |
| 04 | Flame Sensor | Fire and open flame detection | 1 |
| 05 | Water / Moisture Sensor | Leakage and moisture level detection | 1 |
| 06 | Breadboard / PCB | Circuit assembly and prototyping | 1 |
| 07 | 5V DC Power Supply | System power input | 1 |

</div>

---

## Software Requirements

<div align="center">

| Tool | Purpose |
|:---|:---|
| Arduino IDE | Firmware development and upload environment |
| ESP8266 Board Package | NodeMCU hardware board support |
| Blynk IoT Mobile App | Remote monitoring, control, and alert reception |
| Embedded C / C++ | Firmware programming language |

</div>

---

## Pin Configuration

<div align="center">

### IR Sensors — Input

| Sensor | NodeMCU Pin | Signal Type |
|:---|:---:|:---:|
| IR Sensor 1 | D5 | Digital |
| IR Sensor 2 | D6 | Digital |
| IR Sensor 3 | D7 | Digital |

### LED Indicators — Output

| LED | NodeMCU Pin | Signal Type |
|:---|:---:|:---:|
| LED 1 — Room 1 | D1 | Digital |
| LED 2 — Room 2 | D2 | Digital |
| LED 3 — Room 3 | D4 | Digital |

### Safety Sensors

| Sensor | NodeMCU Pin | Signal Type |
|:---|:---:|:---:|
| Flame Sensor | D0 | Digital |
| Water / Moisture Sensor | A0 | Analog |

</div>

---

## Blynk Virtual Pin Mapping

<div align="center">

| Virtual Pin | Function | Type |
|:---:|:---|:---:|
| V1 | Room 1 Light Control | Output |
| V2 | Room 2 Light Control | Output |
| V3 | Room 3 Light Control | Output |
| V4 | Flame Alert Indicator | Alert |
| V5 | Water Alert Indicator | Alert |

</div>

---

## Working Logic

<div align="center">

| Trigger | Action |
|:---|:---|
| Motion detected by IR sensor | Corresponding room LED switches ON automatically |
| No occupancy detected | LED extinguished automatically — energy conserved |
| App command received via Blynk | Manual light toggle override via virtual pin |
| Flame sensor threshold crossed | V4 updated — emergency push notification dispatched |
| Water sensor threshold exceeded | V5 updated — moisture alert pushed to mobile device |
| System polling cycle | 300 ms — all sensors read, all outputs refreshed |

</div>

---

## Advantages

<div align="center">

| Advantage | Description |
|:---|:---|
| Enhanced Safety | Continuous automated sensing eliminates reliance on periodic manual inspection |
| Energy Efficiency | Occupancy-based lighting reduces unnecessary power consumption |
| Remote Supervision | Full monitoring and control from any location via the Blynk app |
| Scalable Architecture | Easily extended to accommodate more rooms, sensors, or alert channels |
| Cost-Effective | Built on widely available, low-cost hardware with open-source software |
| Instant Alerts | Push notifications ensure safety events reach personnel within milliseconds |

</div>

---

## Applications

<div align="center">

| Domain | Use Case |
|:---|:---|
| Cotton Industry | Cotton storage godowns and bale warehouses |
| Textile Sector | Textile raw material and finished goods warehouses |
| Agriculture | Grain, seed, and produce storage facilities |
| Industrial | General-purpose industrial warehouses |
| Manufacturing | Smart factory floor monitoring |
| Pharma and Cold Chain | Temperature and moisture sensitive storage environments |

</div>

---

## Future Enhancements

<div align="center">

| Phase | Enhancement | Priority |
|:---:|:---|:---:|
| Phase 2 | Temperature and humidity monitoring using DHT22 sensor | High |
| Phase 2 | Automatic fire suppression via relay-controlled sprinkler system | High |
| Phase 3 | GSM-based SMS alerts as a redundant notification pathway | Medium |
| Phase 3 | Cloud-based data analytics dashboard with trend visualization | Medium |
| Phase 4 | AI-based fire prediction model trained on historical sensor patterns | Low |

</div>

---

<div align="center">

<img width="100%" src="https://capsule-render.vercel.app/api?type=waving&color=0:ff6600,50:ffaa00,100:ff6600&height=120&section=footer" />

**IoT-Based Intelligent Godown Automation and Safety System**

*Built with ESP8266 NodeMCU and Blynk IoT Platform*

</div>
