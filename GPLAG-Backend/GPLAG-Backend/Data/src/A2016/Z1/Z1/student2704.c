#include <stdio.h>

int main() {
	double ta, tb, tc, td, te, tbodovi, tocjena, ba, bb, bc, bd, be, bbodovi, bocjena, ma, mb, mc, md, me, mbodovi, mocjena;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &ta);
	if(ta<0 || ta>20) {
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &tb);
	if(tb<0 || tb>20) {
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Prisustvo: ");
	scanf("%lf", &tc);
	if(tc<0 || tc>10) {
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Zadace: ");
	scanf("%lf", &td);
	if(td<0 || td>10) {
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &te);
	if(te<0 || te>40) {
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &ba);
	if(ba<0 || ba>20) {
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &bb);
	if(bb<0 || bb>20) {
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Prisustvo: ");
	scanf("%lf", &bc);
	if(bc<0 || bc>10) {
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Zadace: ");
	scanf("%lf", &bd);
	if(bd<0 || bd>10) {
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &be);
	if(be<0 || be>40) {
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &ma);
	if(ma<0 || ma>20) {
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &mb);
	if(mb<0 || mb>20) {
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Prisustvo: ");
	scanf("%lf", &mc);
	if(mc<0 || mc>10) {
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Zadace: ");
	scanf("%lf", &md);
	if(md<0 || md>10) {
		printf("Neispravan broj bodova");
		return 1;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &me);
	if(me<0 || me>40) {
		printf("Neispravan broj bodova");
		return 1;
	}
	tbodovi=ta+tb+tc+td+te;
	bbodovi=ba+bb+bc+bd+be;
	mbodovi=ma+mb+mc+md+me;
	if(tbodovi>=0 && tbodovi<55) tocjena=5;
	if(tbodovi>=55 && tbodovi<65) tocjena=6;
	if(tbodovi>=65 && tbodovi<75) tocjena=7;
	if(tbodovi>=75 && tbodovi<85) tocjena=8;
	if(tbodovi>=85 && tbodovi<92) tocjena=9;
	if(tbodovi>=92 && tbodovi<=100) tocjena=10;
	if(bbodovi>=0 && bbodovi<55) bocjena=5;
	if(bbodovi>=55 && bbodovi<65) bocjena=6;
	if(bbodovi>=65 && bbodovi<75) bocjena=7;
	if(bbodovi>=75 && bbodovi<85) bocjena=8;
	if(bbodovi>=85 && bbodovi<92) bocjena=9;
	if(bbodovi>=92 && bbodovi<=100) bocjena=10;
	if(mbodovi>=0 && mbodovi<55) mocjena=5;
	if(mbodovi>=55 && mbodovi<65) mocjena=6;
	if(mbodovi>=65 && mbodovi<75) mocjena=7;
	if(mbodovi>=75 && mbodovi<85) mocjena=8;
	if(mbodovi>=85 && mbodovi<92) mocjena=9;
	if(mbodovi>=92 && mbodovi<=100) mocjena=10;
	
	if(tocjena>5 && bocjena>5 && mocjena>5) {
		printf("Sva tri studenta su polozila. \n");
	}
	if(tocjena>5 && bocjena>5 && mocjena==5) {
		printf("Dva studenta su polozila. \n");
	}
	if(tocjena>5 && bocjena==5 && mocjena>5) {
		printf("Dva studenta su polozila. \n");
	}
	if(tocjena==5 && bocjena>5 && mocjena>5) {
		printf("Dva studenta su polozila. \n");
	}
	if(tocjena>5 && bocjena==5 && mocjena==5) {
		printf("Jedan student je polozio. \n");
	}
	if(tocjena==5 && bocjena>5 && mocjena==5) {
		printf("Jedan student je polozio. \n");
	}
	if(tocjena==5 && bocjena==5 && mocjena>5) {
		printf("Jedan student je polozio. \n");
	}
	if(tocjena==5 && bocjena==5 && mocjena==5) {
		printf("Nijedan student nije polozio. \n");
	}
	if(tocjena>=6 && bocjena>=6 && mocjena>=6) 
	{
			if(tocjena==bocjena && bocjena==mocjena) {
			printf("Sva tri studenta imaju istu ocjenu. \n");
			}
			if((tocjena==bocjena && bocjena!=mocjena) || (tocjena==mocjena && mocjena!=bocjena) || (mocjena==bocjena && bocjena!=tocjena)) {
			printf("Dva od tri studenta imaju istu ocjenu. \n");
			} else {
					printf("Svaki student ima razlicitu ocjenu. \n");
			}
	}
	return 0;
}