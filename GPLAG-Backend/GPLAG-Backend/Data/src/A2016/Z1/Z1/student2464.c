#include <stdio.h>

int main() {
	float IpTarik, IIpTarik, PrTarik, ZadTarik, ZITarik;
	float IpBojan, IIpBojan, PrBojan, ZadBojan, ZIBojan;
	float IpMirza, IIpMirza, PrMirza, ZadMirza, ZIMirza;
	float Tarikbod, Bojanbod, Mirzabod;
	int Tarikocjena, Bojanocjena, Mirzaocjena, brpolozio;
	
	printf ("Unesite bodove za Tarika: \n");
	printf ("I parcijalni ispit: ");
	scanf ("%f", &IpTarik);
		if(IpTarik<0 || IpTarik>20) {
			printf("Neispravan broj bodova");
			return 0;
		}
	printf ("II parcijalni ispit: ");
	scanf ("%f", &IIpTarik);
		if(IIpTarik<0 || IIpTarik>20) {
			printf("Neispravan broj bodova");
			return 0;
		}
	printf ("Prisustvo: ");
	scanf ("%f", &PrTarik);
		if(PrTarik<0 || PrTarik>10) {
			printf("Neispravan broj bodova");
			return 0;
		}
	printf ("Zadace: ");
	scanf ("%f", &ZadTarik);
		if (ZadTarik<0 || ZadTarik>10) {
			printf ("Neispravan broj bodova");
			return 0;
		}
	printf ("Zavrsni ispit: ");
	scanf ("%f", &ZITarik);
		if (ZITarik<0 || ZITarik>40) {
			printf ("Neispravan broj bodova");
			return 0;
		}
		
	printf ("Unesite bodove za Bojana: \n");
	printf ("I parcijalni ispit: ");
	scanf ("%f", &IpBojan);
		if (IpBojan<0 || IpBojan>20) {
			printf ("Neispravan broj bodova");
			return 0;
		}
	printf ("II parcijalni ispit: ");
	scanf ("%f", &IIpBojan);
		if (IIpBojan<0 || IIpBojan>20) {
			printf ("Neispravan broj bodova");
			return 0;
		}
	printf ("Prisustvo: ");
	scanf ("%f", &PrBojan);
		if (PrBojan<0 || PrBojan>10) {
			printf ("Neispravan broj bodova");
			return 0;
		}
	printf ("Zadace: ");
	scanf ("%f", &ZadBojan);
		if (ZadBojan<0 || ZadBojan>10) {
			printf ("Neispravan broj bodova");
			return 0;
		}
	printf ("Zavrsni ispit: ");
	scanf ("%f", &ZIBojan);
		if (ZIBojan<0 || ZIBojan>40) {
			printf ("Neispravan broj bodova");
			return 0;
		}
		
	printf ("Unesite bodove za Mirzu: \n");
	printf ("I parcijalni ispit: ");
	scanf ("%f", &IpMirza);
		if (IpMirza<0 || IpMirza>20) {
			printf ("Neispravan broj bodova");
			return 0;
		}
	printf ("II parcijalni ispit: ");
	scanf ("%f", &IIpMirza);
		if (IIpMirza<0 || IIpMirza>20) {
			printf ("Neispravan broj bodova");
			return 0;
		}
	printf ("Prisustvo: ");
	scanf ("%f", &PrMirza);
		if (PrMirza<0 || PrMirza>10) {
			printf ("Neispravan broj bodova");
			return 0;
		}
	printf ("Zadace: ");
	scanf ("%f", &ZadMirza);
		if (ZadMirza<0 || ZadMirza>10) {
			printf ("Neispravan broj bodova");
			return 0;
		}
	printf ("Zavrsni ispit: ");
	scanf ("%f", &ZIMirza);
		if (ZIMirza<0 || ZIMirza>40) {
			printf ("Neispravan broj bodova");
			return 0;
		}
		
	Tarikbod = IpTarik + IIpTarik + PrTarik + ZadTarik + ZITarik;
	Bojanbod = IpBojan + IIpBojan + PrBojan + ZadBojan + ZIBojan;
	Mirzabod = IpMirza + IIpMirza + PrMirza + ZadMirza + ZIMirza;
	
	if (Tarikbod<55) Tarikocjena=5;
	else if (Tarikbod>=55 && Tarikbod<65) Tarikocjena=6;
	else if (Tarikbod>=65 && Tarikbod<75) Tarikocjena=7;
	else if (Tarikbod>=75 && Tarikbod<85) Tarikocjena=8;
	else if (Tarikbod>=85 && Tarikbod<92) Tarikocjena=9;
	else Tarikocjena=10;
	
	if (Bojanbod<55) Bojanocjena=5;
	else if (Bojanbod>=55 && Bojanbod<65) Bojanocjena=6;
	else if (Bojanbod>=65 && Bojanbod<75) Bojanocjena=7;
	else if (Bojanbod>=75 && Bojanbod<85) Bojanocjena=8;
	else if (Bojanbod>=85 && Bojanbod<92) Bojanocjena=9;
	else Bojanocjena=10;
	
	if (Mirzabod<55) Mirzaocjena=5;
	else if (Mirzabod>=55 && Mirzabod<65) Mirzaocjena=6;
	else if (Mirzabod>=65 && Mirzabod<75) Mirzaocjena=7;
	else if (Mirzabod>=75 && Mirzabod<85) Mirzaocjena=8;
	else if (Mirzabod>=85 && Mirzabod<92) Mirzaocjena=9;
	else Mirzaocjena=10;
	
	brpolozio=0;
	if (Tarikocjena>5) brpolozio++;
	if (Bojanocjena>5) brpolozio++;
	if (Mirzaocjena>5) brpolozio++;
	
	if (brpolozio==0) printf ("Nijedan student nije polozio.");
	if (brpolozio==1) printf ("Jedan student je polozio.");
	if (brpolozio==2) printf ("Dva studenta su polozila.");
	if (brpolozio==3) {
		printf ("Sva tri studenta su polozila.\n");
		if (Mirzaocjena==Tarikocjena && Tarikocjena==Bojanocjena) printf ("Sva tri studenta imaju istu ocjenu.");
		else if (Tarikocjena!=Bojanocjena && Mirzaocjena!=Tarikocjena && Bojanocjena!=Mirzaocjena) printf ("Svaki student ima razlicitu ocjenu.");
		else printf ("Dva od tri studenta imaju istu ocjenu.");
	}
		return 0;
}