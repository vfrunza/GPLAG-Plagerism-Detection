#include <stdio.h>
#define EPSILON 0.00001

int main() {
    
    float ppt,dpt,prist,zadt,zit,ppb,dpb,prisb,zadb,zib,ppm,dpm,prism,zadm,zim;
    float tu=0,bu=0,mu=0;
    int ocjt,ocjb,ocjm,tpol=0,bpol=0,mpol=0,svipol=0;
    
    printf("Unesite bodove za Tarika:\n");
    printf("I parcijalni ispit: ");
    scanf("%f",&ppt);
    if(ppt<0 || ppt>20){
        printf("Neispravan broj bodova");
    return 0;
    }
    printf("II parcijalni ispit: ");
    scanf("%f",&dpt);
    if(dpt<0 || dpt>20){
        printf("Neispravan broj bodova");
    return 0;
    }
    printf("Prisustvo: ");
    scanf("%f",&prist);
    if(prist<0 || prist>10){
        printf("Neispravan broj bodova");
    return 0;
    }
    printf("Zadace: ");
    scanf("%f",&zadt);
    if(zadt<0 || zadt>10){
        printf("Neispravan broj bodova");
    return 0;
    }
    printf("Zavrsni ispit: ");
    scanf("%f",&zit);
    if(zit<0 || zit>40){
        printf("Neispravan broj bodova");
    return 0;
    }
    
    printf("Unesite bodove za Bojana:\n");
    printf("I parcijalni ispit: ");
    scanf("%f",&ppb);
    if(ppb<0 || ppb>20){
        printf("Neispravan broj bodova");
    return 0;
    }
    printf("II parcijalni ispit: ");
    scanf("%f",&dpb);
    if(dpb<0 || dpb>20){
        printf("Neispravan broj bodova");
    return 0;
    }
    printf("Prisustvo: ");
    scanf("%f",&prisb);
    if(prisb<0 || prisb>10){
        printf("Neispravan broj bodova");
    return 0;
    }
    printf("Zadace: ");
    scanf("%f",&zadb);
    if(zadb<0 || zadb>10){
        printf("Neispravan broj bodova");
    return 0;
    }
    printf("Zavrsni ispit: ");
    scanf("%f",&zib);
    if(zib<0 || zib>40){
        printf("Neispravan broj bodova");
    return 0;
    }
    
    printf("Unesite bodove za Mirzu:\n");
    printf("I parcijalni ispit: ");
    scanf("%f",&ppm);
    if(ppm<0 || ppm>20){
        printf("Neispravan broj bodova");
    return 0;
    }
    printf("II parcijalni ispit: ");
    scanf("%f",&dpm);
    if(dpm<0 || dpm>20){
        printf("Neispravan broj bodova");
    return 0;
    }
    printf("Prisustvo: ");
    scanf("%f",&prism);
    if(prism<0 || prism>10){
        printf("Neispravan broj bodova");
    return 0;
    }
    printf("Zadace: ");
    scanf("%f",&zadm);
    if(zadm<0 || zadm>10){
        printf("Neispravan broj bodova");
    return 0;
    }
    printf("Zavrsni ispit: ");
    scanf("%f",&zim);
    if(zim<0 || zim>40){
        printf("Neispravan broj bodova");
    return 0;
    }
    
    tu=ppt+dpt+prist+zadt+zit+EPSILON;
    if (tu<55){
        tpol=0;
    } else if (tu>=55 && tu<65){
        tpol=1;
    ocjt=6;
    } else if(tu>=65 && tu<75){
        tpol=1;
    ocjt=7;
    } else if(tu>=75 && tu<85){
        tpol=1;
    ocjt=8;
    } else if(tu>=85 && tu<92){
    tpol=1;
    ocjt=9;
    } else if(tu>=92 && tu<=100){
    tpol=1;
    ocjt=10;
    }
    
    bu=ppb+dpb+prisb+zadb+zib+EPSILON;
    if (bu<55){
    bpol=0;
    } else if (bu>=55 && bu<65){
    bpol=1;
    ocjb=6;
    } else if(bu>=65 && bu<75){
    bpol=1;
    ocjb=7;
    } else if(bu>=75 && bu<85){
    bpol=1;
    ocjb=8;
    } else if(bu>=85 && bu<92){
    bpol=1;
    ocjb=9;
    } else if(bu>=92 && bu<=100){
    bpol=1;
    ocjb=10;
    }
    
    mu=ppm+dpm+prism+zadm+zim+EPSILON;
     if (mu<55){
       mpol=0;
    } else if (mu>=55 && mu<65){
    mpol=1;
    ocjm=6;
    } else if(mu>=65 && mu<75){
    mpol=1;
    ocjm=7;
    } else if(mu>=75 && mu<85){
    mpol=1;
    ocjm=8;
    } else if(mu>=85 && mu<92){
    mpol=1;
    ocjm=9;
    } else if(mu>=92 && mu<=100){
    mpol=1;
    ocjm=10;
    }
    
    svipol=tpol+bpol+mpol;
    
    if(tu<55 && mu<55 && bu<55){
        printf("Nijedan student nije polozio.\n");
     }
     else if(tu>55 && mu<55 && bu<55){
         printf ("Jedan student je polozio.\n");
     }
     else if(tu<55 && mu>55 && bu<55){
         printf("Jedan student je polozio.\n");
     }
     else if(tu<55 && mu<55 && bu>55){
         printf("Jedan student je polozio.\n");
     }
     else if(tu>55 && mu>55 && bu<55){
         printf("Dva studenta su polozila.\n");
     }
     else if(tu>55 && mu<55 && bu>55){
         printf("Dva studenta su polozila.\n");
     }
     else if(tu<55 && mu>55 && bu>55){
         printf("Dva studenta su polozila.\n");
     }
     else if(tu>55 && mu>55 && bu>55){
         printf("Sva tri studenta su polozila.\n");
     }
    
     
     
     if (svipol==3){
     if (ocjt==ocjb && ocjt==ocjm && ocjb==ocjm){
         printf("Sva tri studenta imaju istu ocjenu.");
     }
     else if(ocjt==ocjb && ocjt!=ocjm && ocjb!=ocjm){
     printf("Dva od tri studenta imaju istu ocjenu.");
     }
     else if(ocjt!=ocjb && ocjb==ocjm && ocjt!=ocjm){
         printf("Dva od tri studenta imaju istu ocjenu.");
     }
     else if(ocjt==ocjm && ocjt!=ocjb && ocjb!=ocjm){
         printf("Dva od tri studenta imaju istu ocjenu.");
     }
     else if(ocjt!=ocjb && ocjt!=ocjm && ocjb!=ocjm){
         printf("Svaki student ima razlicitu ocjenu.");
         }
     }
    
    return 0;
}

