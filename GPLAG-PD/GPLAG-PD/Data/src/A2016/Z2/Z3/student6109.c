#include <stdio.h>

int main() {
	int tacke[20][20], i, j, brojac, x, y, broj_tacki;
	
	
	
	broj_tacki=0;
	while(broj_tacki<1 || broj_tacki>10)
	{
		printf("Unesite broj tacaka: ");
		scanf("%d", &broj_tacki);
		if(broj_tacki<1 || broj_tacki>10)
		{
			printf("Pogresan unos\n");
			continue;
		}
		
	}
	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
			tacke[i][j]=0;
			
	
	brojac=0;
	x=-1;
	y=-1;
	while((x>0 || x<20 || y>0 || y<20) && brojac<broj_tacki)
	{
		
		printf("Unesite %d. tacku: ", brojac+1);
		scanf("%d %d", &x, &y);
		if(x<0 || x>19 || y<0 || y>19)
		{
			printf("Pogresan unos\n");
			continue;
		}
		for(i=0;i<20;i++)
		{
			for(j=0;j<20;j++)
			{
				if(x==j && y==i) tacke[i][j]=1;
			}
		}
		brojac++;
	}
	
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			if(tacke[i][j]==1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	
	return 0;
}
