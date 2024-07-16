// initiaizing pins connected to logic pins 
// i.e (In1,In2,In3,In4) of motor driver
#define m1 3
#define m2 5
#define m3 6
#define m4 9

// initializing moving speed and turning speed of the car
// you can adjust according to your desired speed
int speed = 240;
int turn =  150;

// variable for storing signals from bluetooth module
char command;

void setup() {
  // put your setup code here, to run once:
    
    // setting pins of the motor driver to output
    pinMode(m1, OUTPUT);
    pinMode(m2, OUTPUT);
    pinMode(m3, OUTPUT);
    pinMode(m4, OUTPUT);

    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // first we will check that our arduino is receiving any signal
  if (Serial.available() > 0)
    {
      // we will store the signals coming from bluetooth module
      command = Serial.read() ;
      initialize_motor();
    

    switch (command)
    {
      case 'F' :

      forward();
      break;

      case 'B' :

      reverse();
      break;

      case 'R' :

      right();
      break;

      case 'L' :

      left();
      break;
    }
  }
}

// reseting the speed and turn values 
void initialize_motor()
{
  analogWrite(m1, 0);
  analogWrite(m2, 0);
  analogWrite(m3, 0);
  analogWrite(m4, 0);
}

// initiaizing function for forward movement
void forward()
{
  analogWrite(m1, speed);
  analogWrite(m3, speed);
}

// // initiaizing function for reverse movement
void reverse()
{
  analogWrite(m2, speed);
  analogWrite(m4, speed);
}

// initiaizing function for right turn
void right()
{
  analogWrite(m2, turn);
  analogWrite(m3, turn);
}

// initiaizing function for left turn
void left()
{
  analogWrite(m1, turn);
  analogWrite(m4, turn);
}
