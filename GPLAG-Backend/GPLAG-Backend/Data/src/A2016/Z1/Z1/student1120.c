#include <stdio.h>
#define EPSILON 0.001
#include <math.h>

int main() {
	int aoc,boc,coc;
	double ap1,ap2,apr,az,azi,as;
	double bp1,bp2,bpr,bz,bzi,bs;
	double cp1,cp2,cpr,cz,czi,cs;
	aoc=5;
	boc=5;
	coc=5;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &ap1);
	if(ap1<0 || ap1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &ap2);
	if(ap2<0 || ap2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &apr);
	if(apr<0 || apr>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &az);
	if(az<0 || az>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &azi);
	if(azi<0 || azi>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	as=ap1+ap2+apr+az+azi;
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &bp1);
	if(bp1<0 || bp1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &bp2);
	if(bp2<0 || bp2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &bpr);
	if(bpr<0 || bpr>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &bz);
	if(bz<0 || bz>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &bzi);
	if(bzi<0 || bzi>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	bs=bp1+bp2+bpr+bz+bzi;
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &cp1);
	if(cp1<0 || cp1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &cp2);
	if(cp2<0 || cp2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &cpr);
	if(cpr<0 || cpr>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &cz);
	if(cz<0 || cz>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &czi);
	if(czi<0 || czi>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	cs=cp1+cp2+cpr+cz+czi;
	if(as>92 || fabs(as-92)<EPSILON)
	aoc=10;
	else if((as>85 || fabs(as-85)<EPSILON) && as<92)
    aoc=9;
    else if((as>75 || fabs(as-75)<EPSILON) && as<85)
    aoc=8;
    else if((as>65 || fabs(as-65)<EPSILON) && as<75)
    aoc=7;
    else if((as>55 || fabs(as-55)<EPSILON) && as<65)
    aoc=6;
    if(bs>92 || fabs(bs-92)<EPSILON)
    boc=10;
    else if((bs>85 || fabs(bs-85)<EPSILON) && bs<92)
    boc=9;
    else if((bs>75 || fabs(bs-75)<EPSILON) && bs<85)
    boc=8;
    else if((bs>65 || fabs(bs-65)<EPSILON) && bs<75)
    boc=7;
    else if((bs>55 || fabs(bs-55)<EPSILON) && bs<65)
    boc=6;
    if(cs>92 || fabs(cs-92)<EPSILON) 
    coc=10;
    else if((cs>85 || fabs(cs-85)<EPSILON) && cs<92)
    coc=9;
    else if((cs>75 || fabs(cs-75)<EPSILON) && cs<85)
    coc=8;
    else if((cs>65 || fabs(cs-65)<EPSILON) && cs<75)
    coc=7;
    else if((cs>55 || fabs(cs-55)<EPSILON) && cs<65)
    coc=6;
    if(aoc<=5 && boc<=5 && coc<=5){
    	printf("Nijedan student nije polozio.\n");
    }
    else if((aoc>5 && boc<=5 && coc<=5) || (aoc<=5 && boc>5 && coc<=5) || (aoc<=5 && boc<=5 && coc>5)){
    	printf("Jedan student je polozio.\n");
    }
    else if((aoc>5 && boc>5 && coc<=5) || (aoc>5 && boc<=5 && coc>5) || (aoc<=5 && boc>5 && coc>5)){
    	printf("Dva studenta su polozila.\n");
    }
    else{
    	printf("Sva tri studenta su polozila.\n");
    	if(aoc==boc && boc==coc){
    		printf("Sva tri studenta imaju istu ocjenu.");
    	}
    	else if((aoc==boc && boc!=coc && aoc!=coc) || (aoc!=boc && boc==coc && aoc!=coc) || (aoc!=boc && boc!=coc && aoc==coc)){
    		printf("Dva od tri studenta imaju istu ocjenu.");
    	}
    	else printf("Svaki student ima razlicitu ocjenu.");
    }
    
    return 0;
}
