#include <stdio.h>

int main() {
	int a,b,c,i,j,k,m;
	do
	{printf("Unesite broj redova: ");
	scanf("%d", &a);
	}
	while(a<=0 || a>10);
	do{
	printf("Unesite broj kolona: ");
	scanf("%d", &b);}
	while(b<=0 || b>10);
	do{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &c); }
	while(c<=0 || c>10);
	
   for(m=0;m<a;m++)
   {
   	
   	for(j=0;j<b;j++)
   	{printf("+");
   	for(k=0;k<c;k++)
   	printf("-");}
   	printf("+");
   	printf("\n");
   	
   	for(i=0;i<=b;i++)
   	{printf("|");
   	for(j=0;j<c;j++)
   	printf(" ");
   	}
   	printf("\n");
   }
   for(j=0;j<b;j++)
   {printf("+");
   for(k=0;k<c;k++)
   printf("-");}
   printf("+");
   printf("\n");
 
	return 0;
}
