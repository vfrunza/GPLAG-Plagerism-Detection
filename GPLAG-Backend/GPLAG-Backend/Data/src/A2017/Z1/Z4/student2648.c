#include <stdio.h>

int main() {
	int red,kolona,sirina_jedne_kolone,i,j,k,l,z,n,h;
	do {
		printf("Unesite broj redova: ");
		scanf("%d", &red);
	}    while(red<1 || red>10);
	
	do{ 
		printf("Unesite broj kolona: ");
		scanf("%d", &kolona);
	}	while(kolona<1 || kolona>10);
	
	do { 
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &sirina_jedne_kolone);
	}   while(sirina_jedne_kolone<1 || sirina_jedne_kolone>10);
	
	for(i=0;i<red;i++)
	{
		for(j=0;j<kolona;j++)
		{
			printf("+");
		for(k=0;k<sirina_jedne_kolone;k++)
		{
			printf("-");
		}
		}
		
	printf("+");
	printf("\n");
	
	for(l=0;l<kolona;l++)
	{  
		printf("|");
	for(n=0;n<sirina_jedne_kolone;n++)
	{
		printf(" ");
	}
	}
	printf("|");
	printf("\n");
	
	}
	
	
	
	for(z=0;z<kolona;z++)
	{
		printf("+");
	for(h=0;h<sirina_jedne_kolone;h++)
	{
		printf("-");
	}
	}
	printf("+");
	
		
		
	  
	
	return 0;
}
