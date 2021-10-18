#include <stdio.h>
#define k 0.01

int main() {

	float  ipm, iipm, pm, dzm, zim, ipb, iipb, pb, dzb, zib, ipt, iipt, pt, dzt, zit, om, ob, ot;
	

	/*Tarik*/

printf("Unesite bodove za Tarika: \n");
printf("I parcijalni ispit: ");
scanf("%f,", &ipt);
if (ipt<0 || ipt> 40) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("II parcijalni ispit: ");
scanf("%f,", &iipt);
if (iipt<0 || iipt> 40) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Prisustvo: ");
scanf("%f,", &pt);
if (pt<0 || pt> 10) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zadace: ");
scanf("%f,", &dzt);
if (dzt<0 || dzt> 10) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zavrsni ispit: ");
scanf("%f,", &zit);
if (zit<0 || zit> 40) {
	printf("Neispravan broj bodova");
	return 0;
}

/*Bojan*/
	
printf("Unesite bodove za Bojana: \n");
printf("I parcijalni ispit: ");
scanf("%f,", &ipb);
if (ipb<0 || ipb> 20) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("II parcijalni ispit: ");
scanf("%f,", &iipb);
if (iipb<0 || iipb> 20) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Prisustvo: ");
scanf("%f,", &pb);
if (pb<0 || pb> 10) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zadace: ");
scanf("%f,", &dzb);
if (dzb<0 || dzb> 10) {
	printf("Neispravan broj bodova");
	return 0;
}
printf("Zavrsni ispit: ");
scanf("%f,",&zib);
if (zib<0 || zib> 40) {
	printf("Neispravan broj bodova");
	return 0;
}
/* Mirza*/
printf("Unesite bodove za Mirzu:  \n");
printf("I parcijalni ispit: ");
scanf("%f,", &ipm);
if (ipm<0 || ipm> 20) {
	printf("Neispravan broj bodova");
	return 0;
}

printf("II parcijalni ispit: ");
scanf("%f,", &iipm);

if (iipm<0 || iipm> 20) {
	printf("Neispravan broj bodova");
	return 0;
}
	
printf("Prisustvo: ");
scanf("%f,", &pm);

if (pm<0 || pm> 10) {
	printf("Neispravan broj bodova");
	return 0;
}
	
	
printf("Zadace: ");
scanf("%f,", &dzm);

if (dzm<0 || dzm>10) {
	printf("Neispravan broj bodova");
	return 0;
}
	
	
printf("Zavrsni ispit: ");
scanf("%f,", &zim);

if (zim<0 || zim> 40) {
	printf("Neispravan broj bodova");
	return 0;
}
 /*Za Mirzu ocjena*/
 
om=ipm+iipm+pm+dzm+zim+k;


/*Za Bojana ocjena*/
 
ob=ipb+iipb+pb+dzb+zib+k;


/*Za Tarika ocjena*/
 
ot=ipt+iipt+pt+dzt+zit+k;

	/* Koliko studenata je položilo*/

if (ot<55){
	if(ob<55){
		if(om<55){
			printf("Nijedan student nije polozio.\n");}
	}
}

if (ot<55) {
	if(ob <55){
		if(om>=55){
			printf("Jedan student je polozio.\n");}
	}
}

if (ot <55){
	if(ob >= 55){
		if(om < 55){
			printf("Jedan student je polozio.\n");}
	}
}

if (ot<55){
	if(ob >= 55){
		if(om >=55){
			printf("Dva studenta su polozila.\n");}
	}
}
if (ot >= 55){
	if(ob < 55){
		if(om < 55){
			printf("Jedan student je polozio.\n");}
	}
}
if (ot >= 55){
	if(ob < 55){
		if(om >= 55){
			printf("Dva studenta su polozila.\n");}
	}
}
if (ot >= 55){
	if(ob >= 55){
		if(om < 55){
			printf("Dva studenta su polozila.\n");}
	}
}
if (ot> 55){
	if(ob > 55){
		if(om > 55){
			printf("Sva tri studenta su polozila.\n");
if(((ot!=ob) && (ob!=om)) && (ot!=om)){
		printf("Svaki student ima razlicitu ocjenu.\n");
	}
	if((ot!=ob) && (ob==om)){
		printf("Dva od tri studenta imaju istu ocjenu.\n");
	}
	if((ot==ob) && (ob!=om)){
		printf("Dva od tri studenta imaju istu ocjenu.\n");
	}
	if((ot!=om) && (om==ob)){
		printf("Dva od tri studenta imaju istu ocjenu.\n");
	}
	if((ot==ob) && (ob==om)){
		printf("Sva tri studenta imaju istu ocjenu.\n");
	}
	}
	}
}



	return 0;
}
