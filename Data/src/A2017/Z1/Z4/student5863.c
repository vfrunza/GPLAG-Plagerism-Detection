#include <stdio.h>

int main() {
	int i,j,n,m,s;
	do
	{
	do
	{
	printf("Unesite broj redova: ");
	scanf("%d",&n);
	}	while(n>10);
	} while(n<=0);
	do
	{
	do
	{
	printf("Unesite broj kolona: ");
	scanf("%d",&m);	
	}  while(m>10);
	} while(m<=0);
	do
	{
	do 
	{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&s);
	}	while(s>10);
	} while(s<=0);
	for(i=0;i<(2*n)+1;i++)
	{
		for(j=0;j<(m*(s+1))+1;j++)
		{
		 if(i==0||i%2==0)
		 {
		 	if(j==0||j%(s+1)==0)
		 	printf("+");
		 	else printf("-");
		 }
		 else
		 {
		   	if(j==0||j%(s+1)==0)
		   	printf("|");
		   	else printf(" ");
		 }
		}
		printf("\n");
	}
	return 0;
}
