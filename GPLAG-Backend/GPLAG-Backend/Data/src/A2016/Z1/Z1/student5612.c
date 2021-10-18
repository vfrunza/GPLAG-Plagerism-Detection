#include <stdio.h>

int main() {
    double T_P1,T_P2,T_PP,T_Z,T_ZI;
    double B_P1,B_P2,B_PP,B_Z,B_ZI;
    double M_P1,M_P2,M_PP,M_Z,M_ZI;
    double T_SB,B_SB,M_SB;
    double ocjena1,ocjena2,ocjena3;
    /*Bodovi za Tarika: */
    printf("Unesite bodove za Tarika:\n");
    printf("I parcijalni ispit: ");
    scanf("%lf", &T_P1);
    if(T_P1 < 0 || T_P1 > 20){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("II parcijalni ispit: ");
    scanf("%lf", &T_P2);
    if(T_P2 < 0 || T_P2 > 20){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Prisustvo: ");
    scanf("%lf", &T_PP);
    if(T_PP < 0 || T_PP > 10){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zadace: ");
    scanf("%lf", &T_Z);
    if(T_Z < 0 ||T_Z > 10){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zavrsni ispit: ");
    scanf("%lf", &T_ZI);
    if(T_ZI < 0 || T_ZI > 40){
        printf("Neispravan broj bodova");
        return 1;
    }
    T_SB = T_P1 + T_P2 + T_PP + T_Z + T_ZI;
    if(T_SB < 0 || T_SB > 100){
        return 0;
    }
    /*Ispitivanje ocjena za Tarika*/
    if(T_SB < 55) ocjena1 = 5;
    else if (T_SB >= 55 && T_SB < 65) ocjena1 = 6;
    else if (T_SB >= 65 && T_SB < 75) ocjena1 = 7;
    else if (T_SB >= 75 && T_SB < 85) ocjena1 = 8;
    else if (T_SB >= 85 && T_SB < 92) ocjena1 = 9;
    else ocjena1 = 10;
    /*Bodovi za Bojana: */
    printf("Unesite bodove za Bojana:\n");
    printf("I parcijalni ispit: ");
    scanf("%lf", &B_P1);
    if(B_P1 < 0 || B_P1 > 20){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("II parcijalni ispit: ");
    scanf("%lf", &B_P2);
    if(B_P2 < 0 || B_P2 > 20){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Prisustvo: ");
    scanf("%lf", &B_PP);
    if(B_PP < 0 || B_PP > 10){
        printf("Neispravan broj bodova");
        return 1;
    }
    printf("Zadace: ");
    scanf("%lf", &B_Z);
    if(B_Z < 0 || B_Z > 10){
        printf("Neispravan broj bodova");
        return 1;
    }
    printf("Zavrsni ispit: ");
    scanf("%lf", &B_ZI);
    if(B_ZI < 0 || B_ZI > 40){
        printf("Neispravan broj bodova");
        return 0;
    }
    B_SB = B_P1 + B_P2 + B_PP + B_Z + B_ZI;
    if(B_SB < 0 || B_SB > 100){
        return 0;
    }
    /*Ispitivanje ocjena za Bojana*/
    if(B_SB < 55) ocjena1 = 5;
    else if(B_SB >= 55 && B_SB < 65) ocjena2 = 6;
    else if(B_SB >= 65 && B_SB < 75) ocjena2 = 7;
    else if(B_SB >= 75 && B_SB < 85) ocjena2 = 8;
    else if(B_SB >= 85 && B_SB < 92) ocjena2 = 9;
    else ocjena1 = 10;
    /*Bodovi za Mirzu: */
    printf("Unesite bodove za Mirzu:\n");
    printf("I parcijalni ispit: ");
    scanf("%lf", &M_P1);
    if(M_P1 < 0 || M_P1 > 20){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("II parcijalni ispit: ");
    scanf("%lf", &M_P2);
    if(M_P2 < 0 || M_P2 > 20){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Prisustvo: ");
    scanf("%lf", &M_PP);
    if(M_PP < 0 || M_PP > 10){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zadace: ");
    scanf("%lf", &M_Z);
    if(M_Z < 0 || M_Z > 10){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zavrsni ispit: ");
    scanf("%lf", &M_ZI);
    if(M_ZI < 0 || M_ZI > 40){
        printf("Neispravan broj bodova");
        return 0;
    }
    M_SB = M_P1 + M_P2 + M_PP + M_Z + M_ZI;
    if(M_SB < 0 || M_SB > 100){
        return 0;
    }
    /*Ispitivanje ocjena za Mirzu*/
    if(M_SB < 55) ocjena3 = 5;
    else if(M_SB >= 55 && M_SB < 65) ocjena3 = 6;
    else if(M_SB >= 65 && M_SB < 75) ocjena3 = 7;
    else if(M_SB >= 75 && M_SB < 85) ocjena3 = 8;
    else if(M_SB >= 85 && M_SB < 92) ocjena3 = 9;
    else ocjena3 = 10;
    /*Ispitivanje zbira bodova u odnosu na zadani interval */
    if(T_SB < 55 && B_SB < 55 && M_SB < 55){
        printf("Nijedan student nije polozio.");
        return 0;
        
    }
    if((T_SB >= 55 && B_SB < 55 && M_SB < 55) || (T_SB < 55 && B_SB >= 55 && M_SB < 55) || (T_SB < 55 && B_SB < 55 && M_SB >= 55)){
        printf("Jedan student je polozio.");
        return 0;
        
    }
    if((T_SB >= 55 && B_SB >= 55 && M_SB < 55) || (T_SB >= 55 && B_SB < 55 && M_SB >= 55) || (T_SB < 55 && B_SB >= 55 && M_SB >= 55)){
        printf("Dva studenta su polozila.");
        return 0;
        
    }
    if(T_SB >= 55 && B_SB >= 55 && M_SB >= 55 ){
        printf("Sva tri studenta su polozila.\n");
    }
    
    if(ocjena1 == ocjena2 && ocjena2 == ocjena3){
        printf("Sva tri studenta imaju istu ocjenu.");
    } else if ((ocjena1 == ocjena2 && ocjena2 != ocjena3) || (ocjena1 == ocjena2 && ocjena2 != ocjena3) || (ocjena2 == ocjena3 && ocjena3 != ocjena1)){
        printf("\nDva od tri studenta imaju istu ocjenu.");
    }else if(ocjena1 != ocjena2 && ocjena2 != ocjena3 && ocjena1 != ocjena3){
        printf("\nSvaki student ima razlicitu ocjenu.");
    }
	return 0;
}
