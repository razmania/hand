// Razma Mogharrab
// Project Vader / Codename: Shadowhand
// Summer 2015
// Date of completion of code: August 4, 2015

#include <Wire.h>
#include <Servo.h>
#include <IRremote.h>

// Controller IR codes:
// SINGLES:
// Up: 2519209162
// Down: 1502638218
// Left: 2999730842
// Right: 2953994586
// A: 2368359343
// B: 472047109
// Start: 2534555274
// Select: 2054033594
// COMBOS:
// Up + A: 120554099
// Up + B: 2519209161
// Down + A: 3398950451
// Down + B: 1502638217
// Left + A: 601075779
// Left + B: 2999730841
// Right + A: 2366630827
// Right + B: 2953994585

Servo myservo1; // Pinky
Servo myservo2; // Index
Servo myservo3; // Middle
Servo myservo4; // Ring

int IRpin = 11;
IRrecv irrecv(IRpin);
decode_results results;

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

void setup() {
  // put your setup code here, to run once:
  // Begin keyboard fetch
  Serial.begin(9600);
  
  // Start the receiver
  irrecv.enableIRIn();
  
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

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) 
    {
      delay(29); // Need more
      //delay(50); // Nvm 29 was fine.. Not the problem
      irrecv.resume();   // Receive the next value
    }
    switch(results.value)
    {
      case 2519209162: // Up
      myservo2.write(550); // Grip
      delay(2000); // Pause
      myservo2.write(3550); // Extend
      //Serial.println("Up"); // Test.. I mean good enough lol
      results.value = 0;
      break;
    
      case 1502638218: // Down
      myservo3.write(550); // Grip
      delay(2000); // Pause
      myservo3.write(3550); // Extend
      results.value = 0;
      break;
    
      case 2999730842: // Left
      myservo4.write(550); // Grip
      delay(2000); // Pause
      myservo4.write(3550); // Extend
      results.value = 0;
      break;
  
      case 2953994586: // Right
      myservo1.write(550); // Grip
      delay(2000); // Pause
      myservo1.write(3550); // Extend
      results.value = 0;
      break;
  
      case 2368359343: // A
      dance(); // Dance
      results.value = 0;
      break;
  
      case 472047109: // B
      myservo1.write(550); // Grip
      myservo2.write(550); // Grip
      myservo3.write(550); // Grip
      myservo4.write(550); // Grip
      straighten(); // Straighten
      results.value = 0;
      break;
  
      case 2534555274: // Start
      //Serial.println("Start"); // Nothing yet
      results.value = 0;
      break;
  
      case 2054033594:
      //Serial.println("Select"); // Nothing yet
      results.value = 0;
      break;

      case 120554099: // Up + A
      flipOff(); // Flip the bird
      straighten(); // Straighten
      results.value = 0;
      break;

      case 2519209161: // Up + B
      victory(); // Flash victory sign
      straighten(); // Straighten
      results.value = 0;
      break;

      case 3398950451: // Down + A
      juggle(); // Juggle balls
      juggle(); // Juggle balls again
      straighten(); // Straighten
      results.value = 0;
      break;

      case 1502638217: // Down + B
      results.value = 0; // Nothing yet
      break;

      case 601075779: // Left + A
      results.value = 0; // Nothing yet
      break;

      case 2999730841: // Left + B
      results.value = 0; // Nothing yet
      break;

      case 2366630827: // Right + A
      results.value = 0; // Nothing yet
      break;

      case 2953994585: // Right + B
      results.value = 0; // Nothing yet
      break;
    
      //default:
      //Serial.println("Idle");
      //digitalWrite(LED, HIGH);
  
  }
}


// Just in case...
/* IR SIGNAL DECODER CODE... FOR A RAINY DAY
 *  
 *  #include <IRremote.h>

int IRpin = 11;
IRrecv irrecv(IRpin);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() 
{
  if (irrecv.decode(&results)) 
    {
      Serial.println(results.value, DEC); // Print the Serial 'results.value'
      irrecv.resume();   // Receive the next value
    }
  
  
}
 */
