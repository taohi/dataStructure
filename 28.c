#include <stdio.h>
#define MAXLINE 1000

int getline(char line[],int maxline);
void copy(char to[],char from[]);

main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    
    max = 0;
    while((len = getline(line,MAXLINE))>0)
        if(len>max){
            max = len;
            copy(longest,line);
        }
    if(max)
}
