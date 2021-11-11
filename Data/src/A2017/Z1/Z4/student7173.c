#include <stdio.h>

int main() {
	
	int redovi,kolone,sirina_kolone,i,j;
	
	do  
	{
		printf("Unesite broj redova: ");
		scanf("%d",&redovi);
	}while(redovi<=0 || redovi>10);
	
	do 
	{
		printf("Unesite broj kolona: ");
		scanf("%d",&kolone);
	}while (kolone<=0 || kolone>10);

	do 
	{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d",&sirina_kolone);
		
	}while(sirina_kolone<=0 || sirina_kolone>10);
		
	for(i=0;i<=redovi*2;i++)
	{
		for(j=0;j<=kolone * sirina_kolone + kolone;j++)
		{
			if(i%2==0)
			{
			
			
				if(j%(sirina_kolone+1)==0) printf("+");
				else printf("-");
				
			}
			else
			{
				if(j%(sirina_kolone+1)==0) printf("|");
				else printf(" ");
			}
			
			
		}
		printf("\n");
		
	}
	
	return 0;
}
