#include <stdio.h>

int main() {
	char mat[20][20];
	int i,j,brtac;
	int br;
	printf("Unesite broj tacaka: ");
	scanf("%d",&brtac);
	while((brtac<1)||(brtac>10))
	{
		printf("Pogresan unos\n");
		printf("Unesite broj tacaka: ");
		scanf("%d",&brtac);
		
	}
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			mat[i][j]=' ';
			
		}
	}
	for(br=0;br<brtac;br++)
	{
		printf("Unesite %d. tacku: ",br+1);
		scanf("%d %d",&i,&j);
		while((i<0)||(i>19)||(j<0)||(j>19))
		{
			printf("Pogresan unos\n");
			printf("Unesite %d. tacku: ",br+1);
			scanf("%d %d",&i,&j);
		}
		mat[i][j]='*';
	}
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			printf("%c",mat[j][i]);	
			
		}
		printf("\n");
	}
	

	return 0;
	}

