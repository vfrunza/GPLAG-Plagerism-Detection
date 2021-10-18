#include <stdio.h>
#include <math.h>
#define EPSILON 0.000001
int main() {

	double a=0, b=0, c=0, d=0, e=0, a1=0, b1=0, c1=0, d1=0, e1=0, a2=0, b2=0, c2=0, d2=0, e2=0, s=0, s1=0, s2=0, o1=0,  o2=0, o3=0, ou=0;
	printf("Unesite bodove za Tarika: \n");

	printf("I parcijalni ispit: ");
	scanf("%lf", &a);
		if(a>20 || a<0) {
		printf("Neispravan broj bodova");
	
	return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &b);
	if(b>20 || b<0) {
		printf("Neispravan broj bodova");
	
	return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &c);
	if(c>10 || c<0) {
		printf("Neispravan broj bodova");
	
	return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &d);
	if(d>10 || d<0) {
		printf("Neispravan broj bodova");
	
	return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &e);
		if(e>40 || a<0) {
		printf("Neispravan broj bodova");
	
	return 0;
	}	
	else {	
	printf("Unesite bodove za Bojana: ");

	printf("\nI parcijalni ispit: ");
	scanf("%lf", &a1);
	if(a1>20 || a1<0) {
		printf("Neispravan broj bodova");
	
	return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &b1);
	if(b1>20 || b2<0) {
		printf("Neispravan broj bodova");
	
	return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &c1);
	if(c1>10 || c1<0) {
		printf("Neispravan broj bodova");
	
	return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &d1);
	if(d1>10 || d<0) {
		printf("Neispravan broj bodova");
	
	return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &e1);
			if(e1>40 || e1<0) {
		printf("Neispravan broj bodova");
	
	return 0;
	}
			
	}{	
	printf("Unesite bodove za Mirzu:");
	
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &a2);
	if(a2>20 || a2<0) {
		printf("Neispravan broj bodova");
	
	return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &b2);
	if(b2>20 || b2<0) {
		printf("Neispravan broj bodova");
	
	return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &c2);
		if(c2>10 || c2<0) {
		printf("Neispravan broj bodova");
	
	return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &d2);
	if(d2>10 || d2<0) {
		printf("Neispravan broj bodova");
	
	return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &e2);
			if(e2>40 || e2<0) {
		printf("Neispravan broj bodova");
	
	return 0;
	}
		
	s=a+b+c+d+e;
	s1=a1+b1+c1+d1+e1;
	s2=a2+b2+c2+d2+e2;
	if(s>=55 && s<65)
	o1=6;
	if(s>=65 && s<75)
	o1=7;
	if(s>=75 && s<85)
	o1=8;
	if(s>=85 && s<92)
	o1=9;
	if(s>=92 && s<=100)
	o1=10;
	if(s1>=55 && s1<65)
	o2=6;
	if(s1>=65 && s1<75)
	o2=7;
	if(s1>=75 && s1<85)
	o2=8;
	if(s1>=85 && s1<92)
	o2=9;
	if(s1>=92 && s1<=100)
	o2=10;
	if(s2>=55 && s2<65)
	o3=6;
	if(s2>=65 && s2<75)
	o3=7;
	if(s2>=75 && s2<85)
	o3=8;
	if(s2>=85 && s2<92)
	o3=9;
	if(s2>=92 && s2<=100)
	o3=10;
	
	ou=o1+o2+o3;
	if((o1>=0 && o1<6) && (o2>=0 && o2<6) &&(o3>=0 && o3<6))
	printf("Nijedan student nije polozio.\n");
	else if(ou>=18 && ou<=30) {
		printf("Sva tri studenta su polozila.\n");

	if(fabs(o1-o2)<EPSILON && fabs(o2-o3)<EPSILON && fabs(o1-o3)<EPSILON)
	printf("Sva tri studenta imaju istu ocjenu.\n");
	else if (!(fabs(o1-o2)<EPSILON) && !(fabs(o1-o3)<EPSILON) && !(fabs(o2-o3)<EPSILON))
	printf("Svaki student ima razlicitu ocjenu. \n");
	else
	printf("Dva od tri studenta imaju istu ocjenu. \n");
	}
	else if((o1>=6 && o1<=10 && o2>=6 && o2<=10) || (o1>=6 && o1<=10 && o3>=6 && o3>=6 && o3<=10) || (o2>=6 && o2<=10 && o3>=6 && o3<=10))
	printf("Dva studenta su polozila.\n");
	else if((o1>=6 && o1<=10) || (o2>=6 && o2<=10) || (o3>=6 && o3<=10))
	printf("Jedan student je polozio.\n");
	}		
return 0;
 }
