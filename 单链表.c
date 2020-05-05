#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ERROR 0;
#define OK 1;

typedef int Status;
typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node* next;
}Node;

typedef struct  Node* LinkList;

Status InitList(LinkList *L)
/*初始化带头节点的的空链表*/
{
    *L = (LinkList)malloc(sizeof(Node));
    if(!(*L))
    {
        return ERROR;
    }
    (*L) -> next = NULL;
    return OK;
}

void CreateListHead(LinkList *L, int n)
/*头插法创建单链表*/
{
    LinkList p;
    int i;
    srand(time(0));
    for( i=0; i < n; i++ )
    {
        p = (LinkList)malloc(sizeof(Node));
        p -> data = rand()%100 + 1;
        p -> next = (*L) -> next;
        (*L) -> next = p;
    }
}

Status ListLength(LinkList L)
/*链表长度*/
{
    int i = 0;
    LinkList p = L -> next;
    while(p)
    {
        i++;
        p = p -> next;
    }
    return i;
}

Status ClearList(LinkList *L)
/*清除单链表，释放内存*/
{
    LinkList p, q;
    p = (*L) -> next;
    while(p)
    {
        q = p -> next;
        free(p);
        p = q;
    }
    (*L) -> next = NULL;
    return OK;
} 

Status GetElem( LinkList L, int i,ElemType *e)
/*获取元素*/
{
    int j;
    LinkList p;
    p = L -> next;
    j = 1;
    while(p && j<i)
    {
        p = p -> next;
        ++j;
    }
    if(!p || j >i || i > ListLength(L))
    {
        return ERROR;
    }
    *e = p -> data;
    return 0;
}

Status GetList(LinkList L)
/*获得单链表全体成员*/
{
    int i = 1;
    int m;
    LinkList p;
    p = L ->next;
    while (p && i < ListLength(L))
    {
        m = p ->  data;
        printf("%d\t",m);
        p = p -> next;
    }
    
}

Status ListDelete(LinkList *L, int i)
/*删除元素*/
{
    int j;
    LinkList p,q;
    p = *L;
    j = 1;
    while(p -> next && j<i)
    {
        p = p -> next;
        ++j;
    }
    if (!(p -> next) || j>i || i > ListLength(*L))
    {
        return ERROR;
    }
    q = p -> next;
    p -> next = q -> next;
    free(q);
    GetList(*L);
    return OK;
}

Status Lisinsert(LinkList *L, int i, ElemType e)
/*插入元素*/
{
    int j;
    LinkList p,q;
    p = *L;
    j = 1;
    while (p && j < i)
    {
        p = p -> next;
        ++j;
    }
    if (!p || j > i || i > (ListLength(*L) + 1))
    {
        return ERROR;
    }
    q = (LinkList)malloc(sizeof(Node));
    q ->data = e;
    q ->next = p -> next;
    p -> next = q;
    GetList(*L);
    return OK;
}

int main()
{
    LinkList L;
    Status n,m;
    char opp;
    ElemType *e;
    
    *e = (int*)malloc(sizeof(int));
    InitList(&L);
    printf("初始化L后：ListLength(L) = %d\n", ListLength(L));
    printf("\n1.创建单链表(头插法)  \n2.单链表长度  \n3.获取第几位链表元素  \n4.清空链表  \n5.获得单链表 \n");
    printf("6.删除元素 \n7.插入元素\n0.推出\n\n");
    scanf("%c",&opp);
    while(opp != '0')
    {  
        switch (opp)
        {
        case '1':
            printf("你要创建几位链表？\n");
            scanf("%d",&m);
            CreateListHead(&L,m);
            printf("成功创建单链表\n");
            printf("\n\n");
            break;
        case '2':
            printf("链表长度为 = %d。\n", ListLength(L));
            printf("\n\n");
            break;
        case '3':
            printf("请问获取第几个元素？\n");
            scanf("%d", &n);
            GetElem(L,n, e);
            printf("链表第%d位是元素：%d\n",n,*e);
            printf("\n\n");
            break;
        case '4':
            ClearList(&L);
            printf("链表以清空\n");
            printf("\n\n");
            break;
        case '5':
            GetList(L);
            printf("\n\n\n");
            break;
        case '6':
            printf("小姐姐，你要删除第几为元素？\n");
            scanf("%d",&n);
            ListDelete(&L, n);
            printf("\n\n");
            break;
        case '7':
            printf("小姐姐，你要在第几位插入元素呢？\n");
            scanf("%d",&n);
            printf("小姐姐，你要插入什么元素呢？\n");
            scanf("%d",&m);
            Lisinsert(&L, n, m);
            printf("\n\n");
            break;
        case '0':
            free(e);
            exit(0);
        }
        scanf("%c",&opp);
    }
}

