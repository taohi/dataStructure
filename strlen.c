#include <stdio.h>
int strlen(char s[]);
int strlen2(char *s);
void main()
{
    char s[]="asdfasdfasdf";
    printf("lenth:%d\n",strlen(s));
    printf("lenth2:%d\n",strlen2(s));
}

int strlen(char s[])
{
    int i;
    i=0;
    while(s[i]!='\0')
        ++i;
    return i;
}

int strlen2(char *s)
{
    char *p=s;
    while(*p!='\0')
       p++; 
    return p-s;
}
