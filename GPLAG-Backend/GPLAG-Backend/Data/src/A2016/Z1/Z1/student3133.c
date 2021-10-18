#include <stdio.h>

int main() {
	double T=0, B=0, M=0, P1, P2, P, Z, ZI, ocjenaT, ocjenaB, ocjenaM;
	printf("Unesite bodove za Tarika: \nI parcijalni ispit: ");
	scanf("%lf", &P1);
	if(P1<0||P1>20){
		printf("Neispravan broj bodova");
		return 1;
	}
	else T=T+P1;
	printf("II parcijalni ispit: ");
	scanf("%lf", &P2);
	if(P2<0||P2>20){
		printf("Neispravan broj bodova");
		return 1;
	}
	else T=T+P2;
	printf("Prisustvo: ");
	scanf("%lf", &P);
	if(P<0||P>10){
		printf("Neispravan broj bodova");
		return 1;
	}
	else T=T+P;
	printf("Zadace: ");
	scanf("%lf", &Z);
	if(Z<0||Z>10){
		printf("Neispravan broj bodova");
		return 1;
	}
	else T=T+Z;
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZI);
	if(ZI<0||ZI>40){
		printf("Neispravan broj bodova");
		return 1;
	}
	else T=T+ZI;
	printf("Unesite bodove za Bojana: \nI parcijalni ispit: ");
	scanf("%lf", &P1);
	if(P1<0||P1>20){
		printf("Neispravan broj bodova");
		return 1;
	}
	else B=B+P1;
	printf("II parcijalni ispit: ");
	scanf("%lf", &P2);
	if(P2<0||P2>20){
		printf("Neispravan broj bodova");
		return 1;
	}
	else B=B+P2;
	printf("Prisustvo: ");
	scanf("%lf", &P);
	if(P<0||P>10){
		printf("Neispravan broj bodova");
		return 1;
	}
	else B=B+P;
	printf("Zadace: ");
	scanf("%lf", &Z);
	if(Z<0||Z>10){
		printf("Neispravan broj bodova");
		return 1;
	}
	else B=B+Z;
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZI);
	if(ZI<0||ZI>40){
		printf("Neispravan broj bodova");
		return 1;
	}
	else B=B+ZI;
	printf("Unesite bodove za Mirzu: \nI parcijalni ispit: ");
	scanf("%lf", &P1);
	if(P1<0||P1>20){
		printf("Neispravan broj bodova");
		return 1;
	}
	else M=M+P1;
	printf("II parcijalni ispit: ");
	scanf("%lf", &P2);
	if(P2<0||P2>20){
		printf("Neispravan broj bodova");
		return 1;
	}
	else M=M+P2;
	printf("Prisustvo: ");
	scanf("%lf", &P);
	if(P<0||P>10){
		printf("Neispravan broj bodova");
		return 1;
	}
	else M=M+P;
	printf("Zadace: ");
	scanf("%lf", &Z);
	if(Z<0||Z>10){
		printf("Neispravan broj bodova");
		return 1;
	}
	else M=M+Z;
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZI);
	if(ZI<0||ZI>40){
		printf("Neispravan broj bodova");
		return 1;
	}
	else M=M+ZI;
		if(T<55) ocjenaT=0;
		else if(T<65&&T>=55) ocjenaT=6;
		else if(T<75&&T>=65) ocjenaT=7;
		else if(T<85&&T>=75) ocjenaT=8;
		else if(T<92&&T>=85) ocjenaT=9;
		else ocjenaT=10;
			if(B<55) ocjenaB=0;
		else if(B<65&&B>=55) ocjenaB=6;
		else if(B<75&&B>=65) ocjenaB=7;
		else if(B<85&&B>=75) ocjenaB=8;
		else if(B<92&&B>=85) ocjenaB=9;
		else ocjenaB=10;
			if(M<55) ocjenaM=0;
		else if(M<65&&M>=55) ocjenaM=6;
		else if(M<75&&M>=65) ocjenaM=7;
		else if(M<85&&M>=75) ocjenaM=8;
		else if(M<92&&M>=85) ocjenaM=9;
		else ocjenaM=10;
		if(ocjenaT&&ocjenaB&&ocjenaM) printf("Sva tri studenta su polozila.");
		else if((ocjenaT==0&&ocjenaB*ocjenaM!=0)||(ocjenaB==0&&ocjenaT*ocjenaM!=0)||(ocjenaM==0&&ocjenaT*ocjenaB!=0))
		printf("Dva studenta su polozila.");
		else if((ocjenaT==0&&ocjenaB==0&&ocjenaM!=0)||(ocjenaT!=0&&ocjenaB==0&&ocjenaM==0)||(ocjenaB!=0&&ocjenaM==0&&ocjenaT==0))
		printf("Jedan student je polozio.");
		else if(ocjenaM==0&&ocjenaT==0&&ocjenaB==0)
		printf("Nijedan student nije polozio.");
		if(ocjenaT!=0 && ocjenaB!=0 && ocjenaM!=0 && ocjenaT==ocjenaB&&ocjenaB==ocjenaM)
		printf("\nSva tri studenta imaju istu ocjenu.");
		else if((ocjenaT!=0&&ocjenaM!=0&&ocjenaB!=0)&&((ocjenaT==ocjenaB&&ocjenaB!=ocjenaM)||(ocjenaT==ocjenaM&&ocjenaM!=ocjenaB)||(ocjenaM==ocjenaB&&ocjenaB!=ocjenaT)))
		printf("\nDva od tri studenta imaju istu ocjenu.");
		else if(ocjenaT!=0 && ocjenaB!=0 && ocjenaM!=0 && ocjenaT!=ocjenaM&&ocjenaM!=ocjenaB)
		printf("\nSvaki student ima razlicitu ocjenu.");
	return 0;
}
