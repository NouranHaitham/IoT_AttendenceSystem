# IOT-Attendence-System-Project-2023

## Team members:

Menna Elbarbary

Nora ahmed salem

Fatma El zahraa Atef Mahmoud

Mohamed Mahmoud Abdeltwab Abdelkader Gad

Beshoy Akram Alfy shenouda

Nouran Haitham Othman

Karen Samuel gerges shenouda

Rosol Magdy Abdelhaleem


## Description:
  
The IoT Attendance System Project 2023 is designed to streamline the attendance process for the company Creative by using an RFID scanner with a Wi-Fi module to read RFID cards and upload data to a Google Sheet. The system includes features such as LED lights, a buzzer, and email notifications to alert for banned individuals, while the MIT application provides the manager with login access, real-time employee presence display, and a searchable history log.

## An outline of the project:


The employee will swip his ID card infront of the RFID sensor then the NodeMCU code will 

-->send the data saved within that ID to Google sheet (Link: https://docs.google.com/spreadsheets/d/1Of4h9LQfTOir4lgUNRSC3x5Ne8-ZmxXV87v4c2R3oTU/edit?usp=sharing)


-->send serial messages to arduino uno through UART communication to do certain commands depending on the person(employee,manager,or a banned person).



### There are two scenarios: 

1.For a Manager or an employee the green leds start lightning one by one until the lcd print the name of the person.


2.For a Banned person the red led turns (on and off),a buzzer activates to warn people of an intruder entering,the lcd prints "ALERT! intruder got in!" and emails are sent to all employees to notify them (email contains the ID of the banned person) using SMTP protocol.     



The MIT application reads the data from google sheet and dislpays it on the screen.  

### Main functionalities of MIT application: (link https://gallery.appinventor.mit.edu/?galleryid=1d3281aa-b03f-4b87-83bc-aff6551f3e31) 

  
-->The manager is the only one allowed to login.  // username: nora  password: 1234

-->The application will display the employees currently in the company (also says if an intruder is inside).  

-->The application will display the history log with the basic information of the employees (ID, Name, Age, date, time),also you can search for the history of a certain employee through search bar. 


#### Components used:

1.LCD I2C  
2.RFID sensor  
3.Leds  
4.Arduino UNO  
5.NodeMCU esp8266  
7.Buzzer  
6.Jumpers and Resistors  

  

