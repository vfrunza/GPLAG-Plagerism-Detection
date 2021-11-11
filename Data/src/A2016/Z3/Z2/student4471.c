#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//funkcija koja racuna fibonacijevi brojeve
long int fib(int x){
	
	if(x<=1){
		
		return x;
		
	}else {
		
		return fib(x-1) + fib(x-2);
	}
	
	
}

//FUNKCIJA KOJA PROVJERAVA JE LI BROJ FIBONACIJEV I VRACA 0 NIJE , 1 ako jest
int isfibonaci( int num){
	int counter = 0;
	
	//OVIM USLOVOM OBEZBJEDUJEMO DA 0 NIJE FIBONACIJEV BROJ
	if(num <= 0 ){
		return 0;
	}
	
	while(1){
		if(fib(counter) < num){
			counter++;
			continue;
		}
		
		if(fib(counter) == num){
			return 1;
		}
		
		if(fib(counter) > num ){
			return 0;
		}
		
		
	}
	
}

//FUNKCIJA ZA SUMIRANJE CIFRI BROJA ! 
int sumaCIFARA(int x){
	
	int broj = 0;
	int suma = 0;
	x = (fabs)(x);
	
	while(x != 0){
		broj = x%10;
		suma += broj;
		x = x/10;
	}
	
	return suma;
}

//FUNKCIJA KOJA UBACUJE POSLIJE SVAKOG ELEMNTA ELEMNT KOJI JE SUMA CIFARA PRETHODNOG BROJA NIZA
void ubaci(int niz[], int velicina){
	
	int velicina1 = velicina;
	int i, j, x=1 , y=0;   //POSTAVIT CEMO X=1 JER JE TO PRVO MJESTO GDJE CEMO UBACITI NOVI CLAN A Y=0 jer CEMO RACUNATI PRVO NJEGOVU SUMU 

	
	for(i=0; i<velicina; i++){ //OVA PETLJA CE SE OBAVITI velicina puta JER cemo samo tolko puta ubacivati brojeve
	
		for(j=velicina1 -1; j>=x-1; j--){   //POMJERAMO OVOM PETLJOM NIZ ZA JEDNO MJESTO UDESNO 
		
			niz[j+1] = niz[j];
		}
	
		
		niz[x] = sumaCIFARA(niz[y]);
		//POVECAVAT CEMO I VELICINU NIZA JER DODAJEMO CLANOVE te X I Y za 2 ,JER CEMO RACUNATI SUMU ELEMANATA NA POZICIJI 0,2,4...
		velicina1++; x = x + 2; y = y + 2;
	}
	
}

//FUNKCIJA KOJA IZBACUJE SVE CLANOVE NIZA KOJI SU FIBONACIJEVI
int izbaci(int niz[],int velicina){
	int i, j ;
	int velicina1 = velicina; //JER velicina(u) ne mozemo promijeniti iz funkcije u maiinu ce opet ispisivati ono sto smo poslali funkciji
	
	//kroz ove petlje provjeramo ako je broj u nizu fibonacijev prepisujemo iza brojeve preko njega i smanjujemo velicinu
	for(i=0;i<velicina1;i++){
		
		if( isfibonaci ( niz[i] ) == 1){
			
			for(j=i;j<velicina1-1;j++){
				
				niz[j] = niz[j+1];
			}
			
			velicina1--;
			i--;
		}
	}
	
	
	return velicina1;
	
}


int main() {
	//DOVOLJNO JE NAPRAVITI NIZ OD 100 u ovom zadatku
	
	int niz[100] ;
	int n = 10;
	int i ,velicina ;
	
	
	printf("Unesite niz od 10 brojeva: ");
	
	for(i=0;i<10;i++){
		scanf("%d",&niz[i]);
	}
	
	//OVDJE ZNAMO DA JE NIZ DUPLO VECI OD PRVOBITNOG
	ubaci(niz,n);
	
	//TREBA NAM VARIJABLA DA SACUVA VELICINU NOVOG NIZA 
	velicina = izbaci(niz,2*n); 
	
	printf("Modificirani niz glasi: ");
	
	
	for(i=0; i<velicina; i++){
		
		if(i!=velicina-1){
			
			printf("%d, ",niz[i]);
			
		}else{
			
			printf("%d.",niz[i]);
		}
	}
	
	
	return 0;
}
