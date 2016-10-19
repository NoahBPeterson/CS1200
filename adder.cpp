#include <iostream>

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

/**
 * start program
 */
int main(int argc, char** argv){
  bool* sum = addBits(true, true, true);
  std::cout << sum[0] << sum[1] << std::endl;
  bool* sum2 = addBits(true, true, false);
  std::cout << sum2[0] << sum2[1] << std::endl;
  bool* sum3 = addBits(true, false, false);
  std::cout << sum3[0] << sum3[1] << std::endl;
  bool* sum4 = addBits(false, false, true);
  std::cout << sum4[0] << sum4[1] << std::endl;
  bool* sum5 = addBits(false, true, true);
  std::cout << sum5[0] << sum5[1] << std::endl;
  bool* sum6 = addBits(false, true, false);
  std::cout << sum6[0] << sum6[1] << std::endl;
  bool* input1 = new bool[3];
  bool* input2 = new bool[3];
  bool* output = new bool[4];
  input1[0] = 1;
  input1[1] = 1;
  input1[2] = 1;
  input2[0] = 1;
  input2[1] = 1;
  input2[2] = 1;
  output[2] = addBits(input1[2], input2[2])[0];
  output[3] = addBits(input1[2], input2[2])[1];
  output[1] = addBits(input1[1], input2[1], output[2])[0];
  output[2] = addBits(input1[1], input2[1], output[2])[1];
  output[0] = addBits(input1[0], input2[0], output[1])[0];
  output[1] = addBits(input1[0], input2[0], output[1])[1];
  std::cout << output[0] << output[1] << output[2] << output[3] << std::endl;
  return 0;
}
