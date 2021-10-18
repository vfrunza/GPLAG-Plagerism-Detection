#include <stdio.h>
#include <math.h>
int izbaci_cifre(int niz1[], int vel1, int niz2[], int vel2)
{
	int i,j;
	int cifra=0;
	int broj;
	int novibroj=0;
	int izbaci;
	int cifre[10]= {0};
	int brojac=0;
	int negativan;
	for (i=0;i<vel2;i++)
	{
	if (niz2[i]<0 || niz2[i]>9) return 0; //provjera ispravnosti niza cifara 1
	cifre[niz2[i]]++;
	if (cifre[niz2[i]]>1) return 0; //provjera ispravnosti niz
	}
	for(i=0; i<vel1; i++) {
		broj=niz1[i];
		negativan=1;
		if (broj<0) 
		{
			broj*=-1;
			negativan=-1; //provjera da li je negativan zbog dijeljenja posljednje cifre
		}
		for(j=0; j<vel2; j++) {
			novibroj=0;
			izbaci=niz2[j];
			brojac=0;
			do {
				cifra=broj%10;
				if(cifra!=izbaci) {
					novibroj+=cifra*pow(10,brojac);
					brojac++;
				}
				broj/=10;
			}	while (broj!=0);
			broj=novibroj;
		}
		niz1[i]=broj*negativan;
	}
	
	return 1;
}
int main()
{
	int niz1[1000]= {0}, niz2[1000]= {0};
	int vel1, vel2;
	int i;
	scanf("%d", &vel1);
	scanf("%d", &vel2);
	printf("Unesite clanove niza 1:");
	for(i=0; i<vel1; i++) {
		scanf("%d", &niz1[i]);
	}

	printf("Unesite clanove niza 2:");
	for(i=0; i<vel2; i++) {
		scanf("%d", &niz2[i]);
	}
	izbaci_cifre(niz1, vel1, niz2, vel2);

	return 0;
}
