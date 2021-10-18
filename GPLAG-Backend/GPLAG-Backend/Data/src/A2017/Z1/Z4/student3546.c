#include <stdio.h>

int main() {
	int r,k,sk,i,j,sirina,duzina;
	do
	{
		printf("Unesite broj redova: ");
		scanf("%d",&r);
	}while(r<=0 || r>10);
	do
	{
		printf("Unesite broj kolona: ");
		scanf("%d",&k);
	}while(k<=0 || k>10);
	do
	{	
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&sk);
	}while(sk<=0 || sk>10);
	duzina=(r*2)+1;
	sirina=(k+1)+(k*sk);
	for(i=1;i<=duzina;i++)
	{
		for(j=0;j<sirina;j++)
		{
			if(j%(sk+1)==0 && i%2!=0)
			{
				printf("+");
			}
			else if(i%2!=0)
			{
				printf("-");
			}
			if(i%2==0 && j%(sk+1)==0)
			{
				printf("|");
			}
			else if(i%2==0)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
		return 0;
}
