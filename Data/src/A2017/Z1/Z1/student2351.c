#include <stdio.h>
#define p1 6.8
#define p2 8
#define p3 5.3
#define h1 3.3
#define h2 3
#define h3 5
#define c1 5
#define c2 3.9
#define c3 6

int main() {
	char tarik, bojan, mirza, novi_red;
	float s1=0, s2=0, s3=0, popp=0, popc=0, poph=0, popust;
	printf("Unesite jelo za Tarika: ");
	scanf("%c", &tarik);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Bojana: ");
	scanf("%c", &bojan);
	scanf("%c", &novi_red);
	printf("Unesite jelo za Mirzu: ");
	scanf("%c", &mirza);
	scanf("%c", &novi_red);
	
	/*RACUNAMO CIJENE BEZ POPUSTA*/
	if(tarik=='P') s1=s1+p1;
	else if(tarik=='C') s1=s1+c1;
	else s1=s1+h1;
	
	if(bojan=='P') s1=s1+p1;
	else if(bojan=='C') s1=s1+c1;
	else s1=s1+h1;
	
	if(mirza=='P') s1=s1+p1;
	else if(mirza=='C') s1=s1+c1;
	else s1=s1+h1;
	
	
	
	if(tarik=='P') s2=s2+p2;
	else if(tarik=='C') s2=s2+c2;
	else s2=s2+h2;
	
	if(bojan=='P') s2=s2+p2;
	else if(bojan=='C') s2=s2+c2;
	else s2=s2+h2;
	
	if(mirza=='P') s2=s2+p2;
	else if(mirza=='C') s2=s2+c2;
	else s2=s2+h2;
	
	
	if(tarik=='P') s3=s3+p3;
	else if(tarik=='C') s3=s3+c3;
	else s3=s3+h3;
	
	if(bojan=='P') s3=s3+p3;
	else if(bojan=='C') s3=s3+c3;
	else s3=s3+h3;
	
	if(mirza=='P') s3=s3+p3;
	else if(mirza=='C') s3=s3+c3;
	else s3=s3+h3;
	
	
	/*RACUNAMO POPUST RESTORANA NA SVAKO JELO*/
	
	
	/*kad je pizza na popustu*/
	if(tarik=='P') popp=popp+p1-p1*10/100; /*popp=cijena s popustom*/
	else if(tarik=='C') popp=popp+c1;
	else popp=popp+h1;
	
	if(bojan=='P') popp=popp+p1-p1*10/100;
	else if(bojan=='C') popp=popp+c1;
	else popp=popp+h1;
	
	if(mirza=='P') popp=popp+p1-p1*10/100;
	else if(mirza=='C') popp=popp+c1;
	else popp=popp+h1;
	
	/*kad su cevapi na popustu*/
	if(tarik=='C') popc=popc+c1-c1*10/100;
	else if(tarik=='P') popc=popc+p1;
	else popc=popc+h1;
	
	if(bojan=='C') popc=popc+c1-c1*10/100;
	else if(bojan=='P') popc=popc+p1;
	else popc=popc+h1;
	
	if(mirza=='C') popc=popc+c1-c1*10/100;
	else if(mirza=='P') popc=popc+p1;
	else popc=popc+h1;
	
	/*kad je hamburger na popustu*/
	if(tarik=='H') poph=poph+h1-h1*10/100;
	else if(tarik=='C') poph=poph+c1;
	else poph=poph+p1;
	
	if(bojan=='H') poph=poph+h1-h1*10/100;
	else if(bojan=='C') poph=poph+c1;
	else poph=poph+p1;
	
	if(mirza=='H') poph=poph+h1-h1*10/100;
	else if(mirza=='C') poph=poph+c1;
	else poph=poph+p1;
	
	
	
	if(popp<=popc && popp<=poph) popust=popp;
	else if(popc<=popp && popc<=poph) popust=popc;
	else popust=poph;
	
	/*uporedivanje cijena*/
	if(s1<=s2 && s1<=s3) {
		printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", s1);
		return 0;
	}
	
	if(s2<=s1 && s2<=s3) {
		printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).\n", s2);
		if(popust<s2) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
		return 0;
	}
	
		if(s3<=s1 && s3<=s2) {
		printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).\n", s3);
		if(popust<s3) printf("Sa popustom bi Restoran bio jeftiniji (%.2f KM).", popust);
	}
	
	
	
	return 0;
}
