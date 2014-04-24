#include <stdio.h>

int my_strcmp(char *s,char *t)
{
    for(;*s==*t;s++,t++) 
        if(*s=='\0')
            return 0;
    return *s - *t;
}

void main()
{
    char s[]="abcdef";
    char t[]="abcdef";
    if(!my_strcmp(s,t))
        printf("equal!\n");
}

