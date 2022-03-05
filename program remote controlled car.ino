/*
Code from SkyNow_ 2022
*/

#include <AFMotor.h>
#include <SoftwareSerial.h> 

SoftwareSerial bluetoothSerial(9, 10); // RX, TX

//Initialisation des moteur sur les pin.
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

char command;

void setup()
{
  bluetoothSerial.begin(9600);  //Etablie une ligne de communication avec le module BLE.
}

void loop() {
  if (bluetoothSerial.available() > 0)
  {
    command = bluetoothSerial.read();

    Stop(); //Initialisation du moteur a l'arret

    switch (command)
    {
      case '1':
        forward();
        break;
      case '3':
        back();
        break;
      case '4':
        left();
        break;
      case '2':
        right();
        break;
    }
  }
}


void Stop()
{
  motor1.setSpeed(0);  //Definit la puissance minimum
   motor1.run(RELEASE); //rotate the motor clockwise
     motor2.setSpeed(0);  //Definit la puissance minimum
       motor2.run(RELEASE); //rotate the motor clockwise
}

void forward()
{
  motor1.setSpeed(255); //Definit la puissance maximum
   motor1.run(FORWARD);  //rotate the motor clockwise
     motor2.setSpeed(255); //Definit la puissance maximum
       motor2.run(FORWARD);  //rotate the motor clockwise
}

void right()
{
   //FORWARD
     motor1.setSpeed(255); //Definit la puissance maximum
       motor1.run(FORWARD);  //rotate the motor clockwise
         motor2.setSpeed(255); //Definit la puissance maximum
           motor2.run(BACKWARD);  //rotate the motor clockwise
}

void left()
{
   //BACKWARD
     motor1.setSpeed(255); //Definit la puissance maximum
       motor1.run(BACKWARD); //rotate the motor anti-clockwise
         motor2.setSpeed(255); //Definit la puissance maximum
           motor2.run(FORWARD); //rotate the motor anti-clockwise
}

void back()
{
  motor1.setSpeed(255); //Definit la puissance maximum
   motor1.run(BACKWARD); //rotate the motor anti-clockwise
      motor2.setSpeed(255); //Definit la puissance maximum
         motor2.run(BACKWARD); //rotate the motor anti-clockwise
}
