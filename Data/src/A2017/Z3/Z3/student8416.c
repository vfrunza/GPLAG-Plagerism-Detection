#include <stdio.h>
#include <stdlib.h>
 int okreni(int broj){
 	int c, r=0;
 	while(broj!=0){
 		c=broj%10;
 		r=(r*10)+c;
 		broj/=10;
 	}
 	return r;
 }

int izbaci_cifre(int niz1[], int velicina1, int niz2[], int velicina2){
	int i, j, ostatak, novi_broj=0, broj, negativan=0;
	
	for(i=0; i<velicina2; i++){
		if(niz2[i]<0 || niz2[i]>9) return 0;
		for(j=i+1; j<velicina2; j++){
			if(niz2[i]==niz2[j]) return 0;
		}
	}
	
	for(i=0; i<velicina1; i++){
		broj=niz1[i];
		for(j=0; j<velicina2; j++){
			if(broj<0) negativan=1;
			while(broj!=0){
				ostatak=abs(broj%10);
				if(ostatak==niz2[j]){
					goto preskoci;
				}
				novi_broj=(novi_broj*10)+ostatak;
				preskoci:
				broj/=10;
			}
			if(negativan) novi_broj*=-1;
			niz1[i]=okreni(novi_broj);
			novi_broj=0;
			broj=niz1[i];
			negativan=0;
		}
	}
	return 1;
}

int main(){
	int brojevi[] = {-12345, 12345};
int cifre[] = {3,5};
int i;
izbaci_cifre(brojevi, 2, cifre, 2);
printf("%d %d", brojevi[0], brojevi[1]);
	return 0;
}
