#include <stdio.h>
#define visina 20
#define sirina 20
int main()
{
	char selma[visina][sirina];
	int br_t,i,j,counter;
	printf("Unesite broj tacaka: ");
	scanf("%d",&br_t);
	while(br_t<1 || br_t>10)
	{
	    printf("Pogresan unos\n");
	    printf("Unesite broj tacaka: ");
	    scanf("%d",&br_t);
	}
	    for(i=0;i<visina;i++)
	{
		for(j=0;j<sirina;j++)
		{
			selma[i][j]=' ';
		}
	}
	
	for(counter=0;counter<br_t;counter++)
	{
		printf("Unesite %d. tacku: ",counter+1);
		scanf("%d",&i);
		scanf("%d",&j);
		
		while(i<0 || i>19 || j<0 || j>19)
		{
		printf("Pogresan unos\n");
		printf("Unesite %d. tacku: ",counter+1);
		scanf("%d",&i);
		scanf("%d",&j);
		}
		selma[i][j]='*';
	}
	
	
	for(i=0;i<visina;i++)
	{
		for(j=0;j<sirina;j++)
		{
			printf("%c",selma[j][i]);
			
			
		}
		printf("\n");
	}
	
	
	
	
	
	
	return 0;
}
/*bilo je ludo*/