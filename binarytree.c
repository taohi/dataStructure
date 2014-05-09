#include <stdio.h>
#include <stdlib.h>
//二叉树的结点结构体
typedef struct tNode{
    int data;
    struct tNode *lchild;
    struct tNode *rchild;
}treeNode;

//二叉树的先序遍历递归方法
void PreOrderTraverse(treeNode *T)
{
    if(!T)
        return;
    printf("%d\t",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

//二叉树的中序遍历递归方法
void InOrderTraverse(treeNode * T)
{
    if(!T)
        return;
    InOrderTraverse(T->lchild);
    printf("%d\t",T->data);
    InOrderTraverse(T->rchild);
}

//二叉树的后序遍历递归方法
void PostOrderTraverse(treeNode * T)
{
    if(!T)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%d\t",T->data);
}

//二叉树的插入，按值x大小选择合适的位置插入新结点
void insertTree(treeNode ** pT,int x)
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
        insertTree(&((*pT)->lchild),x);
    else
        insertTree(&((*pT)->rchild),x);
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

void main()
{
    int n[10] = {3,2,4,1,7,6,5,8,10,9};
    int i=0;
    treeNode *T=NULL;
    //构建二叉排序树，依次插入数组元素
    while(i<10)
    {
        insertTree(&T,n[i]);
        i++;
    }
    printf("PreOrder:\t"); PreOrderTraverse(T); printf("\n");
    printf("InOrder:\t"); InOrderTraverse(T); printf("\n");
    printf("PostOrder:\t"); PostOrderTraverse(T); printf("\n");
    freeTree(&T);
}
