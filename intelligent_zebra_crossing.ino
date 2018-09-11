int pir=7;
unsigned long startFlag;
unsigned long startTime;
unsigned long previousTime;
unsigned long duration=10000;
unsigned long times; 
unsigned long sec;
long unsigned int lowIn;
long unsigned int pause = 5000;
boolean lockLow = true;
boolean takeLowTime;
int pin;
int i;
int led1= 14; 
int led2=15; 
int led3=16;
int pled1=17;
int pled2=11;
//button
const int buttonPin = 18;    // the number of the pushbutton pin
      // the number of the LED pin

// Variables will change:
int ledState = LOW;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = HIGH;   // the previous reading from the input pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    
//display
int pin1 = 8;
int pin2 = 13;                                    //                            --6--
int pin3 = 2;                                    //                         5 |     | 7
int pin4 = 3;                                    //                           |--4--|
int pin5 = 4;                                    //                         1 |     | 3
int pin6 = 5;                                    //                            --2--
int pin7 = 6;
int gnd1 = 10;                                 //                          gnd1 is display 1's gnd
int gnd2 = 9;                                   //                          gnd2 is display 2's gnd
int timer = 50;                               //   A timer, to run the for loop 10 times, which turns out as 1 second.
int value;
int calibrationTime = 10; //   The value, part of the FADING display

int stat;
int rumple=0;
//int led = 12;
int ledPin = 12;
void setup() {
  // put your setup code here, to run once:
 pinMode(pir, INPUT);
 Serial.begin(9600);
  //pinMode(ledPin, OUTPUT);
  //pinMode(led, OUTPUT);
   pinMode(buttonPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(pled1, OUTPUT);
  pinMode(pled2, OUTPUT);
 // display
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);           //The following sets up all of the pins for use.
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(gnd1, OUTPUT);
  pinMode(gnd2, OUTPUT);
   digitalWrite(pir, LOW);
    Serial.print("calibrating sensor ");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);
   digitalWrite(led1,HIGH);
   digitalWrite(pled1, LOW);
   digitalWrite(pled2, HIGH);
   

}

void loop()
{
   int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
        //Serial.println(ledState);
      }
    }
  }

  // set the LED:
  

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading; 
 

if (((digitalRead(pir) == HIGH)||(ledState == HIGH)) && (startFlag == 0)){ // start new time sequence
  digitalWrite(ledPin, HIGH);
  if(lockLow){
    lockLow = false; 
  }
  takeLowTime = true;
   startFlag = 1;
   startTime = millis();
   previousTime = startTime;
}
  if((ledState == HIGH))
  {
  digitalWrite(ledPin, HIGH);
  delay(20000);
  startFlag = 0;
  ledState = LOW;
   goto a;
    digitalWrite(ledPin, LOW);
  }
if ( (startFlag ==1) && ((millis() - previousTime) >= duration) ) {  // duration = 100, sample 10 times a second
   previousTime = previousTime + duration;
  Serial.println(buttonState);
   if ((millis() - startTime )<=5000){ // still waiting it out
    if (digitalRead(pir) == LOW ){
       // pin went low
       startFlag = 0;
       digitalWrite(ledPin, LOW);
       }
    }
   if ((millis() - startTime) >15000){ 
       if (digitalRead(pir) == LOW){
       // pin went low
       startFlag = 0;
       digitalWrite(ledPin, LOW);
       }
      else{  // made it!
      rumple = 1;
      digitalWrite(ledPin, HIGH);
      
      
      startFlag = 0;
      }
      if(rumple == 1)
      {
        a:
        //digitalWrite(led, HIGH);
         digitalWrite(led1, LOW);
         
       digitalWrite(ledPin, LOW);
        sec = millis();
        Serial.println(sec);
        delay(250);
        digitalWrite(led2, HIGH);
        delay(3000);
        digitalWrite(led2, LOW);
        delay(300);
        digitalWrite(led2, HIGH);
        delay(800);
        digitalWrite(led2, LOW);
        delay(200);
        digitalWrite(led2, HIGH);
        delay(800);
        digitalWrite(led2, LOW);
        delay(200);
        digitalWrite(led2, HIGH);
        delay(800);
        digitalWrite(led2, LOW);
        delay(1000);
        digitalWrite(led2, LOW);
        digitalWrite(led3, HIGH);
        delay(2500);
        digitalWrite(pled1, HIGH);
        digitalWrite(pled2, LOW);
        for (int i=0; i<timer; i++){                     //   The for loop, for running the program 10 times.
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B0);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);                         
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 20 to the display.
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  
for (int i=0; i<timer; i++){
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 19 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 18 to the display.
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 17 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 16 to the display.
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B0);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 15 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B0);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 14 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 13 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 12 to the display.
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B0);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 11 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 10 to the display.
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 09 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 08 to the display.
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 07 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 06 to the display.
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B0);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 05 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B0);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 04 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 03 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 02 to the display.
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B0);
   digitalWrite(pin4, B1);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 01 to the display.
   digitalWrite(pin1, B0);
   digitalWrite(pin2, B0);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B0);
   digitalWrite(pin6, B0);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  for (int i=0; i<timer; i++){
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B0);
   digitalWrite(gnd2, B1);
   delay(10);                                        //          Writes 00 to the display.
   digitalWrite(pin1, B1);
   digitalWrite(pin2, B1);
   digitalWrite(pin3, B1);
   digitalWrite(pin4, B0);
   digitalWrite(pin5, B1);
   digitalWrite(pin6, B1);
   digitalWrite(pin7, B1);
   digitalWrite(gnd1, B1);
   digitalWrite(gnd2, B0);
   delay(10);
   
  }
  digitalWrite(pled2, HIGH);
        digitalWrite(pled1, LOW);
        delay(75);
        digitalWrite(pled1, HIGH);
        delay(500);
         digitalWrite(pled1, LOW);
       
         
  for(i=0;i<2;i++)
  {
     for(value = 0 ; value <= 255; value+=5) // fade in (from min to max) 
  { 
    analogWrite(gnd1, value);           // sets the value (range from 0 to 255) 
    analogWrite(gnd2, value);           // sets the value (range from 0 to 255) 
    delay(10);                            // waits for 30 milli seconds to see the dimming effect 
  } 
  for(value = 255; value >=0; value-=5)   // fade out (from max to min) 
  { 
    analogWrite(gnd1, value);           // sets the value (range from 0 to 255) 
    analogWrite(gnd2, value);           // sets the value (range from 0 to 255) 
    delay(10); 
  }  
  }
        
       // delay(10000);
        
        //delay(2000);
        digitalWrite(led3, LOW);
        digitalWrite(led1, HIGH);
        rumple=0;
        
        
      }
   }
// do other stuff while time is passing
}
}
