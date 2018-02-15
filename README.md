# Smart-Parking-System
This project is to design a smart parking system which can automatically allocate a parking space for a car through internet.
This system can help a driver to reserve a parking space for his car which he can use for a specific amount of time.
This system can help avoid the congestion in traffic due to illegally parked vehicles.

For this system we have used an Arduino ESP8266 for the precossing of the data
We used Firebase as a server to store and relay the data to other platforms
The original model was made using IR sensors and Arduino.


Steps for Building the Arduino Model 

1. Use a Arduino ESP8266 module as the main controller here.
2. Connect 4 IR Arduino sensors to the digital read pins of the ESP module
3. Run a small program to test the IR sensors and their condition.


Steps for setting up the Firebase server 

1.If you haven't operated on Firebase before, use this link to learn how to set-up a firebase server.
  https://youtu.be/F6UWb9FNnj4
 
2. After setting up the firebase, create four dynamic variable in firebase which can be changed remotely by an app, website or the ESP module.

The Android app 
1. Ideally it can be created in android studio
2. You can also use the MIT app invertor 2 to design an alogrithm which it then automatically codes for you.
3. Refer this video for linking the app to the Firebase server
    https://youtu.be/YVu_xSzn2u0
  (Note: This is only for the android studio)

The website 
1. Use this video to host your html website on the Firebase server
    https://youtu.be/Gl-qlxfTJHE
(Note: You must install node js on your machine to host the website)
