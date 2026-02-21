# IoT-Based-Intelligent-Godown-Automation-and-Safety-System
The Smart Godown for Cotton Storage using IoT is an intelligent warehouse monitoring and control system designed to improve safety, energy efficiency, and real-time supervision of cotton storage godowns.
# IoT-Enabled Intelligent Cotton Warehouse Monitoring and Control System

## Project Description
The IoT-Enabled Intelligent Cotton Warehouse Monitoring and Control System is a smart automation and safety solution designed for cotton storage godowns. Cotton is highly susceptible to fire hazards and moisture damage. This project uses Internet of Things (IoT) technology to provide real-time monitoring, automated control, and remote supervision of warehouse environments.

The system is built using an ESP8266 NodeMCU microcontroller and integrates multiple sensors to monitor room occupancy, fire presence, and water leakage. All monitoring and control operations are performed remotely using the Blynk IoT mobile application.

---

## Objectives
- Ensure fire safety in cotton storage godowns  
- Detect water leakage or moisture to prevent cotton damage  
- Implement smart and energy-efficient lighting control  
- Enable remote monitoring and control using IoT  
- Improve warehouse safety and operational efficiency  

---

## Key Features

### Smart Multi-Room Lighting Control
- IR sensors detect human presence in each room  
- Lights turn ON automatically when motion is detected  
- Manual ON/OFF control through mobile application  
- Combined sensor-based and app-based control logic  

### Flame Detection System
- Continuous monitoring using a flame sensor  
- Instant alert notification on fire detection  
- Enhances safety in flammable cotton storage areas  

### Water / Moisture Detection
- Water sensor monitors leakage or moisture  
- Alerts triggered when water exceeds a set threshold  
- Prevents damage to stored cotton  

### IoT-Based Remote Monitoring
- Real-time monitoring through mobile app  
- Remote light control  
- Instant alert notifications  

---

## System Architecture
1. ESP8266 connects to Wi-Fi and Blynk Cloud  
2. IR sensors monitor human movement  
3. LEDs operate automatically or manually  
4. Flame and water sensors ensure safety monitoring  
5. Alerts are sent instantly to the mobile device  

---

## Hardware Components
- ESP8266 NodeMCU  
- IR Sensors (3)  
- LEDs (3)  
- Flame Sensor  
- Water Sensor  
- Breadboard / PCB  
- 5V Power Supply  

---

## Software Requirements
- Arduino IDE  
- ESP8266 Board Package  
- Blynk IoT Mobile Application  
- Embedded C / C++  

---

## Pin Configuration

### IR Sensors
- IR Sensor 1 → D5  
- IR Sensor 2 → D6  
- IR Sensor 3 → D7  

### LEDs
- LED 1 → D1  
- LED 2 → D2  
- LED 3 → D4  

### Safety Sensors
- Flame Sensor → D0  
- Water Sensor → A0  

---

## Blynk Virtual Pin Mapping
- V1 – Room 1 Light Control  
- V2 – Room 2 Light Control  
- V3 – Room 3 Light Control  
- V4 – Flame Alert Indicator  
- V5 – Water Alert Indicator  

---

## Working Logic
- Motion detected → light turns ON automatically  
- App command can manually control lights  
- Flame detected → emergency alert sent  
- Water detected → moisture alert sent  
- Sensor update interval: 300 milliseconds  

---

## Advantages
- Improved fire and moisture safety  
- Energy-efficient lighting  
- Remote monitoring and control  
- Scalable for large warehouses  
- Cost-effective IoT solution  

---

## Applications
- Cotton storage godowns  
- Textile warehouses  
- Agricultural storage units  
- Industrial warehouses  
- Smart factory environments  

---

## Future Enhancements
- Temperature and humidity monitoring  
- Automatic fire suppression system  
- GSM-based SMS alerts  
- Cloud-based data analytics  
- AI-based fire prediction  

---

## License
This project is open-source and intended for educational and academic use.

---

## Author
IoT-Based Smart Cotton Warehouse Project
