#include <stdio.h>
#include <math.h>

int main() {
	double t1,t2,tp,tz,tzi,b1,b2,bp,bz,bzi,m1,m2,mp,mz,mzi,to,bo,mo,sumat,sumab,sumam,sumao;
	
	/*Ulaz*/
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &t1);
	if(t1<0 || t1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &t2);
	if (t2<0 || t2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &tp);
	if (tp<0 || tp>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &tz);
	if(tz<0 || tz>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &tzi);
	if(tzi<0 || tzi>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Bojana: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &b1);
	if (b1<0 || b1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &b2);
	if (b2<0 || b2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &bp);
	if (bp<0 || bp>10){
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
	printf("Unesite bodove za Mirzu: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &m1);
	if(m1<0 || m1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &m2);
	if (m2<0 || m2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &mp);
	if (mp<0 || mp>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &mz);
	if(mz<0 || mz>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &mzi);
	if(mzi<0 || mzi>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	sumat=t1+t2+tp+tz+tzi;
	sumab=b1+b2+bp+bz+bzi;
	sumam=m1+m2+mp+mz+mzi;
	
	if (sumat<55) to=5;
	else if (sumat>=55 && sumat<65) to=6;
	else if (sumat>=65 && sumat<75) to=7;
	else if (sumat>=75 && sumat<85) to=8;
	else if (sumat>=85 && sumat<92) to=9;
	else to=10;
	
	if (sumab<55) bo=5;
	else if (sumab>=55 && sumab<65) bo=6;
	else if (sumab>=65 && sumab<75) bo=7;
	else if (sumab>=75 && sumab<85) bo=8;
	else if (sumab>=85 && sumab<92) bo=92;
	else bo=10;
	
	if (sumam<55) mo=5;
	else if(sumam>=55 && sumam<65) mo=6;
	else if(sumam>=65 && sumam<75) mo=7;
	else if(sumam>=75 && sumam<85) mo=8;
	else if(sumam>=85 && sumam<92) mo=9;
	else mo=10;
		
	sumao=to+mo+bo;	
		
	if (sumao<=15) printf("Nijedan student nije polozio.");
	else if(to>=6 && bo>=6 && mo>=6) printf("Sva tri studenta su polozila.");
	else if((to>=6 && bo>=6) || (to>=6 && mo>=6) || (mo>=6 && bo>=6)) printf("Dva studenta su polozila.");
	else printf("Jedan student je polozio.");
	
	if(to>=6 && bo>=6 && mo>=6){
		if (to==bo && to==mo && bo==mo) printf("\nSva tri studenta imaju istu ocjenu.");
		else if(to==bo || bo==mo || to==mo) printf("\nDva od tri studenta imaju istu ocjenu.");
		else printf("\nSvaki student ima razlicitu ocjenu.");
	}
		
	return 0;
}