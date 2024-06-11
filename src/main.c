/**
 * @file main.c
 * @brief 最小二乘法
 * @date 2024/06/09
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "lsq.h"
#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

// 最大元素数
#define max_num 100
// 数值最长个数
#define max_size 20

int main(int argc,char **argv)
{
    const char *filename = "F:/Case/LSQ/data/dat.txt";      // 文件名
    float *x = (float *)malloc(sizeof(float) * max_num);    // 用来接收数据
    float *y = (float *)malloc(sizeof(float) * max_num);
    char buf[max_size];    // 临时接收文件数据
    unsigned long long x_cnt = 0,y_cnt = 0;    // 计算行数
    float a,b;    // 拟合直线斜率、截距
    int j = 0;

    memset(x,0,sizeof(float) * max_num);
    memset(x,0,sizeof(float) * max_num);
    memset(buf,0,sizeof(char) * max_size);

    FILE *fp = fopen(filename,"r");
    if(fp == NULL)
    {
        printf("File read failure\n");
        exit(0);
    }
    printf("The data is loading...\n");

    while((buf[j++] = fgetc(fp)) != EOF)
    {
        if(buf[j-1] == ' ')
        {
            // buf[j-1] = 0;
            x[x_cnt++] = atof(buf);
            memset(buf,0,sizeof(char)*max_size);
            j = 0;
        }
        else if(buf[j-1] == '\n')
        {
            // buf[j-1] = 0;
            y[y_cnt++] = atof(buf);
            memset(buf,0,sizeof(char)*max_size);
            j = 0;
        }
    }
    fclose(fp);
    fp = NULL;
    printf("Data load complete.\n");

    if(x_cnt != y_cnt)
    {
        printf("Please check the file format!\n");
        exit(0);
    }

    calc_lsq(x,y,x_cnt,&a,&b);
    printf("a: %f, b: %f\r\n",a,b);

#if 1
    // 使用结构体
    lsq.x = x;
    lsq.y = y;
    lsq.num = x_cnt;
    lsq.lsq(&lsq);
    printf("结构体输出为, a: %f, b: %f\r\n",lsq.coef[0],lsq.coef[1]);
#endif


    return 0;
}
