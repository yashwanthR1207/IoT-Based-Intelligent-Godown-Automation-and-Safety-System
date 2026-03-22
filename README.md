<div align="center">

<img width="100%" src="https://capsule-render.vercel.app/api?type=waving&color=0:FF4500,30:FF8C00,60:FFA500,100:FF6347&height=220&section=header&text=IoT%20Intelligent%20Godown&fontSize=42&fontColor=ffffff&fontAlignY=33&desc=Automation%20%26%20Safety%20System%20%7C%20ESP8266%20%2B%20Blynk%20IoT&descAlignY=53&descColor=ffe0b2&animation=fadeIn" />

<br>

<img src="https://img.shields.io/badge/Platform-ESP8266-FF6F00?style=for-the-badge&logo=arduino&logoColor=white" />
<img src="https://img.shields.io/badge/Language-C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white" />
<img src="https://img.shields.io/badge/IDE-Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white" />
<img src="https://img.shields.io/badge/App-Blynk%20IoT-00E5FF?style=for-the-badge&logoColor=white" />
<img src="https://img.shields.io/badge/Sensors-IR%20%7C%20Flame%20%7C%20Water-EF5350?style=for-the-badge" />
<img src="https://img.shields.io/badge/Status-Active-00E676?style=for-the-badge" />
<img src="https://img.shields.io/badge/Use-Academic%20%7C%20Open%20Source-AB47BC?style=for-the-badge" />
<img src="https://img.shields.io/badge/Network-Wi--Fi%20%7C%20TCP-1565C0?style=for-the-badge&logo=wifi&logoColor=white" />

<br><br>

<img src="https://readme-typing-svg.demolab.com?font=Fira+Code&size=22&duration=3000&pause=1000&color=FF8C00&center=true&vCenter=true&width=700&lines=Smart+Cotton+Warehouse+Monitoring+System;Real-Time+Fire+%26+Moisture+Detection;Automated+Lighting+%7C+Remote+Control;Powered+by+ESP8266+%2B+Blynk+IoT" alt="Typing SVG" />

<br><br>

> ### An IoT-enabled intelligent warehouse monitoring and control system for cotton storage godowns — integrating real-time environmental sensing, automated lighting, fire detection, and moisture monitoring via the Blynk mobile application.

<br>

