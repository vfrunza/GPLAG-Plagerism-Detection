#include <stdio.h>
#include <math.h>
int main() {
    double T1p,T2p,Tzav,Tzad,Tp,B1p,B2p,Bzav,Bzad,Bp,M1p,M2p,Mzav,Mzad,Mp,T,B,M;
    int ocjT,ocjM,ocjB;
    printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &T1p);
	if (T1p>20 || T1p<0 ){
		printf("Neispravan broj bodova\n");
	    return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &T2p);
	if (T2p>20 || T2p <0){
		printf("Neispravan broj bodova\n");
	    return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &Tp);
	if (Tp>10 || Tp<0 ){
		printf("Neispravan broj bodova\n");
	    return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&Tzad);
	if (Tzad>10 || Tzad<0 ){
		printf("Neispravan broj bodova\n");
	    return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf", &Tzav);
	if (Tzav>40 || Tzav<0 ){
		printf("Neispravan broj bodova\n");
	    return 0;
	}
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &B1p);
	if (B1p>20 || B1p<0 ){
		printf("Neispravan broj bodova\n");
	    return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &B2p);
	if (B2p>20 || B2p<0){
		printf("Neispravan broj bodova\n");
	    return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&Bp);
	if (Bp>10 || Bp<0 ){
		printf("Neispravan broj bodova\n");
	    return 0;
	}
	printf("Zadace: ");
	scanf("%lf", &Bzad);
	if (Bzad>10 || Bzad<0 ){
		printf("Neispravan broj bodova\n");
	    return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&Bzav);
	if (Bzav>40 || Bzav<0 ){
		printf("Neispravan broj bodova\n");
	    return 0;
	}
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &M1p);
	if (M1p>20 || M1p<0){
		printf("Neispravan broj bodova\n");
	    return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf", &M2p);
	if (M2p>20 || M2p<0){
		printf("Neispravan broj bodova\n");
	    return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf", &Mp);
	if (Mp>10 || Mp<0 ){
		printf("Neispravan broj bodova\n");
	    return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&Mzad);
	if (Mzad>10 || Mzad<0 ){
		printf("Neispravan broj bodova\n");
	    return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf" ,&Mzav);
	if (Mzav>40 || Mzav<0 ){
		printf("Neispravan broj bodova\n");
	    return 0;
	}
	
	T=T1p+T2p+Tp+Tzad+Tzav;
	B=B1p+B2p+Bp+Bzad+Bzav;
	M=M1p+M2p+Mp+Mzad+Mzav;
	
	if(T>=55 && T<65) 
	ocjT=6;
	else if (T>=65 && T<75)
	ocjT=7;
	else if(T>=75 && T<85)
	ocjT=8;
	else if(T>=85 && T<92)
	ocjT=9;
	else if (T>=92 && T<=100)
	ocjT=10;
	
	if(B>=55 && B<65) 
	ocjB=6;
	else if (B>=65 && B<75)
	ocjB=7;
	else if(B>=75 && B<85)
	ocjB=8;
	else if(B>=85 && B<92)
	ocjB=9;
	else if (B>=92 && B<=100)
	ocjB=10;
	
	if(M>=55 && M<65) 
	ocjM=6;
	else if (M>=65 && M<75)
	ocjM=7;
	else if(M>=75 && M<85)
	ocjM=8;
	else if(M>=85 && M<92)
	ocjM=9;
	else if (M>=92 && M<=100)
	ocjM=10;
	
	if (((T>=55 && T<65) ||(T>=65 && T<75) || (T>=75 && T<85) || (T>=85 && T<92) || (T>=92 && T<=100)) &&
	((B>=55 && B<65) ||(B>=65 && B<75) || (B>=75 && B<85) || (B>=85 && B<92) || (B>=92 && B<=100)) &&
	((M>=55 && M<65) ||(M>=65 && M<75) || (M>=75 && M<85) || (M>=85 && M<92) || (M>=92 && M<=100))) {
		printf("Sva tri studenta su polozila.\n");
	
		if (((T>=55 && T<65) && (B>=55 && B<65) && (M>=55 && M<65)) ||((T>=65 && T<75) && (B>=65 && B<75) && 
		(M>=65 && M<75)) || ((T>=75 && T<85) && (B>=75 && B<85) && (M>=75 && M<85)) || ((T>=85 && T<92) &&
		(B>=85 && B<92)&&(M>=85 && M<92)) || ((T>=92 && T<=100) &&(B>=92 && B<=100) &&(M>=92 && M<=100))) {
		printf("Sva tri studenta imaju istu ocjenu.\n");
	}
	 
		
	else if(ocjT!=ocjM  && ocjT!=ocjB && ocjB!=ocjM ) {
		printf("Svaki student ima razlicitu ocjenu.\n");
		
	} 
	else printf("Dva od tri studenta imaju istu ocjenu.\n"); 
	}
	else if ((((T>=55 && T<65) ||(T>=65 && T<75) || (T>=75 && T<85) || (T>=85 && T<92) || (T>=92 && T<=100)) &&
	((B>=55 && B<65) ||(B>=65 && B<75) || (B>=75 && B<85) || (B>=85 && B<92) || (B>=92 && B<=100))) ||
	(((B>=55 && B<65) ||(B>=65 && B<75) || (B>=75 && B<85) || (B>=85 && B<92) || (B>=92 && B<=100)) &&
	((M>=55 && M<65) ||(M>=65 && M<75) || (M>=75 && M<85) || (M>=85 && M<92) || (M>=92 && M<=100))) ||
	(((M>=55 && M<65) ||(M>=65 && M<75) || (M>=75 && M<85) || (M>=85 && M<92) || (M>=92 && M<=100)) &&
	((T>=55 && T<65) ||(T>=65 && T<75) || (T>=75 && T<85) || (T>=85 && T<92) || (T>=92 && T<=100)))) {
		printf("Dva studenta su polozila.\n");
	}
    else if (((T>=55 && T<65) ||(T>=65 && T<75) || (T>=75 && T<85) || (T>=85 && T<92) || (T>=92 && T<=100)) ||
	((B>=55 && B<65) ||(B>=65 && B<75) || (B>=75 && B<85) || (B>=85 && B<92) || (B>=92 && B<=100)) ||
	((M>=55 && M<65) ||(M>=65 && M<75) || (M>=75 && M<85) || (M>=85 && T<92) || (M>=92 && T<=100))) {
	    printf("Jedan student je polozio.\n");
	}
	else if (T<55 && B<55 && M<55) {
	    printf("Nijedan student nije polozio.\n");
	}
	
	
		return 0;
}
