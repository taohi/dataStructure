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
void DestroyQueue(queue *pqueue);
void ClearQueue(queue *pqueue);
int QueueEmpty(queue *pqueue);
node *GetHead(queue *pqueue);
node *GetGear(queue *pqueue);
node *EnQueue(queue *pqueue,QElemType e);
node *DeQueue(queue *pqueue,QElemType *pe);
int QueueSize(queue *pqueue);


#endif    
