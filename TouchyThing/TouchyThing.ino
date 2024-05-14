// TouchyThing.ino

// put your code here
// define serial speed
static const int SERIAL_SPEED = 115200;

// define the touch pin number
#define touchPin T0

// LEDs 
uint8_t ledPins[] = {GPIO_NUM_27,GPIO_NUM_15,GPIO_NUM_32};
 
// number of led pins
uint8_t numLedPins = sizeof(ledPins)/sizeof(uint8_t);

// variable for storing touch value
int touchValue;

// threshold for yellow LED
const int LED_YELLOW = 60; 

// threshold for red LED
const int LED_RED = 20; 

void setup(){
  // the begining serial speed
  Serial.begin(SERIAL_SPEED); 
  Serial.println("ESP32 Touch Sensing");
  for(int i = 0; i < numLedPins; i++) {
      // set up external led pins
      pinMode(ledPins[i], OUTPUT);     
      // turn off to begin    
      digitalWrite(ledPins[i], LOW);      
    }
   delay(1000);
  }

// Function to blink led
// Parameter is the index of the led
 void blinkLed(int ledIndex){
  // turn on led with the index provided
  digitalWrite(ledPins[ledIndex],HIGH);
  // wait for 300 milliseconds
  delay(300);
  // turn off led with the index provided
  digitalWrite(ledPins[ledIndex],LOW);
}

 void loop(){
  // get the value of the touch pin
  touchValue = touchRead(touchPin);
  // print the touch value to the serial monitor
  Serial.println(touchValue); 

  // if the touch value is less than the threshold for red led
  if(touchValue < LED_RED){
      // blink the red led 
      blinkLed(2);
      
    }
   // if the touch value is less than the threshold for yellow led
   else if (touchValue < LED_YELLOW){
      // blink yellow led
      blinkLed(1);
    }
    else {
      // blink green led
      blinkLed(0);
    }
    delay(300);
    
  }
