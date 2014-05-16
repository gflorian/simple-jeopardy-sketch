#define on_board_LED 13
#define LED_COUNT 4 //number of LEDs below (in the array)
#define bluePin1 21
#define greenPin1 22
#define redPin1 23
#define bluePin2 3

#define BUTTON_COUNT 4 //number of buttons
#define button1Pin 14
#define button2Pin 15
#define button3Pin 16
#define button4Pin 17


const int leds[] = {bluePin1,greenPin1,redPin1,bluePin2}; //should contain only LED_COUNT elements
const int buttons[] = {button1Pin,button2Pin,button3Pin,button4Pin}; //should contain only BUTTON_COUNT elements
const char letters[] = "abcd";
boolean buttonWasPressed[] = {false,false,false,false}; //should contain only BUTTON_COUNT elements
int i;

void setup() {
  pinMode(on_board_LED, OUTPUT);
  
  for(i=0; i<LED_COUNT;i++) {
    pinMode(leds[i], OUTPUT);
  }
  for(i=0;i<BUTTON_COUNT;i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }

  digitalWrite(bluePin1, 1);
  digitalWrite(bluePin2, 1);
  delay(1000);

  digitalWrite(greenPin1, 1);
  delay(1000);

  digitalWrite(redPin1, 1);
  delay(1000);

  digitalWrite(on_board_LED, 1);
}

void loop() {
  for(i=0;i<BUTTON_COUNT;i++) {
    if(digitalRead(buttons[i]) == HIGH) { //button NOT pressed
      if(buttonWasPressed[i] == true) { //released
        digitalWrite(leds[i], !digitalRead(leds[i]));
        delay(12); //blocking debounce
      }
      else { //still NOT pressed
      }
      buttonWasPressed[i] = false;
    }
    else { //button IS pressed
      if(buttonWasPressed[i] == false) { //pressed
        Keyboard.print(letters[i]); //send respective character
        digitalWrite(leds[i], !digitalRead(leds[i]));
        delay(12); //blocking debounce
      }
      else { //button kept pressed
      }
      buttonWasPressed[i] = true;
    }
  }
}
