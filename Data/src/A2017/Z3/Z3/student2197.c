#include <stdio.h>
#include <stdlib.h>
int izbaci_cifre(int niz1[],int vel1,int niz2[],int vel2) {
	int i,j,brojac,broj,faktor;
	
	/* Provjeravam da li je niz cifara ispravan */
	for(i=0;i<vel2;i++) {
		if(niz2[i]<0 || niz2[i]>9)
			return 0;
		for(j=i;j<vel2-1;j++) {
			if(niz2[j+1]==niz2[i])
				return 0;
		}
	}
	/* Rastavljam clanove prvog niza na cifre i uporedjujem sa ciframa iz drugog niza  */
	for(i=0;i<vel1;i++) {
		int negativan = 0;
		if(niz1[i]<0)
			negativan=1;
		broj=abs(niz1[i]);
		niz1[i]=0;
		faktor=1;
		while(broj!=0) {
			
			brojac=0;
			int cifra=broj%10;
			broj/=10;
			for(j=0;j<vel2;j++) {
				if(cifra!=niz2[j]) 
					brojac++;
			}			           	 /* Ako se cifra clana iz niza1 ne nalazi u nizu2
										onda dodaj tu cifru na taj clan sa odgovarajucim faktorom s tim da 
										smo prethodno vrijednost tog clana postavili na nulu	 */
			if(brojac==vel2) { 			
				niz1[i]+= cifra*faktor;
				faktor*=10;
			}
		}
		if(negativan)
			niz1[i]*=-1;
	}

	return 1;
} 
int main() {

	return 0;
}
