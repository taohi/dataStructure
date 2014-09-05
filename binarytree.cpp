#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <queue>
#include <stack>
using namespace::std;

//二叉树的结点结构体
typedef struct tNode{
    int data;
    struct tNode *lchild;
    struct tNode *rchild;
}treeNode;

//二叉树的先序遍历,递归方法
void preOrderTraverse(treeNode *T)
{
    if(!T)
        return;
    printf("%d\t",T->data);
    preOrderTraverse(T->lchild);
    preOrderTraverse(T->rchild);
}

//二叉树的中序遍历,递归方法
void inOrderTraverse(treeNode * T)
{
    if(!T)
        return;
    inOrderTraverse(T->lchild);
    printf("%d\t",T->data);
    inOrderTraverse(T->rchild);
}

//二叉树的后序遍历,递归方法
void postOrderTraverse(treeNode * T)
{
    if(!T)
        return;
    postOrderTraverse(T->lchild);
    postOrderTraverse(T->rchild);
    printf("%d\t",T->data);
}

//二叉树的先序遍历,栈方法
void preOrderStack(treeNode *T)
{
    if(!T) 
        return;
    stack<treeNode *> s;
    s.push(T);
    while(!s.empty())
    {
        treeNode *p=s.top();
        s.pop();
        printf("%d\t",p->data);
        if(p->rchild)
            s.push(p->rchild);
        if(p->lchild)
            s.push(p->lchild);
    }
}

//二叉树的中序遍历,栈方法
void inOrderStack(treeNode *T)
{
    treeNode *p=T;
    stack<treeNode *> s;
    if(!p)
        return;
    while(!s.empty()||p!=NULL)
    {
        while(p!=NULL)
        {
            s.push(p);
            p=p->lchild;
        }
        if(!s.empty())
        {
            p=s.top();
            s.pop();
            printf("%d\t",p->data);
            p=p->rchild;
        }
    }
}

//二叉树后序遍历,栈方法
void postOrderStack(treeNode *T)
{
    treeNode *cur=NULL;
    treeNode *pre=NULL;
    stack<treeNode *> s;
    if(!T)
        return;
    s.push(T);
    while(!s.empty())
    {
        cur=s.top();
        if((cur->lchild==NULL && cur->rchild==NULL)||(pre!=NULL &&(pre==cur->lchild||pre==cur->rchild)))
        {
            printf("%d\t",cur->data);
            s.pop();
            pre=cur;
        }
        else
        {
            if(cur->rchild!=NULL)
                s.push(cur->rchild);
            if(cur->lchild!=NULL)
                s.push(cur->lchild);
        }
    }
}

//二叉树层序遍历,队列方法,空间O(n)
void levelOrderTraverse(treeNode *T) 
{
     queue<treeNode *>nodeQueue;
     if(!T) return;
     nodeQueue.push(T);
     while(!nodeQueue.empty())
     {
         treeNode *pHead=nodeQueue.front();
         printf("%d\t",pHead->data);
         nodeQueue.pop();
         if(pHead->lchild)
             nodeQueue.push(pHead->lchild);
         if(pHead->rchild)
             nodeQueue.push(pHead->rchild);
     }
}

/*
//二叉树层序遍历，空间O(h)，h为树的高度
void levelOrderTraverse2(treeNode *T)
{
    int depth=treeDepth(T);
    int cur_depth=1;
    if(!T) return;
    for(cur_depth=1;cur_depth<depth;cur_depth++)
    {
        
    }
}

*/


//按值x大小插入，构建二叉排序树BST
void insertBST(treeNode ** pT,int x)
{
    treeNode *p=(treeNode *)malloc(sizeof(treeNode));
    if(!p)
    {
        printf("malloc error.");
        exit(0);
    }
    p->data=x;
    p->lchild=NULL;
    p->rchild=NULL;
    if(*pT == NULL)
    {
        *pT=p;
        return ;
    }
    if(x<(*pT)->data)
        insertBST(&((*pT)->lchild),x);
    else
        insertBST(&((*pT)->rchild),x);
}

//判断给出的树是不是二叉排序树
bool isBST(treeNode *T,int low,int high)
{
    if(!T)
        return true;
    if(low < T->data && T->data <high)
        return isBST(T->lchild,low,T->data) && isBST(T->rchild,T->data,high);
    else
        return false;
}

//Binary Sorted Tree:二叉排序树
//判断值x是否在给定的二叉排序树中。
int searchBST(treeNode *T,int x)
{
    if(T==NULL) 
        return 0;
    else if(T->data == x)
        return 1;
    else if(x < T->data)
        return searchBST(T->lchild,x);
    else
        return searchBST(T->rchild,x);
}

//释放掉整个二叉树
void freeTree(treeNode **pT)
{
    if(*pT != NULL)
    {
        freeTree(&((*pT)->lchild));
        freeTree(&((*pT)->rchild));
        free(*pT);
        *pT=NULL;
    }
    return;
}

//统计二叉树的叶结点,递归方法
int countLeaf(treeNode *T)
{
    int counter=0;
    if(!T)
        return 0;
    if((T->lchild==NULL) && (T->rchild==NULL))
        return 1;
    counter+= countLeaf(T->lchild);
    counter+= countLeaf(T->rchild);
    return counter;
}

//计算二叉树的深度,递归方法
int treeDepth(treeNode *T)
{
    int ldepth=0;
    int rdepth=0;
    if(!T)
        return 0;
    ldepth=treeDepth(T->lchild);
    rdepth=treeDepth(T->rchild);
    if(ldepth>rdepth)
        return ldepth+1;
    else 
        return rdepth+1;
}

int main()
{
    int n[10] = {3,2,4,1,7,6,5,8,10,9};
    int i=0,find_key=8;
    treeNode *T=NULL;
    //构建平衡二叉排序树，依次插入数组元素
    while(i<10)
    {
        insertBST(&T,n[i]);
        i++;
    }
    printf("PreOrder(Recursive):\t"); preOrderTraverse(T); printf("\n");
    printf("PreOrder(Stack):\t"); preOrderStack(T); printf("\n");
    printf("InOrder(Recursive):\t"); inOrderTraverse(T); printf("\n");
    printf("InOrder(Stack):\t\t"); inOrderStack(T); printf("\n");
    printf("PostOrder(Recursive):\t"); postOrderTraverse(T); printf("\n");
    printf("PostOrder(Stack):\t"); postOrderStack(T); printf("\n");
    printf("LevelOrder(Queue):\t"); levelOrderTraverse(T); printf("\n");
    printf("tree depth(Recursive):\t%d\n",treeDepth(T));
    printf("tree leaves(Recursive):\t%d\n",countLeaf(T));
    printf("tree is %s BST.\n",isBST(T,INT_MIN,INT_MAX)?"":"not");
    printf("%d is %s in BST tree.\n",find_key,searchBST(T,find_key)?"":"not");
    freeTree(&T);
    return 0;
}
