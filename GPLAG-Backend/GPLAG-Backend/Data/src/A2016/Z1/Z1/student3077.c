#include <stdio.h>

int main() {
	float Iparc1,Iparc2,Iparc3,IIparc1,IIparc2,IIparc3,z1,z2,z3,p1,p2,p3,zavrsni1,zavrsni2,zavrsni3,ukupno1,ukupno2,ukupno3; int o1,o2,o3;
	printf("Unesite bodove za Tarika: \nI parcijalni ispit: ");
	scanf("%f", &Iparc1);
	if(Iparc1<0 || Iparc1>20) {
		printf("Neispravan broj bodova");
		goto kraj;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &IIparc1);
		if(IIparc1<0 || IIparc1>20) {
		printf("Neispravan broj bodova");
		goto kraj; }
	printf("Prisustvo: ");
	scanf("%f", &p1);
	if(p1<0 || p1>10) {
		printf("Neispravan broj bodova");
		goto kraj;
	}
	printf("Zadace: ");
	scanf("%f", &z1);
	if(z1<0 || z1>10) {
		printf("Neispravan broj bodova");
		goto kraj;
	}
	printf("Zavrsni ispit: ");
	scanf("%f", &zavrsni1);
	if(zavrsni1<0 || zavrsni1>40) {
		printf("Neispravan broj bodova");
		goto kraj;
	}
	printf("Unesite bodove za Bojana: \nI parcijalni ispit: ");
	scanf("%f", &Iparc2);
		if(Iparc2<0 || Iparc2>20) {
		printf("Neispravan broj bodova");
		goto kraj;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &IIparc2);
		if(IIparc2<0 || IIparc2>20) {
		printf("Neispravan broj bodova");
		goto kraj;
	}
	printf("Prisustvo: ");
	scanf("%f", &p2);
	if(p2<0 || p2>10) {
		printf("Neispravan broj bodova");
		goto kraj; }
	printf("Zadace: ");
	scanf("%f", &z2);
	if(z2<0 || z2>10) {
		printf("Neispravan broj bodova");
		goto kraj; }
	printf("Zavrsni ispit: ");
	scanf("%f", &zavrsni2);
	if(zavrsni2<0 || zavrsni2>40) {
		printf("Neispravan broj bodova");
		goto kraj;}
	printf("Unesite bodove za Mirzu: \nI parcijalni ispit: ");
	scanf("%f", &Iparc3);
		if(Iparc3<0 || Iparc3>20) {
		printf("Neispravan broj bodova");
		goto kraj;
	}
	printf("II parcijalni ispit: ");
	scanf("%f", &IIparc3);
		if(IIparc3<0 || IIparc3>20) {
		printf("Neispravan broj bodova");
		goto kraj;
	}
	printf("Prisustvo: ");
	scanf("%f", &p3);
	if(p3<0 || p3>10) {
		printf("Neispravan broj bodova");
		goto kraj;}
	printf("Zadace: ");
	scanf("%f", &z3);
	if(z3<0 || z3>10) {
		printf("Neispravan broj bodova");
		goto kraj; }
	printf("Zavrsni ispit: ");
	scanf("%f", &zavrsni3);
	if(zavrsni3<0 || zavrsni3>40) {
		printf("Neispravan broj bodova");
		goto kraj;
	} 
	ukupno1=Iparc1+IIparc1+p1+z1+zavrsni1;
	ukupno2=Iparc2+IIparc2+p2+z2+zavrsni2;
	ukupno3=Iparc3+IIparc3+p3+z3+zavrsni3;
	if(ukupno1<54.99) o1=5;
	else if(ukupno1<65 ) o1=6;
	else if(ukupno1<75) o1=7;
	else if(ukupno1<85) o1=8;
	else if(ukupno1<95) o1=9;
	else if(ukupno1<=100) o1=10;
	if(ukupno2<54.99) o2=5;
	else if(ukupno2<65 ) o2=6;
	else if(ukupno2<75) o2=7;
	else if(ukupno2<85) o2=8;
	else if(ukupno2<95) o2=9;
	else if(ukupno2<=100) o2=10;
	if(ukupno3<54.99) o3=5;
	else if(ukupno3<65 ) o3=6;
	else if(ukupno3<75) o3=7;
	else if(ukupno3<85) o3=8;
	else if(ukupno3<95) o3=9;
	else if(ukupno3<=100) o3=10;
	if(o1==5 && o2==5 && o3==5) {
		printf("Nijedan student nije polozio."); goto kraj;
	} else if((o1>5 && o2==5 && o3==5)||(o1==5 && o2>5 && o3==5) || (o1==5 && o2==5 && o3>5)){
		printf("Jedan student je polozio."); goto kraj;
	} else if((o1>5 && o2>5 && o3==5)||(o1>5 && o2==5 && o3>5)||(o1==5 && o2>5 && o3>5)){
		printf("Dva studenta su polozila."); goto kraj;
	} else printf("Sva tri studenta su polozila.");
	if(o1==o2 && o2==o3 && o1==o3) {
		printf("\nSva tri studenta imaju istu ocjenu.");
	}else if(o1==o2 || o2==o3 || o1==o3) { 
		printf("\nDva od tri studenta imaju istu ocjenu.");
	} else printf("\nSvaki student ima razlicitu ocjenu.");
	
kraj:	
	return 0;
}
