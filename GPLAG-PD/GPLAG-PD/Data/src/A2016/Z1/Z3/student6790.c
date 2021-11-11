#include <stdio.h>

int main() {
	char vozila;
	float bc=0,bb=0,bs=0,bv=0,bp=0,brojacvozila,max,udio;
	printf("Unesite vozila: ");
	
	while (1) {
		scanf("%c",&vozila);
		if (vozila=='k' || vozila=='K') { break; }
		else if(vozila=='c' || vozila=='C') { bc++; }
		else if (vozila=='b' || vozila=='B') { bb++; }	
		else if (vozila=='s' || vozila=='S') { bs++; }
		else if (vozila=='v' || vozila=='V') { bv++; }
		else if (vozila=='p' || vozila=='P') { bp++; }
		else { printf ("Neispravan unos\n"); }
	}
	
	
	brojacvozila=bc+bb+bs+bv+bp;
	printf("Ukupno evidentirano %0.f vozila.",brojacvozila);
	
	if(brojacvozila==0) {
		printf("\nNajpopularnija boja je crna (0.00%).");
	}
	else if (bc>=bb && bc>=bs && bc>=bv && bc>=bp) { 
		max=bc; 
		udio=max/brojacvozila*100; 
		printf ("\nNajpopularnija boja je crna (%.2f%).",udio);}
		
	else if (bb>bc && bb>=bs && bb>=bv && bb>=bp) { 
		max=bb; 
		udio=max/brojacvozila*100;
		printf ("\nNajpopularnija boja je bijela (%.2f%).",udio); }
		
	else if (bs>bc && bs>bb && bs>=bv && bs>=bp) { 
		max=bs; 
		udio=max/brojacvozila*100; 
		printf ("\nNajpopularnija boja je siva (%.2f%).",udio); }
		
	else if (bv>bc && bv>bb && bv>bs && bv>=bp) { 
		max=bv; 
		udio=max/brojacvozila*100; 
		printf ("\nNajpopularnija boja je crvena (%.2f%).",udio); }
		
	else if (bp>bc && bp>bb && bp>bs && bp>bv) { 
		max=bp; 
		udio=max/brojacvozila*100; 
		printf ("\nNajpopularnija boja je plava (%.2f%).",udio); }
		

	
	return 0;
}
