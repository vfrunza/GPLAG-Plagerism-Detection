#include <stdio.h>

void zaokruzi1 (float niz[], int n)
{
	int i;
	int cijeli;
	double razlika;
	int a;
	int pomocni;
	int negativan = 0;
	for (i = 0; i < n; i++)
		{
			negativan = 0;
			
			if (niz[i]<0)
				{
					negativan = 1;
					niz[i] *=-1;
				}
			
			cijeli = niz[i];
			razlika = niz[i] - cijeli;
			
			razlika = razlika*100;
			pomocni = razlika;
			
			a = pomocni%10;
			pomocni = pomocni/10;
			
			if (a>=5)
				pomocni++;
				
			if (pomocni == 10)
				{
					pomocni = 0;
					cijeli++;
				}
			
			razlika = (double)pomocni/10;
			
			niz[i] = cijeli + razlika;
			
			if (negativan == 1)
				niz[i] *= -1;
		}
		
}


void preslozi (float niz[], int n, int k)
{
	zaokruzi1(niz,n);
	float rezultat[10000];
	int indeks[10000];
	int brojac = 0;
	int suma_cifara;
	int i, j;
	int pomocni;
	float realni;
	int a;
	
	for (i = 0; i < n; i++)
		{
			suma_cifara = 0;
			realni = niz[i];
			realni = realni*10;
			pomocni = realni;
			
			if (pomocni<0)
				pomocni*=-1;
			
			
			
			while(pomocni>0)
				{
					a = pomocni%10;
					suma_cifara += a;
					pomocni/=10;
				}
			
			if (suma_cifara>=k)
				{
					rezultat[brojac] = niz[i];
					indeks[brojac] = i;
					brojac++;
				}
			
		}
		
	pomocni = brojac;
	for (i = 0; i < n; i++)
		{
			a = 1;
			for (j = 0; j < pomocni; j++)
				{
					if (i == indeks[j])
						a = 0;
				}
				
			if (a == 1)
				rezultat[brojac++] = niz[i];
			
		}
	
	
	for (i = 0; i < n; i++)
		niz[i] = rezultat[i];
	
}





int main() {
	
	int i;
	float niz[5] = {13.1, 15.749999, 15.75, 9.222, 78.1};
	preslozi(niz,5,14);
	
	for (i = 0; i < 5; i++)
		printf("%g ", niz[i]);
	
	
	return 0;
}
