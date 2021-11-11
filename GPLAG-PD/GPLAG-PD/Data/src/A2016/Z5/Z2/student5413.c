#include <stdio.h>

/* kompresuj */

/* dekompresuj */

void unesi(char niz[]) 
{
	int i;
	char znak = getchar();
	if(znak == '\n') 
	  znak = getchar();
	i = 0;
	while(i < 19 && znak != '\n') 
	{
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i] = '\0';
}

int main() 
{
	int n;
	char ulazna[20], izlazna[20];
	FILE* ulaz, izlaz;
	
	do
	{
		printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
		scanf("%d", &n);
		
		if(n == 0)
		  return 0;
		
		printf("Unesite ime ulazne datoteke: ");
		unesi(ulazna);
		printf("Unesite ime izlazne datoteke: ");
		unesi(izlazna);
		
		ulaz = fopen(ulazna, "r");
		if(ulaz == NULL)
		{
			printf("Greska pri otvaranju ulazne datoteke.");
			exit(1);
		}
		
		izlaz = fopen(izlazna, "w");
		if(izlaz == NULL)
		{
			printf("Greska pri otvaranju izlazne datoteke.");
			fclose(ulaz);
			exit(2);
		}
		
		
		
	}while(n != 0);
	return 0;
}
