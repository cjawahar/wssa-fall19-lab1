/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

#define RED 6
#define BLUE 8
#define GREEN 7

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  
  // Modified version of Blink to work with PowerDue board.
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);

  digitalWrite(RED, LOW);  // Low to turn off the LED. High to turn on.
  digitalWrite(BLUE, LOW);
  digitalWrite(GREEN, LOW);

  SerialUSB.begin(9600);
  while (!SerialUSB) {
    SerialUSB.println("Enter color: ");
  }
}

// the loop function runs over and over again forever
void loop() {

  int inputColor;
  //Need to read the input color
  if (SerialUSB.available()) {
    inputColor = SerialUSB.read();

    switch(inputColor) {
     case '1':
      SerialUSB.println("you printed red");
      //Turn red on, others off.
      digitalWrite(RED, HIGH);
      digitalWrite(GREEN, LOW);
      digitalWrite(BLUE, LOW);
  
      //Delay 1 second then turn off.
      delay(1000);
      digitalWrite(RED, LOW);
      break;
  
    case '2':
      SerialUSB.println("you printed blue");
      //Turn blue on, others off.
      digitalWrite(BLUE, HIGH);
      digitalWrite(RED, LOW);
      digitalWrite(GREEN, LOW);
  
      //Delay 1 second then turn off.
      delay(1000);
      digitalWrite(BLUE, LOW);
      break;
  
    case '3':
      SerialUSB.println("you printed green");
      //Turn green on, others off.
      digitalWrite(GREEN, HIGH);
      digitalWrite(RED, LOW);
      digitalWrite(BLUE, LOW);

      //Delay 1 second then turn off.
      delay(1000);
      digitalWrite(GREEN, LOW);
      break; 
    }
  }
}
