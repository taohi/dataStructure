#include <stdio.h>
void main()
{
    int a[10];
    int *p=a;
    printf("数组a的长度:%d\n",sizeof a/sizeof a[0]);
    printf("size_t的大小:%d\n",sizeof(size_t));
    printf("指针p的大小:%d\n",sizeof(p));
    printf("hello字符串的大小(包含'\\0'):%d\n",sizeof("hello"));
}
