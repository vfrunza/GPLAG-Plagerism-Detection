#include <stdio.h>
#include <math.h>
#define p1 6.80
#define p2 8.00
#define p3 5.30
#define h1 3.30
#define h2 3.00
#define h3 5.00
#define c1 5.00
#define c2 3.90
#define c3 6.00



int main()
{
    int broj_p=0,broj_c=0,broj_h=0;
    double cijena_rest=0,cijena_fast=0,cijena_bistro=0;
    char tarik, bojan, mirza, novi_red;
    double hamburger=3.3,pizza=6.8,cevap=5;

    printf("Unesite jelo za Tarika: ");
    scanf("%c", &tarik);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Bojana: ");
    scanf("%c", &bojan);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c", &mirza);
    scanf("%c", &novi_red);

    if(tarik=='P') broj_p++;
    else if(tarik=='C') broj_c++;
    else if(tarik=='H') broj_h++;

    if(bojan=='P') broj_p++;
    else if(bojan=='C') broj_c++;
    else if(bojan=='H') broj_h++;

    if(mirza=='P') broj_p++;
    else if(mirza=='C') broj_c++;
    else if(mirza=='H') broj_h++;

    cijena_rest = broj_p*p1 + broj_h*h1 + broj_c*c1;
    cijena_fast = broj_p*p2 + broj_h*h2 + broj_c*c2;
    cijena_bistro = broj_p*p3 + broj_h*h3 + broj_c*c3;

    if(cijena_rest<cijena_fast && cijena_rest<cijena_bistro) {
        printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).",cijena_rest);
    } else {
        if(cijena_fast<cijena_bistro) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).",cijena_fast);
        else printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).",cijena_bistro);
        
        if(broj_c>broj_h && broj_c>broj_p) cevap*=0.9;
        else if(broj_h>broj_p && broj_h>broj_c) hamburger*=0.9;
        else if(broj_p>broj_h && broj_p>broj_c) pizza*=0.9;
        else pizza*=0.9;
        cijena_rest = broj_p*pizza + broj_h*hamburger + broj_c*cevap;
        if(cijena_rest<cijena_fast && cijena_rest<cijena_bistro) {
            printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).",cijena_rest);
        }
    }


    return 0;
}