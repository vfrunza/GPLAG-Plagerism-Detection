#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define br_el 10
#define br_el2 20


int ubaci (int *niz, int velicina){
	int cifra,i,br, br2=0;
	for(i=velicina-1; i>=0;i--){
		*(niz+2*i)=*(niz+i);
	}
	for(i=0;i<velicina*2;i++){
		if(i%2==1){
			br=*(niz+i-1);
			while(br!=0){
				cifra=br%10;
				br2+=cifra;
				br/=10;	
			}
			br2=abs(br2);
			*(niz+i)=br2;
			br2=0;
		}
	}
		
	}
	
	

/*
int izbaci(){
	
}
*/
int main() {

	int niz[10],i,n;
	
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
	scanf("%d",&niz[i]);
	}
	
/*	n=ubaci(niz, br_el);
	
	n=izbaci (niz, br_el2);

	
*/
	printf("Modificirani niz glasi: ");
	for(i=0;i<n;i++){
		if(i<(n-1)){
			printf("%d",niz[i]);
		}
		else {
			printf("%d",niz[i]);
		}
	}
	
	
	
	return 0;
}
