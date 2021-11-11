#include <stdio.h>
#define BROJ_EL 100

int izbaci_cifre(int niz_broj[], int duzina_br, int niz_cifre[], int duzina_cif)
{
	int i, j, brojac[10], pom, pom1, mjesto, cifra, vrijednost=0, znak=1;

	for(i=0; i<10; i++) {
		brojac[i]=0;
	}
	for(i=0; i<duzina_cif; i++) {
		if(niz_cifre[i]>9 || niz_cifre[i]<0) return 0;
		brojac[niz_cifre[i]]++;
	}
	for(i=0; i<10; i++) {
		if(brojac[i]>1) return 0;
	}

	for(i=0; i<duzina_br; i++) {
		if(niz_broj[i]>=0) {
			pom=niz_broj[i];
			znak=1;
		} else {
			pom=(-1)*niz_broj[i];
			znak=-1;
		}
		
		pom1=0;
		mjesto=1;
		while(pom>0) {
			cifra=pom%10;
			pom=pom/10;
			vrijednost=0;

			for(j=0; j<duzina_cif; j++) {
				if(cifra==niz_cifre[j]) {
					vrijednost=1;
				}
			}

			if(vrijednost==0) {
				pom1=pom1+cifra*mjesto;
				mjesto=mjesto*10;
			}

		}
		niz_broj[i]=pom1*znak;
	}


	return 1;
}

int main()
{
	int niz_broj[BROJ_EL], niz_cifre[BROJ_EL], i, duzina_br=0, duzina_cif=0;

	printf("Unesite niz brojeva: ");
	for(i=0; i<100; i++) {
		scanf("%d", &niz_broj[i]);
		if(niz_broj[i]==-1) break;
		duzina_br++;
	}

	printf("Unesite niz cifara: ");
	for(i=0; i<100; i++) {
		scanf("%d", &niz_cifre[i]);
		if(niz_cifre[i]==-1) break;
		duzina_cif++;
	}

	izbaci_cifre(niz_broj,duzina_br,niz_cifre,duzina_cif);

	return 0;
}
