#include <stdio.h>

int main() 
{
	/*Unosenje vrijednosti*/
	int r,k,s,i,j,l;
	
	/*Petlje za provjeru broja redova,kolona i sirine kolone*/
	
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
	scanf("%d",&s);	
	}while(s<=0 || s>10);
	
	/*Crtanje*/
	do
	{
		/* prvi red */
		printf("+");
		for(j=0;j<k;j++)
		{
			for(i=0;i<s;i++) { printf("-"); }
			printf("+");
		}
		printf("\n");
			
		for(l=0;l<r*2;l=l+2)
		{
			/*suplji red*/
			printf("|");
			for(j=0;j<k;j++)
			{
				for(i=0;i<s;i++) { printf(" "); }
				printf("|");
			}
			printf("\n");
			
			/*puni red*/
			printf("+");
			for(j=0;j<k;j++)
			{
				for(i=0;i<s;i++) { printf("-"); }
				printf("+");
			}
			printf("\n");
		}
		break;
	}while(r>0 && r<=10 && k>0 && k<=10 && s>0 && s<=10);
return 0;
}

