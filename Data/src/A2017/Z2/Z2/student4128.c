#include <stdio.h>

#define BROJ_EL 100
#define BROJ_CIFARA 1000

int main() {
	int niz[BROJ_EL],i,j, velicina,cifre[BROJ_CIFARA];
	int vel_cifre=0,vel_pomocni,pomocni[10],broj,broj_ponavljanja;
	int rezultat[BROJ_CIFARA];
	int vel_rezultat=0;
	
	
	do{
		printf("Unesite velicinu niza: ");
		scanf("%d",&velicina);
	}
	while(velicina<=0 || velicina>BROJ_EL);
	printf("Unesite clanove niza: ");
	for (i = 0; i < velicina; i++) {
		scanf("%d",&niz[i]);
		if(niz[i]<0){
			i--;
		}
		else{
			
			pomocni[11];
			vel_pomocni=0;
			
			broj = niz[i];
			while(broj!=0){
				pomocni[vel_pomocni++] = broj%10;
				broj/=10;
			}
			for(j=vel_pomocni-1;j>=0;j--){
				cifre[vel_cifre++]=pomocni[j];
			}
			if(niz[i]==0)cifre[vel_cifre++]=0;
			
		}
	}
	
	
	broj_ponavljanja=1;
	for (i = 1; i < vel_cifre; i++) {
		if(cifre[i]!=cifre[i-1]){
			rezultat[vel_rezultat++]=cifre[i-1];
			rezultat[vel_rezultat++]=broj_ponavljanja;
			broj_ponavljanja=1;
		}else{
			broj_ponavljanja++;
		}
	}
	rezultat[vel_rezultat++]=cifre[vel_cifre-1];
	rezultat[vel_rezultat++]=broj_ponavljanja;
	
	printf("Finalni niz glasi:\n");
	for(i=0;i<vel_rezultat;i+=2){
		printf("%d %d ",rezultat[i],rezultat[i+1]);
	}
	
	
	return 0;
}
