#include <stdio.h>

int main() {
	double Ipi, IIpi, p, z, zi, bt, bb, bm;
	int om, ob, ot;

	printf ("Unesite bodove za Tarika: \n" );
	
	printf ("I parcijalni ispit: ");
	scanf("%lf", &Ipi);
	if(Ipi<0||Ipi>20) {printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIpi);
	if(IIpi<0||IIpi>20) {printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf", &p);
	if(p<0||p>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf", &z);
	if(z<0||z>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zi);
	if(zi<0||zi>40) {printf("Neispravan broj bodova"); return 0;}
	bt=Ipi+IIpi+p+z+zi;
	
	printf ("Unesite bodove za Bojana: \n" );
	
	printf ("I parcijalni ispit: ");
	scanf("%lf", &Ipi);
	if(Ipi<0||Ipi>20) {printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIpi);
	if(IIpi<0||IIpi>20) {printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf", &p);
	if(p<0||p>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf", &z);
	if(z<0||z>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zi);
	if(zi<0||zi>40) {printf("Neispravan broj bodova"); return 0;}
	
	bb=Ipi+IIpi+p+z+zi;
	
		printf ("Unesite bodove za Mirzu: \n" );
	
	printf ("I parcijalni ispit: ");
	scanf("%lf", &Ipi);
	if(Ipi<0||Ipi>20) {printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIpi);
	if(IIpi<0||IIpi>20) {printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf", &p);
	if(p<0||p>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf", &z);
	if(z<0||z>10) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zi);
	if(zi<0||zi>40) {printf("Neispravan broj bodova"); return 0;}
	
	bm=Ipi+IIpi+p+z+zi;
	if(bt<55) ot=5;
	else if(bt>=55&&bt<65) ot=6;
	else if(bt>=65&&bt<75) ot=7;
	else if(bt>=75&&bt<85) ot=8;
	else if(bt>=85&&bt<92) ot=9;
	else ot=10;
	if(bm<55) om=5;
	if(bm>=55&&bm<65) om=6;
	if(bm>=65&&bm<75) om=7;
	if(bm>=75&&bm<85) om=8;
	if(bm>=85&&bm<92) om=9;
	else om=10;
	if(bb<55) ob=5;
	if(bb>=55&&bb<65) ob=6;
	if(bb>=65&&bb<75) ob=7;
	if(bb>=75&&bb<85) ob=8;
	if(bb>=85&&bb<92) ob=9;
	else ob=10;
	


	if(bt<55 && bb<55 && bm<55){
		printf ("Nijedan student nije polozio.");
	}
	else if((bt<55&&bm>=55&&bb>=55) || (bm<55&&bt>=55&&bb>=55) || (bb<55&&bm>=55&&bt>=55)) {
		printf("Dva studenta su polozila.");
	}
	else if((bt<55&&bm<55&&bb>=55) || (bm<55&&bt>=55&&bb<55) || (bb<55&&bm>=55&&bt<55)) {
		printf("Jedan student je polozio.");
	}
	else {
		printf("Sva tri studenta su polozila.\n");
		
		if(ob==om&&om==ot&&ob==ot) printf("Sva tri studenta imaju istu ocjenu.");
		
		else if(ob!=om&&om!=ot&&ot!=ob) printf("Svaki student ima razlicitu ocjenu.");
		
		else printf("Dva od tri studenta imaju istu ocjenu.");
	}
	return 0;
}
