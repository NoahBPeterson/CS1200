const byte LED[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

const byte TOGGLE_BUTT = A0; //Toggles LED value: 1 to 0 to 1...
const byte BIT_BUTT = A1; //Switches between LEDs
const byte ADD_BUTT = A2; //Adds LEDs 1-3 + 4-6

/*
 * digital 2-4 for first input number
 * digital 5-7 for second input number
 * digital 8-11 for sum
 * 
 * analog 0-2 for buttons
 */

/**
 * Sum of two bits
 * @param bit1 first bit do add
 * @param bit2 second bit to add
 * @return array with the 1st bool (index 0) as the most significant bit
 */
bool* addBits(const bool bit1, const bool bit2) {
  bool* output = new bool[2];
  output[0] = bit1 && bit2;// most signifcant bit
  output[1] = bit1 ^ bit2;// least significant bit
  return output;
}

/**
 * Add two bits with a bit carried from another addition
 * @param bit1 first bit do add
 * @param bit2 second bit to add
 * @param carriedBit bit that was carried from addition of less significant bits
 * @return array with the 1st bool (index 0) as the most significant bit
 */
bool* addBits(const bool bit1, const bool bit2, const bool carriedBit) {
  bool* output = addBits(bit2, bit1);// add the two bits
  output[0] |= addBits(output[1], carriedBit)[0];// or operaton most significant
  output[1] = addBits(output[1], carriedBit)[1];// add carried bit to least significant
  return output;
}

/**
 * Perform binary addition on two binary numbers
 * The most significant bit will have an array index of 0.
 * @param input1 first bool array representing the first binary number
 * @param input2 second bool array representing the second binary number
 * @param outputLength should be the length of each input array + 1
 * @return sum of the two numbers as a bool array
 */
bool* binaryAdd(const bool* input1, const bool* input2, const byte outputLength) {
  bool* output = new bool[outputLength];
  for (byte i = outputLength - 1; i > 0; i--) {
    // carry a bit into the next place value
    output[i - 1] = addBits(input1[i - 1], input2[i - 1], output[i])[0];
    // actually add the 2 bits (and the carried bit) in the current place value
    output[i] = addBits(input1[i - 1], input2[i - 1], output[i])[1];
  }
  return output;
}

/**
 * Run once before loop
 */
void setup() {
  for (byte i = 0; i < 10; i++) {
    pinMode(LED[i], OUTPUT);
  }

  pinMode(TOGGLE_BUTT, INPUT);
  pinMode(BIT_BUTT, INPUT);
  pinMode(ADD_BUTT, INPUT);

  Serial.begin(9600);
}

/**
 * Run often in a loop
 */
void loop() {
  static byte currentLED = 0;
  static bool bitPressed = false;
  static bool addPressed = false;
  static bool togPressed = false;
  static bool row1[3] = {false, false, false};
  static bool row2[3] = {false, false, false};
  static bool *sum = new bool[4];

  static bool *output = new bool[10];

  static bool valTog = digitalRead(TOGGLE_BUTT);
  static bool valBit = digitalRead(BIT_BUTT);
  static bool valAdd = digitalRead(ADD_BUTT);

  while (true) {
    valTog = digitalRead(TOGGLE_BUTT);
    valBit = digitalRead(BIT_BUTT);
    valAdd = digitalRead(ADD_BUTT);

    // change which bit is being modified
    if (valBit && !bitPressed) {
      if (currentLED >= 5) {
        currentLED = 0;
      } else {
        currentLED++;
      }
      Serial.print("Next bit ");
      Serial.println(currentLED);
    }
    bitPressed = valBit;

    // toggle a bit
    if (valTog && !togPressed) {
      Serial.print("Toggled a bit ");
      if (currentLED < 3) { // change current LED
        row1[currentLED] = !row1[currentLED]; //Make false if already true
        Serial.print(currentLED);
        Serial.print(" ");
        Serial.println(row1[currentLED]);
      } else {
        row2[currentLED - 3] = !row2[currentLED - 3];
        Serial.print(currentLED);
        Serial.print(" ");
        Serial.println(row2[currentLED - 3]);
      }
    }
    togPressed = valTog;

    if (valAdd) {
      for (byte i = 0; i < 4; i++){
        sum[i] = 0;
      }
      // calculate sum
      sum = binaryAdd(row1, row2, 4);
      for (byte i = 0; i < 3; i++) {
        Serial.print(row1[i]);
      }
      Serial.print(" + ");
      for (byte i = 0; i < 3; i++) {
        Serial.print(row2[i]);
      }
      Serial.print(" = ");
      for (byte i = 0; i < 4; i++) {
        Serial.print(sum[i]);
      }
      Serial.println(" Calculated sum");
    }

    // write to input LEDs
    for (byte i = 0; i < 6; i++) {
      if (i < 3) {
        output[i] = row1[i];
      } else {
        output[i] = row2[i - 3];
      }
    }

    // output sum
    for (byte i = 0; i < 4; i++) {
      output[6 + i] = sum[i];
    }

    for (byte i = 0; i < 10; i++) {
      // write to LEDs
      digitalWrite(LED[i], output[i]);
    }
    delay(100);
  }
}
