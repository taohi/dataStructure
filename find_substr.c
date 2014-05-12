#include <stdio.h>
#define MAXLINE 1000

char pattern[]="ould";

//子串查找:在s中查找子串t,找到则返回第一次出现的位置i
//这是朴素模式匹配的粗暴版本，效率相对低
int strindex(char s[],char t[])
{
    int i,j,k;
    for(i=0;s[i]!='\0';i++)   
    {
        for(j=i,k=0;t[k]!='\0' && s[j]==t[k];j++,k++)
            ;
        if(k>0 && t[k] =='\0')
            return i;
    }
    return -1;
}

//从用户获取母串s
int mygetline(char s[],int lim)
{
    int c,i;
    i=0;
    while(--lim>0 && (c=getchar())!=EOF && c!='\n')
        s[i++]=c;
    if(c=='\n')
        s[i++]=c;
    s[i]='\0';
    return i;
}

int main()
{
    char line[MAXLINE];
    int found = 0;
    while(mygetline(line,MAXLINE)>0)
        if(strindex(line,pattern) >=0)
        {
            printf("%s",line);
            found ++;
        }
    return found;
}
