#include <stdio.h>
int main () {
    double IpT, IIpT, PT, ZT, ZiT, Tarik, 
           IpB, IIpB, PB, ZB, ZiB, Bojan, 
           IpM, IIpM, PM, ZM, ZiM, Mirza;
    Tarik=0;
    Bojan=0;
    Mirza=0;
    
    printf ("Unesite bodove za Tarika: \n");
    printf ("I parcijalni ispit: ");
    scanf ("%lf", &IpT);
    if (IpT<0 || IpT>20) {
        printf ("Neispravan broj bodova. \n");
        return 0;}
    printf ("II parcijalni ispit: ");
    scanf ("%lf", &IIpT);
    if (IIpT<0 || IIpT>20) {
        printf ("Neispravan broj bodova. \n");
        return 0;}
    printf ("Prisustvo: ");
    scanf ("%lf", &PT);
    if (PT<0 || PT>10) {
        printf ("Neispravan broj bodova. \n");
        return 0; }
    printf ("Zadace: ");
    scanf ("%lf", &ZT);
    if (ZT<0 || ZT>10) {
        printf ("Neispravan broj bodova. \n");
        return 0; }
    printf ("Zavrsni ispit: ");
    scanf ("%lf", &ZiT);
    if (ZiT<0 || ZiT>40) {
        printf ("Neispravan broj bodova. \n");
        return 0; }
    
    
    printf ("Unesite bodove za Bojana: \n");
    printf ("I parcijalni ispit: ");
    scanf ("%lf", &IpB);
    if (IpB<0 || IpB>20) {
        printf ("Neispravan broj bodova \n");
        return 0; }
    printf ("II parcijalni ispit: ");
    scanf ("%lf", &IIpB);
    if (IIpB<0 || IIpB>20) {
        printf ("Neispravan broj bodova. \n");
        return 0; }
    printf ("Prisustvo: ");
    scanf ("%lf", &PB);
    if (PB<0 || PB>10) {
        printf ("Neispravan broj bodova. \n");
        return 0; }
    printf ("Zadace: ");
    scanf ("%lf", &ZB);
    if (ZB<0 || ZB>10) {
        printf ("Neispravan broj bodova. \n");
        return 0;}
    printf ("Zavrsni ispit: ");
    scanf ("%lf", &ZiB);
    if (ZiB<0 && ZiB>40) {
        printf ("Neispravan broj bodova. \n");
        return 0;}
        

    printf ("Unesite bodove za Mirzu: \n");
    printf ("I parcijalni ispit: ");
    scanf ("%lf", &IpM);
    if (IpM<0 || IpM>20) {
        printf ("Neispravan broj bodova. \n");
        return 0; }
    printf ("II parcijalni ispit: ");
    scanf ("%lf", &IIpM);
    if (IIpM<0 || IIpM>20) {
        printf ("Neispravan broj bodova. \n");
        return 0; }
    printf ("Prisustvo: ");
    scanf ("%lf", &PM);
    if (PM<0 || PM>10) {
        printf ("Neispravan broj bodova \n");
        return 0; }
    printf ("Zadace: ");
    scanf ("%lf", &ZM);
    if (ZM<0 || ZM>10) {
        printf ("Neispravan broj bodova. \n");
        return 0; }
    printf ("Zavrsni ispit: ");
    scanf ("%lf", &ZiM);
    if (ZiM<0 || ZiM>40) {
        printf ("Neispravan broj bodova. \n");
        return 0; }

    Tarik=IpT+IIpT+PT+ZT+ZiT;
    Bojan=IpB+IIpB+PB+ZB+ZiB;
    Mirza=IpM+IIpM+PM+ZM+ZiM;
    
     if (Tarik<55) Tarik=5;
    else if (Tarik>=55 && Tarik<65) Tarik=6;
    else if (Tarik>=65 && Tarik<75) Tarik=7;
    else if (Tarik>=75 && Tarik<85) Tarik=8;
    else if (Tarik>=85 && Tarik<92) Tarik=9;
    else if (Tarik>=92 && Tarik<=100) Tarik=10;
        
    if (Bojan<55) Bojan=5;
    else if (Bojan>=55 && Bojan<65) Bojan=6;
    else if (Bojan>=65 && Bojan<75) Bojan=7;
    else if (Bojan>=75 && Bojan<85) Bojan=8;
    else if (Bojan>=85 && Bojan<92) Bojan=9;
    else if (Bojan>=92 && Bojan<=100) Bojan=10;
        
    if (Mirza<55) Mirza=5;
    else if (Mirza>=55 && Mirza<65) Mirza=6;
    else if (Mirza>=65 && Mirza<75) Mirza=7;
    else if (Mirza>=75 && Mirza<85) Mirza=8;
    else if (Mirza>=85 && Mirza<92) Mirza=9;
    else if (Mirza>=92 && Mirza<=100) Mirza=10;
        
    
    if (Tarik==5 && Bojan==5 && Mirza==5) {
        printf ("Nijedan student nije polozio. \n"); 
        return 0; }

    if ((Tarik==5) && (Bojan==5) && (Mirza>5)) {
        printf ("Jedan student je polozio. \n"); 
        return 0;}
    if ((Tarik==5) && (Bojan>5) && (Mirza==5)) {
        printf ("Jedan student je polozio. \n"); 
        return 0; }
    if ((Tarik>5) && (Bojan==5) && (Mirza==5)) {
        printf ("Jedan student je polozio. \n"); 
        return 0;}


    if ((Tarik>5) && (Bojan>5) && (Mirza==5)) {
        printf ("Dva studenta su polozila. \n");
    return 0;} 
    if ((Tarik>5) && (Bojan==5) && (Mirza>5)) {
        printf ("Dva studenta su polozila. \n");
    return 0;}
    if ((Tarik==5) && (Bojan>5) && (Mirza>5)) {
        printf ("Dva studenta su polozila. \n");
        return 0; }
        
    
    if (Tarik>5 && Bojan>5 && Mirza>5) {
        printf ("Sva tri studenta su polozila. \n"); 
    if ((Tarik==Bojan) && (Tarik==Mirza) && (Mirza==Bojan)) {
        printf ("Sva tri studenta imaju istu ocjenu. \n"); 
        return 0; }
    if ((Tarik!=Bojan) && (Tarik!=Mirza) && (Mirza!=Bojan)) {
        printf ("Svaki student ima razlicitu ocjenu. \n"); 
        return 0; } 
    }
        
        
    if ((Tarik==Bojan) && (Bojan!=Mirza) && (Tarik!=Mirza)) {
        printf ("Dva od tri studenta imaju istu ocjenu. \n"); 
        return 0; }
    if ((Tarik!=Bojan) && (Bojan==Mirza) && (Tarik!=Mirza)) {
        printf ("Dva od tri studenta imaju istu ocjenu. \n");
        return 0;}
    if ((Tarik==Mirza) && (Tarik!=Bojan) && (Bojan!=Mirza)) {
        printf ("Dva od tri studenta imaju istu ocjenu. \n");
        return 0; }
    
    return 0;
}


    
    

    
        
    

	