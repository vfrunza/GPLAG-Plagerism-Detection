#include <stdio.h>
#define EPS 0.01
#include <math.h>

int main() {
double p1t, p2t, prt, zt, zit, p1b, p2b, prb, zb, zib, p1m, p2m, prm, zm, zim, bt, bb, bm;
double ot=0., ob=0., om=0.;
	printf("Unesite bodove za Tarika:\n");
		printf("I parcijalni ispit: ");
		scanf("%lf", &p1t);
			if (p1t<0||p1t>20) printf("Neispravan broj bodova"); else{
		printf("II parcijalni ispit: ");
		scanf("%lf", &p2t);
			if (p2t<0||p2t>20) printf("Neispravan broj bodova"); else{
		printf("Prisustvo: ");
		scanf("%lf", &prt);
			if (prt<0||prt>10) printf("Neispravan broj bodova"); else{
		printf("Zadace: ");
		scanf("%lf", &zt);
			if (zt<0||zt>10) printf("Neispravan broj bodova"); else{
		printf("Zavrsni ispit: ");
		scanf("%lf", &zit);
			if (zit<0||zit>40) printf("Neispravan broj bodova"); else{
	printf("Unesite bodove za Bojana:\n");
		printf("I parcijalni ispit: ");
		scanf("%lf", &p1b);
			if (p1b<0||p1b>20) printf("Neispravan broj bodova"); else{
		printf("II parcijalni ispit: ");
		scanf("%lf", &p2b);
			if (p2b<0||p2b>20) printf("Neispravan broj bodova"); else{
		printf("Prisustvo: ");
		scanf("%lf", &prb);
			if (prb<0||prb>10) printf("Neispravan broj bodova"); else{
		printf("Zadace: ");
		scanf("%lf", &zb);
			if (zb<0||zb>10) printf("Neispravan broj bodova"); else{
		printf("Zavrsni ispit: ");
		scanf("%lf", &zib);
			if (zib<0||zib>40) printf("Neispravan broj bodova"); else{
	printf("Unesite bodove za Mirzu:\n");
		printf("I parcijalni ispit: ");
		scanf("%lf", &p1m);
			if (p1m<0||p1m>20) printf("Neispravan broj bodova"); else{
		printf("II parcijalni ispit: ");
		scanf("%lf", &p2m);
			if (p2m<0||p2m>20) printf("Neispravan broj bodova"); else{
		printf("Prisustvo: ");
		scanf("%lf", &prm);
			if (prm<0||prm>10) printf("Neispravan broj bodova"); else{
		printf("Zadace: ");
		scanf("%lf", &zm);
			if (zm<0||zm>10) printf("Neispravan broj bodova"); else{
		printf("Zavrsni ispit: ");
		scanf("%lf", &zim);
			if (zim<0||zim>40) printf("Neispravan broj bodova"); else{
    bb=p1b+p2b+prb+zb+zib;
	bm=p1m+p2m+prm+zm+zim;
	bt=p1t+p2t+prt+zt+zit;
	
if (bb<55) ob=5;
	else if(bb>=55 && bb<65) ob=6;
	else if(bb>=65 && bb<75) ob=7;
	else if(bb>=75 && bb<85) ob=8;
	else if(bb>=85 && bb<92) ob=9;
	else if(bb>=92 && bb<100) ob=100;
if (bt<55) ot=5;
	else if(bt>=55 && bt<65) ot=6;
	else if(bt>=65 && bt<75) ot=7;
	else if(bt>=75 && bt<85) ot=8;
	else if(bt>=85 && bt<92) ot=9;
	else if(bt>=92 && bt<100) ot=100;
if (bm<55) om=5;
	else if(bm>=55 && bm<65) om=6;
	else if(bm>=65 && bm<75) om=7;
	else if(bm>=75 && bm<85) om=8;
	else if(bm>=85 && bm<92) om=9;
	else if(bm>=92 && bm<100) om=100;
if (fabs(ob-5)<EPS && fabs(om-5)<EPS && fabs(ot-5)<EPS) printf("Nijedan student nije polozio.");
else if (ob>5 && fabs(om-5)<EPS && fabs(ot-5)<EPS) printf("Jedan student je polozio.");
else if (fabs(ob-5)<EPS && om>5 && fabs(ot-5)<EPS) printf("Jedan student je polozio.");
else if (fabs(ob-5)<EPS && fabs(om-5)<EPS && ot>5) printf("Jedan student je polozio.");
else if (ob>5 && om>5 && fabs(ot-5)<EPS) printf("Dva studenta su polozila.");
else if (ob>5 && fabs(om-5)<EPS && ot>5) printf("Dva studenta su polozila.");
else if (fabs(ob-5)<EPS && om>5 && ot>5) printf("Dva studenta su polozila.");
else 
	{if (ob>5 && om>5 && ot>5) printf("Sva tri studenta su polozila.\n");
	if (fabs(ob-om)<EPS && fabs(om-ot)<EPS && fabs(ot-om)<EPS) printf("Sva tri studenta imaju istu ocjenu.");
	else if (fabs(ob-om)<EPS && fabs(ob-ot)>EPS) printf("Dva od tri studenta imaju istu ocjenu.");
	else if (fabs(ob-om)>EPS && fabs(ob-ot)<EPS) printf("Dva od tri studenta imaju istu ocjenu.");
	else if (fabs(ot-om)<EPS && fabs(ob-ot)>EPS) printf("Dva od tri studenta imaju istu ocjenu.");
	else if (fabs(ob-om)>EPS && fabs(ob-ot)>EPS && fabs(ot-om)>EPS) printf("Svaki student ima razlicitu ocjenu.");}
			}}}}}}}}}}}}}}}

return 0;
}