![GitHub repo size](https://img.shields.io/github/repo-size/YourUsername/YourRepoName?style=flat-square&color=FF8C00)
![GitHub last commit](https://img.shields.io/github/last-commit/YourUsername/YourRepoName?style=flat-square&color=FF6F00)
![GitHub stars](https://img.shields.io/github/stars/YourUsername/YourRepoName?style=flat-square&color=FFD600)
![GitHub forks](https://img.shields.io/github/forks/YourUsername/YourRepoName?style=flat-square&color=00E676)

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

This project leverages **Internet of Things** technology to provide real-time monitoring, automated control, and remote supervision of warehouse environments. Built around the **ESP8266 NodeMCU** microcontroller, the system integrates multiple sensors to monitor room occupancy, fire presence, and water leakage — with all operations accessible through the **Blynk IoT mobile application**.
```
Total Rooms Monitored  : 3
Sensor Polling Rate    : 300 ms
Alert Delivery         : Instant Push Notification
Control Interface      : Blynk Mobile App (Android / iOS)
Network Protocol       : Wi-Fi / TCP
```

---

## Objectives

<div align="center">

| No. | Objective |
|:---:|:---|
| 01 | Ensure fire safety in cotton storage godowns through continuous automated monitoring and instant alert generation |
| 02 | Detect water leakage or elevated moisture levels in real-time to prevent damage to stored cotton bales |
| 03 | Implement smart sensor-driven lighting control for improved energy efficiency across all warehouse rooms |
| 04 | Enable complete remote monitoring and manual override control through an IoT-connected mobile application |
| 05 | Improve overall warehouse safety posture and operational efficiency through centralized automated supervision |

</div>

---

## Key Features

<div align="center">

| Feature | Description | Status |
|:---|:---|:---:|
| Smart Multi-Room Lighting | IR sensors detect occupancy and auto-control LEDs per room | ![Active](https://img.shields.io/badge/-Active-00E676?style=flat-square) |
| Manual App Override | Control each room light remotely via Blynk virtual pins | ![Active](https://img.shields.io/badge/-Active-00E676?style=flat-square) |
| Flame Detection | Continuous flame sensor monitoring with instant push alert | ![Active](https://img.shields.io/badge/-Active-00E676?style=flat-square) |
| Water and Moisture Detection | Analog threshold-based water sensor with alert dispatch | ![Active](https://img.shields.io/badge/-Active-00E676?style=flat-square) |
| IoT Remote Dashboard | Real-time Blynk app dashboard for all sensor states | ![Active](https://img.shields.io/badge/-Active-00E676?style=flat-square) |
| Instant Push Notifications | Critical safety alerts delivered to mobile within milliseconds | ![Active](https://img.shields.io/badge/-Active-00E676?style=flat-square) |

</div>

---

## System Architecture
```
╔══════════════════════════════════════════════════════════════════════╗
║                         SENSOR LAYER                                ║
╠══════════════╦═══════════════════════╦═══════════════════════════════╣
║  IR Sensor 1 ║     Flame Sensor      ║       Water Sensor            ║
║  IR Sensor 2 ║     (Digital  D0)     ║       (Analog   A0)           ║
║  IR Sensor 3 ║                       ║                               ║
║ D5 / D6 / D7 ║                       ║                               ║
╚══════╤═══════╩═══════════╤═══════════╩═══════════════╤═══════════════╝
       │                   │                           │
       └───────────────────┴───────────────────────────┘
                                   │
                    ╔══════════════╩══════════════╗
                    ║       ESP8266 NodeMCU        ║
                    ║                              ║
                    ║   Read Sensors  |  Wi-Fi     ║
                    ║   Drive LEDs   |  Blynk API  ║
                    ║   Safety Logic |  Alerts     ║
                    ╚══════════════╦══════════════╝
                                   │
                              Wi-Fi / TCP
                                   │
                    ╔══════════════╩══════════════╗
                    ║         Blynk Cloud          ║
                    ╚══════════════╦══════════════╝
                                   │
                    ╔══════════════╩══════════════╗
                    ║      Mobile Application      ║
                    ║   Monitor  |  Control        ║
                    ║   Alerts   |  Dashboard      ║
                    ╚══════════════════════════════╝
```

**Flow Summary:**

1. ESP8266 connects to Wi-Fi and establishes a live session with the Blynk Cloud server
2. IR sensors monitor human movement across three individual rooms at 300 ms intervals
3. LEDs actuate automatically based on occupancy or manually via the Blynk mobile app
4. Flame and water sensors provide continuous background safety monitoring
5. Any threshold event triggers an instant push alert notification to the mobile device

---

## Hardware Components

<div align="center">

| No. | Component | Description | Qty |
|:---:|:---|:---|:---:|
| 01 | **ESP8266 NodeMCU** | Main microcontroller with built-in Wi-Fi | 1 |
| 02 | **IR Sensor Module** | Room occupancy and motion detection | 3 |
| 03 | **LED Indicator** | Room lighting output actuator | 3 |
| 04 | **Flame Sensor** | Fire and open flame detection | 1 |
| 05 | **Water / Moisture Sensor** | Leakage and moisture level detection | 1 |
| 06 | **Breadboard / PCB** | Circuit assembly and prototyping base | 1 |
| 07 | **5V DC Power Supply** | System power input | 1 |

</div>

---

## Software Requirements

<div align="center">

| Tool | Purpose |
|:---|:---|
| **Arduino IDE** | Firmware development and code upload environment |
| **ESP8266 Board Package** | NodeMCU hardware board support for Arduino IDE |
| **Blynk IoT Mobile App** | Remote monitoring, manual control, and alert reception |
| **Embedded C / C++** | Primary firmware programming language |

</div>

---

## Pin Configuration

<div align="center">

### IR Sensors — Input

| Sensor | NodeMCU Pin | GPIO | Signal Type |
|:---|:---:|:---:|:---:|
| IR Sensor 1 | D5 | GPIO14 | Digital |
| IR Sensor 2 | D6 | GPIO12 | Digital |
| IR Sensor 3 | D7 | GPIO13 | Digital |

### LED Indicators — Output

| LED | NodeMCU Pin | GPIO | Signal Type |
|:---|:---:|:---:|:---:|
| LED 1 — Room 1 | D1 | GPIO5 | Digital |
| LED 2 — Room 2 | D2 | GPIO4 | Digital |
| LED 3 — Room 3 | D4 | GPIO2 | Digital |

### Safety Sensors

| Sensor | NodeMCU Pin | GPIO | Signal Type |
|:---|:---:|:---:|:---:|
| Flame Sensor | D0 | GPIO16 | Digital |
| Water / Moisture Sensor | A0 | ADC0 | Analog |

</div>

---

## Blynk Virtual Pin Mapping

<div align="center">

| Virtual Pin | Function | Direction | Type |
|:---:|:---|:---:|:---:|
| ![V1](https://img.shields.io/badge/V1-Room%201%20Light-FF6F00?style=flat-square) | Room 1 Light Control | App to Device | Output |
| ![V2](https://img.shields.io/badge/V2-Room%202%20Light-FF8C00?style=flat-square) | Room 2 Light Control | App to Device | Output |
| ![V3](https://img.shields.io/badge/V3-Room%203%20Light-FFA500?style=flat-square) | Room 3 Light Control | App to Device | Output |
| ![V4](https://img.shields.io/badge/V4-Flame%20Alert-EF5350?style=flat-square) | Flame Alert Indicator | Device to App | Alert |
| ![V5](https://img.shields.io/badge/V5-Water%20Alert-1565C0?style=flat-square) | Water Alert Indicator | Device to App | Alert |

</div>

---

## Working Logic

<div align="center">

| Trigger | Action | Result |
|:---|:---|:---:|
| Motion detected by IR sensor | Corresponding room LED switches ON | ![Auto](https://img.shields.io/badge/-Automated-FF8C00?style=flat-square) |
| No occupancy detected | LED extinguished — energy conserved | ![Auto](https://img.shields.io/badge/-Automated-FF8C00?style=flat-square) |
| App command received via Blynk | Manual light toggle via virtual pin | ![Manual](https://img.shields.io/badge/-Manual-1565C0?style=flat-square) |
| Flame sensor threshold crossed | V4 updated — emergency push notification dispatched | ![Alert](https://img.shields.io/badge/-Alert-EF5350?style=flat-square) |
| Water sensor threshold exceeded | V5 updated — moisture alert pushed to mobile | ![Alert](https://img.shields.io/badge/-Alert-EF5350?style=flat-square) |
| System polling cycle | 300 ms — all sensors read, all outputs refreshed | ![System](https://img.shields.io/badge/-System-00E676?style=flat-square) |

</div>

---

## Advantages

<div align="center">

| Advantage | Description |
|:---|:---|
| **Enhanced Safety** | Continuous automated sensing eliminates reliance on periodic manual inspection |
| **Energy Efficiency** | Occupancy-based lighting reduces unnecessary power consumption across all rooms |
| **Remote Supervision** | Full monitoring and control from any location via the Blynk mobile application |
| **Scalable Architecture** | Easily extended to accommodate more rooms, sensors, or notification channels |
| **Cost-Effective** | Built on widely available, low-cost hardware with open-source software stack |
| **Instant Alerts** | Push notifications ensure safety events reach responsible personnel within milliseconds |

</div>

---

## Applications

<div align="center">

| Domain | Use Case |
|:---|:---|
| **Cotton Industry** | Cotton storage godowns and bale warehouses |
| **Textile Sector** | Textile raw material and finished goods warehouses |
| **Agriculture** | Grain, seed, and produce storage facilities |
| **Industrial** | General-purpose industrial warehouse monitoring |
| **Manufacturing** | Smart factory floor and production area monitoring |
| **Pharma and Cold Chain** | Temperature and moisture sensitive storage environments |

</div>

---

## Future Enhancements

<div align="center">

| Phase | Enhancement | Priority |
|:---:|:---|:---:|
| Phase 2 | Temperature and humidity monitoring using DHT22 sensor | ![High](https://img.shields.io/badge/-High-EF5350?style=flat-square) |
| Phase 2 | Automatic fire suppression via relay-controlled sprinkler system | ![High](https://img.shields.io/badge/-High-EF5350?style=flat-square) |
| Phase 3 | GSM-based SMS alerts as a redundant notification pathway | ![Medium](https://img.shields.io/badge/-Medium-FF8C00?style=flat-square) |
| Phase 3 | Cloud-based data analytics dashboard with trend visualization | ![Medium](https://img.shields.io/badge/-Medium-FF8C00?style=flat-square) |
| Phase 4 | AI-based fire prediction model trained on historical sensor patterns | ![Low](https://img.shields.io/badge/-Low-00E676?style=flat-square) |

</div>

---

<div align="center">

<br>

**Built with ESP8266 NodeMCU and Blynk IoT Platform**

*IoT-Based Intelligent Godown Automation and Safety System*

<br>

<img width="100%" src="https://capsule-render.vercel.app/api?type=waving&color=0:FF4500,30:FF8C00,60:FFA500,100:FF6347&height=130&section=footer&animation=fadeIn" />

</div>
