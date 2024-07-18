/******************************************************************************
 *  Course 1 Final assignment
 *
 *****************************************************************************/

#include "memory.h"
#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base) {
    if (base < 2 || base > 16) {
        return 0; // Unsupported base
    }

    uint8_t* start = ptr;
    uint8_t digit = 0;
    uint8_t length = 0;

    if (data == 0) {
        *ptr++ = '0';
        *ptr = '\0';
        return 2; // Including null terminator
    }

    if (base == 10 && data < 0) {
        *ptr++ = '-';
        length++;
        if (data == INT32_MIN) {
            data = INT32_MAX;
            data += 1; // Handle the special case for -2147483648
        } else {
            data = -data;
        }
    }

    uint8_t* temp_ptr = ptr;

    while (data != 0) {
        digit = data % base;
        data = data / base;
        if (digit < 10) {
            *temp_ptr++ = digit + '0';
        } else {
            *temp_ptr++ = digit - 10 + 'A';
        }
        length++;
    }

    *temp_ptr = '\0'; // Null terminator
    length++;

    if (*start == '-') {
        my_reverse(ptr, length - 2); // Exclude sign and null terminator
    } else {
        my_reverse(start, length - 1); // Exclude null terminator
    }

    return length;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base) {
    if (base < 2 || base > 16) {
        return 0; // Unsupported base
    }

    int32_t result = 0;
    uint32_t pow = 1;
    uint8_t isNeg = 0;
    uint8_t* end_ptr = ptr + digits - 1; // Pointer to the last digit

    if (*ptr == '-') {
        isNeg = 1;
        ptr++; // Move past the negative sign
        digits--; // Decrease digit count since the negative sign is not part of the number
    }

    while (digits > 0) {
        uint8_t digit = *end_ptr;
        uint8_t mult = 0;

        if (digit >= '0' && digit <= '9') {
            mult = digit - '0';
        } else if (digit >= 'A' && digit <= 'F') {
            mult = digit - 'A' + 10;
        } else if (digit >= 'a' && digit <= 'f') {
            mult = digit - 'a' + 10;
        }

        result += pow * mult;
        pow *= base;
        end_ptr--;
        digits--;
    }

    if (isNeg) {
        result = -result;
    }

    return result;
}