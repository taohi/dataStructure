#include <stdio.h>
#include <string.h>
//朴素子串查找：返回子串T在母串S中第pos个字符之后首次出现的位置。
//若不存在，则函数返回0 时间复杂度O((n-m+1)*m),空间复杂度O(1)
int simple_index(char s[],char t[],int pos)
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
    int i=0,j=-1;
    next[0]=-1;
    int m=strlen(t);
    while(i<m)
    {
        if(j==-1||t[i]==t[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
            j=next[j];
    }
}

//KMP算法改进版：将get_next改为get_nextval
//时间空间复杂度没有变,匹配次数减少
void get_nextval(char t[],int *nextval)
{
    int i=0,j=-1;
    int m=strlen(t);
    nextval[0]=-1;
    while(i<m)
    {
        if(j==-1||t[i]==t[j])
        {
            i++;
            j++;
            if(t[i]!=t[j])
                nextval[i]=j;
            else
                nextval[i]=nextval[j];
        }
        else
            j=nextval[j];
    }
}

int index_KMP(char s[],char t[],int pos)
{
    int i=pos,j=0;
    int n=strlen(s);
    int m=strlen(t);
    int next[255];
    //get_next(t,next);
    get_nextval(t,next);
    while(i<n && j<m)
    {
        if(j==-1||s[i]==t[j])
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

void main()
{
    char s[]="abcabcdabcabceabcabcabcabcxab";
    char t[]="abcabcx";
    int pos1=simple_index(s,t,2);
    int pos2=index_KMP(s,t,2);

    printf("simple_index:\t");
    if(pos1)
        printf("t is in pos %d of s.\n",pos1);
    else
        printf("t isn't in s.\n");

    printf("index_KMP:\t");
    if(pos2)
        printf("t is in pos %d of s.\n",pos2);
    else
        printf("t isn't in s.\n");
}
