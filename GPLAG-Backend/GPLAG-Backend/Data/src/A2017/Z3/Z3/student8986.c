#include <stdio.h>
#include <math.h>

int izbaci_cifre(int* niz1,int vel1,int* niz2,int vel2){
	
	int i=0,j,*p,*q,cifra,broj=0,stepen=-1,br=0,predznak=1;
	
/* Funkcija vraca nulu ako niz cifara sadrzi element manji od nule ili veci od devet */
	p=q=niz2;
	while(p<niz2+vel2){
		if(*p<0 || *p>9)return 0;
		p++;
	}
	
/* Funkcija vraca nulu ako niz cifara sadrzi element koji se ponavlja */
	for(i=0;i<vel2;i++){
		for(j=0;j<vel2;j++){
			if(niz2[j]==niz2[i] && j!=i)return 0;
		}
	}
	
	p=niz1;
	q=niz2;
	i=0;
	while(p<niz1+vel1){
	
/* Provjerava da li je clan niza brojeva negativan i memorise predznak */		
		if(*p<0){
			predznak=-1;
			*p=-*p;
		} else predznak=1;
		
		while(*p>0){
			cifra=*p%10;
			*p=*p/10;
			
/* Provjerava da li niz cifara sadrzi cifre broja i povecava brojac za jedan za svaku cifru iz niza cifara koja nije ista cifri broja */				
				while(q<niz2+vel2){
					if(*q!=cifra)br++;
					q++;
				}q=niz2;
/* Ako je brojac jednak velicini niza cifara to znaci da se cifra broja ne pojavljuje nijednom u tom nizu cifara */	
/* Konacni broj je jednak zbiru cifara broja koje se ne pojavljuju u nizu cifara, sa odgovarajucim stepenom koji raste samo ako se cifra broja ne izbacuje */			
			if(br==vel2){
				stepen++;
				broj=broj+cifra*pow(10,stepen);
			}br=0;
		}	
/* Vraca broj na njegovu prvobitnu pozitivnu ili negativnu vrijednost i upisuje taj broj u prvobitni niz brojeva na mjesto gdje je prethodno stajao prije poziva funkcije */		
		broj=broj*predznak;	
		niz1[i++]=broj;
		broj=0;
		stepen=-1;
		p++;
	}
	
	return 1;
}

int main() {
	
	int i,v1,v2,niz1[100],niz2[100];
	
	scanf("%d",&v1);
	for(i=0;i<v1;i++)scanf("%d",&niz1[i]);
	scanf("%d",&v2);
	for(i=0;i<v2;i++)scanf("%d",&niz2[i]);
	
	printf("%d",izbaci_cifre(niz1,v1,niz2,v2));
	return 0;
}
