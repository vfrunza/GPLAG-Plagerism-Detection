#include <stdio.h>

int DajSumuCifara (int broj)
{
	if (broj < 0) broj *= (-1);
	int suma = 0;
	while (broj != 0)
	{
		suma += broj%10;
		broj/=10;
	}
	return suma;
}

int DaLiJeFibonaccijevBroj(int broj)
{
	int i, prethodni = 1, trenutni = 1, temp;
	for (i = 0; i < broj; i++)
	{
		if (trenutni == broj) return 1;
		temp = trenutni;
		trenutni += prethodni;
		prethodni = temp;
	}
	return 0;
}

void ubaci(int* niz, int vel)
{
	int i, j;
	for (i = 0; i < vel; i++)
	{
		for (j = vel; j > i; j--)
			niz[j] = niz[j-1];
		vel++;
		niz[i+1] = DajSumuCifara(niz[i]);
		i++;
	}
}

int izbaci (int* niz, int vel)
{
	int i, j;
	for (i = 0; i < vel; i++)
	{
		if (DaLiJeFibonaccijevBroj(niz[i]))
		{
			for(j = i; j < vel-1; j++)
				niz[j] = niz[j+1];
			vel--;
			i--;
		}
	}
	return vel;
}

int main()
{
	int i, niz[20], vel;
	printf ("Unesite niz od 10 brojeva: ");
	for (i = 0; i < 10; i++)
        scanf("%d", &niz[i]);
    
    ubaci (niz, 10);
    vel = izbaci (niz, 20);
	
	printf ("Modificirani niz glasi: ");
	for (i = 0; i < vel-1; i++)
        printf("%d, ", niz[i]);
	printf ("%d.", niz[i]);
    return 0;
}
