/*C语言利用链表数据结构，实现队列的接口
 * 头文件名：queue.h
 */
#ifndef QUEUE_H
#define QUEUE_H

typedef int QElemType;
typedef struct node{
    QElemType data;
    struct node *next;
}node;

typedef struct{
    node *front,*rear;
    int size;
}queue;

queue *InitQueue();
void DestroyQueue(queue *pHead);
void ClearQueue(queue *pHead);
int QueueEmpty(queue *pHead);
node *GetHead(queue *pHead);
node *GetGear(queue *pHead);
node *EnQueue(queue *pHead,QElemType e);
node *DeQueue(queue *pHead,QElemType *pe);
int QueueSize(queue *pHead);


#endif    
