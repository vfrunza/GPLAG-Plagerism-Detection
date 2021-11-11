#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*funkcija koja ubacuje clanove koji predstavljaju zbir cifara u niz*/

void ubaci (int* p, int duzina){
	int* pomp=p;
	int* pomp2;
	int clan=0;
	int k=0;
	int broj;

	while(pomp<p+2*duzina){
		broj=abs(*pomp);
		while(broj){
			clan=clan+broj%10;
			broj= broj/10;
		}
	
		for(pomp2=p+(duzina+k); pomp2>pomp; pomp2--){
			*pomp2=*(pomp2-1);
		}
		k++;
		pomp++;
		*pomp=clan;
		clan=0;
		pomp++;	
	}
}	
/*funkcija koja vraca 1 ako je fibbonacijaev broj*/

int fibonaccijeve(int broj){
	
	int niz[1000];
	niz[0]=1;
	niz[1]=1;
	
	if(broj==1) 
		return 1;
	
	int*pomp1=niz;
	int*pomp2=niz+1;
	int*pomp3=niz+2;
	
	while(1){
		*pomp3=*pomp2+*pomp1;
		if(*pomp3==broj)
			return 1;
		if(*pomp3>broj){
			return 0;
		}
		pomp1++;
		pomp2++;
		pomp3++;
	}
}

/*funkcija koja izbacuje clan niza ako je taj clan fibbonacijev broj*/

int izbaci(int*p, int duzina){
	int*pomp=p;
	int*pomp2;
	int broj;
	
	while(pomp<p+duzina){
		
		broj=*pomp;
        broj=fibonaccijeve(broj);
        if(broj==1){
        	for(pomp2=pomp; pomp2<p+duzina-1; pomp2++){
        		*pomp2=*(pomp2+1);
         }
        	duzina--;
        	pomp--;
    	 }
			pomp++;	
	}
	
	return duzina;	
}

int main() {
	
	int i,n; 
	int niz[100];
	
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++)
		scanf("%d", &niz[i]);
	
	ubaci(niz, 10);
	n=izbaci(niz, 20);
	
/* ispis modificiranog niza */

	printf("Modificirani niz glasi: ");
	for(i=0; i<n; i++){
		if(i==n-1)
			printf("%d.", niz[i]);
		else 
			printf("%d, ", niz[i]);
	}
	return 0;
}