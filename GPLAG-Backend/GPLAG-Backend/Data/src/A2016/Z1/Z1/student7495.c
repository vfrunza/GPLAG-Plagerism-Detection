#include <stdio.h>

int maun (){
    double tparcijala1=0, tparcijala2=0, tzadace=0, tprisustvo==0, tzavrsni=0, tzavrsni=0, tbodovi=0;
    double bparcijala1=0, bparcijala2=0, bzadace=0, bprisustvo=0, bzavrsni=0, bzavrsni=0, bbodovi=0;
    double mparcijala1=0, mparcijala2=0, mzadace=0, mprisustvo=0, mzavrsni=0, mzavrsni=0, mbodovi=0;
    int tarik=0, bojan=0, mirza=0;
    
    printf("Unesite bodove za Tarika: \n");
    printf(" Prvi parcijalni ispit: ");
    scanf("%f", ˛tparcijala1);
    if(tparcijala1>20 || tparcijala1<0){
        printf("Neispravan unos");
        return 0;
    }
    
    printf ("Drugi parcijalni ispit: ");
    scanf ("%1f", &tparcijala2);
    if(tparcijala2>10 || tparcijala<0){
        printf ("Neispravan broj bodova ");
        return 0;
    }
    
    printf("Prisustvo: ");
    scanf("%1f", &tprisustvo);
    if(tprisustvo>10 || tparcijala1<0){
        printf("Neispravan broj bodova");
        return 0;
    }
    
    printf ("Zadace ");
    scanf("%1f", &tzadace);
    if(tzadace>10 || tparcijala1<0){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zavrsni ispit: ");
    scanf ("%1f", &tzavrsni);
    if(tzavrsni>40 || tparcijala1<0){
        printf ("neispravan broj bodova");
        return 0;
    }
    
    printf("Unesite bodove za Bojana: \n ");
    printf( "Prvi parcijalni ispit:");
    scanf("1f", &bparcijala1);
    if(tparcijala1>20 || tparcijala1<0)
    {
        printf("Neispravan broj bodova");
        return 0;

    }
    
    printf (" Drugi parcijalni ispit: ");
    scanf("1f", &tparcijala2);
    if(tparcijala2>20 || tparcijala2<0);
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    
    printf("Prisustvo: ");
    scanf("%1f", tprisustvo);
    if(tprisustvo>10 || tparcijala1<0)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    
    printf("Zadace: ");
    scanf("%1f", &bzadace);
    if(bzadace>10 || bparcijala1<0){
        printf ("Neispravan broj bodova");
        return 0;
    }
    
    printf("Zavrsni ispit: ");
    scanf ("%1f", &bzavrsni);
    if(bzavrsni>40 || bparcijala1<0){
        printf ("Neispravan broj bodova");
        return 0;
    }
    printf("Unesite bodove za Mirzu: \n ");
    printf( "Prvi parcijalni ispit:");
    scanf("1f", &mparcijala1);
    if(mparcijala1>20 || mparcijala1<0)
    {
        printf("Neispravan broj bodova");
        return 0;

    }
    
    printf (" Drugi parcijalni ispit: ");
    scanf("1f", &mparcijala2);
    if(mparcijala2>20 || mparcijala2<0);
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    
    printf("Prisustvo: ");
    scanf("%1f", mprisustvo);
    if(mprisustvo>10 || mparcijala1<0)
    {
        printf("Neispravan broj bodova");
        return 0;
    }
    
    printf("Zadace: ");
    scanf("%1f", &mzadace);
    if(mzadace>10 || mparcijala1<0){
        printf ("Neispravan broj bodova");
        return 0;
    }
    
    printf("Zavrsni ispit: ");
    scanf ("%1f", &mzavrsni);
    if(mzavrsni>40 || mparcijala1<0){
        printf ("Neispravan broj bodova");
        return 0;
    }
    
    tbodovi=tparcijala1+tparcijala2+tprisustvo+tzadace+tzadace+tzavrsni;
    bbodovi=bparcijala1+bparcijala2+bprisustvo+bzadace+bbzavrsni;
    mbodovi=mparcijala1+mparcijala2+mprisustvo+mzadace+mzavrsni;
    if (tbodovi<55){
        tarik=0;
    }
    else if (tbodovi>=55 && tbodovi<65){
        tarik=6;
    }
    else if (tbodovi>=65 && tbodovi<75){
        tarik=7;
    }
    else if (tbodovi>=75 && tbodovi<85){
        tarik=8;
    }
    else if (tbodovi>=85 && tbodovi<92){
        tarik=9;
    }
    else if (tbodovi>=92 && tbodovi<=100){
        tarik=10;
    }
     if (bbodovi<55){
        bojan=0;
    }
    else if (bbodovi>=55 && bbodovi<65){
        bojan=6;
    }
    else if (bbodovi>=65 && bbodovi<75){
        bojan=7;
    }
    else if (bbodovi>=75 && bbodovi<85){
        bodovi=8;
    }
    else if (bbodovi>=85 && bbodovi<92){
        bojan=9;
    }
    else if (bbodovi>=92 && bbodovi<=100){
        bojan=10;
    }
     if (mbodovi<55){
        mirza=0;
    }
    else if (mbodovi>=55 && mbodovi<65){
        mirza=6;
    }
    else if (mbodovi>=65 && mbodovi<75){
        mirza=7;
    }
    else if (mbodovi>=75 && mbodovi<85){
        mirza=8;
    }
    else if (mbodovi>=85 && mbodovi<92){
        mirza=9;
    }
    else if (mbodovi>=92 && mbodovi<100){
        mirza=10;
    }
    if(tarik !=0 && bojan !=0 && mirza !=0 ){
        printf ("Sva tri studenta su polozila");
        if(tarik == bojan && bojan == mirza){
            printf ("\n Sva tri studenta imaju istu ocjenu");
        }
        else if (tarik == bojan || bojan == mirza || tarik == mirza){
            printf("\n Dva od tri studenta imaju istu ocjenu");
        }
        else if (tarik != bojan || bojan != mirza || tarik != mirza){
            printf("\n Svaki student imaa razlicitu ocjenu");
        }
        
    }    
    else if (tarik ==0  && bojan==0 && mirza==0){
            printf("\n Nijedan student nije polozio");
    }
    else if ((tarik !=0 && bojan==0 && mirza==0) || (tarik ==0 && bojan !=0 && mirza==0) || (tarik==0 && bojan ==0 && mirza !=0)){
            printf("\n Jedan student je polozio");
    }
    else if ((tarik !=0 && bojan !=0 &&  mirza==0) || (tarik ==0 && bojan !=0 && mirza !=0) || (tarik !=0 && bojan ==0 && mirza !=0)){
            printf("\n Dva studenta su polozila");
    }
    else if (tarik != bojan || bojan != mirza || tarik != mirza){
            printf("\n Svaki student imaa razlicitu ocjenu");
    }
    return 0;
    