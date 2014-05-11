/*C语言利用链表数据结构，实现队列的接口
 * 文件名：queue.c
 */
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue *InitQueue()
{
    queue *pqueue=(queue *)malloc(sizeof(queue));
    pqueue->front=NULL;
    pqueue->rear=NULL;
    pqueue->size=0;
    return pqueue;
}

node *EnQueue(queue *pqueue,QElemType e)
{
    node *pNode=(node *)malloc(sizeof(node));
    if(!pNode)
        exit(0);
    pNode->data = e;
    pNode->next=NULL;
    if(QueueEmpty(pqueue))
        pqueue->front=pNode;
    else
        pqueue->rear->next = pNode;
    pqueue->rear = pNode;
    pqueue->size++;
    return pNode;
}


node *DeQueue(queue *pqueue,QElemType *pe)
{
    if(QueueEmpty(pqueue))
        return NULL;
    else
    {
        node *pNode = pqueue->front;
        if(pe)
            *pe=pNode->data;
        pqueue->size--;
        pqueue->front = pNode->next;
        if(pqueue->size == 0)
            pqueue->rear=NULL;
        free(pNode);
        return pqueue->front;
    }
}

int QueueEmpty(queue *pqueue)
{
    if(pqueue->front==NULL && pqueue->rear == NULL && pqueue->size ==0)
        return 1;
    else
        return 0;
}


