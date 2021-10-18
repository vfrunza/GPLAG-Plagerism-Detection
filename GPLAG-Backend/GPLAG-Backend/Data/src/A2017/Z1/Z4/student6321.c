#include <stdio.h>

int main() {
	int br, bk, sk;
	int i, j, k;
	do
	{
		printf("Unesite broj redova: ");
		scanf("%d", &br);
		
	}while(br<=0 || br>10);
	
		do{
		printf("Unesite broj kolona: ");
		scanf("%d", &bk);
		
	}while(bk<=0 || bk>10);
	
		do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sk);
		
	}while(sk<=0 || sk>10);
	
	for(i=0; i< 2*br+1; i++)
	{
		if(i%2==0)
		{
			for(j=0; j< bk; j++)
		{
			printf("+");
			for(k=0; k<sk; k++)
			{
				printf("-");
			}
		}
		printf("+\n");
		}
		else{
			for(j=0; j< bk; j++)
		{
			printf("|");
			for(k=0; k<sk; k++)
			{
				printf(" ");
			}
		}
		printf("|\n");
		}
	}
	return 0;
}
