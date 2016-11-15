#include "Addition.h"

const int LED[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

const int TOGGLE_BUTT = A0; //Toggles LED value: 1 to 0 to 1...
const int BIT_BUTT = A1; //Switches between LEDs
const int ADD_BUTT = A2; //Adds LEDs 1-3 + 4-6

int currentLED = 0;

bool bitPressed = false;
bool addPressed = false;
bool togPressed = false;

bool row1[3];
bool row2[3];
bool* out;


void setup() {
  pinMode(LED[0], OUTPUT);
  pinMode(LED[1], OUTPUT);
  pinMode(LED[2], OUTPUT);
  pinMode(LED[3], OUTPUT);
  pinMode(LED[4], OUTPUT);
  pinMode(LED[5], OUTPUT);
  pinMode(LED[6], OUTPUT);
  pinMode(LED[7], OUTPUT);
  pinMode(LED[8], OUTPUT);
  pinMode(LED[9], OUTPUT);

  pinMode(TOGGLE_BUTT, INPUT);
  pinMode(BIT_BUTT, INPUT);
  pinMode(ADD_BUTT, INPUT);

}

void loop() {
  bool valAdd = digitalRead(ADD_BUTT); //Reads adder button
  bool valBit = digitalRead(BIT_BUTT); //Reads LED switcher button
  bool valTog = digitalRead(TOGGLE_BUTT); //Toggles LED value

  if(valBit&&!bitPressed){
    currentLED++;
    bitPressed=true;
    }
   if(!valBit){
    bitPressed=false;
    }
   
  if(valTog&&!togPressed){
    togPressed=true;
    valTogger(valTog);
    }
   if(!valTog){
    togPressed=false;
    }

  if(valAdd){
    out = binaryAdd(row1, row2, 4);
    for(int i = 0; i < 4; i++){
      digitalWrite(LED[6+i],out[i]);
      }
    }
    
  
}

void valTogger(bool valTog){
  
  if(currentLED<=3){ //If valTog is true, change current LED
      row1[currentLED]=true; //Make false if already true, do later
      digitalWrite(LED[currentLED],valTog);
    }
  if(currentLED>3){
      row2[currentLED]=true;
      digitalWrite(LED[currentLED],valTog);
    }
}

