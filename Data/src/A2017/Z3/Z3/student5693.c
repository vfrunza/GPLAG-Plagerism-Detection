#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ponavljanje(int niz[], int vel, int br){
	int i,broj=0;
	for(i=0; i<vel; i++) {
		if(niz[i]==br) broj++;
		return broj;
	}
}


int izbaci_cifre(int brojevi[], int vel1, int cifre[], int vel2) {
	int i,j,izbaci,niz,broj=0,cifra=1;

    for(i=0; i < vel1; i++) {
        	if( ponavljanje(cifre,vel2,cifre[i]) > 1 || cifre[i] < 0 || cifre[i] >9) return 0;
       for(j=0; j<vel2; j++ ) {
           while(brojevi[i] !=0) {
           	if(abs(brojevi[i]%10) != cifre[j]) {
           		broj += (brojevi[i]%10)*cifra;
           		cifra*=10;
           	}
           	brojevi[i]/=10;
           }
           brojevi[i]=broj;
           broj=0;
           cifra=1;
       }
    }
    return 1;
}
       
      
int main() {
	int  vel1=0,vel2=0,brojevi[100],cifre[100];
	izbaci_cifre(brojevi,vel1,cifre,vel2);
	
	return 0;
}
