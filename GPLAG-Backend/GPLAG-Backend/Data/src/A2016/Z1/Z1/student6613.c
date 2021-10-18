#include <stdio.h>
#include<math.h>
#define E 0.000001

int main() {
    double b1t,b2t,pt,zt,zit,ot,bbt,b1b,b2b,pb,zb,zib,ob,bbb,b1m,b2m,pm,zm,zim,om,bbm;
   
    /*Tarik*/
    printf("Unesite bodove za Tarika:\n");
    printf("I parcijalni ispit: ");
    scanf("%lf", &b1t);
    if(b1t<0 || b1t>20) { printf("Neispravan broj bodova"); return 0;}
    printf("II parcijalni ispit: ");
    scanf("%lf", &b2t);
    if(b2t<0 || b2t>20) { printf("Neispravan broj bodova"); return 0;}
    printf("Prisustvo: ");
    scanf("%lf", &pt);
    if(pt<0 || pt>10) { printf("Neispravan broj bodova"); return 0;}
    printf("Zadace: ");
    scanf("%lf", &zt);
     if(zt<0 || zt>10) { printf("Neispravan broj bodova"); return 0;}
    printf("Zavrsni ispit: ");
    scanf("%lf", &zit);
    if(zit<0 || zit>40) { printf("Neispravan broj bodova"); return 0;}
   
    /*Bojan*/
    printf("Unesite bodove za Bojana:\n");
    printf("I parcijalni ispit: ");
    scanf("%lf", &b1b);
    if(b1b<0 || b1b>20) { printf("Neispravan broj bodova"); return 0;}
    printf("II parcijalni ispit: ");
    scanf("%lf", &b2b);
    if(b2b<0 || b2b>20) { printf("Neispravan broj bodova"); return 0;}
    printf("Prisustvo: ");
    scanf("%lf", &pb);
     if(pb<0 || pb>10) { printf("Neispravan broj bodova"); return 0;}
    printf("Zadace: ");
    scanf("%lf", &zb);
     if(zb<0 || zb>10) { printf("Neispravan broj bodova"); return 0;}
    printf("Zavrsni ispit: ");
    scanf("%lf", &zib);
    if(zib<0 || zib>40) { printf("Neispravan broj bodova"); return 0;}
   
    /*Mirza*/
    printf("Unesite bodove za Mirzu:\n");
    printf("I parcijalni ispit: ");
    scanf("%lf", &b1m);
    if(b1m<0 || b1m>20) { printf("Neispravan broj bodova"); return 0;}
    printf("II parcijalni ispit: ");
    scanf("%lf", &b2m);
    if(b2m<0 || b2m>20) { printf("Neispravan broj bodova"); return 0;}
    printf("Prisustvo: ");
    scanf("%lf", &pm);
     if(pm<0 || pm>10) { printf("Neispravan broj bodova"); return 0;}
    printf("Zadace: ");
    scanf("%lf", &zm);
     if(zm<0 || zm>10) { printf("Neispravan broj bodova"); return 0;}
    printf("Zavrsni ispit: ");
    scanf("%lf", &zim);
     if(zim<0 || zim>40) { printf("Neispravan broj bodova"); return 0;}
   
    if(b1t>=0 && b1t<=20 && b1b>=0 && b1b<=20 && b1m>=0 && b1m<=20 && b2t>=0 && b2t<=20 && b2b>=0 && b2b<=20 && b2m>=0 && b2m<=20 && pt>=0 && pt<=10 && pb>=0 && pb<=10 && pm>=0 && pm<=10 && zt>=0 && zt<=10 && zb>=0 && zb<=10 && zm>=0 && zm<=10 && zit>=0 && zit<=40 && zib>=0 && zib<=40 && zim>=0 && zim<=40)
    {bbt=b1t+b2t+pt+zt+zit;
    bbb=b1b+b2b+pb+zb+zib;
    bbm=b1m+b2m+pm+zm+zim;
    
    /*ocjena Tarik*/
    if(bbt<55) ot=5;
    if(bbt>=55 && bbt<65) ot=6;
    if(bbt>=65 && bbt<75) ot=7;
    if(bbt>=75 && bbt<85) ot=8;
    if(bbt>=85 && bbt<92) ot=9;
    if(bbt>=92 && bbt<=100) ot=10;
    
    /*ocjena Bojan*/
    if(bbb<55) ob=5;
    if(bbb>=55 && bbb<65) ob=6;
    if(bbb>=65 && bbb<75) ob=7;
    if(bbb>=75 && bbb<85) ob=8;
    if(bbb>=85 && bbb<92) ob=9;
    if(bbb>=92 && bbb<=100) ob=10;
    
    /*ocjena Mirza*/
    if(bbm<55) om=5;
    if(bbm>=55 && bbm<65) om=6;
    if(bbm>=65 && bbm<75) om=7;
    if(bbm>=75 && bbm<85) om=8;
    if(bbm>=85 && bbm<92) om=9;
    if(bbm>=92 && bbm<=100) om=10;
    
    /*Broj studenata koji su polozili*/
    if(ob>5 && ot>5 && om>5) printf("Sva tri studenta su polozila.");
    else if(ob>5 && ot>5 && om<6) printf("Dva studenta su polozila.");
    else if(ob<6 && ot>5 && om>5) printf("Dva studenta su polozila.");
    else if(ob>5 && ot<6 && om>5) printf("Dva studenta su polozila.");
    else if(ob>5 && ot<6 && om<6) printf("Jedan student je polozio.");
    else if(ob<6 && ot>5 && om<6) printf("Jedan student je polozio.");
    else if(ob<6 && ot<6 && om>5) printf("Jedan student je polozio.");
    else if(ob<6 && ot<6 && om<6) printf("Nijedan student nije polozio.");
    
    /*jednakost ocjena*/
    if(ob>5 && om>5 && om>5) {
    if(fabs(ot-ob)<E && fabs(ot-om)<E && fabs(ob-om)<E) printf("\nSva tri studenta imaju istu ocjenu.");
    else if(fabs(ot-ob)<E && fabs(ob-om)>E) printf("\nDva od tri studenta imaju istu ocjenu.");
    else if(fabs(ot-ob)<E && fabs(ob-om)<E) printf("\nDva od tri studenta imaju istu ocjenu.");
    else if(fabs(ot-om)<E && fabs(ob-om)>E) printf("\nDva od tri studenta imaju istu ocjenu.");
    else if(fabs(ot-om)>E && fabs(ot-ob)>E && fabs(ob-om)>E) printf("\nSvaki student ima razlicitu ocjenu.");}
    }
    
    else{printf("\nNeispravan broj bodova");
    	return 0;}
	return 0;
}
