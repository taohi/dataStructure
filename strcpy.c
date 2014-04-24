#include <stdio.h>

void my_strcpy(char *s,char *t)
{
    while(*s++=*t++)
        ;
}

void main()
{
    char t[]="asdfasdfasdf";
    char s[20];
    my_strcpy(s,t);
    printf("s:%s\n",s);
}

