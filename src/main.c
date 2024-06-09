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
    // 文件名
    const char *filename = "F:/Case/LSQ/data/dat.txt";

    // 用来接收数据
    float *x = (float *)malloc(sizeof(float) * max_num);
    float *y = (float *)malloc(sizeof(float) * max_num);
    // 用来接收文件数据
    char buf[max_size];   
    memset(x,0,sizeof(float) * max_num);
    memset(x,0,sizeof(float) * max_num);
    memset(buf,0,sizeof(char) * max_size);

    // 计算行数
    unsigned long long x_cnt = 0,y_cnt = 0;   
    int j = 0;
    
    FILE *fp = fopen(filename,"r");

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

    if(x_cnt != y_cnt)
    {
        printf("警告: 请检查文件格式，数组元素不完整或者最后一行不是以换行符结束!\n");
        exit(0);
    }

    float a,b;
    lsq(x,y,x_cnt,&a,&b);
    printf("a: %f, b: %f\r\n",a,b);
    return 0;
}
