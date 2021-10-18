#include <stdio.h>

int main() {
	double Ip1,IIp1,pris1,zad1,zi1,s1;
	double Ip2,IIp2,pris2,zad2,zi2,s2;
	double Ip3,IIp3,pris3,zad3,zi3,s3;
	char ot='a',ob='a',om='a';
	printf("Unesite bodove za Tarika: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &Ip1);
	if(Ip1<0 || Ip1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIp1);
	if(IIp1<0 || IIp1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &pris1);
	if(pris1<0 || pris1>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &zad1);
	if(zad1<0 || zad1>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zi1);
	if(zi1<0 || zi1>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	
	else{
		s1=Ip1+IIp1+pris1+zad1+zi1;
		if(s1<55) ot='p';
		else if(s1>=55 && s1<65) ot=6;
		else if(s1>=65 && s1<75) ot=7;
		else if(s1>=75 && s1<85) ot=8;
		else if(s1>=85 && s1<92) ot=9;
		else if(s1>=92 && s1<=100) ot=10;
	}
	
	printf("Unesite bodove za Bojana: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &Ip2);
	if(Ip2<0 || Ip2>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIp2);
	if(IIp2<0 || IIp2>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &pris2);
	if(pris2<0 || pris2>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &zad2);
	if(zad2<0 || zad2>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zi2);
	if(zi2<0 || zi2>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	else{
		s2=Ip2+IIp2+pris2+zad2+zi2;
		if(s2<55) ob='p';
		else if(s2>=55 && s2<65) ob=6;
		else if(s2>=65 && s2<75) ob=7;
		else if(s2>=75 && s2<85) ob=8;
		else if(s2>=85 && s2<92) ob=9;
		else if(s2>=92 && s2<=100) ob=10;
	}
	
	printf("Unesite bodove za Mirzu: ");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &Ip3);
	if(Ip3<0 || Ip3>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIp3);
	if(IIp3<0 || IIp3>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &pris3);
	if(pris3<0 || pris3>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &zad3);
	if(zad3<0 || zad3>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &zi3);
	if(zi3<0 || zi3>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	else{
		s3=Ip3+IIp3+pris3+zad3+zi3;
		if(s3<55) om='p';
		else if(s3>=55 && s3<65) om=6;
		else if(s3>=65 && s3<75) om=7;
		else if(s3>=75 && s3<85) om=8;
		else if(s3>=85 && s3<92) om=9;
		else if(s3>=92 && s3<=100) om=10;
	}
	
	
	if((ot!='p' && ob=='p' && om=='p') || (ot=='p' && ob=='p' && om!='p') || (ot=='p' && ob!='p' && om=='p'))  
		printf("Jedan student je polozio.\n");
	else if((ot=='p' && ob!='p' && om!='p') || (ot!='p' && ob!='p' && om=='p') || (ot!='p' && ob=='p' && om!='p')) 
		printf("Dva studenta su polozila.\n");
	else if(ot!='p' && ob!='p' && om!='p') 
		printf("Sva tri studenta su polozila.\n");
	else if(ot=='p' && ob=='p' && om=='p') 
		printf("Nijedan student nije polozio.\n");
	
	if((s1>=55 && s1<=100) && (s2>=55 && s2<=100) && (s3>=55 && s3<=100)){
		
		if(ot==ob && ob==om)
			printf("Sva tri studenta imaju istu ocjenu.\n");
		if((ot!=ob && ot!=om && ob==om) || (ot==om  && ob!=ot && ob!=om) || (ot==ob && ot!=om && ob!=om))
			printf("Dva od tri studenta imaju istu ocjenu.\n");
		if(ot!=ob && ob!=om && ot!=om) 
			printf("Svaki student ima razlicitu ocjenu.\n");
	}
	
	
	return 0;
}
