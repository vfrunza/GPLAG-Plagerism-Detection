#include <stdio.h>
#include <stdlib.h>
int main()
{
int a,i,p=0,u,d,f,g;
int b=0,m=1;
printf("Unesite broj: ");
scanf("%d", &a);

while(a!=0){
 
 d=abs(a)%10;
 a=abs(a)/10;
 if (a==0) {
 break;
 }
 u=abs(a)%10;
 g=abs(d-u);
p=p+(g*m);
 m=m*10;

}

printf("%d",p);


return 0; 
}