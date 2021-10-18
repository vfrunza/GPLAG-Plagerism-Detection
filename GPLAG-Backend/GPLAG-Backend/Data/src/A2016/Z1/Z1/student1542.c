#include <stdio.h>

int main() {
    float pp, dp, p, z, u,tarik=0, bojan=0, mirza=0;
    int pomocna=0;
    int br6=0,br7=0,br8=0,br9=0,br10=0;
    printf("Unesite bodove za Tarika: ");
    printf("\nI parcijalni ispit: ");
    scanf("%f", &pp);
    if(pp<0 || pp>20){printf("Neispravan broj bodova\n");return 0;}
    
    printf("II parcijalni ispit: ");
    scanf("%f", &dp);
    if(dp<0 || dp>20){printf("Neispravan broj bodova\n");return 0;}
    
    printf("Prisustvo: ");
    scanf("%f", &p);
    if(p<0 || p>10){printf("Neispravan broj bodova\n");return 0;}
    
    printf("Zadace: ");
    scanf("%f", &z);
    if(z<0 || z>10){printf("Neispravan broj bodova\n");return 0;}
    printf("Zavrsni ispit: ");
    scanf("%f", &u);
    if(u<0 || u>40){printf("Neispravan broj bodova\n");return 0;}
    
    tarik=pp+dp+p+z+u;
      if(tarik>=54.9 && tarik<55){
        pomocna=tarik;
        tarik=pomocna+1;
    }
    
    printf("Unesite bodove za Bojana:\nI parcijalni ispit: " );
    scanf("%f", &pp);
    if(pp<0 || pp>20){printf("Neispravan broj bodova\n");return 0;}
    
    printf("II parcijalni ispit: ");
    scanf("%f", &dp);
    if(dp<0 || dp>20){printf("Neispravan broj bodova\n");return 0;}
    
    printf("Prisustvo: ");
    scanf("%f", &p);
    if(p<0 || p>10){printf("Neispravan broj bodova\n");return 0;}
    
    printf("Zadace: ");
    scanf("%f", &z);
    if(z<0 || z>10){printf("Neispravan broj bodova\n");return 0;}
    
    printf("Zavrsni ispit: ");
    scanf("%f", &u);
    if(u<0 || u>40){printf("Neispravan broj bodova\n");return 0;}
    
    bojan=dp+pp+p+u+z;
     
    printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
    scanf("%f", &pp);
    if(pp<0 || pp>20){printf("Neispravan broj bodova\n");return 0;}
    
    printf("II parcijalni ispit: ");
    scanf("%f", &dp);
    if(dp<0 || dp>20){printf("Neispravan broj bodova\n");return 0;}
    
    printf("Prisustvo: ");
    scanf("%f", &p);
    if(p<0 || p>10){printf("Neispravan broj bodova\n");return 0;}
    
    printf("Zadace: ");
    scanf("%f", &z);
    if(z<0 || z>10){printf("Neispravan broj bodova\n");return 0;}

    printf("Zavrsni ispit: ");
    scanf("%f", &u);
    if(u<0 || u>40){printf("Neispravan broj bodova\n");return 0;}
    
    mirza=pp+dp+p+u+z;
   
    if(tarik>=55 && tarik<65 ) br6++;
    if(mirza >=55 && mirza<65) br6++;
    if(bojan >=55 && bojan<65)br6++;
    if(tarik>=65 && tarik<75) br7++;
    if( mirza >=65 && mirza<75) br7++;
    if(bojan >=65 && bojan<75)br7++;
    if(tarik>=75 && tarik<85) br8++;
    if( mirza >=75 && mirza<85) br8++;
    if(bojan >=75 && bojan<85)br8++;
    if(tarik>=85 && tarik<92) br9++;
    if( mirza >=85 && mirza<92) br9++;
    if(bojan >=85 && bojan<92)br9++;
    if(tarik>=92 && tarik<=100) br10++;
    if( mirza >=92 && mirza<=100) br10++;
    if(bojan >=92 && bojan<=100)br10++;
    
    if(tarik<55 && bojan<55 && mirza<55)
    printf("Nijedan student nije polozio.");
    
    else if((tarik<55 && bojan<55 && mirza>=55)||(tarik>=55 && mirza<55 && bojan<55)||(tarik<55 && bojan>=55 && mirza<55))
    printf("Jedan student je polozio.");
    
    else if((tarik<55 && mirza>=55 && bojan>=55) ||(tarik>=55 && mirza>=55 && bojan<55)||(tarik>=55&&bojan>=55 && mirza<55))
    printf("Dva studenta su polozila.");
    
    else {
    	printf("Sva tri studenta su polozila.");
        if(br6==3 || br7==3 || br8==3 || br9==3 || br10==3)
    	printf("\nSva tri studenta imaju istu ocjenu.");
    	
    	else if(br6==2 || br7==2 || br8==2 || br9==2 || br10==2)
    	printf("\nDva od tri studenta imaju istu ocjenu.");
    
    	else if(br6==1 || br7==1 || br8==1 || br9==1 || br10==1)
    	printf("\nSvaki student ima razlicitu ocjenu.");
    }
   return 0;
}
