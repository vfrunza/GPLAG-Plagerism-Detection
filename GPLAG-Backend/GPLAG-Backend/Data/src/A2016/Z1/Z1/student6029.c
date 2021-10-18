#include <stdio.h>

int main() {
	double ip1=0,iip1=0,pr1=0,zad1=0,zi1=0;
	double ip2=0,iip2=0,pr2=0,zad2=0,zi2=0;
	double ip3=0, iip3=0,pr3=0,zad3=0,zi3=0;
	int oc1=0,oc2=0,oc3=0;
	double b1=0,b2=0,b3=0;
	int brpolozilo=3;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&ip1);
	if(ip1<0||ip1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&iip1);
	if(iip1<0||iip1>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&pr1);
	if(pr1<0||pr1>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&zad1);
	if(zad1<0||zad1>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&zi1);
	if(zi1<0||zi1>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	b1=ip1+iip1+pr1+zad1+zi1;
	if(b1<55) 
		oc1=5;
	else if(b1>=55&&b1<65)
		oc1=6;
	else if(b1>=6&&b1<75)
		oc1=7;
	else if(b1>=75&&b1<85)
		oc1=8;
	else if(b1>=85&&b1<92)
		oc1=9;
	else if(b1>=92&&b1<=100)
		oc1=10;
		
	if(oc1==5)
		brpolozilo--;
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&ip2);
	if(ip2<0||ip2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&iip2);
	if(iip2<0||iip2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&pr2);
	if(pr2<0||pr2>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&zad2);
	if(zad2<0||zad2>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&zi2);
	if(zi2<0||zi2>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	b2=ip2+iip2+pr2+zad2+zi2;
	if(b2<55)
		oc2=5;
	else if(b2>=55&&b2<65)
		oc2=6;
	else if(b2>=65&&b2<75)
		oc2=7;
	else if(b2>=75&&b2<85)
		oc2=8;
	else if(b2>=85&&b2<92)
		oc2=9;
	else if(b2>=92&&b2<=100)
		oc2=10;
	if(oc2==5)
		brpolozilo--;
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&ip3);
	if(ip3<0||ip3>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&iip3);
	if(iip3<0||iip3>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&pr3);
	if(pr3<0||pr3>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&zad3);
	if(zad3<0||zad3>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&zi3);
	if(zi3<0||zi3>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	b3=ip3+iip3+pr3+zad3+zi3;
	if(b3<55)
		oc3=5;
	else if(b3>=55&&b3<65)
		oc3=6;
	else if(b3>=65&&b3<75)
		oc3=7;
	else if(b3>=75&&b3<85)
		oc3=8;
	else if(b3>=85&&b3<92)
		oc3=9;
	else if(b3>=92&&b3<=100)
		oc3=10;
	if(oc3==5)
		brpolozilo--;
		
	if(brpolozilo==0){
		printf("Nijedan student nije polozio. ");
		return 0;
	}
	else if(brpolozilo==1){
		printf("Jedan student je polozio. ");
		return 0;
	}
	else if(brpolozilo==2){
		printf("Dva studenta su polozila. ");
		return 0;
	}
	else if(brpolozilo==3){
		printf("Sva tri studenta su polozila. \n");
		if(oc1==oc2&&oc1==oc3&&oc1==oc2)
			printf("Sva tri studenta imaju istu ocjenu. ");
		else if (oc1==oc2||oc1==oc3||oc1==oc2)
			printf("Dva od tri studenta imaju istu ocjenu. ");
		else
			printf("Svaki student ima razlicitu ocjenu. ");
	}
	return 0;
}
