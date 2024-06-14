/**
 * @file ringq.c
 * @brief 环形队列
 * @date 2024/06/14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "ringq.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Construct a new ringq init object
 * 
 * @param p_que 初始化的环形队列
 * @param size 环形队列大小
 */
uint8_t ringq_init(ringq_t *p_que,int size)
{
    p_que->head = 0;
    p_que->tail = 0;
    p_que->tag = 0;
    p_que->size = size;

    p_que->queue = (float *)malloc(sizeof(float) * p_que->size);

    return 0;
}

/**
 * @brief 释放队列
 * 
 * @param p_que 需要释放的队列
 * @return uint8_t 释放完成
 */
uint8_t ringq_free(ringq_t *p_que)
{
    if(p_que->queue != NULL)
    {
        free(p_que->queue);
    }
    return 0;
}

/**
 * @brief 写队列
 * 
 * @param p_que 队列
 * @param val 写入的值
 * @return uint8_t 队列满标志位
 */
uint8_t ringq_write(ringq_t *p_que,float val)
{
    if(ringq_is_full(p_que))
    {
        printf("The queue is full.\n");
        return -1;
    }

    p_que->queue[p_que->tail++] = val;
    p_que->tail %= p_que->size;
    if(p_que->tail == p_que->head)
    {
        p_que->tag = 1;
    }

    return p_que->tag;
}

/**
 * @brief 获取队列数据
 * 
 * @param p_que 读取的队列
 * @param dat 读取目的地址
 * @return uint8_t 队列满标志位
 */
uint8_t ringq_read(ringq_t *p_que,float *dat)
{
    if(ringq_is_empty(p_que))
    {
        printf("The queue is empty.\n");
        return -1;
    }

    *dat = p_que->queue[p_que->head++];
    p_que->head %= p_que->size;
    if(p_que->head == p_que->tail)
    {
        p_que->tag = 0;
    }
    return p_que->tag;
}
