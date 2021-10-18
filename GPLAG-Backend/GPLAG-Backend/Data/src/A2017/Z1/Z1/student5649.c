#include <stdio.h>

int main() {
	double IPT, IIPT, PT, ZT, ZIT, IPB, IIPB, PB, ZB, ZIB, IPM, IIPM, PM, ZM, ZIM, T, B, M;
	printf("Unesite bodove za Tarika:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &IPT);
	if(IPT<0 || IPT>20) {
	printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIPT);
	if(IIPT<0 || IIPT>20) {
	printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf", &PT);
	if(PT<0 || PT>10) {
	printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf", &ZT);
	if(ZT<0 || ZT>10) {
	printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIT);
	if(ZIT<0 || ZIT>40) {
	printf("Neispravan broj bodova"); return 0;}
	
	printf("Unesite bodove za Bojana:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &IPB);
	if(IPB<0 || IPB>20) {
	printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIPB);
	if(IIPB<0 || IIPB>20) {
	printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf", &PB);
	if(PB<0 || PB>10) {
	printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf", &ZB);
	if(ZB<0 || ZB>10) {
	printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIB);
	if(ZIB<0 || ZIB>40) {
	printf("Neispravan broj bodova"); return 0;}
	
	printf("Unesite bodove za Mirzu:");
	printf("\nI parcijalni ispit: ");
	scanf("%lf", &IPM);
	if(IPM<0 || IPM>20) {
	printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &IIPM);
	if(IIPM<0 || IIPM>20) {
	printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf", &PM);
	if(PM<0 || PM>10) {
	printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf", &ZM);
	if(ZM<0 || ZM>10) {
	printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &ZIM);
	if(ZIM<0 || ZIM>40) {
	printf("Neispravan broj bodova"); return 0;}
	
	T=IPT+IIPT+PT+ZT+ZIT;
	B=IPB+IIPB+PB+ZB+ZIB;
	M=IPM+IIPM+PM+ZM+ZIM;
	
	if(T<55 && B<55 && M<55)
    printf("Nijedan student nije polozio.");
    else if((T<55 && B>=55 && M<55) || (T>=55 && B<55 && M<55) || (T<55 && B<55 && M>=55))
    printf("Jedan student je polozio.");
    else if((T>=55 && B>=55 && M<55) || (T<55 && B>=55 && M>=55) || (T>=55 && B<55 && M>=55))
    printf("Dva studenta su polozila.");
    else if(T>=55 && B>=55 && M>=55)
    printf("Sva tri studenta su polozila.\n");
    
    
    
    
    if((T>=55 && B>=55 && M>=55) && (((T>=55 && T<65) && (B>=55 && B<65) && (M>=55 && M<65)) || ((T>=65 && T<75) && (B>=65 && B<75) && (M>=65 && M<75)) || ((T>=75 && T<85) && (B>=75 && B<85) && (M>=75 && M<85)) || ((T>=85 && T<95) && (B>=85 && B<95) && (M>=85 && M<95)) || ((T>=95 && T<=100) && (B>=95 && B<=100) && (M>=95 && M<=100))))
    printf("Sva tri studenta imaju istu ocjenu.");
    else if((T>=55 && B>=55 && M>=55) && (((T>=55 && T<65) && (B>=55 && B<65) && (M>=65)) || ((T>=65 && T<75) && (B>=65 && B<75) && (M>=75 || M<65)) || ((T>=75 && T<85) && (B>=75 && B<85) && (M>=85 || M<75)) || ((T>=85 && T<95) && (B>=85 && B<95) && (M>=95 && M<85)) || ((T>=95 && T<=100) && (B>=95 && B<=100) && (M<95)) || ((T>=65) && (B>=55 && B<65) && (M>=55 && M<65)) || ((T<65 || T>=75) && (B>=65 && B<75) && (M>=65 && M<75)) || ((T<75 || T>=85) && (B>=75 && B<85) && (M>=75 && M<85)) || ((B<85 || B>=95) && (B>=85 && B<95) && (M>=85 && M<95)) || ((T<95) && (B>=95 && B<=100) && (M>=95 && M<=100)) || ((T>=55 && T<65) && (B>=65) && (M>=55 && M<65)) || ((T>=65 && T<75) && (B<75 || B>=75) && (M>=65 && M<75)) || ((T>=75 && T<85) && (B<75 || B>=85) && (M>=75 && M<85)) || ((T>=85 && T<95) && (B<85 || B>=95) && (M>=85 && M<95)) || ((T>=95 && T<=100) && (B<95) && (M>=95 && M<=100))))
    printf("Dva od tri studenta imaju istu ocjenu.");
    else if((T>=55 && B>=55 && M>=55) && ((T>=55 && T<65) && (B>=65 && B<75) && (M>=75)))
    printf("Svaki student ima razlicitu ocjenu.");
    else if((T>=55 && B>=55 && M>=55) && ((T>=55 && T<65) && (B>=75 && B<85) && ((M>=65 && M<75) || (M>=85))))
    printf("Svaki student ima razlicitu ocjenu.");
    else if((T>=55 && B>=55 && M>=55) && ((T>=55 && T<65) && (B>=85 && B<95) && ((M>=65 && M<85) || (M>=95))))
    printf("Svaki student ima razlicitu ocjenu.");
    else if((T>=55 && B>=55 && M>=55) && ((T>=55 && T<65) && (B>=95) && (M>=65 && M<95)))
    printf("Svaki student ima razlicitu ocjenu.");
    else if((T>=55 && B>=55 && M>=55) && ((T>=65 && T<75) && (B>=55 && B<65) && (M>=75)))
    printf("Svaki student ima razlicitu ocjenu.");
    else if((T>=55 && B>=55 && M>=55) && ((T>=65 && T<75) && (B>=75 && B<85) && ((M>=55 && M<65) || (M>=85))))
    printf("Svaki student ima razlicitu ocjenu.");
    else if((T>=55 && B>=55 && M>=55) && ((T>=65 && T<75) && (B>=85 && B<95) && ((M>=55 && M<65) || (M>=75 && M<85) || (M>=95))))
    printf("Svaki student ima razlicitu ocjenu.");
    else if((T>=55 && B>=55 && M>=55) && ((T>=65 && T<75) && (B>=95) && ((M>=55 && M<65) || (M>=75 && M<95))))
    printf("Svaki student ima razlicitu ocjenu.");
    else if((T>=55 && B>=55 && M>=55) && ((T>=75 && T<85) && (B>=55 && B<65) && ((M>=65 && M<75) || (M>=85))))
    printf("Svaki student ima razlicitu ocjenu.");
    else if((T>=55 && B>=55 && M>=55) && ((T>=75 && T<85) && (B>=65 && B<75) && ((M>=55 && M<65) || (M>=85))))
    printf("Svaki student ima razlicitu ocjenu.");
    else if((T>=55 && B>=55 && M>=55) && ((T>=75 && T<85) && (B>=85 && B<95) && ((M>=55 && M<75) || (M>=95))))
    printf("Svaki student ima razlicitu ocjenu.");
    else if((T>=55 && B>=55 && M>=55) && ((T>=75 && T<85) && (B>=95) && ((M>=55 && M<65) || (M>=85 && M<95))))
    printf("Svaki student ima razlicitu ocjenu.");
    else if((T>=55 && B>=55 && M>=55) && ((T>=85 && T<95) && (B>=55 && B<65) && ((M>=65 && M<85) || (M>=95))))
    printf("Svaki student ima razlicitu ocjenu.");
    else if((T>=55 && B>=55 && M>=55) && ((T>=85 && T<95) && (B>=65 && B<75) && ((M>=55 && M<65) || (M>=75 && M<85) || (M>=95))))
    printf("Svaki student ima razlicitu ocjenu.");
    else if((T>=55 && B>=55 && M>=55) && ((T>=85 && T<95) && (B>=75 && B<85) && ((M>=55 && M<75) || (M>=95))))
    printf("Svaki student ima razlicitu ocjenu.");
    else if((T>=55 && B>=55 && M>=55) && ((T>=85 && T<95) && (B>=95) && (M>=55 && M<85)))
    printf("Svaki student ima razlicitu ocjenu.");
    else if((T>=55 && B>=55 && M>=55) && ((T>=95) && (B>=55 && B<65) && (M>=65 && M<95)))
    printf("Svaki student ima razlicitu ocjenu.");
    else if((T>=55 && B>=55 && M>=55) && ((T>=95) && (B>=65 && B<75) && ((M>=55 && M<65) || (M>=75 && M<95))))
    printf("Svaki student ima razlicitu ocjenu.");
    else if((T>=55 && B>=55 && M>=55) && ((T>=95) && (B>=75 && B<85) && ((M>=55 && M<75) || (M>=85 && M<95))))
    printf("Svaki student ima razlicitu ocjenu.");
    else if((T>=55 && B>=55 && M>=55) && ((T>=95) && (B>=85 && B<95) && (M>=55 && M<85)))
    printf("Svaki student ima razlicitu ocjenu.");
    
    
    
    
    
    
	return 0;
}
