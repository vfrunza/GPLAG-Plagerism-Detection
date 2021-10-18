#include <stdio.h>

int main() {
	double t1,t2,tp,tz,tzi,tu,b1,b2,bp,bz,bzi,bu,m1,m2,mp,mz,mzi,mu;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &t1);
	if(t1>=0 && t1<=20){
	printf("II parcijalni ispit: ");
	scanf("%lf", &t2);
	if(t2>=0 && t2<=20){
	printf("Prisustvo: ");
	scanf("%lf", &tp);
	if(tp>=0 && tp<=10){
	printf("Zadace: ");
	scanf("%lf", &tz);
	if(tz>=0 && tz<=10){
	printf("Zavrsni ispit: ");
	scanf("%lf", &tzi);
	if(tzi>=0 && tzi<=40){
	
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &b1);
	if(b1>=0 && b1<=20){
	printf("II parcijalni ispit: ");
	scanf("%lf", &b2);
	if(b2>=0 && b2<=20){
	printf("Prisustvo: ");
	scanf("%lf", &bp);
	if(bp>=0 && bp<=10){
	printf("Zadace: ");
	scanf("%lf", &bz);
	if(bz>=0 && bz<=10){
	printf("Zavrsni ispit: ");
	scanf("%lf", &bzi);
	if(bzi>=0 && bzi<=40){
	
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &m1);
	if(m1>=0 && m1<=20){
	printf("II parcijalni ispit: ");
	scanf("%lf", &m2);
	if(m2>=0 && m2<=20){
	printf("Prisustvo: ");
	scanf("%lf", &mp);
	if(mp>=0 && mp<=10){
	printf("Zadace: ");
	scanf("%lf", &mz);
	if(mz>=0 && mz<=10){
	printf("Zavrsni ispit: ");
	scanf("%lf", &mzi);
	if(mzi>=0 && mzi<=40){
	
		tu=t1+t2+tp+tz+tzi;
		mu=m1+m2+mp+mz+mzi;
		bu=b1+b2+bp+bz+bzi;
		if(!(tu<55 && mu<55 && bu<55)){
			if((tu>=55 && mu<55 && bu<55)||(mu>=55 && tu<55 && bu<55)||(bu>=55 && tu<55 && bu<55)){
				printf("Jedan student je polozio.");
			}else{
				if((tu>=55 && mu>=55 && bu<55)||(tu>=55 && mu<55 && bu>=55)||(tu<55 && mu>=55 && bu>=55)){
					printf("Dva studenta su polozila.");
				}else{
					printf("Sva tri studenta su polozila.\n");
					if( (tu<65 && mu<65 && bu<65) || (tu>=65 && tu<75 && mu>=65 && mu<75 && bu>=65 && bu<75) || (tu>=75 && tu<85 && mu>=75 && mu<85 && bu>=75 && bu<85) || (tu>=85 && tu<92 && mu>=85 && mu<92 && bu>=85 && bu<92)||(tu>=92 && mu>=92 && bu>=92)){
						printf("Sva tri studenta imaju istu ocjenu.");
					}else{
						if((tu<65 && mu<65 && bu>=65)||(tu>=65 && tu<75 && mu>=65 && mu<75 && (bu<65 || bu>=75) ) || (tu>=75 && tu<85 && mu>=75 && mu<85 && (bu<75 || bu>=85)) || (tu>=85 && tu<92 && mu>=85 && mu<92 && (bu<85 || bu>=92)) || (tu>=92 && mu>=92 && bu<92)||(tu<65 && bu<65 && mu>=65)||(tu>=65 && tu<75 && bu>=65 && bu<75 && (mu<65 || mu>=75) ) || (tu>=75 && tu<85 && bu>=75 && bu<85 && (mu<75 || mu>=85)) || (tu>=85 && tu<92 && bu>=85 && bu<92 && (mu<85 || mu>=92)) || (tu>=92 && bu>=92 && mu<92)||(mu<65 && bu<65 && tu>=65)||(mu>=65 && mu<75 && bu>=65 && bu<75 && (tu<65 || tu>=75) ) || (mu>=75 && mu<85 && bu>=75 && bu<85 && (tu<75 || tu>=85)) || (mu>=85 && mu<92 && bu>=85 && bu<92 && (tu<85 || tu>=92)) || (mu>=92 && bu>=92 && tu<92)){
							printf("Dva od tri studenta imaju istu ocjenu.");
						}else{
							printf("Svaki student ima razlicitu ocjenu.");
						}
					}
				}
			}
		}else{
			printf("Nijedan student nije polozio.");
		}
	}else{
		printf("Neispravan broj bodova");
	}
	}else{
		printf("Neispravan broj bodova");
	}
	}else{
		printf("Neispravan broj bodova");
	}
	}else{
		printf("Neispravan broj bodova");
	}
	}else{
		printf("Neispravan broj bodova");
	}
	}else{
		printf("Neispravan broj bodova");
	}
	}else{
		printf("Neispravan broj bodova");
	}
	}else{
		printf("Neispravan broj bodova");
	}
	}else{
		printf("Neispravan broj bodova");
	}
	}else{
		printf("Neispravan broj bodova");
	}
	}else{
		printf("Neispravan broj bodova");
	}
	}else{
		printf("Neispravan broj bodova");
	}
	}else{
		printf("Neispravan broj bodova");
	}
	}else{
		printf("Neispravan broj bodova");
	}
	}else{
		printf("Neispravan broj bodova");
	}
	return 0;
}
