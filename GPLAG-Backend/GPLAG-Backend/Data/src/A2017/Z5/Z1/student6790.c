#include <stdio.h>

struct Datum {
	int dan,mjesec,godina;
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

struct Uposlenik unos_uposlenika() {
	struct Uposlenik u;
	struct Datum dat;
	printf("\nIme i prezime: "); 
	scanf("%s",&u.ime_prezime);
	printf("\nDatum rodjenja: "); 
	scanf("%s %s %s",&u.datum_rodjenja.dan,&u.datum_rodjenja.mjesec,&u.datum_rodjenja.godina);
	
	return u;
}

int pretvori_u_dane(struct Datum d){
	int x=0,y=0,br_dana;
	
	if(d.mjesec!=12) {
		switch(d.mjesec+1) {
			case  2: x+=28;
			case  3: x+=31;
			case  4: x+=30;
			case  5: x+=31;
			case  6: x+=30;
			case  7: x+=31;
			case  8: x+=31;
			case  9: x+=30;
			case 10: x+=31;
			case 11: x+=30;
			case 12: x+=31;
		}
	}
	else {
		x=31-d.dan;
	}
	
	if(d.mjesec!=12) {
		switch(d.mjesec) {
			case  1: y=31-d.dan; break;
			case  2: y=28-d.dan; break;
			case  3: y=31-d.dan; break;
			case  4: y=30-d.dan; break;
			case  5: y=31-d.dan; break;
			case  6: y=30-d.dan; break;
			case  7: y=31-d.dan; break;
			case  8: y=31-d.dan; break;
			case  9: y=30-d.dan; break;
			case 10: y=31-d.dan; break;
			default: y=30-d.dan; break;
		}
	}
	br_dana=365*(d.godina-1)+(d.godina/4)+(365-x-y);
	
	return br_dana;
}

int poredi_godine(struct Uposlenik direktor, struct Uposlenik kanidat,int x) {
	int dan_direktor, dan_kandidat;
	dan_direktor=pretvori_u_dane(direktor.datum_rodjenja);
	dan_kandidat=pretvori_u_dane(kanidat.datum_rodjenja);
	
	if(dan_direktor+x>dan_kandidat) return 1;
	return 0;
}

int suzi_listu(struct Uposlenik* kandidati,int vel,struct Uposlenik direktor,int broj_dana) {
	int i,j,x;
	
	
	for(i=0;i<vel;i++) {
		x=poredi_godine(direktor,kandidati[i],broj_dana);
		printf("%d ",x);
	}
	
	
	return 1;
}

int main() {
	struct Uposlenik direktor;
	struct Uposlenik kandidati[100];
	int broj_kandidata,i,stariji_od, broj_kandidata_za_izbaciti;
	
	printf("Unesite broj kandidata: ");
	scanf("%d",&broj_kandidata);
	
	printf("Izbaci kandidate starije od: ");
	scanf("%d",&stariji_od);
	
	printf("Direktor: ");
	direktor=unos_uposlenika();
	
	printf("Unesite listu kandidata: ");
	for(i=0;i<broj_kandidata;i++) {
		kandidati[i]=unos_uposlenika();
	}
	
	
	broj_kandidata_za_izbaciti = suzi_listu(kandidati,broj_kandidata,direktor,stariji_od); 
	
	return 0;
}
