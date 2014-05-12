#include <stdio.h>
#include <string.h>
//朴素子串查找：返回子串T在母串S中第pos个字符之后首次出现的位置。
//若不存在，则函数返回0
int strindex(char s[],char t[],int pos)
{
    int i=pos,j=0;
    int s_len=strlen(s);
    int t_len=strlen(t);
    while(i<s_len && j<t_len)
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
    if(j=t_len)
        return i-j;
    else 
        return 0;
}
    
void main()
{
    char s[]="hello this is the human world.";
    char t[]="human";
    int flag=strindex(s,t,4);
    if(flag)
        printf("t is in pos %d of s.\n",flag);
    else
        printf("t isn't in s.\n");

}
