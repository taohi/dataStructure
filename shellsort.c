#include <stdio.h>
void shellsort(int v[],int n)
{
    int gap,i,j,temp;
    for(gap = n/2;gap>0;gap/=2)
        for(i=gap;i<n;i++)
            for(j=i-gap;j>=0 &&v[j]>v[j+gap];j-=gap)
            {
                temp=v[j];
                v[j]=v[j+gap];
                v[j+gap]=temp;
            }
}

void main()
{
    int i;
    int num[]={1,3,6,2,8,4,9,0,7,12,16};
    for(i=0;i<11;i++)
    {
        printf("%d\t",num[i]);
    }
    printf("\n");
    shellsort(num,11);
    for(i=0;i<11;i++)
    {
        printf("%d\t",num[i]);
    }
    printf("\n");
}

