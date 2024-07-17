
#include <stdint.h>
#include <stddef.h>

/**
 * @brief convert data from a standard integer type into an ASCII string
 * 
 * @param data the 32-bit signed data to convert into ASCII code
 * @param ptr the address to sotrage converted data
 * @param base the output string base, can be 2-16 
 * @return the length of ASCII array
 */

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief convert data from a standard integer type into an ASCII string
 * @param ptr pointer sotrage ASCII data
 * @param digits how many digits in your ASCII data
 * @param base the convert base
 * @return the int32_t value
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

