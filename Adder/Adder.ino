void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

/**
 * sum of two bits
 * the 1st bool in the output array is the most significant
 */
bool* addBits(bool bit1, bool bit2){
  bool* output = new bool[2];
  output[0] = bit1 && bit2;// most signifcant bit
  output[1] = bit1 ^ bit2;// least significant bit
  return output;
}

/**
 * add two bits with a bit carried from another addition
 */
bool* addBits(bool bit1, bool bit2, bool carriedBit){
  bool* output = addBits(bit2, bit1);// add the two bits
  output[0] |= addBits(output[1], carriedBit)[0];// or operaton most significant
  output[1] = addBits(output[1], carriedBit)[1];// add carried bit to least significant
  return output;
}

