#include <stdio.h>

int main() {
	double t=0, b=0, m=0, tpar1, tpar2, tz, ti, tp, bpar1, bpar2, bz, bi, bp, mpar1, mpar2, mz, mi, mp, ot, ob, om;
	printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
	scanf("%lf", &tpar1);
	if(tpar1<0 || tpar1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	else{t=t+tpar1;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &tpar2);
	if(tpar2<0 || tpar2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	else{t=t+tpar2;}
	printf("Prisustvo: ");
	scanf("%lf", &tp);
	if(tp<0 || tp>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	else{t=t+tp;}
	printf("Zadace: ");
	scanf("%lf", &tz);
	if(tz<0 || tz>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	else{t=t+tz;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &ti);
	if(ti<0 || ti>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	else{t=t+ti;}
	printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
	scanf("%lf", &bpar1);
	if(bpar1<0 || bpar1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	else{b=b+bpar1;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &bpar2);
	if(bpar2<0 || bpar2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	else{b=b+bpar2;}
	printf("Prisustvo: ");
	scanf("%lf", &bp);
	if(bp<0 || bp>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	else{b=b+bp;}
	printf("Zadace: ");
	scanf("%lf", &bz);
	if(bz<0 || bz>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	else{b=b+bz;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &bi);
	if(bi<0 || bi>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	else{b=b+bi;}
	printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
	scanf("%lf", &mpar1);
	if(mpar1<0 || mpar1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	else{m=m+mpar1;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &mpar2);
	if(mpar2<0 || mpar2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	else{m=m+mpar2;}
	printf("Prisustvo: ");
	scanf("%lf", &mp);
	if(mp<0 || mp>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	else{m=m+mp;}
	printf("Zadace: ");
	scanf("%lf", &mz);
	if(mz<0 || mz>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	else{m=m+mz;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &mi);
	if(mi<0 || mi>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	else{m=m+mi;}
	if(t>=0 && t<55) ot=5;
	else if(t>=55 && t<65) ot=6;
	else if(t>=65 && t<75) ot=7;
	else if(t>=75 && t<85) ot=8;
	else if(t>=85 && t<95) ot=9;
	else if(t>=95 && t<=100) ot=10;
	if(m>=0 && m<55) om=5;
	else if(m>=55 && m<65) om=6;
	else if(m>=65 && m<75) om=7;
	else if(m>=75 && m<85) om=8;
	else if(m>=85 && m<95) om=9;
	else if(m>=95 && m<=100) om=10;
	if(b>=0 && b<55) ob=5;
	else if(b>=55 && b<65) ob=6;
	else if(b>=65 && b<75) ob=7;
	else if(b>=75 && b<85) ob=8;
	else if(b>=85 && b<95) ob=9;
	else if(b>=95 && b<=100) ob=10;
	if(ot==5 && ot==ob && ot==om){
		printf("Nijedan student nije polozio.");
		
	}
	else if(ot==5 && ob==5 && om!=5 || ot==5 && ob!=5 && om==5 || ot!=5 && ob==5 && om==5){
		printf("Jedan student je polozio.");
	}
	else if(ot==5 && ob!=5 && om!=5 || ot!=5 && ob==5 && om!=5 || ot!=5 && ob!=5 && om==5){
		printf("Dva studenta su polozila.");
	}
	else if(ot!=5 && ob!=5 && om!=5){
		printf("Sva tri studenta su polozila.");
	if(ob==om && om==ot)
		printf("\nSva tri studenta imaju istu ocjenu.");
	
	else if(ob==om && om!=ot || ob==ot && ot!=om){
		printf("\nDva od tri studenta imaju istu ocjenu.");
	}
	else if(ob!=om && ob!=ot && ot!=om){
		printf("\nSvaki student ima razlicitu ocjenu.");
	}
	}
	return 0;
}
