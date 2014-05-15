#include <stdio.h>
#include <stdlib.h>
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

//O(n**2) Not Stable
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

//归并排序，递归版本
//O(nlogn) Stable. spare space  O(n+logn)
void merge(int *array,int left,int m,int right)
{
    int i,j,k=0,l;
    //merged动态临时数组,将有序的array[left...m]和有序的array[m+1...right]
    //归并成新的有序数组存放到merged中
    int *merged=(int *)malloc(sizeof(int)*(right+1));
    for(i=left,j=m+1;i<=m && j<=right;k++)
    {
        if(array[i]<=array[j])
            merged[k]=array[i++];
        else
            merged[k]=array[j++];
    }
    //如果比较完后，前半部分还有剩的，直接接到merged后面
    if(i<=m)
    {
        for(;i<=m;k++)
            merged[k]=array[i++];
    }
    //如果比较完后，后半部分还有剩的，直接接到merged后面
    if(j<=right)
    {
        for(;j<=right;k++)
            merged[k]=array[j++];
    }
    //将有序的merged拷贝到原始array[left...right]
    for(l=left,k=0;l<=right;l++)
        array[l]=merged[k++];
    free(merged);
}

void merge_sort(int *a,int left,int right)
{
    int i=0;
    if(left<right) 
    {
        i=(left + right)/2;
        merge_sort(a,left,i);
        merge_sort(a,i+1,right);
        merge(a,left,i,right);
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
    int a8[]={13,0,5,8,1,7,21,50,9,2};
    bubble_sort(a1,10);     print(a1,10);
    select_sort(a2,10);     print(a2,10);
    quick_sort(a3,0,9);     print(a3,10);
    insertion_sort(a4,10);  print(a4,10);
    shell_insert_sort(a5,10);print(a5,10);
    heap_sort(a6,10);       print(a6,10);
    merge_sort(a7,0,9);     print(a7,10);

    //如果排序前要手动获得数组长度，用sizeof：
    //printf("Array a1 length =%d\n",sizeof(a1)/sizeof(int));
}
