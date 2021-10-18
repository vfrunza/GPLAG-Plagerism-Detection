#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define GRESKA 0.0001


int main()
{
    float IparcT, IIparcT, prisustvoT, zadaceT, zavrsniT;
    float IparcB, IIparcB, prisustvoB, zadaceB, zavrsniB;
    float IparcM, IIparcM, prisustvoM, zadaceM, zavrsniM;
    float ukupnoT, ukupnoB, ukupnoM;
    int ocjenaT=5, ocjenaB=5, ocjenaM=5;

    printf("Unesite bodove za Tarika: ");
    printf("\nI parcijalni ispit: ");
    scanf("%f",&IparcT);
    if(IparcT<0||IparcT>20){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("II parcijalni ispit: ");
    scanf("%f",&IIparcT);
    if(IIparcT<0||IIparcT>20){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Prisustvo: ");
    scanf("%f",&prisustvoT);
    if(prisustvoT<0||prisustvoT>10){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zadace: ");
    scanf("%f",&zadaceT);
    if(zadaceT<0||zadaceT>10){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zavrsni ispit: ");
    scanf("%f",&zavrsniT);
    if(zavrsniT<0||zavrsniT>40){
        printf("Neispravan broj bodova");
        return 0;
    }

    printf("Unesite bodove za Bojana: ");
    printf("\nI parcijalni ispit: ");
    scanf("%f",&IparcB);
    if(IparcB<0||IparcB>20){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("II parcijalni ispit: ");
    scanf("%f",&IIparcB);
    if(IIparcB<0||IIparcB>20){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Prisustvo: ");
    scanf("%f",&prisustvoB);
    if(prisustvoB<0||prisustvoB>10){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zadace: ");
    scanf("%f",&zadaceB);
    if(zadaceB<0||zadaceB>10){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zavrsni ispit: ");
    scanf("%f",&zavrsniB);
    if(zavrsniB<0||zavrsniB>40){
        printf("Neispravan broj bodova");
        return 0;
    }

    printf("Unesite bodove za Mirzu: ");
    printf("\nI parcijalni ispit: ");
    scanf("%f",&IparcM);
    if(IparcM<0||IparcM>20){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("II parcijalni ispit: ");
    scanf("%f",&IIparcM);
    if(IIparcM<0||IIparcM>20){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Prisustvo: ");
    scanf("%f",&prisustvoM);
    if(prisustvoM<0||prisustvoM>10){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zadace: ");
    scanf("%f",&zadaceM);
    if(zadaceM<0||zadaceM>10){
        printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zavrsni ispit: ");
    scanf("%f",&zavrsniM);
    if(zavrsniM<0||zavrsniM>40){
        printf("Neispravan broj bodova");
        return 0;
    }

    ukupnoT=IparcT+IIparcT+prisustvoT+zadaceT+zavrsniT+GRESKA;
    if(ukupnoT>=55&&ukupnoT<65){ocjenaT=6;}
    if(ukupnoT>=65&&ukupnoT<75){ocjenaT=7;}
    if(ukupnoT>=75&&ukupnoT<85){ocjenaT=8;}
    if(ukupnoT>=85&&ukupnoT<95){ocjenaT=9;}
    if(ukupnoT>=95&&ukupnoT<=100){ocjenaT=10;}
    
    ukupnoB=IparcB+IIparcB+prisustvoB+zadaceB+zavrsniB+GRESKA;
    if(ukupnoB>=55&&ukupnoB<65){ocjenaB=6;}
    if(ukupnoB>=65&&ukupnoB<75){ocjenaB=7;}
    if(ukupnoB>=75&&ukupnoB<85){ocjenaB=8;}
    if(ukupnoB>=85&&ukupnoB<95){ocjenaB=9;}
    if(ukupnoB>=95&&ukupnoB<=100){ocjenaB=10;}
    
    ukupnoM=IparcM+IIparcM+prisustvoM+zadaceM+zavrsniM+GRESKA;
    if(ukupnoM>=55&&ukupnoM<65){ocjenaM=6;}
    if(ukupnoM>=65&&ukupnoM<75){ocjenaM=7;}
    if(ukupnoM>=75&&ukupnoM<85){ocjenaM=8;}
    if(ukupnoM>=85&&ukupnoM<95){ocjenaM=9;}
    if(ukupnoM>=95&&ukupnoM<=100){ocjenaM=10;}

    
    if(ukupnoT>=55&&ukupnoB<55&&ukupnoM<55){
        printf("Jedan student je polozio.");
    }
    if(ukupnoT<55&&ukupnoB>=55&&ukupnoM<55){
        printf("Jedan student je polozio.");
    }
    if(ukupnoT<55&&ukupnoB<55&&ukupnoM>=55){
        printf("Jedan student je polozio.");
    }
    if(ukupnoT>=55&&ukupnoB>=55&&ukupnoM<55){
       printf("Dva studenta su polozila.");
    }
    if(ukupnoT>=55&&ukupnoB<55&&ukupnoM>=55){
        printf("Dva studenta su polozila.");
    }
    if(ukupnoT<55&&ukupnoB>=55&&ukupnoM>=55){
        printf("Dva studenta su polozila.");
    }
    
    if(ukupnoT<55&&ukupnoB<55&&ukupnoM<55){
        printf("Nijedan student nije polozio.");
    }
    
    if(ukupnoT>=55&&ukupnoB>=55&&ukupnoM>=55){
        printf("Sva tri studenta su polozila.");
        if(ocjenaT==ocjenaB&&ocjenaB==ocjenaM){
            printf("\nSva tri studenta imaju istu ocjenu.");
        }
        if(ocjenaT==ocjenaB&&ocjenaB!=ocjenaM){
            printf("\nDva od tri studenta imaju istu ocjenu.");
        }
        if(ocjenaT==ocjenaM&&ocjenaM!=ocjenaB){
            printf("\nDva od tri studenta imaju istu ocjenu.");
        }
        if(ocjenaT!=ocjenaB&&ocjenaB==ocjenaM){
            printf("\nDva od tri studenta imaju istu ocjenu.");
        }
        if(ocjenaT!=ocjenaB&&ocjenaB!=ocjenaM&&ocjenaT!=ocjenaM){
            printf("\nSvaki student ima razlicitu ocjenu.");
        }
    }

    return 0;
}