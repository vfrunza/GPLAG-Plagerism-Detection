#include <stdio.h>

int ispitaj_ispravnost(int niz[], int vel){
	int i,j;
	for(i=0;i<vel;i++){
		if(niz[i]<0 || niz[i]>9) return 1;
		for(j=0;j<vel;j++){
			if(i!=j){
				if(niz[i]==niz[j]) return 1;
			}
		}
	}
	return 0;
}

int izbaci(int broj, int cifra){
	int novi=0, negativan=0;
	if(broj<0){ 
		negativan=1;
		broj*=-1;
	}
	while(broj!=0){
		if(broj%10==cifra){ 
			broj/=10;
			continue;
		}
		novi+=broj%10;
		broj/=10;
		novi*=10;
	}
	novi/=10;
	while(novi!=0){
		broj+=novi%10;
		novi/=10;
		broj*=10;
	}
	broj/=10;
	if(negativan==1) broj*=-1;
	return broj;
}

int izbaci_cifre(int niz[], int vel, int cifre[], int velc){
	if(ispitaj_ispravnost(cifre,velc)) return 0;
	int i,j;
	for(i=0;i<vel;i++){
		for(j=0;j<velc;j++){
			niz[i]=izbaci(niz[i],cifre[j]);
		}
	}
	return 1;
}

int main() {
	int brojevi[50],velb=0,cifre[50],velc=0,i;
	printf("Unesite clanove niza brojeva (max 50, -1 za prekid): ");
	for(i=0;i<50;i++){
		int x;
		scanf("%d",&x);
		if(x==-1) break;
		brojevi[i]=x;
		velb++;
	}
	printf("Unesite cifre (max 10 , -1 za prekid):");
	for(i=0;i<10;i++){
		int x;
		scanf("%d",&x);
		if(x==-1) break;
		cifre[i]=x;
		velc++;
	}
	if(izbaci_cifre(brojevi,velb,cifre,velc)){
		printf("Vas niz brojeva izgleda ovako: ");
		for(i=0;i<velb;i++){
			printf("%d ",brojevi[i]);
		}
	}
	return 0;
}
