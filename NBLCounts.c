// 逆波兰表达式：
// a + b ---->a b +
// a + ( b - c ) -----> a b c - +
// a + ( b - c ) -----> a b c - +
// a + （ b - c ）* d ----> a b c - d * +
// a + d*( b - c) ----> a d b c - * +

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define ERROR 0;
#define OK 1;
#define STACK_INIT_SIZE 20
#define STACKINCREMENT  10
#define MAXBUFFER       10

typedef  double ElemType;
typedef int Status;
typedef  struct
{
    ElemType *base;
    ElemType *top;
    int stackSize;
}sqStack;

void InitStack(sqStack *s)
{
    s -> base = (ElemType*)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if( !s -> base)
    {
        exit(0);
    }
    s -> top = s -> base;
    s -> stackSize = STACK_INIT_SIZE;
}

void Push(sqStack *s, ElemType e)
{
    if(s -> top - s -> base >= s -> stackSize)
    {
        s -> base = (ElemType *)realloc(s->base, (s -> stackSize + STACKINCREMENT) * sizeof(ElemType));
        if(!s->base)
        {
            exit(0);
        }
        s->top = s->base + s->stackSize;
        s->stackSize = s->stackSize = STACKINCREMENT;
    }
    *(s -> top) = e;
    (s -> top)++;
}

void Pop(sqStack *s, ElemType *e)
{
    if( s->top == s->base)
    {
        return 0;
    }
    *e = *--(s->top);
}

Status StackLen(sqStack s)
{
    return(s.top - s.base);
}

int  main()
{
    sqStack s;
    int i = 0;
    char c;
    double d,e;
    char str[MAXBUFFER];

    InitStack(&s);

    printf("请按逆波兰表达式输入带计算数据，数据与运算符之间用空隔开，以#作为结束标志：");
    scanf("%c", &c);
    while(c != '#')
    {
        while(isdigit(c) || c == '.')     // 用于过滤数字
        {
            str[i++] = c;
            str[i]= '\0';
            if( i >= 10)
            {
                printf("出错：输入的但个数据过大！\n");
                return -1;
            }
            scanf("%c", &c);
            if(c == ' ')
            {
                d = atof(str);     // 将字符串转换为浮点数
                Push(&s, d);
                i = 0;
                break;             // 跳出循环
            }
        }

        switch(c)
        {
            case '+':
              Pop(&s, &e);
              Pop(&s, &d);
              Push(&s, d+e);
              break;
            case '-':
              Pop(&s, &e);
              Pop(&s, &d);
              Push(&s, d-e);
              break;
            case '*':
              Pop(&s, &e);
              Pop(&s, &d);
              Push(&s, d*e);
              break;
            case '/':
              Pop(&s, &e);
              Pop(&s, &d);
              if( e != 0)
              {
                  Push(&s, d/e);
              }
              else
              {
                  printf("\n出错：除数为零！\n");
                  return -1;
              }
              break;
        }
        scanf("%c", &c);
    }
    Pop(&s, &d);
    printf("\n最终的计算结果为：%f\n", d);

    return 0;
}
