#include <stdio.h>
#include <stdlib.h>
int main() {
	
	double a, b, c, d, e, s, m, n;
	
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &a);
	if(a<0 || a>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &b);
	if(b<0 || b>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &c);
	if(c<0 || c>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &d);
	if(d<0 || d>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &e);
	if(e<0 || e>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	s=a+b+c+d+e;

	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &a);
	if(a<0 || a>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &b);
	if(b<0 || b>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &c);
	if(c<0 || c>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &d);
	if(d<0 || d>10) {
		printf("Neispravan broj bodova");
		return 0; 
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &e);
	if(e<0 || e>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	m=a+b+c+d+e;
	
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &a);
	if(a<0 || a>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &b);
	if(b<0 || b>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &c);
	if(c<0 || c>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &d);
	if(d<0 || d>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &e);
	if(e<0 || e>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	n=a+b+c+d+e;

	if(s<55 && m<55 && n<55) {
		printf("Nijedan student nije polozio.\n");
	}
	else if((s>=55 && m<55 && n<55) || (s<55 && m>=55 && n<55) || (s<55 && m<55 && n>=55)) {
		printf("Jedan student je polozio.\n");
	}
	else if((s>=55 && m>=55 && n<55) || (s>=55 && m<55 && n>=55) || (s<55 && m>=55 && n>=55)) {
		printf("Dva studenta su polozila.\n");
	}
	else if((s>=55 && m>=55 && n>=55)) {
		printf("Sva tri studenta su polozila.\n");
		
		
		if(((s>=55 && s<65) && (m>=55 && m<65) && (n>=55 && n<65)) || ((s>=65 && s<75) && (m>=65 && m<75) && (n>=65 && n<75)) || ((s>=75 && s<85) && (m>=75 && m<85) && (n>=75 && n<85))
		|| ((s>=85 && s<92) && (m>=85 && m<92) && (n>=85 && n<92)) || ((s>=92 && s<=100) && (m>=92 && m<=100) && (n>=92 && n<=100))) {
			printf("Sva tri studenta imaju istu ocjenu.");
		}
		else if(((s>=55 && s<65) && (m>55 && m<65) || (n>=55 && n<65)) || ((s>=65 && s<75) && (m>=65 && m<75) || (n>=65 && n<75)) || ((s>=75 && s<85) && (m>=75 && m<85) || (n>=75 && n<85))
		&& ((s>=85 && s<92) && (m>=85 && m<92) || (n>=85 && n<92)) || ((s>=92 && s<=100) && (m>=92 && m<=100) || (n>=92 && n<=100))) {
			printf("Dva od tri studenta imaju istu ocjenu.");
		}
		else if(((s>=55 && s<65) || (m>=55 && m<65) || (n>=65 && n<65)) || ((s>=65 && s<75) || (m>=65 && m<75) || (n>=65 && n<75)) || ((s>=75 && s<85) || (m>=75 && m<85) || (n<=75 && n<85)) 
		|| ((s>=85 && s<92) || (m>=85 && m<92) || (n>=85 && n<92)) || ((s>=92 && s<=100) || (m>=92 && m<=100) || (n>=92 && n<=100))) 
	{
			printf("Svaki student ima razlicitu ocjenu.");
		
		}
	}
	return 0;
}