#include <stdio.h>

int main() {
	double parc1T,parc2T,zadT,prisT,ziT,ubT;
	double parc1B,parc2B,zadB,prisB,ziB,ubB;
	double parc1M,parc2M,zadM,prisM,ziM,ubM;
	int ocB,ocT,ocM,brp=0;
/* Unos za Tarika */	
	printf("Unesite bodove za Tarika: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf",&parc1T);
	if(parc1T<0 || parc1T>20)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("II parcijalni ispit: ");
	scanf("%lf",&parc2T);
	if(parc2T<0 || parc2T>20)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Prisustvo: ");
	scanf("%lf",&prisT);
	if(prisT<0 || prisT>10)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Zadace: ");
	scanf("%lf",&zadT);
	if(zadT<0 || zadT>10)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Zavrsni ispit: ");
	scanf("%lf",&ziT);
	if(ziT<0 || ziT>40)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	
/* Unos za Bojana */		
	printf("Unesite bodove za Bojana: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf",&parc1B);
	if(parc1B<0 || parc1B>20)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("II parcijalni ispit: ");
	scanf("%lf",&parc2B);
	if(parc2B<0 || parc2B>20)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Prisustvo: ");
	scanf("%lf",&prisB);
	if(prisB<0 || prisB>10)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Zadace: ");
	scanf("%lf",&zadB);
	if(zadB<0 || zadB>10)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Zavrsni ispit: ");
	scanf("%lf",&ziB);
	if(ziB<0 || ziB>40)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	
/* Unos za Mirzu */	
	printf("Unesite bodove za Mirzu: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf",&parc1M);
	if(parc1M<0 || parc1M>20)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("II parcijalni ispit: ");
	scanf("%lf",&parc2M);
	if(parc2M<0 || parc2M>20)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Prisustvo: ");
	scanf("%lf",&prisM);
	if(prisM<0 || prisM>10)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Zadace: ");
	scanf("%lf",&zadM);
	if(zadM<0 || zadM>10)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
	printf("Zavrsni ispit: ");
	scanf("%lf",&ziM);
	if(ziM<0 || ziM>40)
		{
			printf("Neispravan broj bodova");
			return 0;
		}
		
/*Racunanje ukupnog broja bodova*/
	ubT=parc1T+parc2T+zadT+prisT+ziT;
	ubB=parc1B+parc2B+zadB+prisB+ziB;
	ubM=parc1M+parc2M+zadM+prisM+ziM;
	
/* Tarikova ocjena */	
	if(ubT<55)
	ocT=5;
	if(ubT>=55 && ubT<65)
	ocT=6;
	if(ubT>=65 && ubT<75)
	ocT=7;
	if(ubT>=75 && ubT<85)
	ocT=8;
	if(ubT>=85 && ubT<92)
	ocT=9;
	if(ubT>=92 && ubT<=100)
	ocT=10;

/* Bojanova ocjena */
	if(ubB<55)
	ocB=5;
	if(ubB>=55 && ubB<65)
	ocB=6;
	if(ubB>=65 && ubB<75)
	ocB=7;
	if(ubB>=75 && ubB<85)
	ocB=8;
	if(ubB>=85 && ubB<92)
	ocB=9;
	if(ubB>=92 && ubB<=100)
	ocB=10;
	
/* Mirzina ocjena */
	if(ubM<55)
	ocM=5;
	if(ubM>=55 && ubM<65)
	ocM=6;
	if(ubM>=65 && ubM<75)
	ocM=7;
	if(ubM>=75 && ubM<85)
	ocM=8;
	if(ubM>=85 && ubM<92)
	ocM=9;
	if(ubM>=92 && ubM<=100)
	ocM=10;
	
/* Prolaznost */
	if(ocT>5)
	brp++;
	if(ocB>5)
	brp++;
	if(ocM>5)
	brp++;
	
	if(brp==0)
	printf("Nijedan student nije polozio.");
	if(brp==1)
	printf("Jedan student je polozio.");
	if(brp==2)
	printf("Dva studenta su polozila.");
	if(brp==3)
	printf("Sva tri studenta su polozila.");
	
	if(brp==3)
		{
			if(ocT==ocB && ocB==ocM && ocT==ocM)
			printf("\nSva tri studenta imaju istu ocjenu.");
			else{
				if(ocT==ocB || ocB==ocM || ocT==ocM)
				printf("\nDva od tri studenta imaju istu ocjenu.");
				else
				printf("\nSvaki student ima razlicitu ocjenu.");
			}
		}
	return 0;
}
