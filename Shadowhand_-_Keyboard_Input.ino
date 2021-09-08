// Razma Mogharrab
// Project: Vader / Codename: Shadow Hand
// De Anza College / Winter Quarter / ENGR 10 - Edward Lam
// Date of completion of code - February 5, 2014

// Second iteration of code
// Version 2.0 implements use of keyboard to dictate finger bends

#include <Wire.h>
#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

// Straighten to base position
void straighten()
{
    myservo2.write(3550);
    delay(200);
    myservo3.write(3550);
    delay(200);
    myservo4.write(3550);
    delay(200);
    myservo1.write(3550);
    delay(200); 
}

void setup() 
{
// put your setup code here, to run once:

// Begin keyboard fetch
    Serial.begin(9600);

// Attach servos to respective pins on board
    myservo1.attach(9); // pinky
    myservo2.attach(3); // index
    myservo3.attach(5); // middle 
    myservo4.attach(6); // ring

// Write servos to gripped position
    myservo1.write(550);
    myservo2.write(550);
    myservo3.write(550);
    myservo4.write(550);
    straighten();
}

// Grip, delay, let go for each
void dance() 
{
    myservo2.write(550);
    delay(2000);
    myservo2.write(3550);
    delay(2000);
    myservo3.write(550);
    delay(2000);
    myservo3.write(3550);
    delay(2000);
    myservo4.write(550);
    delay(2000);
    myservo4.write(3550);
    delay(2000);
    myservo1.write(550);
    delay(2000);
    myservo1.write(3550);
    delay(2000);
}

// Flip the bird
void flipOff() 
{
    myservo2.write(550);
    delay(200);
    myservo4.write(550);
    delay(200);
    myservo1.write(550);
    delay(3000);
}

// Flash victory symbol
void victory() 
{
    myservo4.write(550);
    delay(200);
    myservo1.write(550);
    delay(3000);
}

// Juggle balls
void juggle()
{
    myservo2.write(550);
    delay(900);
    myservo3.write(550);
    myservo2.write(3550);
    delay(900);
    myservo4.write(550);
    myservo3.write(3550);
    delay(900);
    myservo1.write(550);
    myservo4.write(3550);
    delay(900);
    myservo1.write(3550);
}



void loop() 
{
// put your main code here, to run repeatedly: 

//dance();

    char HA; 
    if(Serial.available() > 0)
    {
        HA = Serial.read();
        Serial.println(HA);
    }
    switch (HA)
    {
        case 'q': myservo2.write(550);
        delay(2000);
        myservo2.write(3550);
        break;
        case 'w': myservo3.write(550);
        delay(2000);
        myservo3.write(3550);
        break;
        case 'e': myservo4.write(550);
        delay(2000);
        myservo4.write(3550);
        break;
        case 'r': myservo1.write(550);
        delay(2000);
        myservo1.write(3550);
        break;
        case 'd': dance();
        break;
        case 's': myservo1.write(550);
        myservo2.write(550);
        myservo3.write(550);
        myservo4.write(550);
        straighten();
        break;
        case 'f': flipOff();
        straighten();
        break;
        case 'v': victory();
        straighten();
        break;
        case 'j': juggle();
        juggle();
        juggle();
        straighten();
        break;
        //default: println("No, fudge you.");
    }
} 

