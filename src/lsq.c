/**
 * @file lsq.c
 * @brief 最小二乘算法
 * @date 2024/06/07
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "lsq.h"

/**
 * @brief 最小二乘算法
 *
 * @param x 横坐标数组
 * @param y 纵坐标数组
 * @param num 数组大小
 * @param a 一次函数斜率
 * @param b 一次函数截距
 * @return uint8_t 是否拟合成功
 */
uint8_t lsq(float x[],float y[],unsigned long long num,float *a,float *b)
{
    float sum_x = 0;
    float sum_y = 0;
    float sum_xy = 0;
    float sum_x2 = 0;

    for(int i = 0;i < num;i++)
    {
        sum_x2 += x[i]*x[i];
        sum_y  += y[i];
        sum_x  += x[i];
        sum_xy += x[i]*y[i];
    }

    *a = (num*sum_xy - sum_x*sum_y)/(num*sum_x2 - sum_x*sum_x);
    *b = (sum_x2*sum_y - sum_x*sum_xy)/(num*sum_x2-sum_x*sum_x);

    return 1;
}
