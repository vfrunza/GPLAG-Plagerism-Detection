#include <stdio.h>
#include <math.h>
#define eps 0.00001

int main() {
	double prvi, drugi,zadaca,prisus,zavrsni,sum=0;
	int i1=0,i2=0,i3=0,i4=0,i5=0,i6=0;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&prvi);
	if(prvi<0 || prvi>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&drugi);
	if(drugi<0 || drugi>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&prisus);
	if(prisus<0 || prisus>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&zadaca);
	if(zadaca<0 || zadaca>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&zavrsni);
	if(zavrsni<0 || zavrsni>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	sum=prvi+drugi+zadaca+prisus+zavrsni;
	if(sum<55) i1++;
	else if(sum>=55 && sum<65) i2++;
	else if(sum>=65 && sum<75) i3++;
	else if(sum>=75 && sum<85) i4++;
	else if(sum>=85 && sum<92) i5++;
	else if(sum>=92 && sum<100)i6++;
	
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&prvi);
	if(prvi<0 || prvi>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&drugi);
	if(drugi<0 || drugi>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&prisus);
	if(prisus<0 || prisus>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&zadaca);
	if(zadaca<0 || zadaca>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&zavrsni);
	if(zavrsni<0 || zavrsni>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	sum=prvi+drugi+zadaca+prisus+zavrsni;
	if(sum<55) i1++;
	else if(sum>=55 && sum<65) i2++;
	else if(sum>=65 && sum<75) i3++;
	else if(sum>=75 && sum<85) i4++;
	else if(sum>=85 && sum<92) i5++;
	else if(sum>=92 && sum<100)i6++;
	
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&prvi);
	if(prvi<0 || prvi>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&drugi);
	if(drugi<0 || drugi>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&prisus);
	if(prisus<0 || prisus>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&zadaca);
	if(zadaca<0 || zadaca>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&zavrsni);
	if(zavrsni<0 || zavrsni>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	sum=prvi+drugi+zadaca+prisus+zavrsni;
	if(sum<55) i1++;
	else if(sum>=55 && sum<65) i2++;
	else if(sum>=65 && sum<75) i3++;
	else if(sum>=75 && sum<85) i4++;
	else if(sum>=85 && sum<92) i5++;
	else if(sum>=92 && sum<100)i6++;
	
	if(i1==3)
	printf("Nijedan student nije polozio.");
	else if(i1==2)
	printf("Jedan student je polozio.");
	else if(i1==1)
	printf("Dva studenta su polozila.");
	else if(i1==0)
	printf("Sva tri studenta su polozila.\n");
	
	if(i1==0 && (i2==3|| i3==3 || i4==3 || i5==3 || i6==3))
	printf("Sva tri studenta imaju istu ocjenu.");
	else if(i1==0 &&(i2==2|| i3==2 || i4==2 || i5==2 || i6==2))
	printf("Dva od tri studenta imaju istu ocjenu.");
	else if(i1==0 &&(i2==1|| i3==1 || i4==1 || i5==1 || i6==1))
	printf("Svaki student ima razlicitu ocjenu.");
	return 0;
}
