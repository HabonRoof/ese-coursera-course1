/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief analyze array data and show the statistic of the element
 *
 * This file is the main file of the assesment, include the main function, print 
 * array implementation, and statistic implementation.
 *
 * @author JohnsonCL Chen
 * @date 2024/06/25
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)
unsigned char median, maximum, minimum, mean;

// int main()
// {

//   unsigned char test[SIZE] = {34, 201, 190, 154, 8, 194, 2, 6,
//                               114, 88, 45, 76, 123, 87, 25, 23,
//                               200, 122, 150, 90, 92, 87, 177, 244,
//                               201, 6, 12, 60, 8, 2, 5, 67,
//                               7, 87, 250, 230, 99, 3, 100, 90};

//   /* Other Variable Declarations Go Here */

//   /* Statistics and Printing Functions Go Here */
//   print_array(test, SIZE);
//   print_statistics(test, SIZE);
//   return 0;
// }
#define VERBOSE

unsigned char print_array(unsigned char *array, __uint8_t size) {
 #ifdef VERBOSE

  if (size > 0) {
    printf("array[%d] = ", SIZE);
    for (__uint8_t i = 0; i < size; i++) {
      printf("%d, ", array[i]);
    }
    printf("\n\r");
  }
  else
    printf("Array size error! \n\r");
    
#endif
  return 0;
}

/**
 * @brief print statistics of input array
 * @param array the array to be statistic
 * @param size the size of array
 * @return 0 of no error
 */
unsigned char print_statistics(unsigned char *array, __uint8_t size) {
  median = find_median(array, size);
  mean = find_mean(array, size);
  maximum = find_maximim(array, size);
  minimum = find_minimum(array, size);

  printf("the median is %d \r\n", median);
  printf("the mean is %d \r\n", mean);
  printf("the mamimum is %d \r\n", maximum);
  printf("the minimum is %d \r\n", minimum);
  return 0;
}

/**
 * @brief find medium value of an array
 * @param array the array to find median
 * @param size the size of an array
 * @return 0 if no error
 */
unsigned char find_median(unsigned char *array, __uint8_t size) {
  sort_array(array, size);
  return array[SIZE / 2];
}

/**
 * @brief find mean value of an array
 * @param array the array to find mean
 * @param size the size of an array
 * @return 0 if no error
 */
unsigned char find_mean(unsigned char *array, __uint8_t size) {
  __uint32_t total = 0;
  __uint8_t mean = 0;
  for(__uint8_t i = 0; i < size - 1; i++) {
    total += array[i];
  }
  mean = total / size;
  return mean;
}

/**
 * @brief find maximum value of an array
 * @param array the array to find maximum
 * @param size the size of an array
 * @return 0 if no error
 */
unsigned char find_maximim(unsigned char *array, __uint8_t size) {
  sort_array(array, size);
  return array[0];
}

/**
 * @brief find minimum value of an array
 * @param array the array to find minimum
 * @param size the size of an array
 * @return 0 if no error
 */
unsigned char find_minimum(unsigned char *array, __uint8_t size) {
  sort_array(array, size);
  return array[size - 1];
}

/**
 * @brief sort the array from smallest to biggest, using bubble sort for implementation
 * @param array the array to be sort
 * @param size the size of an array
 * @return 0 if no error
 */
unsigned char sort_array(unsigned char *array, __uint8_t size) {
  __uint8_t temp;
  if(size <= 0)
    return 0;
  for(__uint8_t i = 0; i < size - 1; i++) {
    for(__uint8_t j = 0; j < size - i - 1; j++){
      if(array[j] < array[j + 1]) {
          temp = array[j];
          array[j] = array [j + 1];
          array[j + 1] = temp;
      }
    }
  }
    return 0;
}