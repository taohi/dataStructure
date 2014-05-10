/*C语言利用链表数据结构，实现队列的接口
 * 文件名：queue.c
 */
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue *InitQueue()
{
    queue *pHead=(queue *)malloc(sizeof(queue));
    if(!pHead)
        exit(0);
    pHead->front=pHead;
    pHead->rear=pHead;
    pHead->size=0;
    return pHead;
}

QNode *EnQueue(queue *pHead,QElemType e)
{
    node *pNode=(node *)malloc(sizeof(node));
    if(!pNode)
        exit(0);
    pNode->data = e;
    pNode->next=NULL;
    if(QueueEmpty(pHead))
    {
        pHead->front=pNode;
        pHead->rear =pNode;
    }
    else
        pHead->rear->next = pNode;
    pqueue->rear = pQNode;
    pqueue->size++;
    return 

}
