#include <stdio.h>

int main() {
	double Ix,IIx,px,zx,zix,Iy,IIy,py,zy,ziy,Iz,IIz,pz,zz,ziz,tarik,bojan,mirza;
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&Ix);
	if(Ix>20 || Ix<0) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&IIx);
	if(IIx>20 || IIx<0) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&px);
	if(px>10 || px<0) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&zx);
	if(zx>10 || zx<0) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&zix);
	if(zix>40 || zix<0) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&Iy);
	if(Iy>20 || Iy<0) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&IIy);
	if(IIy>20 || IIy<0) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&py);
	if(py>10 || py<0) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&zy);
	if(zy>10 || zy<0) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&ziy);
	if(ziy>40 || ziy<0) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&Iz);
	if(Iz>20 || Iz<0) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&IIz);
	if(IIz>20 || IIz<0) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&pz);
	if(pz>10 || pz<0) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&zz);
	if(zz>10 || zz<0) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&ziz);
	if(ziz>40 || ziz<0) {
		printf("Neispravan broj bodova");
		return 0;
	}
	tarik=Ix+IIx+px+zx+zix;
	bojan=Iy+IIy+py+zy+ziy;
	mirza=Iz+IIz+pz+zz+ziz;
	if(mirza<55 && bojan<55 && tarik<55) {
		printf("Nijedan student nije polozio.\n");
		return 0;
	}
	
	else if((mirza>=55 && bojan<55 && tarik<55) || (bojan>=55 && tarik<55 && mirza<55) || (tarik>=55 && mirza<55 && bojan<55)) {
		printf("Jedan student je polozio.\n");
		return 0;
	}
	
	else if((mirza>=55 && bojan>=55 && tarik<55) || (bojan>=55 && tarik>=55 && mirza<55) || (tarik>=55 && mirza>=55 && bojan<55)) {
		printf("Dva studenta su polozila.\n");
		return 0;
	}
	
	else if(mirza>=55 && bojan>=55 && tarik>=55) {
		printf("Sva tri studenta su polozila.\n");
		if((mirza>=55 && mirza<65) && (bojan>=55 && bojan<65) && (tarik>=55 && tarik<65))
		printf("Sva tri studenta imaju istu ocjenu.");
		else if((mirza>=65 && mirza<75) && (bojan>=65 && bojan<75) && (tarik>=65 && tarik<75))
		printf("Sva tri studenta imaju istu ocjenu.");
		else if((mirza>=75 && mirza<85) && (bojan>=75 && bojan<85) && (tarik>=75 && tarik<85))
		printf("Sva tri studenta imaju istu ocjenu.");
		else if((mirza>=85 && mirza<92) && (bojan>=85 && bojan<92) && (tarik>=85 && tarik<92))
		printf("Sva tri studenta imaju istu ocjenu.");
		else if((mirza>=92 && mirza<=100) && (bojan>=92 && bojan<=100) && (tarik>=92 && tarik<=100))
		printf("Sva tri studenta imaju istu ocjenu.");
		else if((tarik>=55 && tarik<65)&&(bojan>=55 && bojan<65)&& mirza>=65||
		(mirza>=55 && mirza<65)&&(bojan>=55 && bojan<65)&& tarik>=65||
		(tarik>=55 && tarik<65)&&(mirza>=55 && mirza<65)&& bojan>=65)
		printf("Dva od tri studenta imaju istu ocjenu.");
		else if((tarik>=65 && tarik<75)&&(bojan>=65 && bojan<75)&&(mirza<65 || mirza>=75)||
		(mirza>=65 && mirza<75)&&(bojan>=65 && bojan<75)&&(tarik<65 || tarik>=75)||
		(tarik>=65 && tarik<75)&&(mirza>=65 && mirza<75)&&(bojan<65 || bojan>=75))
		printf("Dva od tri studenta imaju istu ocjenu.");
		else if((tarik>=75 && tarik<85)&&(bojan>=75 && bojan<85)&&(mirza<75 || mirza>=85)||
		(mirza>=75 && mirza<85)&&(bojan>=75 && bojan<85)&&(tarik<75 || tarik>=85)||
		(tarik>=75 && tarik<85)&&(mirza>=75 && mirza<85)&&(bojan<75 || bojan>=85))
		printf("Dva od tri studenta imaju istu ocjenu.");
		else if((tarik>=85 && tarik<92)&&(bojan>=85 && bojan<92)&&(mirza<85 || mirza>=92)||
		(mirza>=85 && mirza<92)&&(bojan>=85 && bojan<92)&&(tarik<85 || tarik>=92)||
		(tarik>=85 && tarik<92)&&(mirza>=85 && mirza<92)&&(bojan<85 || bojan>=92))
		printf("Dva od tri studenta imaju istu ocjenu.");
		else if((tarik>=92 && tarik<=100)&&(bojan>=92 && bojan<=100)&&(mirza<92 || mirza>100)||
		(mirza>=92 && mirza<=100)&&(bojan>=92 && bojan<=100)&&(tarik<92 || tarik>100)||
		(tarik>=92 && tarik<=100)&&(mirza>=92 && mirza<=100)&&(bojan<92 || bojan>100))
		printf("Dva od tri studenta imaju istu ocjenu.");
		else printf("Svaki student ima razlicitu ocjenu.");
	}
	return 0;
}
