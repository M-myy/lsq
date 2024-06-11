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
 * @brief 最小二乘结构体
 * 
 */
struct _lsq
{
    float *x;
    float *y;
    unsigned long long num;
    float coef[2];    // 拟合系数，0->1:高次项->低次项

    void (*lsq)(struct _lsq *lsq);
};
typedef struct _lsq lsq_t;

// lsq结构体接口
extern lsq_t lsq;

/**
 * @brief 最小二乘法
 */
uint8_t calc_lsq(float x[],float y[],unsigned long long num,float *a,float *b);



#endif
