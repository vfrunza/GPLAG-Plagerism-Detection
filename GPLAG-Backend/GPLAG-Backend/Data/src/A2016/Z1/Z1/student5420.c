#include <stdio.h>

int main() {
	float tp1,tp2,tp,tz,tu,tuk,bp1,bp2,bp,bz,bu,buk,mp1,mp2,mp,mz,mu,muk;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%f", &tp1);
	if(tp1<0||tp1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &tp2);
	if(tp2<0||tp2>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &tp);
	if(tp<0||tp>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &tz);
	if(tz<0||tz>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &tu);
	if(tu<0||tu>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%f", &bp1);
	if(bp1<0||bp1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &bp2);
	if(bp2<0||bp2>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &bp);
	if(bp<0||bp>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &bz);
	if(bz<0||bz>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &bu);
	if(bu<0||bu>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%f", &mp1);
	if(mp1<0||mp1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &mp2);
	if(mp2<0||mp2>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &mp);
	if(mp<0||mp>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &mz);
	if(mz<0||mz>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &mu);
	if(mu<0||mu>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	tuk=tp1+tp2+tp+tz+tu+0.00001;
	buk=bp1+bp2+bp+bz+bu+0.00001;
	muk=mp1+mp2+mp+mz+mu+0.00001;
	if(tuk<55 && buk<55 && muk<55) {
		printf("Nijedan student nije polozio.");
		return 0;
	}
	if((tuk>=55 && buk<55 && muk<55)||(buk>=55 && tuk<55 && muk<55)||(muk>=55 && tuk<55 && buk<55)) {
		printf("Jedan student je polozio.");
		return 0;
	}
	if((tuk>=55 && buk>=55 && muk<55)||(buk>=55 && tuk<55 && muk>=55)||(muk>=55 && tuk>=55 && buk<55)) {
		printf("Dva studenta su polozila.");
		return 0;
	}
	if(tuk>=55 && muk>=55 && buk>=55) {
		printf("Sva tri studenta su polozila.\n");
	}
	if((int)tuk/10+0.5==(int)buk/10+0.5&&(int)tuk/10+0.5==(int)muk/10+0.5) {
		printf("Sva tri studenta imaju istu ocjenu.");
	}
	else if((int)tuk/10+0.5!=(int)buk/10+0.5&&(int)tuk/10+0.5!=(int)muk/10+0.5&&(int)buk/10+0.5!=(int)muk/10+0.5) {
		printf("Svaki student ima razlicitu ocjenu.");
	} 
	else {
		printf("Dva od tri studenta imaju istu ocjenu.");
	}
	return 0;
}
