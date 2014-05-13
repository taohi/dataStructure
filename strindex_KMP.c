#include <stdio.h>
#include <string.h>
//朴素子串查找：返回子串T在母串S中第pos个字符之后首次出现的位置。
//若不存在，则函数返回0 时间复杂度O((n-m+1)*m),空间复杂度O(1)
int index(char s[],char t[],int pos)
{
    int i=pos,j=0;
    int n=strlen(s);
    int m=strlen(t);
    while(i<n && j<m)
    {
        if(s[i]==t[j])
        {
            i++;
            j++;
        }
        else
        {
            i=i-j+1;
            j=0;
        }
    }
    if(j=m)//t的每个字符都匹配完,说明匹配到了
        return i-j;
    else 
        return 0;
}
    
//KMP算法简单版：get_next时间、空间复杂度为O(m),index_KMP为O(n)
//时间复杂度O(m+n),空间复杂度O(m);
void get_next(char t[],int *next)
{

}

int index_KMP(char s[],char t[],int pos)
{
    int i=pos,j=0;
    int n=strlen(s);
    int m=strlen(t);
    int next[255];
    get_next(t,next);
    while(i<n && j<m)
    {
        if(s[i]==t[j])
        {
            i++;
            j++;
        }
        else
        {
            j=next[j];
        }
    }
    if(j=m)//t的每个字符都匹配完,说明匹配到了
        return i-j;
    else 
        return 0;
}

//KMP算法改进版：将get_next改为get_nextval
//时间空间复杂度没有变



void main()
{
    char s[]="hello this is the human world.";
    char t[]="human";
    int pos=index(s,t,4);
    if(pos)
        printf("t is in pos %d of s.\n",flag);
    else
        printf("t isn't in s.\n");
}
