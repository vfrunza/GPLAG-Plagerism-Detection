#include <stdio.h>

/* Navodno ima gresku kod testa 4 ali kad ja provjeravam te slucajeve izbaci rezultat koji se i trazi */
/* Test 5 sere za jedan space na kraju ispisa kod provjere da li su modifikovani nizovi */

int dva_od_tri(int niz1[], int n1, int niz2[], int n2, int niz3[], int n3);
void unesiNiz(int* niz, int* duzina);

int main() {
	
	int niz1[100], niz2[100], niz3[100], n1 = 0, n2 = 0, n3 = 0, brojac;
	int i;
	
	unesiNiz(niz1, &n1);
	unesiNiz(niz2, &n2);
	unesiNiz(niz3, &n3);
	
	brojac = dva_od_tri(niz1, n1, niz2, n2, niz3, n3);
	
	printf("%d", brojac);
	
	
	return 0;
	
}

void unesiNiz(int* niz, int* duzina)
{
	int i;
	
	do
	{
		printf("Unesite duzinu niza: ");
		scanf("%d", &(*duzina));
		
	}while(*duzina <= 0 || *duzina > 100);
	
	
	printf("Unesite niz: \n");
	for(i = 0; i < *duzina; i++)
		scanf("%d", &(*(niz+i)));
}

int dva_od_tri(int niz1[], int n1, int niz2[], int n2, int niz3[], int n3)
{
	int i, j, brojac = 0;
	int niz[100] = {0};
	int ponavlja;
	
	for(i = 0; i <= n1 - 1; i++)
	{
		ponavlja = 0;
		for(j = i + 1; j < n1; j++)
		{
			if(niz1[i] == niz1[j]) ponavlja = 1;
		}
		
		if(ponavlja == 0) niz[niz1[i]]++;
	}
		
	for(i = 0; i <= n2 - 1; i++)
	{
		ponavlja = 0;
		for(j = i + 1; j < n2; j++)
		{
			if(niz2[i] == niz2[j]) ponavlja = 1;
		}
		
		if(ponavlja == 0) niz[niz2[i]]++;
	}
	
	for(i = 0; i <= n3 - 1; i++)
	{
		ponavlja = 0;
		for(j = i + 1; j < n2; j++)
		{
			if(niz3[i] == niz3[j]) ponavlja = 1;
		}
		
		if(ponavlja == 0) niz[niz3[i]]++;

	}
	
	for(i = 0; i < 100; i++)
	{
		if(niz[i] == 2) brojac++;
	}
	
	return brojac;
	
}
