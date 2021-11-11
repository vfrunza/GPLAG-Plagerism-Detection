#include <stdio.h>
#include <math.h>
#define PKK 6.80
#define HKK 3.30
#define CKK 5.00
#define PT 8.00
#define HT 3.00
#define CT 3.90
#define PL 5.30 
#define HL 5.00
#define CL 6.00
#define epsilon 0.0000001
int main() {
    int pizza=0, hamburger=0, cevapi=0;
    char tarik, bojan, mirza, novi_red;
    float konj, trovac, lorelei, min;
    printf("Unesite jelo za Tarika: ");
    scanf("%c", &tarik);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Bojana: ");
    scanf("%c", &bojan);
    scanf("%c", &novi_red);
    printf("Unesite jelo za Mirzu: ");
    scanf("%c", &mirza);
    scanf("%c", &novi_red);
    if(tarik=='P') pizza++;
    else if(tarik=='H') hamburger++;
    else if(tarik=='C') cevapi++;
    if(bojan=='P') pizza++;
    else if(bojan=='H') hamburger++;
    else if(bojan=='C') cevapi++;
    if(mirza=='P') pizza++;
    else if(mirza=='H') hamburger++;
    else if(mirza=='C') cevapi++;
    konj=pizza*PKK+hamburger*HKK+cevapi*CKK;
    trovac=pizza*PT+hamburger*HT+cevapi*CT;
    lorelei=pizza*PL+hamburger*HL+cevapi*CL;
    min=konj;
    if(trovac<min) min=trovac;
    if(lorelei<min) min=lorelei;
    if(fabs(min-konj)<epsilon) printf("Najjeftiniji je Restoran \"Kod konja i konjusara\" (%.2f KM).", min);
    else if(fabs(min-trovac)<epsilon) printf("Najjeftiniji je Fast-food \"Trovac\" (%.2f KM).", min);
    else if(fabs(min-lorelei)<epsilon) printf("Najjeftiniji je Bistro \"Lorelei\" (%.2f KM).", min);
	if(fabs(min-konj)>epsilon){
        if(pizza!=0) konj=konj-(pizza*(PKK*10/100));
        else if(cevapi!=0) konj=konj-(cevapi*(CKK*10/100));
        else if(hamburger!=0) konj=konj-(hamburger*(HKK*10/100));
        if(konj<min) printf("\nSa popustom bi Restoran bio jeftiniji (%.2f KM).", konj);
	}
	return 0;
}
