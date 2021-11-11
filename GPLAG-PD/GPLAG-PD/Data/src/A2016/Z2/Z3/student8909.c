/* zadaca 2, zadatak 3. */

#include <stdio.h>

int main() 
{
	char mat[20][20];
	int x, y, i, j, broj_tacaka, k;
	
	for(i=0; i<20; i++)
	{
		for(j=0; j<20; j++)
		{
			mat[i][j] = ' ';
		}
	}
	
	do
	{
		printf("Unesite broj tacaka: ");
		scanf("%d", &broj_tacaka);
		if(broj_tacaka < 1 || broj_tacaka > 10) printf("Pogresan unos \n");
	}
	while (broj_tacaka < 1 || broj_tacaka > 10);
	
	
	
	for(k=0; k<broj_tacaka; k++)
	{
		i = 0;
		j = 0;
		printf("Unesite %d. tacku: ", k+1);
		scanf("%d", &x);
		scanf("%d", &y);
		
		if(x > 19 || x < 0 || y > 19 || y < 0)
		{
			 printf("Pogresan unos \n");
			 k--;
			 continue;
		}
		
		
		for(i=0; i<20; i++)
		{
			for(j=0; j<20; j++)
			{
				if(i == y && j == x) mat[i][j] ='*';
            }
             
	    }
		
	}
	
	for(i=0; i<20; i++)
	{
		for(j=0; j<20; j++)
		{
			printf("%c", mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}
