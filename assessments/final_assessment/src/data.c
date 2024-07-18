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
    uint8_t length = 0;
    int32_t original_data = data;

    if (data == 0) {
        *ptr++ = '0';
        *ptr = '\0';
        return 2; // Including null terminator
    }

    if (data < 0 && base == 10) {
        *ptr++ = '-';
        length++;
        data = -data;
    }

    uint8_t* temp_ptr = ptr;

    while (data != 0) {
        uint8_t digit = data % base;
        data /= base;
        if (digit < 10) {
            *temp_ptr++ = digit + '0';
        } else {
            *temp_ptr++ = digit - 10 + 'A';
        }
        length++;
    }

    *temp_ptr = '\0'; // Null terminator
    length++;

    if (original_data < 0 && base == 10) {
        my_reverse(ptr - length + 1, length - 2); // Exclude sign and null terminator
    } else {
        my_reverse(start, length - 1); // Exclude null terminator
    }

    return length;
}


int32_t my_atoi(uint8_t* ptr, uint8_t digits, uint32_t base) {
    if (base < 2 || base > 16) {
        return 0; // Unsupported base
    }

    int32_t result = 0;
    uint8_t isNeg = 0;

    if (*ptr == '-') {
        isNeg = 1;
        ptr++;
        digits--; // Decrease digit count since the negative sign is not part of the number
    }

    while (digits > 0) {
        uint8_t digit = *ptr;
        if (digit >= '0' && digit <= '9') {
            result = result * base + (digit - '0');
        } else if (digit >= 'A' && digit <= 'F') {
            result = result * base + (digit - 'A' + 10);
        } else if (digit >= 'a' && digit <= 'f') {
            result = result * base + (digit - 'a' + 10);
        }
        ptr++;
        digits--;
    }

    if (isNeg) {
        result = -result;
    }

    return result;
}