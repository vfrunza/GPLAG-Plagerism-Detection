#include <stdio.h>
#include <math.h>

int main() {
	int a, b, c;
	double x1, x2, x3, x4, x5, y1, y2, y3, y4, y5, z1, z2, z3, z4, z5, S1, S2, S3;

	
	/*Tarik*/
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &x1);
	if (x1<0 || x1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("II parcijalni ispit: ");
	scanf("%lf", &x2);
		if (x2<0 || x2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Prisustvo: ");
	scanf("%lf", &x3);
		if (x3<0 || x3>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zadace: ");
	scanf("%lf", &x4);
		if (x4<0 || x4>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%lf", &x5);
		if (x5<0 || x5>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	/*Bojan*/
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &y1);
	if (y1<0 || y1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("II parcijalni ispit: ");
	scanf("%lf", &y2);
		if (y2<0 || y2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Prisustvo: ");
	scanf("%lf", &y3);
		if (y3<0 || y3>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zadace: ");
	scanf("%lf", &y4);
		if (y4<0 || y4>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%lf", &y5);
		if (y5<0 || y5>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	/*Mirza*/
		printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &z1);
	if (z1<0 || z1>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("II parcijalni ispit: ");
	scanf("%lf", &z2);
		if (z2<0 || z2>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Prisustvo: ");
	scanf("%lf", &z3);
		if (z3<0 || z3>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zadace: ");
	scanf("%lf", &z4);
		if (z4<0 || z4>10){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Zavrsni ispit: ");
	scanf("%lf", &z5);
		if (z5<0 || z5>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	S1=x1+x2+x3+x4+x5;
	S2=y1+y2+y3+y4+y5;
	S3=z1+z2+z3+z4+z5;
	
	if (S1>=0 && S1<55){
		
	 a=5;
	}

	else if (S1>=55 && S1<65 ){
		a=6;
	}
	else if (S1>=65 && S1<75){
		a=7;
	}
	else if (S1>=75 && S1<85){
		a=8;
	}
	else if (S1>=85 && S1<92){
		a=9;
	}
	else if (S1>=92 && S1<=100){
		a=10;
	}
	
	if (S2>=0 && S2<55){
		
	 b=5;
	}
	else if (S2>=55 && S2<65 ){
		b=6;
	}
	else if (S2>=65 && S2<75){
		b=7;
	}
	else if (S2>=75 && S2<85){
		b=8;
	}
	else if (S2>=85 && S2<92){
		b=9;
	}
	else if (S2>=92 && S2<=100){
		b=10;
	}
	
	
	if (S3>=0 && S3<55){
		
	 c=5;
	}
	else if (S3>=55 && S3<65 ){
		c=6;
	}
	else if (S3>=65 && S3<75){
		c=7;
	}
	else if (S3>=75 && S3<85){
		c=8;
	}
	else if (S3>=85 && S3<92){
		c=9;
	}
	else if (S3>=92 && S3<=100){
		c=10;
	}
	
	if ((a==5) && (b==5) && (c==5)){
		printf("Nijedan student nije polozio.\n");
	}
	else if (((a==5) && (b==5) && (c!=5)) || ((a==5) && (c==5) && (b!=5)) || ((c==5) && (b==5) && (a!=5))){
		printf("Jedan student je polozio.\n");
	}
	else if (((a!=5) && (b!=5) && (c==5)) || ((a!=5) && (b==5) && (c!=5)) || ((a==5) && (b!=5) && (c!=5))){
		printf("Dva studenta su polozila.\n");
	}
	else if ((a!=5) && (b!=5) && (c!=5)){
		printf("Sva tri studenta su polozila.\n");
		 
	
	if (((a==b) && (a!=c) && (b!=c))|| ((a==c) && (a!=b) && (b!=c)) || ((c==b) && (a!=c) && (b!=a))){
	 	printf("Dva od tri studenta imaju istu ocjenu.\n");
	 	
	 }
	  else if ((a==b) && (b==c) && (a==c)){
	 	printf("Sva tri studenta imaju istu ocjenu.\n");
		  }
	else if ((a!=b) && (b!=c) && (a!=c)){
		printf("Svaki student ima razlicitu ocjenu.\n");
		
	}
	
	}


	return 0;
}
