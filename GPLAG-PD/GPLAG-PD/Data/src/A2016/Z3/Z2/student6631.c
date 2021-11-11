#include <stdio.h>
#include <math.h>

int sCifara(int a){												/* pomocna funkcija koja kao rezultat daje sumu cifara */
	
	int zadnjaCifra, duzinaBroja=0, sumaC=0, kopija;
	int i=0;
	a=fabs(a);
	kopija=a;
	
	do{
		kopija=kopija/10;
		duzinaBroja++;
	}
	while(kopija!=0);
	
		
	for(i=0; i<duzinaBroja;i++){
		zadnjaCifra=a%10;
		sumaC=sumaC + zadnjaCifra;
		a=a/10;
	}
	
	return sumaC;
}


int fib(int poredi){											/* pomocna funkcija koja provjerava da li je broj fibonacijev */
    int prvi, drugi, sljedeci, i=0;
    int sljedeci_broj, jeJednak=0;
    
    prvi=1;
    drugi=1;
    sljedeci=2;
    
    while(i<poredi){
        sljedeci=prvi+drugi;
        if(poredi==sljedeci || poredi==0 || poredi == 1 || poredi==2)  jeJednak=1;
        prvi=drugi;
        drugi=sljedeci;
        i++;
    }
    
    if(jeJednak==1)return 1;
    else return 0;
	
}

void ubaci(int niz[],int duzinaNiza){
	int stvarnaDuzina= duzinaNiza*2;
	int i,pomocna;
	
	for(i=0;i<duzinaNiza-1;i++){
		niz[stvarnaDuzina-2-2*i]=niz[duzinaNiza-i-1];
	}
	for(i=1;i<=stvarnaDuzina;i++){
	pomocna=niz[i-1];
		
		if(i%2!=0){
			niz[i]=sCifara(pomocna);
		}
	}
	
	
}
	
int izbaci(int* niz, int duzinaNiza){
	int i,j;
	int prvi, drugi, sljedeci, jeJednak=0;
	
	prvi=1;
    drugi=1;
    sljedeci=2;
	
	for(i=0;i<duzinaNiza;i++){
    
    		jeJednak= fib(niz[i]);
			if(jeJednak==1){
				for(j=i;j<duzinaNiza-1;j++){
				niz[j]=niz[j+1];
			}
			duzinaNiza--;
			i--;
			} 
	}
	return duzinaNiza;
}
	

int main() {
	
	int niz[20];
	int i, prvi=0;
	int duzinaIspis, nizDuzina=10, nizDuzinaStvarna=20;
	
	printf("Unesite niz od 10 brojeva: ");
	
		
	for(i=0;i<nizDuzina;i++){
		scanf("%d", &niz[i]);
	}
	
	ubaci(niz,nizDuzina);
	duzinaIspis=izbaci(niz,nizDuzinaStvarna);
	
	printf("Modificirani niz glasi: ");
	
	if(duzinaIspis==0){
		printf("Prazan niz.");
	}
	else{
	for(i=0; i<duzinaIspis;i++){
		printf("%d", niz[i]);
		if (prvi!=duzinaIspis-1){
			printf(", ");
		}
		else printf (".");
	prvi++;
		
	}
	}
	return 0;
}