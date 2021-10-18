#include <stdio.h>
#include <math.h>
#define eps 0.00000001

int main() {
	double ppt, dpt, pt, zt, zit, ppb, dpb, pb, zb, zib, ppm, dpm, pm, zm, zim, tarik, mirza, bojan;
	printf ("Unesite bodove za Tarika:\n");
	printf ("I parcijalni ispit: ");
	scanf ("%lf", &ppt); 
	if(ppt<0 || ppt>20) { printf ("Neispravan broj bodova "); return 0; }
	printf ("II parcijalni ispit: ");
	scanf ("%lf", &dpt);
	if (dpt<0 || dpt>20) { printf ("Neispravan broj bodova "); return 0; }
	printf ("Prisustvo: ");
	scanf ("%lf", &pt);
	if (pt<0 || pt>10) { printf ("Neispravan broj bodova "); return 0; }
	printf ("Zadace: ");
	scanf ("%lf", &zt);
	if (zt<0 || zt>10) { printf ("Neispravan broj bodova "); return 0;	}
	printf ("Zavrsni ispit: ");
	scanf ("%lf", &zit);
	if (zit<0 || zit>40) { printf ("Neispravan broj bodova "); return 0; }
	printf ("Unesite bodove za Bojana:\n");
	printf ("I parcijalni ispit: ");
	scanf ("%lf", &ppb);
	if (ppb<0 || ppb>20) { printf ("Neispravan broj bodova "); return 0; }
	printf ("II parcijalni ispit: ");
	scanf ("%lf", &dpb);
	if (dpb<0 || dpb>20) { printf ("Neispravan broj bodova "); return 0; }
	printf ("Prisustvo: ");
	scanf ("%lf", &pb);
	if (pb<0 || pb>10) { printf ("Neispravan broj bodova "); return 0; } 
	printf ("Zadace: ");
	scanf ("%lf", &zb);
	if (zb<0 || zb>10) { printf ("Neispravan broj bodova "); return 0; }
	printf ("Zavrsni ispit: ");
	scanf ("%lf", &zib);
	if (zib<0 || zib>40) { printf ("Neispravan broj bodova "); return 0; }
	printf ("Unesite bodove za Mirzu:\n");
	printf ("I parcijalni ispit: ");
	scanf ("%lf", &ppm);
	if (ppm<0 || ppm>20) { printf ("Neispravan broj bodova "); return 0; }
	printf ("II parcijalni ispit: ");
	scanf ("%lf", &dpm);
	if (dpm<0 || dpm>20) { printf ("Neispravan broj bodova "); return 0; }
	printf ("Prisustvo: ");
	scanf ("%lf", &pm);
	if (pm<0 || pm>10) { printf ("Neispravan broj bodova "); return 0; } 
	printf ("Zadace: ");
	scanf ("%lf", &zm);
	if (zb<0 || zb>10) { printf ("Neispravan broj bodova "); return 0; }
	printf ("Zavrsni ispit: ");
	scanf ("%lf", &zim);
	if (zim<0 || zim>40) { printf ("Neispravan broj bodova "); return 0; }
	
	mirza=ppm+dpm+zm+pm+zim;
	tarik=ppt+dpt+zt+zit+pt;
	bojan=ppb+dpb+zb+pb+zib;
	
	if (mirza-55+eps<0 && tarik-55+eps<0 && bojan-55+eps<0) {
		printf ("Nijedan student nije polozio.");
		return 0;
	}
	else if ((fabs(mirza-55)>eps && tarik-55<eps && bojan-55<eps) || (mirza-55<eps && fabs(tarik-55)>eps && bojan-55<eps) || (mirza-55<eps && tarik-55<eps && fabs(bojan-55)>eps)) {
		printf ("Jedan student je polozio.");
		return 0;
	}
	else if ((fabs(mirza-55)>eps && fabs(tarik-55)>eps && bojan<55) || (fabs(mirza-55)>eps && tarik<55 && fabs(bojan-55)>eps) || (mirza<55 && fabs(tarik-55)>eps && fabs(bojan-55)>eps)) {
		printf ("Dva studenta su polozila.");
		return  0;
	}
	else if (fabs(mirza-55)>eps && fabs(tarik-55)>eps && fabs(bojan-55)>eps)  {
		printf ("Sva tri studenta su polozila.");
	}
	if (((mirza>=55 && mirza<65) && (bojan>=55 && bojan<65) && (tarik>=55 && tarik<65)) || ((mirza>=65 && mirza<75) && (tarik>=65 && tarik<75) && (bojan>=65 && bojan<75)) || ((mirza>=75 && mirza<85) && (bojan>=75 && bojan<85) && (tarik>=75 && tarik<85)) || ((tarik>=85 && tarik<92) && (bojan>=85 && bojan<92) && (mirza>=85 && mirza<92)) || ((tarik>=92 && tarik<=100) && (mirza>=92 && mirza<=100) && (bojan>=92 && bojan<=100))  ) {
		printf ("\nSva tri studenta imaju istu ocjenu.");
	}
	else if (((mirza>=55 && mirza<65) && (bojan>=55 && bojan<65) && (tarik<55 || tarik>=65)) || ((mirza>=55 && mirza<65) && (tarik>=55 && tarik<65) && (bojan<55 || bojan>65)) || ((tarik>=55 && tarik<65) && (bojan>=55 && bojan<65) && (mirza<55 || mirza>65)) || ((mirza>=65 && mirza<75) && (tarik>=65 && mirza<75) && (bojan<65 || bojan>=75)) || ((mirza>=65 && mirza<75) && (bojan>=65 && bojan<75) && (tarik<65 || tarik>=75)) || ((bojan>=65 && bojan<75) && (tarik>=65 && tarik<75) && (mirza<65 || mirza>=75)) || ((mirza>=75 && mirza<85) && (tarik>=75 && tarik<85) && (bojan<75 || bojan>=85)) || ((mirza>=75 && mirza<85) && (bojan>=75 && bojan<85) && (tarik<75 || tarik>=85)) || ((bojan>=75 && bojan<85) && (tarik>=75 && tarik<85) && (mirza<75 || mirza>=85)) || ((mirza>=85 && mirza<92) && (tarik>=85 && tarik<92) && (bojan<85 && bojan>=92)) || ((mirza>=85 && mirza<92) && (bojan>=85 && bojan <92) && (tarik<85 && tarik>=92)) || ((tarik>=85 && tarik<92) && (bojan>=85 && bojan<92) && (mirza<85 && mirza>=92)) || ((mirza>=92 && mirza<=100) && (tarik>=92 && tarik<=100) && (bojan<92)) || ((mirza>=92 && mirza<=100) && (bojan>=92 && bojan<=100) && (tarik<92)) || ((tarik>=92 && tarik<=100) && (bojan>=92 && bojan<=100) && (mirza<92))) {
		printf ("\nDva od tri studenta imaju istu ocjenu.");
	}
	else  {
		printf ("\nSvaki student ima razlicitu ocjenu.");
	}
	return 0;
}
