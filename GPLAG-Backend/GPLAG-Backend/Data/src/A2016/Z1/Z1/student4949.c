#include <stdio.h>
#include <math.h>
#define epsilon 0.00000001
int main() {
	double a,b,c,d,e,f,g,h,i,j,k,l,m,n,o;
	double S1,S2,S3;
		printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &a);
	    if(a<0 || a>20) printf("Neispravan broj bodova");
	    else{
	printf("II parcijalni ispit: ");
	scanf("%lf", &b);
	    if(b<0 || b>20) printf("Neispravan broj bodova");
	    else{
	printf("Prisustvo: ");
	scanf("%lf", &c);
	    if(c<0 || c>10) printf("Neispravan broj bodova");
	    else{
	printf("Zadace: ");
	scanf("%lf", &d);
	    if(d<0 || d>10) printf("Neispravan broj bodova");
	    else{
	printf("Zavrsni ispit: ");
	scanf("%lf", &e);
    	if(e<0 || e>40) printf("Neispravan broj bodova");
	    else{
		printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &f);
	    if(f<0 || f>20) printf("Neispravan broj bodova");
	    else{
	printf("II parcijalni ispit: ");
	scanf("%lf", &g);
	    if(g<0 || g>20) printf("Neispravan broj bodova");
	    else{
	printf("Prisustvo: ");
	scanf("%lf", &h);
		if(h<0 || h>10) printf("Neispravan broj bodova");
	    else{
	printf("Zadace: ");
	scanf("%lf", &i);
		if(i<0 || i>10) printf("Neispravan broj bodova");
	    else{
	printf("Zavrsni ispit: ");
	scanf("%lf", &j);
		if(j<0 || j>40) printf("Neispravan broj bodova");
	    else{
		printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &k);
	    if(k<0 || k>20) printf("Neispravan broj bodova");
	    else{
	printf("II parcijalni ispit: ");
	scanf("%lf", &l);
		if(l<0 || l>20) printf("Neispravan broj bodova");
	    else{
	printf("Prisustvo: ");
	scanf("%lf", &m);
		if(m<0 || m>10) printf("Neispravan broj bodova");
	    else{
	printf("Zadace: ");
	scanf("%lf", &n);
		if(n<0 || n>10) printf("Neispravan broj bodova");
	    else{
	printf("Zavrsni ispit: ");
	scanf("%lf", &o);
	   if(o<0 || o>40) printf("Neispravan broj bodova");
	    

	if(a>=0 && a<=20 && n>=0 && n<=10 && m>=0 && m<=10 && l>=0 && l<=20 && k>=0 && k<=20 && j>=0 && j<=40 && i>=0 && i<=10 && h>=0 && h<=10 && g>=0 && g<=20 && f>=0 && f<=20 && e>=0 && e<=40 && d>=0 && d<=10 && c>=0 && c<=10 && b>=0 && b<=20 && o>=0 && o<=40 ) {
		S1=a+b+c+d+e;
		S2=f+g+h+i+j;
		S3=k+l+m+n+o;
		if(S1<55) S1=5;
	    else if(S1>=55 && S1<65) S1=6;
		else if(S1>=65 && S1<75) S1=7;
		else if(S1>=75 && S1<85) S1=8;
		else if(S1>=85 && S1<92) S1=9;
		else if(S1>=92 && S1<=100) S1=10;
		
		if(S2<55) S2=5;
	    else if(S2>=55 && S2<65) S2=6;
		else if(S2>=65 && S2<75) S2=7;
		else if(S2>=75 && S2<85) S2=8;
		else if(S2>=85 && S2<92) S2=9;
		else if(S2>=92 && S2<=100) S2=10;
		
		if(S3<55) S3=5;
	    else if(S3>=55 && S3<65) S3=6;
		else if(S3>=65 && S3<75) S3=7;
		else if(S3>=75 && S3<85) S3=8;
		else if(S3>=85 && S3<92) S3=9;
		else if(S3>=92 && S3<=100) S3=10;
		
		if(fabs(S1-5)<epsilon && fabs(S2-5)<epsilon && fabs(S3-5)<epsilon) printf("Nijedan student nije polozio.");
		else if((S1>5 && fabs(S2-5)<epsilon && fabs(S3-5)<epsilon) || (fabs(S1-5)<epsilon && S2>5 && fabs(S3-5)<epsilon) || (fabs(S1-5)<epsilon && fabs(S2-5)<epsilon && S3>5)) printf("Jedan student je polozio.");
		else if((S1>5 && S2>5 && fabs(S3-5)<epsilon) || (fabs(S1-5)<epsilon && S2>5 && S3>5) || (S1>5 && fabs(S2-5)<epsilon && S3>5)) printf("Dva studenta su polozila.");
		else if(S1>5 && S2>5 && S3>5) printf("Sva tri studenta su polozila.");
		
		if(S1>5 && S2>5 && S3>5) {
			if(fabs(S1-S2)<epsilon && fabs(S1-S3)<epsilon && fabs(S2-S3)<epsilon) printf("\nSva tri studenta imaju istu ocjenu.");
			else if(fabs(S1-S2)<epsilon || fabs(S1-S3)<epsilon || fabs(S2-S3)<epsilon) printf("\nDva od tri studenta imaju istu ocjenu.");
			else if(fabs(S1-S2)>epsilon && fabs(S1-S3)>epsilon && fabs(S2-S3)>epsilon) printf("\nSvaki student ima razlicitu ocjenu.");
			
			
		}
		
	
		
		
		
		

	}
	    }}}}}}}}}}}}}}
	return 0;}

