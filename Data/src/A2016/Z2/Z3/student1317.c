#include <stdio.h>

int main() 
{
	int i, j, k, broj_tacaka, x[10], y[10], ispisan=0;
	
	/* Unos i provjera da li je broj tacaka u intervalu od 0 do 10 */
	do
	{
		printf("Unesite broj tacaka: ");
		scanf("%d", &broj_tacaka);
		
		if(broj_tacaka < 1 || broj_tacaka > 10) printf("Pogresan unos\n");
		
	} while(broj_tacaka < 1 || broj_tacaka > 10);
	
	/* Unos koordinata tacaka */ 
	for(i=0; i < broj_tacaka; i++)
	{
		printf("Unesite %d. tacku: ", i + 1);
		scanf("%d %d", &x[i], &y[i]);
		
		if(y[i] < 0 || y[i] > 19 || x[i] < 0 || x[i] > 19) 
		{
			printf("Pogresan unos\n");
			i--;
		}
	}
	
	/* Formiranje sistema formata 20x20 i ispisivanje tacke na odredjenim koordinatama */ 
	for(i=0; i <= 19; i++)
	{
		for(j=0; j <= 19; j++)
		{
			for(k=0; k < broj_tacaka; k++)
			{
				if(x[k] == j && y[k] == i) { printf("*"); ispisan=1; break;}
			}
			if(ispisan==0) printf(" ");
			ispisan=0;
		}
		printf("\n");
	}
	return 0;
}
