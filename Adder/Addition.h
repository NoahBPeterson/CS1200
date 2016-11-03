#ifndef ADDER_H_
#define ADDER_H_

/**
 * Sum of two bits
 * @param bit1 first bit do add
 * @param bit2 second bit to add
 * @return array with the 1st bool (index 0) as the most significant bit
 */
bool* addBits(bool bit1, bool bit2);

/**
 * Add two bits with a bit carried from another addition
 * @param bit1 first bit do add
 * @param bit2 second bit to add
 * @param carriedBit bit that was carried from addition of less significant bits
 * @return array with the 1st bool (index 0) as the most significant bit
 */
bool* addBits(bool bit1, bool bit2, bool carriedBit);

/**
 * Perform binary addition on two binary numbers
 * The most significant bit will have an array index of 0.
 * @param input1 first bool array representing the first binary number
 * @param input2 second bool array representing the second binary number
 * @param outputLength should be the length of each input array - 1
 * @return sum of the two numbers as a bool array
 */
bool* binaryAdd(bool* input1, bool* input2, int outputLength);

#endif
