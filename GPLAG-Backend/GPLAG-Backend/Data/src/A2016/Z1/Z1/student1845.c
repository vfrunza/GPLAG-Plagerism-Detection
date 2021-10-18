#include <stdio.h>
#include <math.h>
#define E 0.00001

int main() {
	int O,O1,O2;
	float P8, P2, Z,P,P3,P4,Z1,P1,P5,P6,Z2,z,C,D,P7,B,B1,B2;
	int neispravanUnos=0;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &P8);
	printf("II parcijalni ispit: ");
	scanf("%f", &P2);
	printf("Prisustvo: ");
	scanf("%f", &P);
	printf("Zadace: ");
	scanf("%f", &Z);
	printf("Zavrsni ispit: ");
	scanf("%f", &z);
	//if(P8>=0 && P8<=20) printf("I");
	//if(P2>=0 && P2<=20) printf("II");
	//if(P>=0 && P<=10) printf("Prisustvo");
	//if(Z>=0 && Z<=10) printf("Zadace");
	//if(z>=15 && z<=40) printf("Zavrsni ispit");
	if((P8>=0 && P8<=20) && (P2>=0 && P2<=20) && (P>=0 && P<=10) && (Z>=0 && Z<=10) && z<=40) {
		B=P8+P2+P+Z+z+E;
		
		if(B < 55) {
			O = 5;
		} else if(B < 65) {
			O = 6;
		} else if(B < 75) {
			O = 7;
		} else if(B < 85) {
			O = 8;
		} else if(B < 92) {
			O = 9;
		} else {
			O = 10;
		}
	} else {
		neispravanUnos++;
	}
	
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &P3);
	printf("II parcijalni ispit: ");
	scanf("%f", &P4);
	printf("Prisustvo: ");
	scanf("%f", &P1);
	printf("Zadace: ");
	scanf("%f", &Z1);
	printf("Zavrsni ispit: ");
	scanf("%f", &C);
	if(P3>=0 && P3<=20 && P4>=0 && P4<=20 && P1>=0 && P1<=10 && Z1>=0 && Z1<=10 && C<=40 )
	{
		B1=P3+P4+P1+Z1+C;
		
		if(B1 < 55) {
			O1 = 5;
		} else if(B1 < 65) {
			O1 = 6;
		} else if(B1 < 75) {
			O1 = 7;
		} else if(B1 < 85) {
			O1 = 8;
		} else if(B1 < 92) {
			O1 = 9;
		} else {
			O1 = 10;
		}
	} else {
		neispravanUnos++;
	}
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &P5);
	printf("II parcijalni ispit: ");
	scanf("%f", &P6);
	printf("Prisustvo: ");
	scanf("%f", &P7);
	printf("Zadace: ");
	scanf("%f", &Z2);
	printf("Zavrsni ispit: ");
	scanf("%f", &D);
	
	if(P5>=0 && P5<=20 && P6>=0 && P6<=20 && P7>=0 && P7<=10 && Z2>=0 && Z2<=10 && D<=40 ) {
		B2=P5+P6+P7+Z2+D;
		
		if(B2 < 55) {
			O2 = 5;
		} else if(B2 < 65) {
			O2 = 6;
		} else if(B2 < 75) {
			O2 = 7;
		} else if(B2 < 85) {
			O2 = 8;
		} else if(B2 < 92) {
			O2 = 9;
		} else {
			O2 = 10;
		}
	}
	else {
		neispravanUnos++;
	}

	if(neispravanUnos > 0){
		printf("Neispravan broj bodova."); return 0;
	}
	
	int prosli = 0;
	if(O>5) {
		prosli++;
	}
	if(O1>5) {
		prosli++;
	}
	if(O2>5) {
		prosli++;
	} 
	switch(prosli) {
		case 3:
			printf("Sva tri studenta su polozila.\n"); break;
		case 2:
			printf("Dva studenta su polozila.\n"); break;
		case 1: 
			printf("Jedan student je polozio.\n"); break;
		default:
			printf("Nijedan student nije polozio.\n");
	}
	
	if(prosli == 3) {
		if(O==O1 && O==O2 && O1==O2) {
			printf("Sva tri studenta imaju istu ocjenu.");
		} else if((O==O1 && O!=O2) || (O==O2 && O!=O1) || (O1==O2 && O!=O1)) {
			printf("Dva od tri studenta imaju istu ocjenu.");
		} else if(O!=O1 && O!=O2) {
			printf("Svaki student ima razlicitu ocjenu.");
		}
	}
	return 0;
}
