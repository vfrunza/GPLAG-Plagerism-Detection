#include <stdio.h>

int main() {
int br, bk, sk;
int j, k;
int i = 0;	
	
	do 
	{
		printf("Unesite broj redova: ");
		scanf("%d", &br);
	}while(br<=0 || br>10);
	
	do 
	{
		printf("Unesite broj kolona: ");
		scanf("%d", &bk);
	}while(bk<=0 || bk>10);
	
	do 
	{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sk);
	}while(sk<=0 || sk>10);
	
	


do {	

	for(j=0; j<bk; j++)
	{
		if(i%2==0) 
		{
			printf("+");
		} else 
		{
			printf("|");
		}
		for(k=0; k<sk; k++)
		{
			if(i%2==0) 
			{
				printf("-");
			} else 
			{
			printf(" ");
			}
		}
			
	} 
	if(i%2==0) 
		{
			printf("+");
		}
		else 
		{
			printf("|");
		}
		printf("\n");
	i++;
  
	}while(i < 2*br+1);


	return 0;
}
