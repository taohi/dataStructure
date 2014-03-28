#include <stdio.h>

void swap(int v[],int i,int j)
{
    int temp;
    temp = v[i];
    v[i]=v[j];
    v[j]=temp;
}

void qsort(int v[],int left,int right)
{
    int i,last;
    if(left >=right)
        return;
    swap(v,left,(left+right)/2);
    last=left;
    for(i = left+1;i <=right;i++)
        if(v[i]<v[left])
            swap(v,++last,i);
    swap(v,left,last);
//    i=0;
//    while(i<=right)
//        printf("%d\t",v[i++]);
//    printf("\n");
    qsort(v,left,last-1);
    qsort(v,last+1,right);
}

int main()
{
    int i=0;
    int num[]={3,1,2,6,8,12,11,28,45};
    qsort(num,0,8);
    while(i<9)
        printf("%d\t",num[i++]);
    printf("\n");

}
