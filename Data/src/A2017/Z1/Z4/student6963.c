#include <stdio.h>
int main() {
	int r,ko,sk,i,j,k,z;
	do
	{
	printf("Unesite broj redova: ");
	scanf("%d",&r);
	}
	while(r<=0 || r>10);
	
	do
	{
	printf("Unesite broj kolona: ");
	scanf("%d",&ko);
	}
	while(ko<=0 || ko>10);
	do
	{
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d",&sk);
	}
	while(sk<=0 || sk>10);
	r=2*r+1;
	do
	{
		if(r%2!=0)
		{
			printf("+");
		
		for(i=0;i<ko;i++)
		{
			for(j=0;j<sk;j++)
		{
			printf("-");
		}
		
		printf("+");
	}
	printf("\n");
		}
	else
	{
		for(k=0;k<ko+1;k++)
		{
			printf("|");
		for(z=0;z<sk;z++)
		{
			printf(" ");
		}}
		printf("\n");
	}
	 r=r-1;
	}
	
    while(r>0);
    return 0;
}
