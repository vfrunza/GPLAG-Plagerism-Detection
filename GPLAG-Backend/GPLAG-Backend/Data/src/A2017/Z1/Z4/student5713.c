#include <stdio.h>

int main() {
int a,b,i,c,j,u;
	do
	{printf("Unesite broj redova: ");
	scanf("%d",&b);
	}
	while ((b<1)||(b>10));
	do
	{
	printf("Unesite broj kolona: ");
	scanf("%d",&a);
	}
	while((a<=0)||(a>10));
	do
	{printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&c);
	}
	while((c<=0)||(c>10));
	for(u=0;u<b;u++)
		
		{
		for (i=0;i<a;i++)
	{printf("+");
	for(j=0;j<c;j++)
	printf("-");}
		printf("+\n");
		
		for(i=0;i<a;i++)
	{printf("|");
	for(j=0;j<c;j++)
	printf(" ");
       }
	printf("|\n");}
	
	for (i=0;i<a;i++)
	{printf("+");
	for(j=0;j<c;j++)
	printf("-");}
		printf("+\n");
	return 0;
}
