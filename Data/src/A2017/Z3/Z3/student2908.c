#include <stdio.h>
#include <math.h>


int izbaci_cifre(int niz[], int duzina, int cifre[], int duzina_cif)
{
	int i,x,j,z,p,q,k,broj,t,cifra,niz_cifara[100],temp,provjera;


	for(i = 0; i < duzina; i++) {
		broj=niz[i];
		for(t = 0; broj!=0; t++) {
			cifra=broj%10;
			niz_cifara[t]=cifra;
			broj/=10;
		}

		x=t;

		for(j = 0; j < x; j++) {
			temp=fabs(niz_cifara[j]);
			for(k = 0; k < duzina_cif; k++) {
				if(temp == cifre[k]) {
					for(z = j; z < x-1; z++) {
						niz_cifara[z]=niz_cifara[z+1];
					}
					x--;
					j--;
				}
			}
		}

		for(p = i; p <= i; p++) {
			niz[p]=0;
			for(q = 0; q < x; q++) {
				niz[p]+=niz_cifara[q]*pow(10,q);
			}
		}
	}

	for(i = 0; i < duzina_cif; i++) {
		if(cifre[i] < 0 || cifre[i] > 9)
			return 0;
		provjera=cifre[i];
		for(j = i+1; j < duzina_cif; j++) {
			if(provjera == cifre[j])
				return 0;
		}
	}

	return 1;
}


int main()
{

	int niz[100],duzina,cifre[100],duz,i,rez;

	printf("Unesite duzinu niza: ");
	scanf("%d",&duzina);

	printf("Unesite clanove niza: \n");
	for(i = 0; i < duzina; i++) {
		printf("%d. clan niza brojeva: ",i+1);
		scanf("%d",&niz[i]);
	}
	printf("Unesite duzinu niza cifara: ");
	scanf("%d",&duz);

	printf("Unesite clanove niza cifara: \n");
	for(i = 0; i < duz; i++) {
		printf("%d. clan niza cifara: ",i+1);
		scanf("%d",&cifre[i]);
	}

	rez=izbaci_cifre(niz,duzina,cifre,duz);

	for(i = 0; i < duzina; i++) {
		printf("\n%d. clan niza: %d",i+1,niz[i]);
	}
	printf("\nDa li je uspjelo ili ne(1-uspjelo, 0-nije uspjelo): %d",rez);
	return 0;
}
