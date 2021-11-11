#include <stdio.h>

int main() {
	int i, j, k=1, br, bk, s;
	
	do
	{
	printf("Unesite broj redova: ");
	scanf("%d", &br);
	}while((br<1) || (br>10));
	
	do
	{
	printf("Unesite broj kolona: ");
	scanf("%d", &bk);
	}while((bk<1) || (bk>10));
	
	do
	{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &s);
	}while((s<1) || (s>10));
	
	for(i=0; i<bk; i++)
	{
		printf("+");
		for(j=0; j<s; j++)
		printf("-");
	}
	printf("+");
	printf("\n");
	
	for(i=0; i<bk; i++)
	{
		printf("|");
		for(j=0; j<s; j++)
		printf(" ");
	}
	printf("|");
	printf("\n");
	
	while(k<br)
	{
		for(i=0; i<bk; i++)
	{
		printf("+");
		for(j=0; j<s; j++)
		printf("-");
	}
	printf("+");
	printf("\n");
	
	for(i=0; i<bk; i++)
	{
		printf("|");
		for(j=0; j<s; j++)
		printf(" ");
	}
	printf("|");
	printf("\n");
	k++;
	}
	
	for(i=0; i<bk; i++)
	{
		printf("+");
		for(j=0; j<s; j++)
		printf("-");
	}
	printf("+");
return 0;
}
	
