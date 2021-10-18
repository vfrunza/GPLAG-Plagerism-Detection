#include <stdio.h>

int f1(char *x)
{
    char *q=x+1;
    while(*q > *(q-1) && *q!='\0') q++;
    return q-x;
}
int *f2(int *p,char*q)
{
    int i;
    p=p+4;
    for(i=0; i<4; i++) *(--p)=*q++;
    return p+1;
}
void f3(char *x)
{
    char *s=x+4;
    *(s++)=*x++;
    *s++=(*x)--;
    s--;
}
int main()
{
    int Q[5]= {3,4,5,6};
    char P[5]= {'A','B','C','D','F'};
    char s[18]="Francuska";
    int p=5,q=4;
    q=*(Q+p-q)+*(q+P);
    printf("%d\n",q);
    q=f1(s);
    printf("%d\n",q);
    int *pf2=f2(Q,P);
    printf("%d\n",*(pf2+1));
    printf("%c %d %s\n",*s+4,*(s+4),s+4);
    f3(s);
    printf("%s\n",s);
    return 0;
}