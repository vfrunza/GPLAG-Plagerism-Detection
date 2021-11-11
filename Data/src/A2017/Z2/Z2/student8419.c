#include <stdio.h>

int main() {
	int vel, i, j, indeks=0, pom=0, br=0, indeks2=0;
	int niz[100], niz_cifara[1000], finalni_niz[1000];
	
	do {
		printf("Unesite velicinu niza: ");
		scanf("%d", &vel);
	}
	while(vel<=0);
	
	printf("Unesite clanove niza: ");
	for(i=0; i<vel; i++){
		scanf("%d", &niz[i]);
		if(niz[i]<0) i--;
	}
	
	for(i=vel-1; i>=0; i--) {
		pom=niz[i];
		
		while(pom/10!=0) {
			niz_cifara[indeks]=pom-((pom/10)*10);
			indeks++;
			if(pom/10==0) break;
			pom/=10;
		}
		niz_cifara[indeks]=pom;
		indeks++;
	}
	
	for(i=indeks-1; i>=0; i--) {
		pom=niz_cifara[i];
		br=0;
		if(i!=0) {
			if(niz_cifara[i]==niz_cifara[i-1]) {
				j=i;
				while(j>=0) {
					if(niz_cifara[i]==niz_cifara[j]) br++;
					else break;
					j--;
				}
			}
			else br++;
		}
		
		else br++;
		
		finalni_niz[indeks2]=pom;
		finalni_niz[indeks2+1]=br;
		indeks2=indeks2+2;
		i=i-br+1;
	}
	
	printf("Finalni niz glasi:\n");
	for(i=0; i<indeks2; i++){
		printf("%d ", finalni_niz[i]);
	}
	
	
	return 0;
}
