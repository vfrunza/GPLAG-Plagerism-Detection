#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void unesi(char niz[], int velicina) {
	char znak=getchar(); 
	int i=0;
	if(znak=='\n') znak=getchar();
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

struct Datum {int dan, mjesec, godina;};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

struct Datum unesi_datum() {
	struct Datum d;
	scanf("%d%d%d", &d.dan, &d.mjesec, &d.godina);
	return d;
}


struct Uposlenik unesi_uposlenika() {
	struct Uposlenik u;
	printf("Ime i prezime: ");
	unesi(u.ime_prezime,50);
	printf("Datum rodjenja: ");
	u.datum_rodjenja=unesi_datum();
	return u;
}

int prestupna(int god) {
	if(god%4==0 && god%100!=0 || god%400==0)
	return 1;
	return 0;
}
 int ref_dani(struct Uposlenik k) {
 	int ukupno=0, i;
 	int bdum[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
 	
 	for(i=1; i<k.datum_rodjenja.godina; i++)
 	ukupno = ukupno + 365 + prestupna(i);
 	
 	if(prestupna(k.datum_rodjenja.godina))
 	bdum[2]++;
 	
 	for(i=1; i<k.datum_rodjenja.mjesec; i++)
 	ukupno = ukupno + bdum[i];
 	ukupno = ukupno + k.datum_rodjenja.dan;
 	return ukupno;
 }
 
 
int suzi_listu(struct Uposlenik* kandidati, int vel, struct Uposlenik direktor, int broj_dana) {
	
	struct Uposlenik* p=kandidati;
	int razlika, prestar=0,i,prezime=0,j;
	char* s;
	char* poc;
	
	for(i=0; i<vel; i++) {
		razlika=ref_dani(direktor)-ref_dani(p[i]);
		if(abs(razlika)>abs(broj_dana))
		prestar=1;
		
		s=direktor.ime_prezime;
		while(*s!='\0') s++;
		while(*s!=' ') s--;
		s++;
		
		poc=kandidati[i].ime_prezime;
		while(*poc!='\0') poc++;
		while(*poc!=' ') poc--;
		poc++;
		
		while(*s!='\0' && *poc!='\0') {
			if(*s++==*poc++);
			
			if(*s!='\0' || *poc!='\0')
			prezime=1;
		}
		
		if(prestar==1 && prezime==0) {
			for(j=i; j<vel-1; j++) {
				kandidati[j]=kandidati[j+1];
			}
			vel--;
			i--;
		}
		
	}
	return vel;
}

int main() {
	struct Uposlenik kandidati[100];
	struct Uposlenik direktor;
	int n,dani,i;
	printf("Unesite broj dana: ");
	scanf("%d",&dani);
	printf("Unesite broj kandidata: ");
	scanf("%d",&n);
	printf("Unesite podatke uposlenika: ");
	for(i=0; i<n; i++)
	kandidati[i]=unesi_uposlenika();
	printf("Unesite podatke direktora: ");
	direktor=unesi_uposlenika();
	
	printf("%d",suzi_listu(kandidati,n,direktor,dani));
	
	return 0;
}











