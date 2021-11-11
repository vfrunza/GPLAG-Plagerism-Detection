#include <stdio.h>

int daj_prost(){
	/* Funkcija daj_prost pronalazi prost broj tako sto prolazeci petljom od 2 do određenog broja "br" gleda da li postoji neki broj sa kojim je djeljiv taj broj "br",
	te ako postoji, taj broj nije prost pa se br povecava za 1, i se vraca na 2 i prolazi sve do trenutka kada je "br" jednak broju i, sto znaci da je petlja prosla kroz sve brojeve
	do tog broja i to je trazeni prost broj. Kako je "br" deklarisan kao "static int" u svakom sljedecem pozivanju se nece vracati na 2, nego krece od broja za 1 veci od prethodnog prostog broja. (br++) */
    int i,prbr=0;
    static int br=2;
    for(i=2; i<=br; i++) 
    {
    	if(br==i) 
    	{
    		prbr=br; 
    		break; 
    	} 
    	else if (br%i==0&&br!=i) {	
    		br++; 
    		i=2; 
    	}
    }
    br++;
    return prbr;
}
int main() {
	int A,B,suma=0,i,poziv;
	do {
	    printf("Unesite brojeve A i B: ");
	    scanf("%d %d", &A, &B);
	    if (A>=B) printf("A nije manje od B.\n");
	    else if (A<=0) printf("A nije prirodan broj.\n");
	} while (A>=B || A<=0 || B<=0);
	for (i=0; i<B; i++) 
	{
		poziv=daj_prost();
		if (poziv<B && poziv>A) suma=suma+poziv;
		else if (poziv>B) break;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,suma);
	return 0;
}
