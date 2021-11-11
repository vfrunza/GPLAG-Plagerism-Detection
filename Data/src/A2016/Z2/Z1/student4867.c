#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Napisati program koji omogućuje unos jednog cijelog broja, 
a zatim na ekranu ispisuje broj koji se dobije tako što se od prve cifre (s desne strane) oduzme druga cifra, od druge treća,
od treće četvrta itd. Ako bi neka od ovih razlika bila negativan broj, uzima se njegova apsolutna vrijednost.
Ako korisnik unese negativan broj uzima se njegova apsolutna vrijednost, a ako unese jednocifren broj rezultat treba biti 0.
*/

int main() {
	int broj, cifra,cifra1,nb,a , b=0;
	int rez=1;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	broj=abs(broj);
	if (broj >= -9 && broj <= 9){ printf("0"); return 0;}
	else
	 {	
			while(broj>9) {
			 cifra = broj%10;
		     broj=broj/10;
		     cifra1=broj%10;
		     nb=abs(cifra1-cifra);
		     rez=rez*10+nb;
		    } 
			
			while(rez%10==0){rez=rez/10; b++;}
			if(b==1){rez=rez*10;}
		    while(rez!=0){
		    	if(rez==1){rez--;}
		    	a = rez % 10;
		    	rez=rez/10;
		    	if(rez==1){rez--;}
		    	printf("%d",a);
		    } 
	}
	

return 0;
}