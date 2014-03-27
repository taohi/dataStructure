#include <stdio.h>
int strlen(char s[]);
void main()
{
    char s[]="asdfasdfasdf";
    printf("lenth:%d\n",strlen(s));
}

int strlen(char s[])
{
    int i;
    i=0;
    while(s[i]!='\0')
        ++i;
    return i;
}

