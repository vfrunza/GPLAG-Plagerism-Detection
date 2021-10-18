#include <stdio.h>

int main() {
	int n,i,j,niz1[100],niz2[1000],x,t=0, br=0;
	int pomocniniz[1000];
	int pomocni;
	int indeks=0;
	int brcif;
	
	/* unos broja clanova i unos clanova niza */
	do {
	printf("Unesite velicinu niza: ");
	scanf ("%d", &n);
	} while (n<1 || n>100);
	
	printf("Unesite clanove niza: ");
	for (i=0;i<n; i++){
		scanf ("%d", &niz1[i]);
		 if (niz1[i]<0){
			i--;
		}
	}
	
	
	for (i=0;i<n;i++){
		pomocni=niz1[i];
		brcif=0;
		if(niz1[i]==0) brcif = 1;
		else {
			while(pomocni != 0){
				pomocni/=10;
				brcif++;
			}
		}
		indeks+=brcif;
		for(j=0; j<brcif; j++){
			pomocniniz[indeks-1] = niz1[i]%10;
			niz1[i]/=10;
			indeks--;
		}
		indeks+=brcif;
	}
	
	brcif=indeks;
	indeks=0;
	for(i=0; i<brcif; i++){
		niz2[indeks] = pomocniniz[i];
		indeks++;
		br=1;
		while(i<brcif-1 && pomocniniz[i]==pomocniniz[i+1]){
			br++;
			i++;
		}
		niz2[indeks] = br;
		indeks++;
	}
	
	printf("Finalni niz glasi: \n");
	for(i=0; i<indeks; i++){
		printf("%d ", niz2[i]);
	}
	
	return 0;
}
