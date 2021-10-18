#include <stdio.h>
#include <math.h>

int suma_cifara_(float broj)
{
	int suma=0;
	broj=broj*10; 
	if(broj<0)
	{
		broj = broj*-1;
	}
	
	int intBroj=(int)(broj);
	while(intBroj>0)
	{
		suma=suma+intBroj%10;
		intBroj=intBroj/10;
	}
	return suma;
}

void zaokruzi1(float brojevi[], int broj_el)
{
	float produzena_vrijednost;
	int i,koeficijent=1;
	for(i=0; i<broj_el;i++)
	{
		if(brojevi[i]<0)
		{
			koeficijent = -1;
		}
		else 
		{
			koeficijent = 1;
		}
	float produzena_vrijednost= (int) (brojevi[i]*10+.5*koeficijent);
		brojevi[i]=(float) produzena_vrijednost/10;
	}
	
}

void preslozi(float brojevi[], int broj_el, int k)
{
	zaokruzi1(brojevi, broj_el);
	float manji_od_k[100];
	float veci_od_k[100];
	int i, br_vecih=0, br_manjih=0;
	
	for(i=0;i<broj_el;i++)
	{
		if(suma_cifara_(brojevi[i])>=k)
		{veci_od_k[br_vecih]=brojevi[i];
		br_vecih++;
	}
	else {
		manji_od_k[br_manjih]=brojevi[i];
	br_manjih++;
	}
}
 for(i=0; i<br_vecih;i++)
 {
 	brojevi[i]=veci_od_k[i];
 }
for(i=0; i<br_manjih; i++)
{
	brojevi[i+br_vecih]=manji_od_k[i];
}
}


int main() {
int i;
float niz[] = { 3.2, -4.301, -123.1999, 1.1, 0.9 };
preslozi(niz, 5, 8);
printf("Niz glasi: ");
for (i=0; i<5; i++)
    printf("%g ", niz[i]);
}
