#include <stdio.h>



int main() {
	
	
	double ppt,dpt,pt,zt,zit,ubt;
	double ppb,dpb,pb,zb,zib,ubb;
	double ppm,dpm,pm,zm,zim,ubm;
	int ot,ob,om,po=0;
	
	printf("Unesite bodove za Tarika: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&ppt);
	if(ppt<0 || ppt >20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&dpt);
	if(dpt<0 || dpt>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&pt);
	if (pt<0 || pt>10) {
		printf("Neispravan broj bodova");
		return 0; 
	}
	printf("Zadace: ");
	scanf("%lf",&zt);
	if (zt<0 || zt >10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&zit);
	if (zit<0 || zit>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Unesite bodove za Bojana: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&ppb);
	if (ppb<0 || ppb>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&dpb);
	if(dpb<0 || dpb>20){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&pb);
	if (pb<0 || pb >10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&zb);
	if (zb<0 || zb>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&zib);
	if(zib<0 || zib>40){
		printf("Neispravan broj bodova");
		return 0;
	}
	
	printf("Unesite bodove za Mirzu: \n");
	printf("I parcijalni ispit: ");
	scanf("%lf",&ppm);
	if (ppm<0 || ppm >20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%lf",&dpm);
	if (dpm<0||dpm>20) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%lf",&pm);
	if (pm<0 || pm>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%lf",&zm);
	if (zm<0||zm>10) {
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%lf",&zim);
	if (zim<0||zim>40) {
		printf("Neispravan broj bodova");
		return 0;
	}
	
	ubt=ppt+dpt+pt+zt+zit;
	ubb=ppb+dpb+pb+zb+zib;
	ubm=ppm+dpm+pm+zm+zim;
	
	if (ubt>=55 && ubt<65)
		ot=6; 
	else if (ubt >=65 && ubt<75)
		ot=7;
	else if (ubt >=75 && ubt<85)
		ot=8;
	else if (ubt >=85 && ubt<92)
		ot=9;
	else if (ubt >=92 && ubt<=100)
		ot=10;
	else ot=5;
	
	if (ubb>=55 && ubb<65) 
		ob=6;
	else if (ubb>=65 && ubb<75)
		ob=7;
	else if (ubb>=75 && ubb<85)
		ob=8;
	else if (ubb>=85 && ubb<92)
		ob=9;
	else if (ubb>=92 && ubb<=100)
		ob=10;
	else ob=5;
	
	if (ubm>=55 && ubm<65)
		om=6;
	else if (ubm>=65 && ubm<75)
		om=7;
	else if (ubm>=75 && ubm<85)
		om=8;
	else if (ubm>=85 && ubm<92)
		om=9;
	else if (ubm>=92 && ubm<=100)
		om=10;
	else om=5;
	
	if(ot>5)
		po++;
	if(ob>5)
		po++;
	if(om>5)
		po++;
		
	
	
	switch(po){
		case 0:
			printf("Nijedan student nije polozio.");
			break;
		case 1:
			printf("Jedan student je polozio.");
			break;
		case 2:
			printf("Dva studenta su polozila.");
			break;
		case 3:
			printf("Sva tri studenta su polozila.\n");
			if(ot==ob && ob==om)
				printf("Sva tri studenta imaju istu ocjenu.");
			else if(ot==ob || ob==om || om==ot)
				printf("Dva od tri studenta imaju istu ocjenu.");
			else 
				printf("Svaki student ima razlicitu ocjenu.");
			break;
	}
	
	return 0;
}
