/**
 * @file lsq.h
 * @brief 最小二乘算法
 * @date 2024/06/07
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef __LSQ_H__
#define __LSQ_H__
#include <stdint.h>

/**
 * @brief 最小二乘法
 */
uint8_t lsq(float x[],float y[],unsigned long long num,float *a,float *b);


#endif
