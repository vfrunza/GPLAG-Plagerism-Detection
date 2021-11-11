#include <stdio.h>
#include <stdlib.h>
#define velicina 10

/* Funkcija koja nakon svakog clana datog niza ubacuje
novi clan niza koji predstavlja sumu cifara svog prethodnika.  */

void ubaci (int *niz, int n) {
	int br, i, suma=0, cifra;
	
	for(i=n-1; i>=0; i--){
		*(niz+2*i)=*(niz+i);
		
	}
	
	for(i=0; i<2*n; i++){
		if(i%2==1){
			br=*(niz+i-1);
			while(br!=0){
				cifra=br%10;
				suma+=cifra;
				br=br/10;
				
			}
			
			suma=abs(suma);
			
			niz[i]=suma;
			
			suma=0;
		}
		
	}

}

/*Funkcija koja provjerava da li neki broj pripada Fibonacci nizu. */

int i_am_fibonacci (int n){
	int prvi=1, drugi=1, broj;
	
	if(n==1){
		return 1;           
	}
	
	else {
		
		broj=prvi+drugi;
		
		while(broj<n){
			prvi=drugi;
			drugi=broj;
			broj=prvi+drugi;
		}
		
		if(broj==n){
			
			return 1;
		}
		
		else return 0;
	}
	
}

/* Funkcija koja izbacuje Fibonaccijeve brojeve datog niza. */


int izbaci (int *niz, int n ){
	int i, j;
	
	for(i=0; i<n; i++){
		if(i_am_fibonacci(*(niz+i))==1){
			for(j=i; j<n-1; j++){
				*(niz+j)=*(niz+j+1);
			}
			
			n--;
			i--;
		}
	}
	
	return n;
}

int main(){
	
	int  niz[2*velicina], i, rezult_niz=0 ;
	
	printf("Unesite niz od 10 brojeva: ");
	
	for(i=0; i<velicina; i++)
	scanf("%d", &niz[i]);
	
	/* Pozivanje funkcija */
	
	ubaci(niz, velicina); 
	rezult_niz=izbaci(niz, 20); 
	
	printf("Modificirani niz glasi: ");
	
	for(i=0; i<rezult_niz; i++){
		if(i==rezult_niz-1)
		printf("%d.", niz[i]);
		else printf("%d, ", niz[i]);
		
		} 

	
	return 0;
	
}


