//BUTTON BOX 
//USE w ProMicro
//Tested in WIN10 + Assetto Corsa
//AMSTUDIO
//20.8.17

#include <Keypad.h>
#include <Joystick.h>


// Create Joystick
// Joystick_ Joystick;

// Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID, 
//   JOYSTICK_TYPE_JOYSTICK, NUMBUTTONS, 0,
//   false, false, false, false, false, false,
//   false, false, false, false, false);

// // Joystick_ Joystick(0x15,JOYSTICK_TYPE_JOYSTICK,
//   // 1, 0,                  // Button Count, Hat Switch Count
//   // true, true, false,     // X and Y, but no Z Axis
//   // false, false, false,   // No Rx, Ry, or Rz
//   // false, false,          // No rudder or throttle
//   // false, false, false);  // No accelerator, brake, or steering

//   // const bool initAutoSendState = true;

//   // int xAxis_ = 0;
//   // int yAxis_ = 0;
//   // int lastButtonState = 0;


// void setup() {
//   // // Set Range Values
//   // Joystick.setXAxisRange(-127, 127);
//   // Joystick.setYAxisRange(-127, 127);
//   // Joystick.setZAxisRange(-127, 127);
//   // Joystick.setRxAxisRange(0, 360);
//   // Joystick.setRyAxisRange(360, 0);
//   // Joystick.setRzAxisRange(0, 720);
//   // Joystick.setThrottleRange(0, 255);
//   // Joystick.setRudderRange(255, 0);
    
  
// //  pinMode(joyButton, INPUT_PULLUP);
// //  Joystick.begin(initAutoSendState);
//   Joystick.begin();
// }
// void loop() { 
//     // xAxis_ = analogRead(joyX);
//     // xAxis_ = map(xAxis_,0, 1023, 0, 1023);
//     // Joystick.setXAxis(xAxis_);
     
//     // yAxis_ = analogRead(joyY);
//     // yAxis_ = map(yAxis_,0, 1023, 0, 1023);
//     // Joystick.setYAxis(yAxis_);
     
//     //  int downPressed = !digitalRead(joyButton);
//     //  if(downPressed != lastButtonState){
//     //   Joystick.setButton(0, downPressed); 
//     //   lastButtonState = downPressed;
//     //  }
     
//     //  delay(10);

//   // CheckAllEncoders();a


// }

// void CheckAllButtons(void) {
//      


//Initial Definitions and Setup
//Libary Inclusion
#include <Joystick.h>

//Define and Allocate Input Pins to memorable names
#define joyR2 A0

#define ENABLE_PULLUPS
#define NUMBUTTONS 32
#define NUMROWS 6
#define NUMCOLS 6


 
byte buttons[NUMROWS][NUMCOLS] = {
    {0,1,2,3,4,5},
    {6,7,8,9,10,11},
    {12,13,14,15,16,17},
    {18,19,20,21,22,23},
    {24,25,26,27,28,29},
    {30,31,32},
};


// byte rowPins[NUMROWS] = {14}; 
// byte colPins[NUMCOLS] = {2,3,4,5,6,7}; 

// Keypad buttbx = Keypad( makeKeymap(buttons), rowPins, colPins, NUMROWS, NUMCOLS); 

//Initializing Axis as Integers, at a 0 default value
int r2_axis_ = 0;


Joystick_ Joystick(0x12, JOYSTICK_TYPE_JOYSTICK, 3, 0,true,true,false,false,false,true,false,true,false,false,false);

//Set Auto Send State
//Enables Auto Sending, allowing the controller to send information to the HID system, rather than waiting to be asked.
const bool initAutoSendState = true;

void setup() {
  //Initialize Buttons
  //Buttons set up between Digital Pin and Ground, following pin allocations from earlier on

  //Start Joystick - Needed to start the Joystick function libary
  Joystick.begin();
}

void loop() {
  
  r2_axis_ = analogRead(joyR2);
  r2_axis_ = map(r2_axis_,0,464,0,255);
  Joystick.setThrottle(r2_axis_);

//Pole Delay/Debounce
//To reduce unessecary processing, the frequency of the reading loop is delayed. The value(in ms) can be changed to match requirement
delay(10);

CheckAllButtons();
}

void CheckAllButtons(void) {

 if (buttbx.getKeys())
    {
       for (int i=0; i<LIST_MAX; i++)   
        {
           if ( buttbx.key[i].stateChanged )   
            {
            switch (buttbx.key[i].kstate) {  
                    case PRESSED:
                    case HOLD:
                              Joystick.setButton(buttbx.key[i].kchar, 1);
                              break;
                    case RELEASED:
                    case IDLE:
                              Joystick.setButton(buttbx.key[i].kchar, 0);
                              break;
            }
           }   
         }
     }
}