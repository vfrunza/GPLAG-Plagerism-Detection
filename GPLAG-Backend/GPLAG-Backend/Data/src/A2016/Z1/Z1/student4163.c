#include <stdio.h>

int main() {
	float prvi, drugi, p, z, zi;
	float prvi1, drugi1, p1, z1, zi1;
	float prvi2, drugi2, p2, z2, zi2;
	float suma1=0,suma2=0,suma3=0;
	int ocjena1, ocjena2, ocjena3;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit:");
	scanf("%f", &prvi);
	if(prvi>20 || prvi<0) {
		printf("Neispravan broj bodova");
    	return 0;
		
	}
	printf(" II parcijalni ispit: ");
	scanf("%f", &drugi);
	if(drugi<0 || drugi>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &p);
	if(p<0 || p>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &z);
	if(z<0 || z>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &zi);
	if(zi<0 || zi>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	suma1=suma1+prvi+drugi+p+z+zi;

	
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%f", &prvi1);
	if(prvi1<0 || prvi1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &drugi1);
	if(drugi1<0 || drugi1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &p1);
	if(p1<0 || p1>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f", &z1);
	if(z1<0 || z1>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &zi1);
	if(zi<0 || zi>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	suma2=prvi1+drugi1+p1+z1+zi1;

	
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%f", &prvi2);
	if(prvi2<0 || prvi2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &drugi2);
	if(drugi2<0 || drugi2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f", &p2);
	if(p2<0 || p2>10){
		printf("Neispravan broj bodova");
		return 0;
		
	}
	printf("Zadace: ");
	scanf("%f", &z2);
	if(z2<0 || z2>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &zi2);
	if(zi2<0 || zi2>40){
		printf("Neispravan broj bodova");
		return 0;
	}

	suma3=prvi2+drugi2+p2+z2+zi2;
	
	
	if(suma1<55) ocjena1=5;
	else if(suma1>=55 && suma1<65) ocjena1=6;
	else if(suma1>=65 && suma1<75) ocjena1=7;
	else if(suma1>=75 && suma1<85) ocjena1=8;
	else if(suma1>=85 && suma1<92) ocjena1=9;
	else if(suma1>=92 && suma1<=100) ocjena1=10;
	
	if(suma2<55) ocjena2=5;
	else if(suma2>=55 && suma2<65) ocjena2=6;
	else if(suma2>=65 && suma2<75) ocjena2=7;
	else if(suma2>=75 && suma2<85) ocjena2=8;
	else if(suma2>=85 && suma2<92) ocjena2=9;
	else if(suma2>=92 && suma2<=100) ocjena2=10;
	
	if(suma3<55) ocjena3=5;
	else if(suma3>=55 && suma3<65) ocjena3=6;
	else if(suma3>=65 && suma3<75) ocjena3=7;
	else if(suma3>=75 && suma3<85) ocjena3=8;
	else if(suma3>=85 && suma3<92) ocjena3=9;
	else if(suma3>=92 && suma3<=100) ocjena3=10;
	
	if(ocjena1==5 && ocjena2==5 && ocjena3==5) printf("Nijedan student nije polozio.\n");
	else if((ocjena1>=6 && ocjena2==5 && ocjena3==5) || (ocjena1==5 && ocjena2>=6 && ocjena3==5) || (ocjena1==5 && ocjena2==5 && ocjena3>=6)) printf("Jedan student je polozio.");
	else if((ocjena1>5 && ocjena2>5 && ocjena3==5) || (ocjena1>5 && ocjena2==5 && ocjena3>5) || (ocjena1==5 && ocjena2>5 && ocjena3>5)) printf("Dva studenta su polozila.\n");
	else if(ocjena1>5 && ocjena2>5 && ocjena3>5){
		printf("Sva tri studenta su polozila.\n");
		if(ocjena1==ocjena2 && ocjena2==ocjena3 && ocjena1==ocjena3) printf("\nSva tri studenta imaju istu ocjenu.\n");
		else if((ocjena1==ocjena2 && ocjena1!=ocjena3 && ocjena2!=ocjena3) || (ocjena1==ocjena3 && ocjena2!=ocjena1 && ocjena2!=ocjena3) || (ocjena2==ocjena3 && ocjena1!=ocjena2 && ocjena1!=ocjena3)) 
		printf("\nDva od tri studenta imaju istu ocjenu.");
		else if(ocjena1!=ocjena2 && ocjena2!=ocjena3 && ocjena1!=ocjena3) printf("Svaki student ima razlicitu ocjenu.\n");
	}
	
	
	return 0;
	
}
