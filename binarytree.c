#include <stdio.h>
//二叉树的结点结构体
typedef struct treeNode
{
    int data;
    struct treeNode *lchild;
    struct treeNode *rchild;
}treeNode,*ptreeNode;

//二叉树的先序遍历递归方法
void PreOrderTraverse(ptreeNode T)
{
    if(!T)
        return;
    printf("%d\t",T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

//二叉树的中序遍历递归方法
void InOrderTraverse(ptreeNode T)
{
    if(!T)
        return;
    InOrderTraverse(T->lchild);
    printf("%d\t",T->data);
    InOrderTraverse(T->rchild);
}

//二叉树的后序遍历递归方法
void PostOrderTraverse(ptreeNode T)
{
    if(!T)
        return;
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%d\t",T->data);
}
