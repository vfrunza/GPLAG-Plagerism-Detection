#include <stdio.h>
#include <math.h>
int main() {
	double Tp1,Tp2,Tp,Tze,Tk,Bp1,Bp2,Bp,Bze,Bk,Mp1,Mp2,Mp,Mze,Mk,Pt,Pb,Pm,Ptn,Pbn,Pmn,x,y,z;
		printf("Unesite bodove za Tarika:\n");
			printf("I parcijalni ispit: ");
			scanf("%lf", &Tp1);
			if(Tp1<0||Tp1>20) { printf("Neispravan broj bodova\n"); return 0; }
			printf("II parcijalni ispit: ");
			scanf("%lf", &Tp2);
			if(Tp2<0||Tp2>20) { printf("Neispravan broj bodova\n"); return 0; }
			printf("Prisustvo:");
			scanf("%lf", &Tp);
			if(Tp<0||Tp>10) { printf("Neispravan broj bodova\n"); return 0; }
			printf(" Zadace:");
			scanf("%lf", &Tze);
			if(Tze<0||Tze>10) { printf("Neispravan broj bodova\n"); return 0; }
			printf(" Zavrsni ispit: ");
			scanf("%lf", &Tk);
			if(Tk<0||Tk>40) { printf("Neispravan broj bodova\n"); return 0; }
				
		printf("Unesite bodove za Bojana:\n");
			printf("I parcijalni ispit: ");
			scanf("%lf", &Bp1);
			if(Bp1<0||Bp1>20) { printf("Neispravan broj bodova\n"); return 0; }
			printf("II parcijalni ispit: ");
			scanf("%lf", &Bp2);
			if(Bp2<0||Bp2>20) { printf("Neispravan broj bodova\n"); return 0; }
			printf("Prisustvo:");
			scanf("%lf", &Bp);
			if(Bp<0||Bp>10) { printf("Neispravan broj bodova\n"); return 0; }
			printf(" Zadace:");
			scanf("%lf", &Bze);
			if(Bze<0||Bze>10) { printf("Neispravan broj bodova\n"); return 0; }
			printf(" Zavrsni ispit: ");
			scanf("%lf", &Bk);
			if(Bk<0||Bk>40)  { printf("Neispravan broj bodova\n"); return 0; }				
	
		printf("Unesite bodove za Mirzu:\n");
			printf("I parcijalni ispit: ");
			scanf("%lf", &Mp1);
			if(Mp1<0||Mp1>20) { printf("Neispravan broj bodova\n"); return 0; }
			printf("II parcijalni ispit: ");
			scanf("%lf", &Mp2);
			if(Mp2<0||Mp2>20)  { printf("Neispravan broj bodova\n"); return 0; }
			printf("Prisustvo:");
			scanf("%lf", &Mp);
			if(Mp<0||Mp>10) { printf(" Neispravan broj bodova\n"); return 0; }
			printf(" Zadace:");
			scanf("%lf", &Mze);
			if(Mze<0||Mze>10) { printf("Neispravan broj bodova\n"); return 0; }
			printf(" Zavrsni ispit: ");
			scanf("%lf", &Mk);
			if(Mk<0||Mk>40) { printf("Neispravan broj bodova\n"); return 0; }
		
else {
Pt=(Tp1+Tp2+Tp+Tze+Tk);
Pb=(Bp1+Bp2+Bp+Bze+Bk);
Pm=(Mp1+Mp2+Mp+Mze+Mk);
Ptn=(Tp1+Tp2+Tp+Tze+Tk)/10.0;
Pbn=(Bp1+Bp2+Bp+Bze+Bk)/10.0;
Pmn=(Mp1+Mp2+Mp+Mze+Mk)/10.0;
x=round(Ptn);
y=round(Pbn);
z=round(Pmn);
if(Pt<55 && Pb<55 && Pm<55) printf("Nijedan student nije polozio.\n");
if((Pt<55&&Pb<55&&Pm>=55)||(Pt<55&&Pb>=55&&Pm<55)||(Pt>=55&&Pb<55&&Pm<55))  
printf("Jedan student je polozio.\n");
if((Pt<55&&Pb>=55&&Pm>=55)||(Pt>=55&&Pb>=55&&Pm<55)||(Pt>=55 && Pb<55 && Pm>=55))
printf("Dva studenta su polozila.");
if(Pt>=55 && Pb>=55 && Pm>=55) {
printf("Sva tri studenta su polozila.\n");
if(x==y&&x==z&&y==z) { printf("Sva tri studenta imaju istu ocjenu.\n"); }
if(x!=y&&x!=z) { printf("Svaki student ima razlicitu ocjenu.\n"); }
if((x!=y&&y==z)||(x==y&&y!=z)||(x==z&&x!=y))
{ printf("Dva od tri studenta imaju istu ocjenu.\n"); }
}
return 0;
}
}
