/**
 * @file ringq.h
 * @brief 环形队列
 * @date 2024/06/14
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef __RINGQ_H__
#define __RINGQ_H__
#include <stdint.h>

struct ringq
{
    // 头部，写入(入队)方向
    int head;
    // 尾部，读取(出队)方向
    int tail;
    // 标志位，1:满、0:空
    int tag;
    // 队列总大小
    int size;
    // 队列
    float *queue;
};
typedef struct ringq ringq_t;

// 队里已满
#define ringq_is_empty(q) ( (q->head == q->tail) && (q->tag == 0))
// 队列为空
#define ringq_is_full(q) ( (q->head == q->tail) && (q->tag == 1))


/**
 * @brief Construct a new ringq init object
 */
uint8_t ringq_init(ringq_t *p_que,int size);

/**
 * @brief 释放队列
 */
uint8_t ringq_free(ringq_t *p_que);

/**
 * @brief 写队列
 */
uint8_t ringq_write(ringq_t *p_que,float val);

/**
 * @brief 获取队列数据
 */
uint8_t ringq_read(ringq_t *p_que,float *dat);


#endif
