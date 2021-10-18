#include <stdio.h>

int main() {
	double tp1, tp2, tp, tz, tzi, bp1, bp2, bp, bz, bzi, mp1, mp2, mp, mz, mzi, t, m, b;
	int it, im, ib, s=0, iit, iim, iib, s1=0;
	printf("Unesite bodove za Tarika:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &tp1);
	if(tp1>20 || tp1<0) {printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &tp2);
	if(tp2>20 || tp2<0) {printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf", &tp);
	if(tp>10 || tp<0) {printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf", &tz);
	if(tz>10 || tz<0) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &tzi);
	if(tzi>40 || tzi<0) {printf("Neispravan broj bodova"); return 0;}
	printf("Unesite bodove za Bojana:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &bp1);
	if(bp1>20 || bp1<0) {printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &bp2);
	if(bp2>20 || bp2<0) {printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf", &bp);
	if(bp>10 || bp<0) {printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf", &bz);
	if(bz>10 || bz<0) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &bzi);
	if(bzi>40 || bzi<0) {printf("Neispravan broj bodova"); return 0;}
	printf("Unesite bodove za Mirzu:\n");
	printf("I parcijalni ispit: ");
	scanf("%lf", &mp1);
	if(mp1>20 || mp1<0) {printf("Neispravan broj bodova"); return 0;}
	printf("II parcijalni ispit: ");
	scanf("%lf", &mp2);
	if(mp2>20 || mp2<0) {printf("Neispravan broj bodova"); return 0;}
	printf("Prisustvo: ");
	scanf("%lf", &mp);
	if(mp>10 || mp<0) {printf("Neispravan broj bodova"); return 0;}
	printf("Zadace: ");
	scanf("%lf", &mz);
	if(mz>10 || mz<0) {printf("Neispravan broj bodova"); return 0;}
	printf("Zavrsni ispit: ");
	scanf("%lf", &mzi);
	if(mzi>40 || mzi<0) {printf("Neispravan broj bodova"); return 0;}
	t=tp1+tp2+tp+tz+tzi;
	m=mp1+mp2+mp+mz+mzi;
	b=bp1+bp2+bp+bz+bzi;
	if(t<55) it=0;
	if(t>=55 && t<65) it=6;
	if(t>=65 && t<75) it=7;
	if(t>=75 && t<85) it=8;
	if(t>=85 && t<92) it=9;
	if(t>=92 && t<=100) it=10;
	if(b<55) ib=0;
	if(b>=55 && b<65) ib=6;
	if(b>=65 && b<75) ib=7;
	if(b>=75 && b<85) ib=8;
	if(b>=85 && b<92) ib=9;
	if(b>=92 && b<=100) ib=10;
	if(m<55) im=0;
	if(m>=55 && m<65) im=6;
	if(m>=65 && m<75) im=7;
	if(m>=75 && m<85) im=8;
	if(m>=85 && m<92) im=9;
	if(m>=92 && m<=100) im=10;
	if(it==0 && im==0 && ib==0) printf("Nijedan student nije polozio.");
	s=it+ib+im;
	if(s>5 && s<12) printf("Jedan student je polozio.");
	if(it!=0 && ib!=0 && im!=0) {printf("Sva tri studenta su polozila.");
	if((it!=ib)&&(it!=im)&&(im!=ib)) printf("\nSvaki student ima razlicitu ocjenu.");
	if((it!=0 && ib!=0 && im!=0)&&((it==ib)&&(it==im)&&(ib==im))) printf("\nSva tri studenta imaju istu ocjenu.");
	  else if(it==ib) printf("\nDva od tri studenta imaju istu ocjenu.");
	  else if(it==im) printf("\nDva od tri studenta imaju istu ocjenu.");
	  else if(im==ib) printf("\nDva od tri studenta imaju istu ocjenu.");
	  }
	if(it!=0) iit=1; else iit=0;
	if(ib!=0) iib=1; else iib=0;
	if(im!=0) iim=1; else iim=0;
	s1=iit+iib+iim;
	if(s1==2) printf("Dva studenta su polozila.");
	return 0;
}
