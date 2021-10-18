#include <stdio.h>

int main() {
	int n;
	int cifre[100], rezultat[1000];
	int uslov;
	int i, j, k;
	int pomocna;
	int ukupno = 0;
	int a;
	int razlika;
	int brojac;
	
	do
	{
		uslov = 0;
		printf("Unesite velicinu niza: ");
		scanf("%d", &n);
		
		if (n>0 && n<=100)
			uslov = 1;
	} while (uslov == 0);
	
	for (i = 0; i < 100; i++)
		cifre[i] = 0;
		
	for (i = 0; i < 1000; i++)
		rezultat[i] = 0;
	
	
	printf("Unesite clanove niza: ");
	for (i = 0; i < n; i++)
		{
			
			do
			{
				uslov = 0;
				scanf("%d", &pomocna);
				if (pomocna>=0)
					uslov = 1;
			} while (uslov == 0);
			
			cifre[i] = pomocna;
		}
	
	
	for (i = 0; i < n; i++)
		{
			pomocna = cifre[i];
			
			j = ukupno;
			while (pomocna>0)
				{
					a = pomocna%10;
					rezultat[ukupno] = a;
					ukupno++;
					pomocna = pomocna/10;
				}
				
			if (cifre[i] == 0)
				{
					rezultat[ukupno] = 0;
					ukupno++;
				}
				
			k = ukupno-1;
			
			razlika = ukupno-j;
			while(razlika>1)
				{
					pomocna = rezultat[j];
					rezultat[j] = rezultat[k];
					rezultat[k] = pomocna;
					j++;
					k--;
					razlika = razlika - 2;
				}
		}
		
		
		for (i = 0; i < 100; i++)
			cifre[i] = 0;
		
		for (i = 0; i < ukupno; i++)
			cifre[i] = rezultat[i];
			
		for (i = 0; i < 1000; i++)
			rezultat[i] = 0;
			
		j = 0;
		k = 0;
		for (i = 0; i < ukupno; i++)
			{
				pomocna = cifre[i];
				brojac = 0;	
				for (j = i; j < ukupno; j++)
					{
						if (cifre[j] != pomocna && j != i)
							break;
							
						if (cifre[j] == pomocna)
							brojac++;
					}
					
				rezultat[k] = pomocna;
				k++;
				rezultat[k] = brojac;
				k++;
				i = j-1;
				
			}
		
		printf("Finalni niz glasi:\n");
		for (i = 0; i<k; i++)
			printf("%d ", rezultat[i]);
	
	
	
	
	
	
	
	
	return 0;
}
