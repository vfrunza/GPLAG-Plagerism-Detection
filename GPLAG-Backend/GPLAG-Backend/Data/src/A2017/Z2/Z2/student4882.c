#include <stdio.h>
#define BROJ 100
#define BROJNOVI 1000
int main() {
	int n,i,j,c,k;
	int indeksubacenog=0;
	int niz[BROJ],noviniz[BROJNOVI], finalniniz[BROJNOVI];
	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	printf("Unesite clanove niza: ");
	for (i=0; i<n; i++){
		scanf("%d", &niz[i]);	
	}
		int indeks=0;
	for(i=0; i<n; i++){
		int x=niz[i];
		while (x != 0) {
			c=x%10;
           noviniz[indeks]=c;
           indeks++;
			x= x/10;
		}
	}
	int pozicija, ind=0,nizbrojaca[1000]={};
    for(i=0; i<n; i++){
		int br=1;
		for(j=i+1; j<n; j++){
			if(noviniz[i]==noviniz[j]) br++;
			else break;
		} 
		   nizbrojaca[ind]=br;
		    ind++;
		    if(br>1) j=i;
	}
	
	
	//izbacimo duplikate iz novog niza
	int novi_indeks=0;
	for(i=0; i<n; i++){
		int broj_pojavljivanja=0;
		for(j=0; j<n; j++){
			if(niz[i]==niz[j]) {broj_pojavljivanja++; novi_indeks=i;}
			if(broj_pojavljivanja>1){
				for(k=j; k<n-1; k++)
				niz[k]=niz[k-1]
		    }
		    n--;
		    j--;
			}
		}
	}
	printf("Finalni niz glasi: ");
	for (i=0; i<100; i++){
		printf("%d ", nizbrojaca[i]);	
	}
	return 0;
}
