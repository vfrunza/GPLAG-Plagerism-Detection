#include <stdio.h>

int main() 
{
	int n1,n2,n3,i,j,k;
	do
	{
	printf("Unesite broj redova: ");
	scanf("%d",&n1);
	} 
	while(n1<=0 || n1>10);
	
	do
	{
	printf("Unesite broj kolona: ");
	scanf("%d",&n2);
	} 
	while(n2<=0 || n2>10);
	
    do
	{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&n3);
	} 
	while(n3<=0 || n3>10);
	
	printf("+");
	
	for(j=0;j<n2;j++) 
	{
	for(i=0;i<n3;i++) 
	{
	printf("-");
	}
	
	printf("+");
	}
	printf("\n");
	
	printf("|");
	
	for(j=0;j<n2;j++) 
	{
	for(i=0;i<n3;i++) 
	{
	printf(" ");
	}
	printf("|");
	}
	
	printf("\n");
	
	printf("+");
	
	for(j=0;j<n2;j++) 
	{
	for(i=0;i<n3;i++) 
	{
	printf("-");
	}
	printf("+");}
	printf("\n");
	
	for(k=0;k<n1-1;k++)
	{
	printf("|");
	for(j=0;j<n2;j++) 
	{
	for(i=0;i<n3;i++) 
	{
	printf(" ");
	}
	printf("|");}
	printf("\n");
	printf("+");
	for(j=0;j<n2;j++) 
	{
	for(i=0;i<n3;i++) 
	{
	printf("-");
	}
	printf("+");}
	printf("\n");
	} 
	
	return 0;
}
