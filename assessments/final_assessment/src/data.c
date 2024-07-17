/******************************************************************************
 *  Course 1 Final assignment
 *
 *****************************************************************************/

#include "../include/common/memory.h"
#include "../include/common/data.h"

uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base){

    uint8_t digit = 0;
    uint8_t idx = 0;
    uint8_t q = 0;

    if(base == 10){
        *ptr = '-';     // add sign
        data *= -1;     // convert data to positive\
        idx++;
    }

    while(data != 0){
        digit = data % base;
        data = data / base;

        if(digit < 10)
            *(ptr + idx) = digit + 48;
        else
            *(ptr + idx) = digit + 55;
        idx++;
    }
    if(*ptr == '-')
        // start from second digit
        my_reverse(ptr + 1, idx - 1);
    else
        my_reverse(ptr, idx);

    *(ptr + idx) = '\n';
    return idx;
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){

}