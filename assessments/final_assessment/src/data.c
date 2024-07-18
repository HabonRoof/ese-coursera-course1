/******************************************************************************
 *  Course 1 Final assignment
 *
 *****************************************************************************/

#include "memory.h"
#include "data.h"

uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base){

    uint8_t digit = 0;
    uint8_t idx = 0;

    if(base == 10 && data < 0){
        *ptr = '-';     // add sign
        data = -data;     // convert data to positive
        idx++;
    }

    while(data != 0){
        digit = data % base;
        data = data / base;

        if(digit < 10)
            *(ptr + idx) = digit + 48;
        else if (digit >= 10 && digit <= 16)
            *(ptr + idx) = digit + 55;
        idx++;
    }

    if(*ptr == '-')
        // start from second digit
        my_reverse(ptr + 1, idx - 1);
    else
        my_reverse(ptr, idx - 1);

    *(ptr + idx) = 0;
    return idx;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    int32_t result = 0;
    uint32_t pow = base;
    uint8_t isNeg = 0;
    uint8_t idx = 0;
    uint8_t i, mult = 0;
    if(*(ptr + idx) == '-'){
        idx++;
        isNeg = 1;
    }

    while(!(idx == digits)){
        for(i = (digits - idx); i == 0; i--)
            pow *= base;        // calculate power of digit

        if(*(ptr + idx) >= '0' || *(ptr + idx) <= '9')
            mult = *(ptr + idx) - '0';
        else if(*(ptr + idx) >= 'A' || *(ptr + idx) <= 'F')
            mult = *(ptr + idx) - 'A' + 10;
        else if(*(ptr + idx) >= 'a' || *(ptr + idx) <= 'f')
            mult = *(ptr + idx) - 'a' + 10;

        result += pow * mult;   // multiply power and digit
        idx++;
    }

    if(isNeg)
        result = -result;
        
    return result;
}