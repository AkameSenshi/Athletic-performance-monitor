# Athletic Performance Monitor
## Overview
The ***Athletic Performance Monitor*** is a wearable device designed for athletes to track and analyze their performance during training or games. Mounted on a body harness, this device collects data in real-time using various sensors and transmits it to a PC application over WiFi. After a session, the PC application provides detailed analytics, enabling coaches and players to evaluate performance metrics effectively.

## Features
- Compact and Wearable Design:
  - Lightweight device mounted on a body harness for ease of use.
- Sensor Integration:
  - NEO-8N GPS: Tracks position and speed.
  - Accelerometer and Gyroscope: Measures movement, orientation, and acceleration.
  - Barometer: Provides altitude and environmental pressure readings.
- Real-Time Data Transmission:
  - Connects to a PC via WiFi to log sensor data continuously.
- Detachable Batteries:
  - Rechargeable batteries ensure ease of use and quick replacement during intense training sessions.
- OLED Display:
  - Displays key metrics or system status during operation.
- Data Analytics:
  - Post-session analytics provided by the PC application, including movement patterns, performance statistics, and GPS-based heatmaps.
## System Architecture
### Device Components
1. Raspberry Pi Zero 2:
- Core processing unit running data acquisition and transmission logic.
2. Custom PCB:
- Integrates all sensors, battery management, and charging circuits.
3. Sensors:
- GPS: NEO-8N GPS module for location and speed tracking.
- IMU: Accelerometer and gyroscope for motion sensing.
- Barometer: Tracks altitude and environmental pressure.
4. Battery Management:
- Rechargeable batteries with detachable design for convenience.
- Built-in charging circuit on the custom PCB.
5. OLED Display:
- Displays metrics such as battery status, GPS signal strength, or session duration.
### PC Application
- Data Logging:
  - Continuously logs data from the device via WiFi.
- Analytics:
  - Processes sensor data to generate performance insights, such as:
    - Distance covered.
    - Average speed.
    - Acceleration and deceleration patterns.
    - Altitude changes.
- Displays session summary with charts, heatmaps, and key statistics.
## Setup Instructions
### Hardware Setup
1. Mount the device securely onto the body harness.
2. Ensure the rechargeable battery is properly attached and charged.
3. Power on the device:
  - The OLED screen will display initial status (e.g., "Connecting to WiFi...").
4. Verify that the device is connected to the PC application via WiFi.
### PC Application Setup
1. Install the application on your PC (see Installation below).
2. Configure the WiFi credentials in the application to connect with the device.
3. Start the application to begin logging sensor data.
## Installation
### Device
1. Clone the repository onto the Raspberry Pi Zero 2:
```bash
git clone https://github.com/your-repo/athletic-performance-monitor.git
cd athletic-performance-monitor
```
2. Install dependencies:
```bash
sudo apt-get install python3 python3-pip
pip3 install -r requirements.txt
```
3. Run the application:
```bash
python3 main.py
```
### PC Application
1. Download the PC application from Release Page.
2. Follow the installation instructions for your OS.
3. Launch the application and connect it to the device via WiFi.
## Usage
1. Start the device and ensure it connects to the PC application.
2. Begin a training or game session.
3. During the session:
- The device collects and transmits data to the PC application.
- The OLED display shows basic metrics and status.
4. End the session:
- Stop data logging on the PC application.
- View and analyze session data using the analytics dashboard.
## Technical Specifications
- Processor: Raspberry Pi Zero 2
- Sensors:
  - NEO-8N GPS
  - Accelerometer and Gyroscope
  - Barometer
- Display: OLED Screen (128x64 resolution)
- Connectivity: WiFi (2.4 GHz)
- Battery:
  - Rechargeable Li-ion batteries with detachable design.
  - Built-in charging circuit.
## Project Goals
- Provide real-time performance tracking for athletes.
- Deliver actionable insights through analytics after each session.
- Ensure ease of use with a compact and detachable design.
## Future Enhancements
- Add Bluetooth support for broader connectivity options.
- Include real-time analytics visualization on the OLED screen.
- Develop a mobile application for on-the-go performance tracking.
## Contributing
We welcome contributions to enhance the project! Please follow these steps:

- Fork the repository.
- Create a new branch for your feature or bugfix.
- Submit a pull request with a detailed explanation of your changes.
## License
This project is licensed under nothing , he he.

## Contact
For any questions or support, please reach out to me.


