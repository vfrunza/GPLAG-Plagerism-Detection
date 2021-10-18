#include <stdio.h>

int main() {
	int N,i,j,broj,temp,velFinalnog;
	int niz[100];
	int drugiNiz[1000];
	int sortiraniNiz[1000];
	int finalniNiz[1000];
	int brojacCifara[1000];
	for(i=0;i<1000;i++) {
		brojacCifara[i]=1;
	}
	do {
		printf("Unesite velicinu niza: ");
		scanf("%d",&N);
	}while(N<0 || N>100);
	printf("Unesite clanove niza: ");
	
			/* Unos */
	
	for(i=0;i<N;i++) {
		scanf("%d",&niz[i]);
		if(niz[i]<0) {
			i--;
			printf("Unesite ponovo\n");
		}
	}
	
	/* Prolazim kroz niz unazad i razlazem brojeve na cifre u drugiNiz */

	int brojac=0;
	j=0;
	for(i=N-1;i>=0;i--) {
		if(niz[i]==0) {
			drugiNiz[j] = 0;
			brojac++;
			j++;
		}
		else {
			broj = niz[i];
		 	while(broj!=0) {
				drugiNiz[j] = broj%10;
				broj/=10;
				brojac++;
				j++;
			}
		}
		if(i==0)
			break;
	}

	
		/*  SORTIRANI NIZ ( obrnuti drugiNiz ) */
		
	for(j=0;j<brojac;j++) {
		sortiraniNiz[j] = drugiNiz[brojac-j-1];
	}

	
		/* Prolazim kroz sortirani niz i broj ponavljanja cifara unosim u niz brojača */

	for(i=0;i<brojac;i++) {
		temp=sortiraniNiz[i];
		for(j=i+1;j<brojac;j++) {
			if(sortiraniNiz[j]!=temp)
				break;
			brojacCifara[i]++;
		}
	}
	
		/* Pomocu elemenata sortiranog niza i niza brojača pravim finalni niz */
		
	temp = 0;
	for(i=0;i<1000;i+=2) {
		if (temp>=brojac)
			break;
		finalniNiz[i] = sortiraniNiz[temp];
		finalniNiz[i+1] = brojacCifara[temp];
		temp+=brojacCifara[temp];
	}
	velFinalnog = i;

	printf("Finalni niz glasi:");
	printf("\n");
	for(i=0;i<velFinalnog;i++) {
		printf("%d ",finalniNiz[i]);
	} 
	

	return 0;
}


	
