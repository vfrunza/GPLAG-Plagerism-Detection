#include <stdio.h>

int daj_prost()
{
	int prost;
	int j;
	/* Deklarisem staticku promjenljivu*/
	static int a=2;
	for(;; a++) {
		/*Uvodim varijablu prost i pridajem joj istinitosnu vrijednost 1*/
		prost=1;
		/* Petljom određujem proste brojeve , u slučaju djeljivosti staticke promjenljive sa nekim od brojeva manjih od njene vrijednosti , znaci da ona nije prost broj te varijabla prost poprima istinitosnu vrijednost 0*/
		for(j=2; j<a; j++) {
			if(a%j==0) prost=0;


		} /*Funkcija vraca vrijednost staticke uvecane za jedan , samo  slucaju da varijabla prost ima istinitosnu vrijednost 1*/
		if(prost==1)return a++;

	}

}


int main()
{
	int A,B,i,broj;
	int suma=0;
	/* Unosim interval brojeva od A do B, petljom osiguravam da se brojevi unose sve dok ne budu u ispravnom intervalu */
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
		/* Osiguravam da su mi brojevi iz skupa prirodnih brojeva i da je A izricito manje od B*/
		if(A<=0)
			printf("A nije prirodan broj.\n");
		if(A>B || A==B)
			printf("A nije manje od B.\n");
	} while(A<=0 || A>B || A==B ) ;
	for(i=0; i<B; i++) {
		/*Pozivam funkciju , smještenu u petlju , da bi za svaki broj do B provjerila da li je prost*/
		broj=daj_prost();
		if(broj>A && broj<B)
			/*Racunam sumu svih prostih brojeva , ciju sam povratnu vrijednost dobila pozivom funkcije*/
			suma+=broj;
	}

	/*Ispis*/
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;



}
