#include <stdio.h>
#include <stdlib.h>

int main()
{
    float t1,t2,tp,tz,tzz,t=0,to;
    printf("Unesite bodove za Tarika: \n");
    printf("I parcijalni ispit: ");
    scanf("%f",&t1);
    if(t1<0 || t1>20){
        printf("Neispravan broj bodova");
        return 0;
    }
    t+=t1;
    printf("II parcijalni ispit: ");
    scanf("%f",&t2);
    if(t2<0 || t2>20){
        printf("Neispravan broj bodova");
        return 0;
    }
    t+=t2;
    printf("Prisustvo: ");
    scanf("%f",&tp);
    if(tp<0 || tp>10){
        printf("Neispravan broj bodova");
        return 0;
    }
    t+=tp;
    printf("Zadace: ");
    scanf("%f",&tz);
    if(tz<0 || tz>10){
        printf("Neispravan broj bodova");
        return 0;
    }
    t+=tz;
    printf("Zavrsni ispit: ");
    scanf("%f",&tzz);
    if(tzz<0 || tzz>40){
        printf("Neispravan broj bodova");
        return 0;
    }
    
t+=tzz;
    if(t<55)to=5;
    else if(t<65)to=6;
    else if(t<75)to=7;
    else if(t<85)to=8;
    else if(t<95)to=9;
    else t=10;

    float b1,b2,bp,bz,bzz,b=0,bo;
    printf("Unesite bodove za Bojana: \n");
    printf("I parcijalni ispit: ");
    scanf("%f",&b1);
    if(b1<0 || b1>20){
        printf("Neispravan broj bodova");
        return 0;
    }
    b+=b1;
    printf("II parcijalni ispit: ");
    scanf("%f",&b2);
    if(b2<0 || b2>20){
        printf("Neispravan broj bodova");
        return 0;
    }
    b+=b2;
    printf("Prisustvo: ");
    scanf("%f",&bp);
    if(bp<0 || bp>10){
        printf("Neispravan broj bodova");
        return 0;
    }
    b+=bp;
    printf("Zadace: ");
    scanf("%f",&bz);
    if(bz<0 || bz>10){
        printf("Neispravan broj bodova");
        return 0;
    }
    b+=bz;
    printf("Zavrsni ispit: ");
    scanf("%f",&bzz);
    if(bzz<0 || bzz>40){
        printf("Neispravan broj bodova");
        return 0;
    }
    b+=bzz;
    if(b<55)bo=5;
    else if(b<65)bo=6;
    else if(b<75)bo=7;
    else if(b<85)bo=8;
    else if(b<95)bo=9;
    else b=10;

    float m1,m2,mp,mz,mzz,m=0,mo;
    printf("Unesite bodove za Mirzu: \n");
    printf("I parcijalni ispit: ");
    scanf("%f",&m1);
    if(m1<0 || m1>20){
        printf("Neispravan broj bodova");
        return 0;
    }
    m+=m1;
    printf("II parcijalni ispit: ");
    scanf("%f",&m2);
    if(m2<0 || m2>20){
        printf("Neispravan broj bodova");
        return 0;
    }
    m+=m2;
    printf("Prisustvo: ");
    scanf("%f",&mp);
    if(mp<0 || mp>10){
        printf("Neispravan broj bodova");
        return 0;
    }
    m+=mp;
    printf("Zadace: ");
    scanf("%f",&mz);
    if(mz<0 || mz>10){
        printf("Neispravan broj bodova");
        return 0;
    }
    m+=mz;
    printf("Zavrsni ispit: ");
    scanf("%f",&mzz);
    if(mzz<0 || mzz>40){
        printf("Neispravan broj bodova");
        return 0;
    }
    m+=mzz;
    if(m<55)mo=5;
    else if(m<65)mo=6;
    else if(m<75)mo=7;
    else if(m<85)mo=8;
    else if(m<95)mo=9;
    else m=10;

    if(to==5 && bo==5 && mo==5)printf("Nijedan student nije polozio.");
    else if((to>5 && bo==5 && mo==5) || (to==5 && bo>5 && mo==5) || (to==5 && bo==5 && mo>5))printf("Jedan student je polozio.");
    else if((to>5 && bo>5 && mo==5) ||(to>5 && bo==5 && mo>5) || (to==5 && bo>5 && mo>5))printf("Dva studenta su polozila.");
    else
    {
        printf("Sva tri studenta su polozila.\n");
        if(to==bo && bo==mo)printf("Sva tri studenta imaju istu ocjenu.");
        else if(to!=bo && bo!=mo && to!=mo)printf("Svaki student ima razlicitu ocjenu.");
        else printf("Dva od tri studenta imaju istu ocjenu.");
    }
    return 0;
}