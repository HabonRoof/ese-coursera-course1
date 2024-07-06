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
 * @file stats.h
 * @brief define the 
 *
 * This file is the header file of the assesment, declare the main function, print 
 * array functions, and statistic functions.
 *
 * @author JohnsonCL Chen
 * @date 2024/06/25
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

/**
 * @brief print the array elements
 *
 * @param array the array to print elements
 * @param size  the size of array
 * @return 0 if no error
 */
unsigned char print_array(unsigned char* array, __uint8_t size);

/**
 * @brief print statistics of input array
 * @param array the array to be statistic
 * @param size the size of array
 * @return 0 of no error
 */
unsigned char print_statistics(unsigned char* array, __uint8_t size);

/**
 * @brief find medium value of an array
 * @param array the array to find median
 * @param size the size of an array
 * @return 0 if no error
 */
unsigned char find_median(unsigned char* array, __uint8_t size);

/**
 * @brief find mean value of an array
 * @param array the array to find mean
 * @param size the size of an array
 * @return 0 if no error
 */
unsigned char find_mean(unsigned char* array, __uint8_t size);

/**
 * @brief find maximum value of an array
 * @param array the array to find maximum
 * @param size the size of an array
 * @return 0 if no error
 */
unsigned char find_maximim(unsigned char* array, __uint8_t size);

/**
 * @brief find minimum value of an array
 * @param array the array to find minimum
 * @param size the size of an array
 * @return 0 if no error
 */
unsigned char find_minimum(unsigned char* array, __uint8_t size);

/**
 * @brief sort the array from smallest to biggest
 * @param array the array to be sort
 * @param size the size of an array
 * @return 0 if no error
 */
unsigned char sort_array(unsigned char* array, __uint8_t size);

#endif /* __STATS_H__ */
