#include <stdio.h>
int f1(int a,int* b)
{
int c=0;
a=2;
*b=3;
c=a+2;
return c ;
}
int f2(int* p1)
{
int a;
p1=p1+2;
a=(*p1)+2;
return a;
}
void f3(char* p)
{
*p='?';
p++;
*p='?';
}
int main()
{
int A[5]={2,4,6,8,10};
int B[2][2]={1,3,5,7};
char rijeka[]="Miljacka";
int a=1,b=1,c=0;
int *p1=&B[0][0];
c=*(A+1)+(*(p1+2));
printf("\n%d",c);
c=f1(a,&b);
printf("\n%d,%d,%d",a,b,c);
c=f2(&B[0][0]+1);
printf("\n%d",c);
c=f2(A+1);
printf("\n%d",c);
f3(rijeka);
printf("\n%s",rijeka);
return 0;
}