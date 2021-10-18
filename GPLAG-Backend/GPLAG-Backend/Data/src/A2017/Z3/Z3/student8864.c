#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int izbaci_cifre(int a[],int vela,int b[],int velb){
	int i,j,pozicija,cifra,ulazniBr,izlazniBr;
	for(i=0;i<velb;i++){
		if(b[i]<0 || b[i]>9) return 0;
	}
	for(i=0;i<velb;i++){
		for(j=i+1;j<velb;j++){
			if(b[i]==b[j]) return 0;
		}
	}
	for(i=0;i<vela;i++){
		for(j=0;j<velb;j++){
			pozicija=1;
			izlazniBr=0;
			ulazniBr=a[i];
			if(a[i]<0) ulazniBr=ulazniBr*(-1);
			while(ulazniBr!=0){
				cifra=ulazniBr%10;
				if(cifra!=b[j]){
					izlazniBr=izlazniBr+cifra*pow(10,pozicija-1);
					pozicija++;
				}
				ulazniBr/=10;
			}
			if(a[i]>0) a[i]=izlazniBr;
			else a[i]=(-1)*izlazniBr;
		}
	
	}
	return 1;
	
	
}

int main() {
	printf("Zadaća 3, Zadatak 3");
	return 0;
}
