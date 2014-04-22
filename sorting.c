#include <stdio.h>
void swap(int *a,int i,int j)
{
    int temp;
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

//O(n**2) Stable
void bubble_sort(int *a,int n)
{
    int i,j,temp;
    for (i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
            if(a[i]>a[j])
                swap(a,i,j);
    }
}

//O(n**2) Stable
//和冒泡类似，只是减少了盲目交换的次数。
void select_sort(int *a,int n)
{
    int i,j,k,temp;
    for(i=0;i<n-1;i++)
    {
        k=i;
        for(j=i+1;j<n;j++)
            if(a[k]>a[j])
                k=j;
        if(i!=k)
            swap(a,i,k);
    }
}

//O(nlogn) Not stable
void quick_sort(int *a,int left,int right)
{
    int last=left;
    int i;
    if(left>=right)
        return ;
    swap(a,left,(left+right)/2);
    for(i=left+1;i<=right;i++)
        if(a[i]<a[left])
            swap(a,++last,i);
    swap(a,left,last);
    quick_sort(a,left,last-1);
    quick_sort(a,last+1,right);
}

/*
 *This is the simplest,but not best edition.
void insertion_sort(int *a,int n)
{
    int i,j;
    for(i=1;i<n;i++)
    {
        j=i;
        while(j>0 &&a[j-1]>a[j])
        {
            swap(a,j-1,j); 
            j-=1;
        }
    }
}
*/

//O(n**2) Stable
void insertion_sort(int *a,int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && temp<a[j])
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = temp; 
    }
}

//O(nlogn) Not stable
void shell_insert_sort(int *a,int n)
{
    int gap,i,j,temp;
    for(gap=n/2;gap>0;gap/=2)
        for(i=gap;i<n;i++)
            for(j=i-gap;j>=0 && a[j]>a[j+gap];j-=gap)
                swap(a,j,j+gap);
}

//O(nlogn) Not stable. O(1) spare space.
void heap_adjust(int *a,int i,int n)
{
    int child,temp;
    for(temp=a[i];2*i+1 < n;i=child)
    {
        child = 2*i +1;
        if(child!=n-1 && a[child+1]>a[child])
            ++child;
        if(temp >= a[child])
            break;
        a[i]=a[child];
    }
    a[i]=temp;
}
void heap_sort(int *a,int n)
{
    int i;
    for(i=n/2 -1;i>=0;i--)
        heap_adjust(a,i,n);
    for(i=n-1;i>0;i--)
    {
        swap(a,0,i);
        heap_adjust(a,0,i);
    }
}

void print(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%5d",a[i]);
    printf("\n");
}

void main()
{
    int a1[]={13,0,5,8,1,7,21,50,9,2};
    int a2[]={13,0,5,8,1,7,21,50,9,2};
    int a3[]={13,0,5,8,1,7,21,50,9,2};
    int a4[]={13,0,5,8,1,7,21,50,9,2};
    int a5[]={13,0,5,8,1,7,21,50,9,2};
    int a6[]={13,0,5,8,1,7,21,50,9,2};
    int a7[]={13,0,5,8,1,7,21,50,9,2};
    bubble_sort(a1,10);     print(a1,10);
    select_sort(a2,10);     print(a2,10);
    quick_sort(a3,0,9);     print(a3,10);
    insertion_sort(a4,10);  print(a4,10);
    shell_insert_sort(a5,10);print(a5,10);
    heap_sort(a6,10);       print(a6,10);

}
