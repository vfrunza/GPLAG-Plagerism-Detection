#include <stdio.h>
int main(){
	int aoc, boc, coc;
	double ap1, ap2, au, az, ap, auk;
	double bp1, bp2, bu, bz, bp, buk;
	double cp1, cp2, cu, cz, cp, cuk;
	printf("Unesite bodove za Tarika: ");
	printf("\nI parcijalni ispit: ");
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
	scanf("%lf", &ap);
	if(ap<0 || ap>10){
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
	scanf("%lf", &au);
	if(au<0 || au>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Bojana: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &bp1);
	if(bp1<0 || bp1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &bp2);
	if(bp2<0 || bp1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &bp);
	if(bp<0 || bp>10){
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
	scanf("%lf", &bu);
	if(bu<0 || bu>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Mirzu: ");
	printf("\nI parcijalni ispit: ");
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
	scanf("%lf", &cp);
	if(cp<0 || cp>10){
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
	scanf("%lf", &cu);
	if(cu<0 || cu>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	auk=ap1+ap2+au+az+ap+0.001;
	buk=bp1+bp2+bu+bz+bp+0.001;
	cuk=cp1+cp2+cu+cz+cp+0.001;
	if((auk-55<0) && (buk-55<0) && (cuk-55<0)){
		printf("Nijedan student nije polozio.");
	}
	else if((auk-55>0) && (buk-55<0) && (cuk-55<0)){
		printf("Jedan student je polozio.");
	}
	else if((auk-55<0) && (buk-55>0) && (cuk-55<0)){
		printf("Jedan student je polozio.");
	}
	else if((auk-55<0) && (buk-55<0) && (cuk-55>0)){
		printf("Jedan student je polozio.");
	}
	else if((auk-55>0) && (buk-55>0) && (cuk-55<0)){
		printf("Dva studenta su polozila.");
	}
	else if((auk-55>0) && (buk-55<0) && (cuk-55>0)){
		printf("Dva studenta su polozila.");
	}
	else if((auk-55<0) && (buk-55>0) && (cuk-55>0)){
		printf("Dva studenta su polozila.");
	}
	else if((auk-55>0) && (buk-55>0) && (cuk-55>0)){
		printf("Sva tri studenta su polozila.");
	}
	
	
	if(auk>=0 && auk<55){
		aoc=auk*0;
	}
	else if(auk>=55 && auk<65){
		aoc=(auk+5)/10;
	}
	else if(auk>=65 && auk<75){
		aoc=(auk+5)/10;
	}
	else if(auk>=75 && auk<85){
		aoc=(auk+5)/10;
	}
	else if(auk>=85 && auk<92){
		aoc=(auk+5)/10;
	}
	else if(auk>=92 && auk<=100){
		aoc=(auk+8)/10;
	}
	if(buk>=0 && buk<55){
		boc=buk*0;
	}
	else if(buk>=55 && buk<65){
		boc=(buk+5)/10;
	}
	else if(buk>=65 && buk<75){
		boc=(buk+5)/10;
	}
	else if(buk>=75 && buk<85){
		boc=(buk+5)/10;
	}
	else if(buk>=85 && buk<92){
		boc=(buk+5)/10;
	}
	else if(buk>=92 && buk<=100){
		boc=(buk+8)/10;
	}
	if(cuk>=0 && cuk<55){
		coc=cuk*0;
	}
	else if(cuk>=55 && cuk<65){
		coc=(cuk+5)/10;
	}
	else if(cuk>=65 && cuk<75){
		coc=(cuk+5)/10;
	}
	else if(cuk>=75 && cuk<85){
		coc=(cuk+5)/10;
	}
	else if(cuk>=85 && cuk<92){
		coc=(cuk+5)/10;
	}
	else if(cuk>=92 && cuk<=100){
		coc=(cuk+8)/10;
	}
	if(aoc>0 && boc>0 && coc>0){
		if(aoc==boc && aoc==coc && boc==coc){
			printf("\nSva tri studenta imaju istu ocjenu.");
		}
		else if(aoc==boc && aoc!=coc && boc!=coc){
			printf("\nDva od tri studenta imaju istu ocjenu.");
		}
		else if(aoc==coc && aoc!=boc && coc!=boc){
			printf("\nDva od tri studenta imaju istu ocjenu.");
		}
		else if(boc==coc && boc!=aoc && coc!=aoc){
			printf("\nDva od tri studenta imaju istu ocjenu.");
		}
		else if(aoc!=boc && aoc!=coc && boc!=coc){
			printf("\nSvaki student ima razlicitu ocjenu.");
		}
	}
	return 0;
}