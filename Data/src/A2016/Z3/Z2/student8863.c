#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ubaci(int* niz, int duzina){
	int i, suma=0, n, temp;
	for(i=duzina-1; i>=0;i--){
		*(niz+2*i)=*(niz+i);
	}
	for(i=0; i<duzina*2; i++){
		if(i%2==1){
			n=abs(*(niz+i-1));
			while(n>0){
				temp=n%10;
				suma+=temp;
				n/=10;
			}
			*(niz+i)=suma;
		}
		suma=0;
	}
}

int izbaci(int* niz, int duzina){
	int fibonnaci[46], a=0, b=1, i, j, k, s; /*duzina Fibonnacijevog niza je uzeta da bude 46 jer je 46. clan Fibonnacijevog niza najveci clan koji ulazi u opseg integera */ 
		for(i=0; i<46; i++){
			if(i==0)
				fibonnaci[i]=1;
			else{
				fibonnaci[i]=a+b;
				a=b;
				b=fibonnaci[i];
			}
		}
	for(i=0; i<46; i++){
		for(j=0; j<duzina; j++){
			if(*(niz+j)==fibonnaci[i]){
				for(k=j; k<duzina-1; k++){
					*(niz+k)=*(niz+k+1);
				}
				duzina--;
				j--;
			}
		}
	}
	s=duzina;
	return s;
}

int main() {
	int niz[20], l=10, i, s;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<l; i++){
		scanf("%d", &niz[i]);
	}
	ubaci(niz,l);
	s=izbaci(niz,2*l);
	printf("Modificirani niz glasi: ");
	for(i=0; i<s; i++){
		if(i==s-1)
			printf("%d.", *(niz+i));
		else
			printf("%d, ", *(niz+i));
	}
	return 0;
}