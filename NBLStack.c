#include<stdio.h>
#include<stdlib.h>

#define ERROR 0;
#define OK 1;

typedef int ElemType;
typedef int Status;
typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPrt;
typedef struct Stack
{
    LinkStackPrt top;
    int count;
}Stack,  *LinkStack;
void InitStack(LinkStack *s)
{
    (*s) = (LinkStack)malloc(sizeof(LinkStack));
    (*s)->count = 0;
    (*s)->top = NULL;
    return OK;
}

Status Push(LinkStack *s, ElemType e)
{
    LinkStackPrt p =(LinkStackPrt)malloc(sizeof(StackNode));
    p->data = e;
    p->next = (*s)->top;
    (*s)->top = p;
    (*s)->count++;
    return OK;
}

Status Pop(LinkStack *s)
{
    LinkStackPrt p;
    if(StackEmpty(&s))
    {
        return ERROR;
    }
    p = (*s)->top;
    (*s)->top = (*s)->top->next;
    free(p);
    (*s)->count--;
    return OK;
}

void StackEmpty(LinkStack *s)
{
    return (*s)->count ==0;
}

Status StackLen(LinkStack *s)
{
    int e;
    e = (*s)->count;
    return e;
}

int main()
{
    LinkStack *s;
    int e,n,m,i;
    char j;
    InitStack(&s);
    printf("Do you want to build a Stack?(Y/N)\n");
    scanf("%c",&j);
    if(j == 'Y')
    {
        printf("How many do you wanna build?\n");
        printf("Please give me a number!\n");
        printf("Thanks!!!\n");
        scanf("%d",&n);
        for(i = 0; i < n; i++)
        {
            scanf("%d",&e);
            Push(&s,e);
        }
    }

    printf("1.Delete ElemType.\n2.Get StackLen\n3.Exit!\n");
    scanf("%d",&m);
    while(m != 3)
    {
        switch(m)
        {
            case 1:
                printf("How many do you want to delete?\n");
                scanf("%d",&n);
                for(i=0;i<n;i++)
                {
                    Pop(&s);
                }
                break;
            case 2:
                e = StackLen(&s);                                 //还是不理解为什么建函数是要改数据的时候用指针不要改的时候不用  
                                                                  //不用的时候为什么也能调用原结构，用的使用后也能调用原结构？
                printf("The StackLen is %d\n", e);                //神之错误，又是无缘无故会崩的程序！！！待解决！！
                break;
            case 3:
                exit(0);
        }
        scanf("%d",&m);
    }
    return 0;
}
