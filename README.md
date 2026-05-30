# ESP32 WiFi Robotic Hand Controller

A web-based robotic hand control system built using ESP32 and servo motors.

The ESP32 hosts a local web server that provides a browser-based control panel with sliders. Users can connect to the ESP32 through WiFi and remotely control the wrist, thumb, index finger, and remaining fingers of a robotic hand in real-time.

---

# Features

## Wireless Control

* WiFi-enabled control system
* No mobile application required
* Works directly from a browser

## Real-Time Servo Control

Control the following joints:

* Wrist Rotation
* Thumb Movement
* Index Finger Movement
* Finger Group Movement

## Web Dashboard

* Responsive UI
* Slider-based control
* Instant updates
* Simple user interface

## ESP32 Embedded Web Server

* Self-hosted control page
* HTTP-based communication
* No external cloud dependency

---

# Hardware Requirements

| Component                        | Quantity    |
| -------------------------------- | ----------- |
| ESP32 Development Board          | 1           |
| Servo Motors (SG90/MG90S/MG996R) | 4           |
| External 5V Power Supply         | 1           |
| Jumper Wires                     | As Required |
| Robotic Hand Mechanism           | 1           |

---

# Pin Configuration

| Servo         | ESP32 GPIO |
| ------------- | ---------- |
| Wrist Servo   | GPIO19     |
| Thumb Servo   | GPIO18     |
| Index Servo   | GPIO26     |
| Fingers Servo | GPIO27     |

---

# WiFi Configuration

Update the following credentials:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_PASSWORD";
```

---

# Working Principle

1. ESP32 connects to WiFi.
2. ESP32 starts an HTTP web server.
3. User accesses ESP32 IP address through browser.
4. Control interface loads automatically.
5. Slider movements generate HTTP requests.
6. ESP32 receives commands.
7. Corresponding servo motor rotates.
8. Robotic hand moves in real-time.

---

# System Architecture

User Browser
↓
WiFi Network
↓
ESP32 Web Server
↓
Servo Control Logic
↓
Robotic Hand

---

# Web Interface

The dashboard contains:

### Wrist Controller

Controls wrist rotation.

### Thumb Controller

Controls thumb movement.

### Index Controller

Controls index finger movement.

### Fingers Controller

Controls remaining finger movement.

Each slider sends commands instantly to ESP32 using JavaScript Fetch API.

---

# API Endpoints

## Home Page

GET /

Loads the control dashboard.

---

## Servo Control

GET /set?servo=name&angle=value

Example:

/set?servo=wrist&angle=90

---

# Supported Servos

* SG90
* MG90S
* MG995
* MG996R
* DS3218
* Other PWM-based servos

---

# Circuit Connections

ESP32 GPIO19 → Wrist Servo Signal

ESP32 GPIO18 → Thumb Servo Signal

ESP32 GPIO26 → Index Servo Signal

ESP32 GPIO27 → Fingers Servo Signal

ESP32 GND → Servo GND

External 5V → Servo VCC

Important:
Use an external 5V supply for servos.
Do NOT power multiple servos directly from ESP32.

---

# Installation

## Install Required Libraries

Arduino IDE → Library Manager

Install:

* ESP32Servo

---

## Upload Code

1. Select ESP32 board.
2. Connect ESP32.
3. Upload firmware.

---

## Access Dashboard

Open Serial Monitor.

Example Output:

Connected to WiFi
192.168.1.100

Open:

http://192.168.1.100

in any browser.

---

# Applications

* Robotic Hand Control
* Prosthetic Hand Research
* Gesture Replication
* Educational Robotics
* Industrial Automation
* Human-Machine Interface
* Remote Robotics

---

# Future Improvements

* Mobile Application
* Voice Control
* Gesture Recognition
* Bluetooth Control
* AI-Based Motion Control
* MQTT Integration
* Cloud Dashboard
* Camera-Based Tracking

---

# Project Highlights

✔ ESP32 Web Server

✔ Wireless Robotics

✔ Real-Time Control

✔ Embedded Systems

✔ IoT Enabled

✔ Human Machine Interface

✔ Multi-Servo Control

---
##circuit connection
<img width="1536" height="1024" alt="image" src="https://github.com/user-attachments/assets/d5e7908a-1c3c-4d3b-83d8-e9b6cd94c098" />

---
# Author

Hariharan Balakrishnan

B.E Electronics and Communication Engineering

Embedded Systems | Robotics | IoT | ESP32 | Zephyr RTOS
