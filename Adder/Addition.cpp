#include "Addition.h"

bool* addBits(bool bit1, bool bit2){
  bool* output = new bool[2];
  output[0] = bit1 && bit2;// most signifcant bit
  output[1] = bit1 ^ bit2;// least significant bit
  return output;
}

bool* addBits(bool bit1, bool bit2, bool carriedBit){
  bool* output = addBits(bit2, bit1);// add the two bits
  output[0] |= addBits(output[1], carriedBit)[0];// or operaton most significant
  output[1] = addBits(output[1], carriedBit)[1];// add carried bit to least significant
  return output;
}

bool* binaryAdd(bool* input1, bool* input2, int outputLength){
  bool* output = new bool[outputLength];
  for (int i = outputLength - 1; i > 0; i--){
    // carry a bit into the next place value
    output[i - 1] = addBits(input1[i - 1], input2[i - 1], output[i])[0];
    // actually add the 2 bits (and the carried bit) in the current place value
    output[i] = addBits(input1[i - 1], input2[i - 1], output[i])[1];
  }
  return output;
}
