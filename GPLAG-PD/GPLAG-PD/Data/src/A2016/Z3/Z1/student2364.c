#include <stdio.h>

int main(){
	int A,B,i,Suma=0,ProstBroj=0;
	int daj_prost();
	
		/* Provjeravamo da li upisani brojevi zadovoljavaju uslove zadatka */
		/* Ukoliko ne zadovoljavaju pomocu do while petlje osiguravamo da program trazi ponovni unos */
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		
		if(A>=B)
		printf("A nije manje od B.\n");
		else if(A<=0)
		printf("A nije prirodan broj.\n");
	}
		while(A<=0 || A>=B);
		
		/* Pozivamo funkciju za prost broj, sve dok je taj broj manji od B */
		for(i=0; i<B; i++){
			ProstBroj = daj_prost();
			if(ProstBroj>A && ProstBroj<B)
			Suma+=ProstBroj;
			else if(ProstBroj>=B)
			break;
		}
		printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, Suma);
		
		return 0;
}
	/* Funkcija koja pri svakom ulasku vraca drugi prost broj */
int daj_prost(){
	static int broj=2;
	int i=2, prost=0;
	
	while(i<=broj){
	if(broj%i==0 && broj==i){
		prost=broj;
		break;
	}
	/* Ukoliko broj nije prost, osiguravamo ponovni ulazak u petlju i trazenje istog */
	else if(broj%i==0 && broj!=0){
		broj++;
		i=2;
	}
	i++;
	}
	
	broj++;
	return prost;
}








