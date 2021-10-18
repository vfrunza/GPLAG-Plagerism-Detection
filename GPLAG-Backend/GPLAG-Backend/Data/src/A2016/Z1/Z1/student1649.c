#include <stdio.h>
#include <math.h>
#define EPSILON 0.0001
int main(){
   float PIT, PIIT, DZT, PT, ZIT, PIB, PIIB, DZB, PB, ZIB, PIM, PIIM, DZM, PM, ZIM, BT, BB, BM;
   int br=0, OT, OB, OM;
   printf("Unesite bodove za Tarika:");
    printf("\nI parcijalni ispit: ");
    scanf("%f", &PIT);
    if (PIT<0 || PIT>20){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("II parcijalni ispit: ");
    scanf("%f", &PIIT);
    if (PIIT<0 || PIIT>20){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Prisustvo: ");
    scanf("%f", &PT);
    if (PT<0 || PT>10){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zadace: ");
    scanf("%f", &DZT);
    if (DZT<0 || DZT>10){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zavrsni ispit: ");
    scanf("%f", &ZIT);
    if (ZIT<0 || ZIT>40){
        printf("Neispravan broj bodova");
        return 0;
    }
   printf("Unesite bodove za Bojana:");    
   printf("\nI parcijalni ispit: ");
    scanf("%f", &PIB);
    if (PIB<0 || PIB>20){
        printf("Neispravan broj bodova");
        return 0;
    }
   printf("II parcijalni ispit: ");
    scanf("%f", &PIIB);
    if (PIIB<0 || PIIB>20){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Prisustvo: ");
    scanf("%f", &PB);
    if (PB<0 || PB>10){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zadace: ");
    scanf("%f", &DZB);
    if (DZB<0 || DZB>10){
       printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zavrsni ispit: ");
    scanf("%f", &ZIB);
    if (ZIB<0 || ZIB>40){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Unesite bodove za Mirzu:");
    printf("\nI parcijalni ispit: ");
    scanf("%f", &PIM);
    if (PIM<0 || PIM>20){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("II parcijalni ispit: ");
    scanf("%f", &PIIM);
    if (PIIM<0 || PIIM>20){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Prisustvo: ");
    scanf("%f", &PM);
    if (PM<0 || PM>10){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zadace: ");
    scanf("%f", &DZM);
    if (DZM<0 || DZM>10){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zavrsni ispit: ");
    scanf("%f", &ZIM);
    if (ZIM<0 || ZIM>40){
        printf("Neispravan broj bodova");
        return 0;
    }
    BT=PIT+PIIT+DZT+PT+ZIT;
    BB=PIB+PIIB+DZB+PB+ZIB;
    BM=PIM+PIIM+DZM+PM+ZIM;
    if ((BT>55 || fabs(BT-55)<EPSILON) && BT<65) OT=6;
        else if ((BT>65 || fabs(BT-65)<EPSILON) && BT<75) OT=7;
            else if ((BT>75 || fabs(BT-75)<EPSILON) && BT<85) OT=8;
                else if ((BT>85 || fabs(BT-85)<EPSILON) && BT<92) OT=9;
                    else if ((BT>92 || fabs(BT-92)<EPSILON) && BT<=100) OT=10;
                        else if (BT<55) OT=5;
    if ((BB>55 || fabs(BB-55)<EPSILON) && BB<65) OB=6;
        else if ((BB>65 || fabs(BB-65)<EPSILON) && BB<75) OB=7;
            else if ((BB>75 || fabs(BB-75)<EPSILON) && BB<85) OB=8;
                else if ((BB>85 || fabs(BB-85)<EPSILON) && BB<92) OB=9;
                    else if ((BB>92 || fabs(BB-92)<EPSILON) && BB<=100) OB=10;
                        else if(BB<55) OB=5;
    if ((BM>55 || fabs(BM-55)<EPSILON) && BM<65) OM=6;
        else if ((BM>65 || fabs(BM-65)<EPSILON) && BM<75) OM=7;
            else if ((BM>75 || fabs(BM-75)<EPSILON) && BM<85) OM=8;
                else if ((BM>85 || fabs(BM-85)<EPSILON) && BM<92) OM=9;
                    else if ((BM>92 || fabs(BM-92)<EPSILON) && BM<=100) OM=10;
                        else if(BM<55) OM=5;
    if(OM!=5) br++;
    if(OB!=5) br++;
    if(OT!=5) br++;
    if(br==0) printf("Nijedan student nije polozio.");
        else if(br==1) printf("Jedan student je polozio.");
            else if(br==2) printf("Dva studenta su polozila."); 
                else if(br==3){
                    printf("Sva tri studenta su polozila.");
                    if(OT!=OM && OB!=OM && OT!=OB) printf("\nSvaki student ima razlicitu ocjenu.");
                        else if(OM==OT && OM==OB) printf("\nSva tri studenta imaju istu ocjenu.");
                            else printf("\nDva od tri studenta imaju istu ocjenu.");
                    }
    return 0;
}