#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct str1{
    int len;
    int b;
    char s[0];
};

struct str2{
    int len;
    char s[0];
    int b;
};

int main()
{
    struct str1 *sp=NULL;
    struct str2 *sp2=NULL;
    printf("Before,sizeof(struct str1):%d\n",sizeof(struct str1));
    sp=(struct str1 *)malloc(sizeof(struct str1)+10);
    sp->len=100;
    sp->b=50;
    strcpy(&sp->s[0],"abc");
    puts(sp->s);
    printf("After,sizeof(struct str1):%d\n",sizeof(struct str1));
    printf("len:%d\t%p\n",sp->len,&sp->len);
    printf("b:%d\t%p\n",sp->b,&sp->b);
    printf("s:%s\t%p\n",sp->s,&sp->s);

    printf("\nBefore,sizeof(struct str2):%d\n",sizeof(struct str2));
    sp2=(struct str2 *)malloc(sizeof(struct str2)+10);
    sp2->len=150;
    sp2->b=60;
    strcpy(&sp2->s[0],"def");
    puts(sp2->s);
    printf("After,sizeof(struct str2):%d\n",sizeof(struct str2));
    printf("len:%d\t\t%p\n",sp2->len,&sp2->len);
    printf("b:%d\t%p\n",sp2->b,&sp2->b);
    printf("s:%s\t\t%p\n",sp2->s,&sp2->s);


    return 0;
}
