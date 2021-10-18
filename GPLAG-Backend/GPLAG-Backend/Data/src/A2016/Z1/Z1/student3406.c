#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
 
int main() {
	double Iparc, IIparc, prisustvo, zadace, zispit, suma1=0, suma2=0, suma3=0;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &Iparc);
	if (Iparc<0 || Iparc>20 ) {
	printf("Neispravan broj bodova\n"); 
		return 0;
	} else {
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIparc);
	}  	if (IIparc>20 || IIparc<0) {
		printf("Neispravan broj bodova\n"); 
		return 0;
	}  else {
	printf("Prisustvo: ");
	scanf("%lf", &prisustvo);
	} if(prisustvo<0 || prisustvo>10) {
		printf("Neispravan broj bodova\n"); 
		return 0;
	} else  {
	printf("Zadace: ");
	scanf("%lf", &zadace);
	}  if (zadace<0 || zadace>10) {
		printf("Neispravan broj bodova\n"); 
		return 0;
	} else {
	printf("Zavrsni ispit: ");
	scanf("%lf", &zispit);
	} if (zispit<0 || zispit>40) {
		printf("Neispravan broj bodova\n"); 
		return 0;
	}  else {
	suma1=Iparc + IIparc + +prisustvo + zadace + zispit;
	}
	printf("Unesite bodove za Bojana: \n");
		printf("I parcijalni ispit: ");
	scanf("%lf", &Iparc);
		if (Iparc<0 || Iparc>20 ) {
	printf("Neispravan broj bodova\n"); 
		return 0;
	} else {
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIparc);
	}  	if (IIparc>20 || IIparc<0) {
		printf("Neispravan broj bodova\n"); 
		return 0;
	}  else {
	printf("Prisustvo: ");
	scanf("%lf", &prisustvo);
	} if(prisustvo<0 || prisustvo>10) {
		printf("Neispravan broj bodova\n"); 
		return 0;
	} else  {
	printf("Zadace: ");
	scanf("%lf", &zadace);
	}  if (zadace<0 || zadace>10) {
		printf("Neispravan broj bodova\n"); 
		return 0;
	} else {
	printf("Zavrsni ispit: ");
	scanf("%lf", &zispit);
	} if (zispit<0 || zispit>40) {
		printf("Neispravan broj bodova\n"); 
		return 0;

	} else {
	suma2 =Iparc + IIparc + +prisustvo + zadace + zispit;
	} 
		printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &Iparc);
	if (Iparc<0 || Iparc>20 ) {
	printf("Neispravan broj bodova\n"); 
		return 0;
	} else {
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIparc);
	}  	if (IIparc>20 || IIparc<0) {
		printf("Neispravan broj bodova\n"); 
		return 0;
	}  else {
	printf("Prisustvo: ");
	scanf("%lf", &prisustvo);
	} if(prisustvo<0 || prisustvo>10) {
		printf("Neispravan broj bodova\n"); 
		return 0;
	} else  {
	printf("Zadace: ");
	scanf("%lf", &zadace);
	}  if (zadace<0 || zadace>10) {
		printf("Neispravan broj bodova\n"); 
		return 0;
	} else {
	printf("Zavrsni ispit: ");
	scanf("%lf", &zispit);
	} if (zispit<0 || zispit>40) {
		printf("Neispravan broj bodova\n"); 
		return 0;

	} else {
	suma3 = Iparc + IIparc + +prisustvo + zadace + zispit;
	}
	if (suma1<55 && suma3<55 && suma2<55)
	printf("Nijedan student nije polozio.\n");
	else if ((suma1>=55 && suma3<55 && suma2<55) || (suma1<55 && suma3>=55 && suma2<55) || (suma1<55 && suma3<55 && suma2>=55 ))
	printf("Jedan student je polozio.\n");
	else if ((suma1>=55 && ((suma3>=55 && suma2<55) || (suma3<55 && suma2>=55))) || (suma2>=55 &&  ((suma3>=55 && suma1<55)|| (suma3<55 && suma1>=55))) || (suma3>=55 && ((suma1>=55 && suma2<55) || (suma2<55 && suma1>=55)  )))
	printf("Dva studenta su polozila.\n");
	else {
		printf("Sva tri studenta su polozila.\n");
		if ( fabs(suma1-suma2)<EPSILON && fabs(suma2-suma3)<EPSILON )
		printf("Sva tri studenta imaju istu ocjenu.\n");
		else if (fabs(suma1-suma2)<10 || fabs(suma2-suma3)<10 || fabs(suma1-suma3)<10)
		printf("Dva od tri studenta imaju istu ocjenu.\n");
		else 
		printf("Svaki student ima razlicitu ocjenu.");
	}

	return 0;
}
