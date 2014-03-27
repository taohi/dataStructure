#include <stdio.h>
int atoi(char s[]);

void main()
{
    char s[]="1231";
    printf("after atoi,n=%d\n",atoi(s));
}
int atoi(char s[])
{
    int i,n;
    n=0;
    for(i=0;s[i]>='0'&&s[i]<='9';++i)
        n=10*n+(s[i]-'0');
    return n;
}

