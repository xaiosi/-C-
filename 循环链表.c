#include <time.h>
#include <stdio.h>
#include <string.h>

#define ERROR 0;
#define OK 1;

typedef int ElemType;
typedef int Status;

typedef struct Node
{
    ElemType data;
    struct Node* next;

}Node;

typedef struct Node* RLinkList;

void InitRLinkList(RLinkList *RL)
/*初始化链表头节点*/
{
    *RL = (RLinkList)malloc(sizeof(Node));
    if(!(*RL)) 
    {
        return ERROR;
    }
    (*RL) -> next = NULL;
    return OK;
}

void CreateRLinkList(RLinkList *RL, int n)
/*创建随机循环链表*/
{
    RLinkList p,q;
    int i;
    srand(time(0));
    p = *RL;
    for( i=0; i<n; i++)
    {
        q = (RLinkList)malloc(sizeof(Node));
        q -> data = rand()%100 + 1;
        q -> next = p -> next;
        p -> next = q;
        p = q;
    }
    p -> next = (*RL) -> next;
    return OK;
}

Status GetReList(RLinkList *RL)
{
    RLinkList p;
    int m;
    p = (*RL) -> next;
    do
    {
        m = p ->data;
        printf("%d\t", m);
        p = p ->next;
    } while (p != (*RL) -> next); 
}

int main()
{
    RLinkList RL;
    int n,c;
    char j;

    InitRLinkList(&RL);
    printf("请输入你有要创建几位元素的链表?\n");
    scanf("%d", &n);
    CreateRLinkList(&RL, n);
    printf("您要获得链表元素吗?请输入(Y/N)!\n");
    while((c = getchar()) != '\n' && c != EOF);
    scanf("%c",&j);
    if(j == 'Y')
    {
        GetReList(&RL);
        printf("\n");
    }
    return 0;
}
