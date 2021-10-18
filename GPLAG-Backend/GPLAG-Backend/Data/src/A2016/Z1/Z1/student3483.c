#include <stdio.h>

int main() {
	double ta1, ta2, tap, taz, tazi, bo1, bo2, bop, boz, bozi, mi1, mi2, mip, miz, mizi, tat, bot, mit, tac, boc, mic;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &ta1);
	if(ta1<0 || ta1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &ta2);
	if(ta2<0 || ta2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &tap);
	if(tap<0 || tap>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &taz);
	if(taz<0 || taz>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &tazi);
	if(tazi<0 || tazi>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &bo1);
	if(bo1<0 || bo1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &bo2);
	if(bo2<0 || bo2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &bop);
	if(bop<0 || bop>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &boz);
	if(boz<0 || boz>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &bozi);
	if(bozi<0 || bozi>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &mi1);
	if(mi1<0 || mi1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &mi2);
	if(mi2<0 || mi2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &mip);
	if(mip<0 || mip>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &miz);
	if(miz<0 || miz>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &mizi);
	if(mizi<0 || mizi>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	tat=ta1+ta2+tap+taz+tazi;
	bot=bo1+bo2+bop+boz+bozi;
	mit=mi1+mi2+mip+miz+mizi;
	if(tat>=55 && tat<65)
		tac=6;
	else if(tat>=65 && tat<75)
		tac=7;
	else if(tat>=75 && tat<85)
		tac=8;
	else if(tat>=85 && tat<92)
		tac=9;
	else if(tat>=92 && tat<=100)
		tac=10;
	if(bot>=55 && bot<65)
		boc=6;
	else if(bot>=65 && bot<75)
		boc=7;
	else if(bot>=75 && bot<85)
		boc=8;
	else if(bot>=85 && bot<92)
		boc=9;
	else if(bot>=92 && bot<=100)
		boc=10;
	if(mit>=55 && mit<65)
		mic=6;
	else if(mit>=65 && mit<75)
		mic=7;
	else if(mit>=75 && mit<85)
		mic=8;
	else if(mit>=85 && mit<92)
		mic=9;
	else if(mit>=92 && mit<=100)
		mic=10;
	if(tat<55 && bot<55 && mit<55)
		printf("Nijedan student nije polozio. \n");
	else if((tat>=55 && bot<55 && mit<55) || (tat<55 && bot>=55 && mit<55) || (tat<55 && bot<55 && mit>=55))
		printf("Jedan student je polozio. \n");
	else if((tat>=55 && bot>=55 && mit<55) || (tat>=55 && bot<55 && mit>=55) || (tat<55 && bot>=55 && mit>=55))
		printf("Dva studenta su polozila. \n");
	else if(tat>=55 && bot>=55 && mit>=55){
		printf("Sva tri studenta su polozila. \n");
		if(tac==boc && tac==mic)
			printf("Sva tri studenta imaju istu ocjenu.");
		else if((tac==boc && tac!=mic) || (tac==mic && tac!=boc) || (boc==mic && tac!=mic))
			printf("Dva od tri studenta imaju istu ocjenu.");
		else 
			printf("Svaki student ima razlicitu ocjenu.");
	}
	return 0;
}
