/*Napisati funkciju izbaci_cifre koja prima dva niza tipa int. Prvi niz sadrži određeni broj cijelih brojeva, a drugi niz je niz cifara. 
Potrebno je iz svih članova prvog niza izbaciti sve one cifre koje se nalaze u drugom nizu. Ako nakon izbacivanja cifara u nekom članu niza ne 
preostane niti jedna cifra, taj član niza treba dobiti vrijednost nula.

Funkcija vraća 1 ako je izbacivanje bilo uspješno, a 0 ako niz cifara iz nekog razloga nije ispravan: ako se u nizu nalazi vrijednost manja od 0 
ili veća od 9 ili ako se neki od članova ponavlja.
*/

#include <stdio.h>
#include <stdlib.h>

int izbaci_cifre ( int niz1[], int n1, int niz2[], int n2){
	
	int i,j,x,h=1,pom;
	
	for (j=0; j<n2; j++)
	if (niz2[j]<0 || niz2[j]>9) return 0;
	
	for (i=0; i<n2; i++){
		for (j=0; j<n2; j++){
			if (niz2[i]==niz2[j] && i!=j) return 0;
		}
	}
	
	for (i=0; i<n1; i++){
	    x=(niz1[i]);
	    niz1[i]=0;
	    
	    do {
	        pom=(x%10);
	        for (j=0; j<n2; j++){
	            if (abs(pom) == niz2[j]) break;
	            }
	        
	        if (j==n2){
	            niz1[i]=niz1[i]+ (pom*h);
	            h=h*10;
	        }
	        x=x/10;
	        
	    } while (abs(x)>0);
	    
	    h=1;
	    
	}
	return 1;
	 
}
int main() {
	

	return 0;
}
