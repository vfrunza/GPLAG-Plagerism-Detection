#include <stdio.h>
#include <math.h>
#define eps 0.000001


int main() {
	int ot,ob,om;
	float pt,dt,prt,zt,zit,sumat,pb,db,prb,zb,zib,sumab,pm,dm,prm,zm,zim,sumam;
	printf("Unesite bodove za Tarika:\nI parcijalni ispit: ");
	scanf("%f",&pt);
	if(pt>20 || pt<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&dt);
	if(dt>20 || dt<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&prt);
	if(prt>10 || prt<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&zt);
	if(zt>10 || zt<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&zit);
	if(zit>40 || zit<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	sumat=zit+zt+prt+pt+dt;
	if(sumat<55) ot=5;
	else if((sumat>55 && sumat<65) || fabs(sumat-55)<eps ) ot=6;
	else if((sumat>65 && sumat<75) || fabs(sumat-65)<eps) ot=7;
	else if((sumat>75 && sumat<85) || fabs(sumat-75)<eps) ot=8;
	else if((sumat>85 && sumat<95) || fabs(sumat-85)<eps) ot=9;
	else ot=10;
	
	printf("Unesite bodove za Bojana:\nI parcijalni ispit: ");
	scanf("%f",&pb);
	if(pb>20 || pb<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&db);
	if(db>20 || db<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&prb);
	if(prb>10 || prb<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&zb);
	if(zb>10 || zb<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&zib);
	if(zib>40 || zib<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	sumab=zib+zb+prb+pb+db;
	if(sumab<55) ob=5;
	else if((sumab>55 && sumab<65) || fabs(sumab-55)<eps ) ob=6;
	else if((sumab>65 && sumab<75) || fabs(sumab-65)<eps) ob=7;
	else if((sumab>75 && sumab<85) || fabs(sumab-75)<eps) ob=8;
	else if((sumab>85 && sumab<95) || fabs(sumab-85)<eps) ob=9;
	else ob=10;
	
		printf("Unesite bodove za Mirzu:\nI parcijalni ispit: ");
	scanf("%f",&pm);
	if(pm>20 || pm<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("II parcijalni ispit: ");
	scanf("%f",&dm);
	if(dm>20 || dm<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Prisustvo: ");
	scanf("%f",&prm);
	if(prm>10 || prm<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zadace: ");
	scanf("%f",&zm);
	if(zm>10 || zm<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	printf("Zavrsni ispit: ");
	scanf("%f",&zim);
	if(zim>40 || zim<0){
		printf("Neispravan broj bodova");
		return 0;
	}
	sumam=zim+zm+prm+pm+dm;
	if(sumam<55) om=5;
	else if((sumam>55 && sumam<65) || fabs(sumam-55)<eps ) om=6;
	else if((sumam>65 && sumam<75) || fabs(sumam-65)<eps) om=7;
	else if((sumam>75 && sumam<85) || fabs(sumam-75)<eps) om=8;
	else if((sumam>85 && sumam<95) || fabs(sumam-85)<eps) om=9;
	else om=10;
	
	if(ot==5 && ob==5 && om==5)
		printf("Nijedan student nije polozio.");
	else if((ot==5 && ob==5 && om!=5) || (ot==5 && om==5 && ob!=5) || (om==5 && ob==5 && ot!=5))
		printf("Jedan student je polozio.");
	else if(ot!=5 && ob!=5 && om!=5){
		printf("Sva tri studenta su polozila.\n");
		if(ot==ob && ob==om)
			printf("Sva tri studenta imaju istu ocijenu.");
		else if(ot!=ob && ob!=om && om!=ot)
			printf("Svaki student ima razlicitu ocjenu.");
		else
			printf("Dva od tri studenta imaju istu ocjenu.");
	}
	else 
		printf("Dva studenta su polozila.");
	return 0;
}
