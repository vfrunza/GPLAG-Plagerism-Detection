#include <stdio.h>
#define EPS 0.0001
int main() {
	
	float T, t1, t2, p1, z1, zi1, B, b1, b2, p2, z2, zi2, M, m1, m2, p3, z3, zi3;
	int br=0;
	
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &t1);
		if(t1<0 || t1>20) {
			printf("Neispravan broj bodova");
		return 0; }
	printf("II parcijalni ispit: ");
	scanf("%f", &t2);
		if(t2<0 || t2>20) {
			printf("Neispravan broj bodova");
		return 0; }
	printf("Prisustvo: ");
	scanf("%f", &p1);
		if(p1<0 || p1>10) {
			printf("Neispravan broj bodova");
		return 0; }
	printf("Zadace: ");
	scanf("%f", &z1);
		if(z1<0 || z1>10) {
			printf("Neispravan broj bodova");
		return 0; }
	printf("Zavrsni ispit: ");
	scanf("%f", &zi1);
		if(zi1<0 || zi1>40) {
			printf("Neispravan broj bodova");
		return 0; }
	
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &b1);
		if(b1<0 || b1>20) {
			printf("Neispravan broj bodova");
		return 0; }
	printf("II parcijalni ispit: ");
	scanf("%f", &b2);
		if(b2<0 || b2>20) {
			printf("Neispravan broj bodova");
		return 0; }
	printf("Prisustvo: ");
	scanf("%f", &p2);
		if(p2<0 || p2>10) {
			printf("Neispravan broj bodova");
		return 0; }
	printf("Zadace: ");
	scanf("%f", &z2);
		if(z2<0 || z2>10) {
			printf("Neispravan broj bodova");
		return 0; }
	printf("Zavrsni ispit: ");
	scanf("%f", &zi2);
		if(zi2<0 || zi2>40) {
			printf("Neispravan broj bodova");
		return 0; }
	
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%f", &m1);
		if(m1<0 || m1>20) {
			printf("Neispravan broj bodova");
		return 0; }
	printf("II parcijalni ispit: ");
	scanf("%f", &m2);
		if(m2<0 || m2>20) {
			printf("Neispravan broj bodova");
		return 0; }
	printf("Prisustvo: ");
	scanf("%f", &p3);
		if(p3<0 || p3>10) {
			printf("Neispravan broj bodova");
		return 0; }
	printf("Zadace: ");
	scanf("%f", &z3);
		if(z3<0 || z3>10) {
			printf("Neispravan broj bodova");
		return 0; }
	printf("Zavrsni ispit: ");
	scanf("%f", &zi3);
		if(zi3<0 || zi3>40) {
			printf("Neispravan broj bodova");
		return 0; }
	
	
	else 
	
	{
		T=t1+t2+p1+z1+zi1+0.01;
		B=b1+b2+p2+z2+zi2+0.01;
		M=m1+m2+p3+z3+zi3+0.01;
		

		if(T>=55) br++;
		if(B>=55) br++;
		if(M>=55) br++;
		
		if(br==0) printf("Nijedan student nije polozio.\n");
		if(br==1) printf("Jedan student je polozio.\n");
		if(br==2) printf("Dva studenta su polozila.\n");
		if(br==3) { 
			
			printf("Sva tri studenta su polozila.\n");
		
	
			if(T>=55 && T<65) 
			T=6;
			else if(T>=65 && T<75)
			T=7;
			else if(T>=75 && T<85)
			T=8;
			else if(T>=85 && T<95)
			T=9;
			else T=10;
			
			if(B>=55 && B<65)
			B=6;
			else if(B>=65 && B<75)
			B=7;
			else if(B>=75 && B<85)
			B=8;
			else if(B>=85 && B<95)
			B=9;
			else B=10;
			
			if(M>=55 && M<65)
			M=6;
			else if(M>=65 && M<75)
			M=7;
			else if(M>=75 && M<85)
			M=8;
			else if(M>=85 && M<95)
			M=9;
			else M=10;
				
			
		if(T==B && T==M && B==M) printf("Sva tri studenta imaju istu ocjenu.\n");
		if(T!=B && T!=M && B!=M) printf("Svaki student ima razlicitu ocjenu.\n");
		if(T==B && T!=M && B!=M) printf("Dva od tri studenta imaju istu ocjenu.\n"); 
		if(T==M && T!=B && M!=B) printf("Dva od tri studenta imaju istu ocjenu.\n"); 
		if(B==M && B!=T)    	 printf("Dva od tri studenta imaju istu ocjenu.\n");
			
		}
		
	}
	
	return 0;
}


