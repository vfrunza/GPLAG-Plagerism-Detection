#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void zaokruzi1(float niz[], int velicina)
{
	int i,x;
	float temp,rez,y;
	for(i = 0; i < velicina; i++)
	{
		x = niz[i];
		y = (niz[i] - x) * 10;
		temp = round(y);
		rez = x + temp/10;
		niz[i] = rez;
	}
}

int SumaCifara(float x)
{
	int suma = 0, rezultat;
	x = fabs(x*10);
	rezultat = x;
	while(rezultat > 0)
	{
		suma += rezultat % 10;
		rezultat /= 10;
	}
	return suma;
}

void preslozi(float niz[], int velicina, int k)
{
	int i,j=0,vraceni=0;
	float temp;
	zaokruzi1(niz,velicina);
	for(i = 0; i < velicina-vraceni; i++)
	{
			if(SumaCifara(niz[i]) < k)
			{
			 	temp = niz[i];
			 	for(j = i+1; j < velicina; j++) {
			 		niz[j-1] = niz[j];
			 		
			 	}
				niz[j-1] = temp;
				vraceni++;
				i--;
			}
	}
}


int main() {
	int i;
	float niz[5] = {13.1, 15.74999, 15.75, 9.222, 78.1};
	preslozi(niz,5,14);
	printf("Niz glasi: ");
	for(i = 0; i < 5; i++)
	{
		printf("%g  ",niz[i]);
	}
	return 0;
}
