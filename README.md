# ArrosageAutomatiqueArduino

Ceci est un projet scolaire d'arrosage automatique faite avec un ardu ino Uno.
Le projet a été créer entre 2019 et 2020 et comprend une connexion bluetooth pour le contrôle manuel, un capteur d'humidité, une pompe à eau, des relais (deux dans cette démonstration et un seul dans le schéma Fritzing) et un ardu ino Uno.

Des photos et vidéos du projet réalisé sont également incluses dans ce GitHub afin de faire une démonstration du système et de voir ce que donne le prototype physique.

Remarque: le schéma fourni avec le projet ne comprend qu'un seul relais et n'a pas de module bluetooth car ils ont été rajoutés après la finalisation du schéma et de la première montagne.

# Automatic Irrigation System with Arduino

## Overview
The **Automatic Irrigation System with Arduino** is a smart irrigation solution designed to optimize plant watering by monitoring soil moisture levels and activating water pumps automatically. This project minimizes manual intervention and ensures optimal plant care using an Arduino-based setup.

## Features
- **Soil Moisture Monitoring** – Uses sensors to detect soil humidity levels in real time.
- **Automated Watering** – Activates a water pump or solenoid valve when moisture levels drop below a predefined threshold.
- **Customizable Thresholds** – Allows users to set specific moisture levels for different plants.
- **Energy Efficient** – Ensures water is used only when necessary, reducing waste.

## Requirements
### Hardware:
- **Arduino Board** (e.g., Arduino Uno)
- **Soil Moisture Sensor**
- **Relay Module**
- **Water Pump or Solenoid Valve**
- **Power Supply**

### Software:
- **Arduino IDE**
- **Required Libraries** (if applicable, e.g., `LiquidCrystal.h` for LCD integration)

## Installation & Setup
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/0Blanck0/ArrosageAutomatiqueArduino.git
   ```
   
2. **Connect the Components**:
   - Attach the soil moisture sensor to the Arduino.
   - Connect the relay module to control the water pump.
   - Power the system appropriately.
     
3. **Upload the Code**:
   - Open the Arduino IDE.
   - Load the provided `.ino` file.
   - Compile and upload it to the Arduino board.

## Usage
Once the system is set up:
- The sensor continuously monitors soil moisture.
- If the moisture level falls below the set threshold, the Arduino triggers the relay to activate the water pump.
- Once optimal moisture is reached, the pump is turned off.

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

## Acknowledgments
This project was developed as part of an initiative to automate irrigation systems using affordable and open-source technologies.   
This projet was created in an educational plan of learning the arduino.
