//线索二叉树的代码实现：
 #include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
 //线索存储标志为
 //Link（0）表示指向左右孩子的指针
 //Thread（1）表示指向前驱的线索
typedef enum{Link, Thread} Pointertag;
typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
    Pointertag ltag;
    Pointertag rtag;
}BiTNode, *BiTree;

//全局变量，始终指向刚刚访问过的结点
BiTree pre;

//创建一棵二叉树，约定用户遵循前序遍历的方式输入数据
int CreateBiTree(BiTree *T)
{
    char c;
    scanf("%c",&c);
    if(' ' == c)
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        (*T)->data = c;
        (*T)->ltag = Link;
        (*T)->rtag = Link;

        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

//中序遍历线素化
void InThreading(BiTree T)
{
    if(T)
    {
        InThreading(T->lchild);    // 递归做孩子线索化
       if(!T->lchild)              //如果该节点没有左孩子，设置ltag为Thread，并把lchild指向前驱（刚刚访问的节点）
       {
        T->ltag = Thread;
        T->lchild = pre;
       } 
       if(!pre->rchild)
       {
           pre->rtag = Thread;
           pre->rchild = T;
       }

       pre = T;
       InThreading(T->rchild);    //递归右孩子线索化
    }
}

int InOrderThreading(BiTree *p,BiTree T )
{
    *p =(BiTree) malloc(sizeof(BiTNode));
    (*p)->ltag = Link;
    (*p)->rtag = Thread;
    (*p)->rchild = *p;
    if(!T)
    {
        (*p)->lchild = *p;
    }
    else
    {
        (*p)->lchild = *p;
        pre = *p;
        InThreading(T);
        pre->rchild = *p;
        pre->rtag = Thread;
        (*p)->rchild = pre;
    }
}

void visit(char c)
{
    printf("%c", c);
}

//中序遍历二叉树，非递归
void InOrderThraverse(BiTree T)
{
    BiTree p;
    p = T->lchild;

    while( p != T)
    {
        while(p->ltag == Link)
        {
            p = p->lchild;
        }
        visit(p->data);

        while(p->rtag == Thread && p->lchild != T)
        {
            p = p->lchild;
            visit(p->data);
        }

        p = p->rchild;
    }
}

int main()
{
    BiTree P, T = NULL;
    CreateBiTree( &T );
    InOrderThreading(&P, T);
    printf("中序遍历输出结果为：\n");
    InOrderThraverse( P );
}
