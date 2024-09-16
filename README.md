# IoT Attendance System 🌐

## Description

The IoT Attendance System is here to make tracking attendance at Creative a breeze! 🚀 We’ve hooked up an RFID scanner with a Wi-Fi module to read ID cards and send the data straight to a [Google Sheet](https://docs.google.com/spreadsheets/d/1Of4h9LQfTOir4lgUNRSC3x5Ne8-ZmxXV87v4c2R3oTU/edit?usp=sharing). The system features LEDs, a buzzer for alerts, and email notifications for banned individuals. 📧 Plus, there’s an MIT app that lets managers log in, see who’s around in real time, and search through attendance history. 📱

## How It Works

1. **RFID Scanning**: Employees swipe their ID cards in front of the RFID sensor. 🆔
   - The NodeMCU uploads the card data to the Google Sheet. 📊
   - It also sends serial messages to the Arduino Uno to handle different scenarios (employee, manager, or banned). 🛠️

2. **LED and Buzzer Alerts**:
   - **Employees/Managers**: Green LEDs flash one by one until the LCD shows their name. 💚🔆
   - **Banned Individuals**: Red LED blinks, buzzer sounds, LCD displays "ALERT! Intruder detected!", and an email is sent to all employees with the banned person’s ID. 🚨🔴📧

3. **MIT App**:
   - Pulls data from the Google Sheet and displays it. 📈
   - **Login**: Only the manager can log in (Username: `nora`, Password: `1234`). 🔐
   - **Features**:
     - Shows who’s in the building and alerts if an intruder is detected. 🏢👀
     - Displays a history log with details (ID, Name, Age, Date, Time) and lets you search for specific employee records. 📜🔍

## Components Used

- LCD I2C 🖥️
- RFID Sensor 🏷️
- LEDs 💡
- Arduino Uno 🎛️
- NodeMCU ESP8266 🌐
- Buzzer 🔔
- Jumper Wires and Resistors 🔧

## Resources

- [MIT Application](https://gallery.appinventor.mit.edu/?galleryid=1d3281aa-b03f-4b87-83bc-aff6551f3e31) 📲
- **Arduino Code**: Check out the repo 📁
- **NodeMCU Code**: Check out the repo 📁
- **Photos and Video**: Also in the repo 📸🎥

## Installation and Setup

1. **Hardware Setup**: Connect everything according to the schematics. 🛠️
2. **Software Configuration**:
   - Upload the Arduino and NodeMCU code to your boards. 📤
   - Set up the Google Sheet and SMTP settings as needed. ⚙️
   - Install the MIT App and log in with the manager credentials. 📲🔑

Enjoy managing attendance with style! 🎉
