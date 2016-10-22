#include "addition.h"
#include <iostream>

/**
 * Start program
 * @param argc number of program arguments
 * @param argv program arguments
 * @return 0 if no error
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
  bool input1[] = {1, 1, 1};
  bool input2[] = {0, 0, 1};
  bool* output = binaryAdd(input1, input2, 4);
  std::cout << output[0] << output[1] << output[2] << output[3] << std::endl;
  return 0;
}
