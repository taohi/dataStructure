#include <stdio.h>
#include <stdlib.h>
//二叉树的结点结构体
typedef struct tNode{
    int data;
    struct tNode *lchild;
    struct tNode *rchild;
}treeNode;

/*
*以下函数中，涉及修改二叉树，用二级指针；
*涉及统计、查找的，用一级指针就行。
*这是函数传参特性,实参形参不同。
*/

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

//统计二叉树的叶结点递归方法
int countLeaf(treeNode *T)
{
    int counter=0;
    if(T!=NULL)
    {
        counter+= countLeaf(T->lchild);
        counter+= countLeaf(T->rchild);
        if((T->lchild==NULL) && (T->rchild==NULL))
            counter++;
    }
        return counter;
}

//计算二叉树的深度递归方法
int treeDepth(treeNode *T)
{
    int ldepth=0;
    int rdepth=0;
    if(!T)
        return 0;
    else
    {
        ldepth=treeDepth(T->lchild);
        rdepth=treeDepth(T->rchild);
    }
    if(ldepth>rdepth)
        return ldepth+1;
    else 
        return rdepth+1;
}

void main()
{
    int n[10] = {3,2,4,1,7,6,5,8,10,9};
    int i=0,find_key=1;
    treeNode *T=NULL;
    //构建二叉排序树，依次插入数组元素
    while(i<10)
    {
        insertBST(&T,n[i]);
        i++;
    }
    printf("PreOrder:\t"); PreOrderTraverse(T); printf("\n");
    printf("InOrder:\t"); InOrderTraverse(T); printf("\n");
    printf("PostOrder:\t"); PostOrderTraverse(T); printf("\n");
    printf("tree depth:%d\n",treeDepth(T));
    printf("tree leaves:%d\n",countLeaf(T));
    printf("%d is %s in BST tree.\n",find_key,searchBST(T,find_key)?"":"not");
    freeTree(&T);
}
