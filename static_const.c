#include <stdio.h>
static int a[3];
const int b=2; 
void main()
{
    static int c;
    int i=0;
    while(i<3)
    {
        printf("global static a[%d]=%d\n",i,a[i]);
        i++;
    }
    printf("local static c=%d\n",c);
    const int d=1;
    //局部const变量a分配在栈上，栈可以通过地址读写，所以
    //可以通过地址修改a的值
    int *pd= (int *)&d;
    *pd=31;
    printf("local const d=%d\n",d);
    int *pb = (int *)&b;
    *pb=20;//报段错误，因为全局const常量b分配在.rodata区，是只读的。
}
