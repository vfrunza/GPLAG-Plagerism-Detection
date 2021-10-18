#include <stdio.h>

#define F 55  /* <55 - student pao*/
#define FD 55 /* >=55 - ocjena 6*/
#define DC 65 /* >=65 - ocjena 7*/
#define CB 75 /* >=75 - ocjena 8*/
#define BA 85 /* >=85 - ocjena 9*/
#define A 92 /* >=92 - ocjena 10*/

int main() {
	
	float I1,II1,I2,II2,I3,II3,P1,P2,P3,Z1,Z2,Z3,ZI1,ZI2,ZI3,UK1,UK2,UK3;
	int ST1=0, ST2=0, ST3=0;
	
	/*Tarik*/
	
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%f",&I1);
	if(I1<0 || I1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&II1);
	if(II1<0 || II1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&P1);
	if(P1<0 || P1>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&Z1);
	if(Z1<0 || Z1>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&ZI1);
	if(ZI1<0 || ZI1>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	/*Bojan*/
	
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%f",&I2);
	if(I2<0 || I2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&II2);
	if(II2<0 || II2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Prisustvo: ");
	scanf("%f",&P2);
	if(P2<0 || P2>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&Z2);
	if(Z2<0 || Z2>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&ZI2);
	if(ZI2<0 || ZI2>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	/*Mirza*/
	
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%f",&I3);
	if(I3<0 || I3>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&II3);
	if(II3<0 || II3>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&P3);
	if(P3<0 || P3>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&Z3);
	if(Z3<0 || Z3>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&ZI3);
	if(ZI3<0 || ZI3>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	UK1 = I1 + II1 + P1 + ZI1 + Z1; /*Tarik*/
	UK2 = I2 + II2 + P2 + ZI2 + Z2; /*Bojan*/
	UK3 = I3 + II3 + P3 + ZI3 + Z3; /*Mirza*/
	
	
	/* ST1 - Student 1; ST2 - Student 2; ST3 - Student 3*/
	
	if(UK1>=F && UK1<DC){
		UK1=55;
		ST1=55;
	}
	else if(UK1>=DC && UK1<CB){
		UK1=65;
		ST1=65;
	}
	else if(UK1>=CB && UK1<BA){
		UK1=75;
		ST1=75;
	}
	else if(UK1>=BA && UK1<A){
		UK1=85;
		ST1=85;
	}
	else if(UK1>=A){
		UK1=92;
		ST1=92;
	}
	
	
	if(UK2>=F && UK2<DC){
		UK2=55;
		ST2=55;
	}
	else if(UK2>=DC && UK2<CB){
		UK2=65;
		ST2=65;
	}
	else if(UK2>=CB && UK2<BA){
		UK2=75;
		ST2=75;
	}
	else if(UK2>=BA && UK2<A){
		UK2=85;
		ST2=85;
	}
	else if(UK2>=A){
		UK2=92;
		ST2=92;
	}
	
	
	if(UK3>=F && UK3<DC){
		UK3=55;
		ST3=55;
	}
	else if(UK3>=DC && UK3<CB){
		UK3=65;
		ST3=65;
	}
	else if(UK3>=CB && UK3<BA){
		UK3=75;
		ST3=75;
	}
	else if(UK3>=BA && UK3<A){
		UK3=85;
		ST3=85;
	}
	else if(UK3>=A){
		UK3=92;
		ST3=92;
	}
	
	
	if(UK1<F && UK2<F && UK3<F){
		printf("Nijedan student nije polozio.");
		return 0;
	}
	else if((UK1>=F && UK2<F && UK3<F) || (UK1<F && UK2>=F && UK3<F) || (UK1<F && UK2<F && UK3>=F)){
		printf("Jedan student je polozio.");
		return 0;
	}
	else if((UK1>=F && UK2>=F && UK3<F) || (UK1<F && UK2>=F && UK3>=F) || (UK1>=F && UK2<F && UK3>=F)){
		printf("Dva studenta su polozila.");
		return 0;
			
	}
	
	else if(UK1>=F && UK2>=F && UK3>=F){
		printf("Sva tri studenta su polozila.\n");
			
		if(ST1==ST2 && ST2==ST2 && ST2==ST3){
			printf("Sva tri studenta imaju istu ocjenu.");
			return 0;
		}
		else if((ST1==ST2 && ST1!=ST3) || (ST2==ST3 && ST1!=ST2) || (ST1==ST3 && ST1!=ST2)){
			printf("Dva od tri studenta imaju istu ocjenu.");
			return 0;
		}
		else if(ST1!=ST2 && ST1!=ST3 && ST2!=ST3){
			printf("Svaki student ima razlicitu ocjenu.");
			return 0;
		}
			
	}
		
	return 0;
}
