#include <stdio.h>

int main() {
	char mat[20][20]={{0},{0}};
	int i=0,j=0,brtacki=0,brojac=0,a,b;
	printf("Unesite broj tacaka: ");
	scanf("%d", &brtacki);
	while(brtacki<0 || brtacki>10)
	{
	printf("Pogresan unos\n");
	printf("Unesite broj tacaka: ");
	scanf("%d", &brtacki);
	}

			
for(brojac=0;brojac<brtacki;brojac++)
{
	printf("Unesite %d. tacku: ",brojac+1);
	scanf("%d", &a);
	scanf("%d", &b);
	while(a<0 || a>19 || b<0 || b>19)
	{
		printf("Pogresan unos\n");
		printf("Unesite %d. tacku: ",brojac+1);
		scanf("%d", &a);
		scanf("%d", &b);
	}
		mat[a][b]++;
}
	

	
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			if(mat[j][i]==0)
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
			
			}
			printf("\n");
		}
		
		return 0;
	}

	
	

	
	
	
	
	
	
	
	
	

