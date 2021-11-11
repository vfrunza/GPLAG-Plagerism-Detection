#include <stdio.h>
#include <math.h>

int main() {
	int broj[100], niz2[1000];
	int i, j=0, cifra, brojac=1, pocetna_cifra, broj_cifre=0, n, r=0, k;
	
	do{
		printf("Unesite velicinu niza: ");
		scanf("%d", &n);
	} while(n>100);
	
	printf("Unesite clanove niza: ");
	for (i=0;i<n;i++){
		do{
			scanf("%d", &broj[i]);
		}while(broj[i]<0);
	}
 
	for (i=0;i<n;i++){	
		do{
			j=0;
			while(broj[i]/pow(10,j)>=10){
				j++;
			}
			for (k=j;k>=0;k--){
				broj_cifre++;
				cifra=broj[i]/pow(10,k);
				broj[i]-=cifra*pow(10,k);
		
				if(broj_cifre==1) {
					pocetna_cifra=cifra; 
					brojac=0;
				}
		
				if (cifra==pocetna_cifra) { 
					brojac++; 
				}
				else {
					niz2[r]=pocetna_cifra;
					niz2[r+1]=brojac;
					r+=2;
					pocetna_cifra=cifra;
					brojac=1;
				}
			}
				
		}while (broj[i]>0);
	}
	niz2[r]=pocetna_cifra;
	niz2[r+1]=brojac;
	r+=2;
	printf("Finalni niz glasi:\n");
	for(i=0;i<r;i++)
		printf("%d ", niz2[i]);
	return 0;
}