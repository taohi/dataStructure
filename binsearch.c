#include <stdio.h>
int binsearch(int x,int v[],int n)
{
    int low,high,mid;
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(x < v[mid])
            high=mid-1;
        else if(x>v[mid])
            low=mid +1;
        else return mid;
    }
    return -1;
}

void main()
{
    int num[10]={1,2,4,6,7,9,12,15,17,20};
    printf("4 is in pos:%d of num.\n",binsearch(4,num,10));
}
