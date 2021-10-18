#include <stdio.h>
#define e 0.001

int main(){
float a1,a2,a3,a4,a5,Zba,b1,b2,b3,b4,b5,Zbb,c1,c2,c3,c4,c5,Zbc;
int OA,OB,OC;

/* Unos podataka sa tastature */

printf("Unesite bodove za Tarika: \n");
printf("I parcijalni ispit: ");
scanf("%f", &a1);
if(a1>20 || a1<0){
    printf("Neispravan broj bodova");
    return 0;
}
printf("II parcijalni ispit: ");
scanf("%f", &a2);
if(a2>20 || a2<0){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Prisustvo: ");
scanf("%f", &a3);
if(a3>10 || a3<0){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zadace: ");
scanf("%f", &a4);
if(a4>10 || a4<0){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zavrsni ispit: ");
scanf("%f", &a5);
if(a5>40 || a5<0){
    printf("Neispravan broj bodova");
    return 0;
}


printf("Unesite bodove za Bojana: \n");
printf("I parcijalni ispit: ");
scanf("%f", &b1);
if(b1>20 || b1<0){
    printf("Neispravan broj bodova");
    return 0;
}
printf("II parcijalni ispit: ");
scanf("%f", &b2);
if(b2>20 || b2<0){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Prisustvo: ");
scanf("%f", &b3);
if(b3>10 || b3<0){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zadace: ");
scanf("%f", &b4);
if(b4>10 || b4<0){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zavrsni ispit: ");
scanf("%f", &b5);
if(b5>40 || b5<0){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Unesite bodove za Mirzu: \n");
printf("I parcijalni ispit: ");
scanf("%f", &c1);
if(c1>20 || c1<0){
    printf("Neispravan broj bodova");
    return 0;
}
printf("II parcijalni ispit: ");
scanf("%f", &c2);
if(c2>20 || c2<0){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Prisustvo: ");
scanf("%f", &c3);
if(c3>10 || c3<0){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zadace: ");
scanf("%f", &c4);
if(c4>10 || c4<0){
    printf("Neispravan broj bodova");
    return 0;
}
printf("Zavrsni ispit: ");
scanf("%f", &c5);
if(c5>40 || c5<0){
    printf("Neispravan broj bodova");
    return 0;
}


{
    Zba = a1+a2+a3+a4+a5+e;
    Zbb = b1+b2+b3+b4+b5+e;
    Zbc = c1+c2+c3+c4+c5+e;
    {
        if(Zba>=55 && Zba<65)
        OA = 6;
        else if(Zba>=65 && Zba<75)
        OA = 7;
        else if(Zba>=75 && Zba<85)
        OA = 8;
        else if(Zba>=85 && Zba<92)
        OA = 9;
        else
        OA = 10;
    }
    {
        if(Zbb>=55 && Zbb<65)
        OB = 6;
        else if(Zbb>=65 && Zbb<75)
        OB = 7;
        else if(Zbb>=75 && Zbb<85)
        OB = 8;
        else if(Zbb>=85 && Zbb<92)
        OB = 9;
        else
        OB = 10;
    }
    {
        if(Zbc>=55 && Zbc<65)
        OC = 6;
        else if(Zbc>=65 && Zbc<75)
        OC = 7;
        else if(Zbc>=75 && Zbc<85)
        OC = 8;
        else if(Zbc>=85 && Zbc<92)
        OC = 9;
        else
        OC = 10;
    }
    if((Zba+e)<55 && (Zbb+e)<55 && (Zbc+e)<55)
    printf("Nijedan student nije polozio.\n");
    else if((Zba+e)>=55 && (Zbb+e)>=55 && (Zbc+e)>=55)
    {
    printf("Sva tri studenta su polozila.\n");
    if((OA==OB) && (OB==OC))
    printf("Sva tri studenta imaju istu ocjenu.");
    else if((OA==OB) || (OB==OC) || (OA==OC))
    printf("Dva od tri studenta imaju istu ocjenu.");
    else
    printf("Svaki student ima razlicitu ocjenu.");
    }
    else if((Zba+e)>=55 && (Zbb+e)>=55 || (Zba+e)>=55 && (Zbc+e)>=55 || (Zbb+e)>=55 && (Zbc+e)>=55)
    printf("Dva studenta su polozila.\n");
    else if((Zba+e)>=55 || (Zbb+e)>=55 || (Zbc+e)>=55)
    printf("Jedan student je polozio.");
        
}
return 0;
}