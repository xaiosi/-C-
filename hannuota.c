//汉诺塔（迭代）
//先将前63个盘子移动到Y上，确保大盘在小盘的下面
//在降低下的第64个盘子移动到z上
//最后在将y上的第63个盘子移动到z上
#include <stdio.h>
#include <stdlib.h>
void move(int n, char x, char y, char z)
{
    if( 1 == n)
    {
        printf("%c --> %c\n",x, z);
    }
    else
    {
        move(n-1, x, z ,y);          //将 n-1 个盘子从x借助z移动到y上
        printf("%c --> %c\n", x, z);  //将第 n 个盘子从x移动到z上
        move(n-1, y, x, z);          //将 n-1 个盘子从y借助x移动到z上
    }
}

int main()
{
    int n;
    printf("Please input the number of the HNT's floors!\n");
    scanf("%d", &n);
    printf("移动的步骤如下：\n");
    move(n, 'X', 'Y', 'Z');

    return 0;
}

