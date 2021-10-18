#include <stdio.h>
int main() {
	double p1,p2,p,z,zi,p11,p22,pp,zz,zzi,pp11,pp22,ppp,zzz,zzzi;
    printf("Unesite bodove za Tarika: \n");
    printf("I parcijalni ispit: ");
    scanf("%lf", &p1);
    if(p1<0 || p1>20){
    printf("Neispravan broj bodova");
        return 0;
    }
    printf("II parcijalni ispit: ");
    scanf("%lf", &p2); 
    if(p2<0 || p2>20){
    printf("Neispravan broj bodova");
        return 0;
    }
    printf("Prisustvo: ");
    scanf("%lf", &p); 
     if(p<0 || p>10){
    printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zadace: ");
    scanf("%lf", &z); 
     if(z<0 || z>10){
    printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zavrsni ispit: ");
    scanf("%lf", &zi);
     if(zi<0 || zi>40){
    printf("Neispravan broj bodova");
        return 0;
    }
       printf("Unesite bodove za Bojana: \n");
    printf("I parcijalni ispit: ");
    scanf("%lf", &p11); 
     if(p11<0 || p11>20){
    printf("Neispravan broj bodova");
        return 0;
    }
    printf("II parcijalni ispit: ");
    scanf("%lf", &p22); 
     if(p22<0 || p22>20){
    printf("Neispravan broj bodova");
        return 0;
    }
    printf("Prisustvo: ");
    scanf("%lf", &pp); 
     if(pp<0 || pp>10){
    printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zadace: ");
    scanf("%lf", &zz); 
     if(zz<0 || zz>10){
    printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zavrsni ispit: ");
    scanf("%lf", &zzi);
     if(zzi<0 || zzi>40){
    printf("Neispravan broj bodova");
        return 0;
    }
    printf("Unesite bodove za Mirzu: \n");
    printf("I parcijalni ispit: ");
    scanf("%lf", &pp11);
     if(pp11<0 || pp11>20){
    printf("Neispravan broj bodova");
        return 0;
    }
    printf("II parcijalni ispit: ");
    scanf("%lf", &pp22);
     if(pp22<0 || pp22>20){
    printf("Neispravan broj bodova");
        return 0;
    }
    printf("Prisustvo: ");
    scanf("%lf", &ppp);
     if(ppp<0 || ppp>10){
    printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zadace: ");
    scanf("%lf", &zzz);
     if(zzz<0 || zzz>10){
    printf("Neispravan broj bodova");
        return 0;
    }
    printf("Zavrsni ispit: ");
    scanf("%lf", &zzzi);
     if(zzzi<0 || zzzi>40){
    printf("Neispravan broj bodova");
        return 0;
    }
		double x,y,k,a,b,c;
		x= p1+p2+p+z+zi;
		y= p11+p22+pp+zz+zzi;
		k= pp11+pp22+ppp+zzz+zzzi;
		if (x>=55 && x<65) a=6;
		if (x>=65 && x<75) a=7;
		if (x>=75 && x<85) a=8;
		if (x>=85 && x<92) a=9;
		if (x>=92 && x<=100) a=10;
			if (x>=55 && y<65) b=6;
		if (y>=65 && y<75) b=7;
		if (y>=75 && y<85) b=8;
		if (y>=85 && y<92) b=9;
		if (y>=92 && y<=100) b=10;
			if (x>=55 && k<65) c=6;
		if (k>=65 && k<75) c=7;
		if (k>=75 && k<85) c=8;
		if (k>=85 && k<92) c=9;
		if (k>=92 && k<=100) c=10;
							
		if (x<55 && y<55 && k<55)
		printf("Nijedan student nije polozio.\n");
		else if((x>=55 && y<55 && k<55) || (y>=55 && x<55 && k<55) || (k>=55 && y<55 && x<55))
		printf("Jedan student je polozio.\n");
		else if ((x>=55 && y>=5 && k<55) || (y>=55 && k>=55 && x<55) || (x>=55 && k>=55 && y<55))
		printf ("Dva studenta su polozila.\n");
		else if (x>=55 && y>=55 && k>=55) {
		printf ("Sva tri studenta su polozila.\n");
		if (a==b && b==c)
		printf ("Sva tri studenta imaju istu ocjenu.\n");
		else if ((a==b && b!=c) || (b==c && c!=a) || (a==c && c!=b))
		printf ("Dva od tri studenta imaju istu ocjenu.\n");
		else if (a!=b && b!=c && a!=c) 
		printf ("Svaki student ima razlicitu ocjenu.\n");
	}
	
	return 0;
}
