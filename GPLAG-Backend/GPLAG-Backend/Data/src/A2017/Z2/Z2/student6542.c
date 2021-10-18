#include <stdio.h>

int main() {
	int niz[100],C[1000],D[1000],n,i;
	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	printf("Unesite clanove niza: ");
	for(i=0;i<n;i++){
		do {
		scanf("%d", &niz[i]);
		if(niz[i]<0) printf("Broj mora biti prirodan! ");
		} while (niz[i]<0);
	}
	int brojac=0,jedinica;
	for(i=0;i<n;i++){
		int jedinica=10;
		if (niz[i]<10) {
			C[brojac]=niz[i];
			brojac++;
		}
		else {
			do {
				 jedinica=jedinica*10;
			} while (jedinica<=niz[i]);
			jedinica=jedinica/10;
			do{
				C[brojac]=niz[i]/jedinica;
				niz[i]=niz[i]-C[brojac]*jedinica;
				jedinica=jedinica/10;
				brojac++;
			}while (jedinica>=1);
		}
	}
	int brojcifara=1,brojac2=0;
	for(i=0;i<brojac;i++){
		if(i==brojac-1 && C[i]==C[i-1]) {
			D[brojac2]=C[i];
			brojac2++;
			D[brojac2]=brojcifara;
			brojac2++;
			
		} 
		else if(i==brojac-1 && C[i]!=C[i-1]){
			D[brojac2]=C[i];
			brojac2++;
			D[brojac2]=brojcifara;
			brojac2++;
			
		}
		else if (C[i]==C[i+1]) brojcifara++;
		else {
			D[brojac2]=C[i];
			brojac2++;
			D[brojac2]=brojcifara;
			brojac2++;
			brojcifara=1;
		}
	}
	printf("Finalni niz glasi:\n");
	for (i=0;i<brojac2;i++){
		if(i==0) printf("%d", D[i]);
		else printf(" %d", D[i]);
	}
	return 0;
}
