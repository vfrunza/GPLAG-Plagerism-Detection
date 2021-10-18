#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KAPACITET 200

struct Vrijeme {
	int sati, minute, sekunde;
};

struct Cas {
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak, kraj;
};

int pretvori_u_sekunde(struct Vrijeme vrijeme) {
	/*Funkcija prima struct vrijeme i vraca broj sekundi*/
	int sek;
	sek=3600*vrijeme.sati+60*vrijeme.minute;/*+vrijeme.sekunde;*/
	return sek;
}

int ucitaj_datoteku(struct Cas *raspored) {
	int ucitano;
	FILE *ulaz=fopen("raspored.dat", "rb");
	if(!ulaz) return 0;
	
	ucitano=fread(raspored, sizeof(struct Cas), KAPACITET, ulaz);
	if(ferror(ulaz)) return 0;
	fclose(ulaz);
	return ucitano;
}

int zapisi_datoteku(struct Cas *raspored, int broj_casova) {
	FILE *izlaz=fopen("raspored.dat", "wb");
	if(!izlaz) return 0;
	
	fwrite(raspored, sizeof(struct Cas), broj_casova, izlaz);
	if(ferror(izlaz)) return 0;
	fclose(izlaz);
	return 1;
}

void ispisi_dan(struct Cas *raspored, int broj_casova, int dan) {
	int i, j=0;
	printf("Uneseni su casovi: \n");
	for(i=0; i<broj_casova; i++) {
		/*Idemo redom kroz niz casova i provjeravamo da li su u nasem danu, ako jesu ispisemo taj cas*/
		if(raspored[i].dan_u_sedmici==dan) {
			printf("%d) ", j+1);
			printf("%s ", raspored[i].predmet);
			printf("(%02d:%02d-%02d:%02d)\n", raspored[i].pocetak.sati, raspored[i].pocetak.minute, raspored[i].kraj.sati, raspored[i].kraj.minute);
			j++;
		}
	}
}

void promijeni_cas(struct Cas *raspored, int broj_casova, int dan, int redni_broj, struct Cas promjena) {
	int i, j=0;
	for(i=0; i<broj_casova; i++) {
		/*Idemo redom kroz casove i kada nadjemo cas ciji je redni broj u tom danu jednak onom koji funkcija prima kao argument,
			zamijenimo ga sa primljenim structom*/
		if(raspored[i].dan_u_sedmici==dan) {
			j++;
			if(j==redni_broj) {
				raspored[i]=promjena;
				return;
			}
		}
	}
}

void obrisi_cas(struct Cas *raspored, int broj_casova, int dan, int redni_broj) {
	int i, j=0;
	for(i=0; i<broj_casova; i++) {
		/*Nadjemo odg. cas sa rednim brojem koji funkcija prima i onda na njegovo mjesto u nizu stavimo zadnji cas i smanjimo velicinu niza*/
		if(raspored[i].dan_u_sedmici==dan) {
			j++;
			if(j==redni_broj) {
				raspored[i]=raspored[broj_casova-1];
				return;
			}
		}
	}
}

int da_li_su_isti(struct Cas cas1, struct Cas cas2) {
	/*Funkcija uporedjuje dva casa i vraca 1 ako su identicni*/
	if(cas1.dan_u_sedmici!=cas2.dan_u_sedmici) return 0;
	if(pretvori_u_sekunde(cas1.pocetak) != pretvori_u_sekunde(cas2.pocetak)) return 0;
	if(pretvori_u_sekunde(cas1.kraj) != pretvori_u_sekunde(cas2.kraj)) return 0;
	if(strcmp(cas1.predmet, cas2.predmet)!=0) return 0;
	return 1;
}

int preklapanje(struct Cas *raspored, int broj_casova, struct Cas cas) {
	int i, poc1, poc2, kraj1, kraj2;
	for(i=0; i<broj_casova; i++) {
		if(!da_li_su_isti(raspored[i], cas)) {
			/*Kada nadjemo cas koji je u istom danu kao i nas cas, uporedjujemo njihova vremena
				pocinjanja i zavrsetka da bismo utvrdili da li se preklapaju*/
			if(raspored[i].dan_u_sedmici==cas.dan_u_sedmici) {
				poc1=pretvori_u_sekunde(raspored[i].pocetak);
				kraj1=pretvori_u_sekunde(raspored[i].kraj);
				poc2=pretvori_u_sekunde(cas.pocetak);
				kraj2=pretvori_u_sekunde(cas.kraj);
				if(!((kraj2<=poc1 && poc2<poc1) || (kraj2>kraj1 && poc2>=kraj1))) return 1;
			}
		}
	}
	return 0;
}

void ispis_rasporeda(struct Cas *raspored, int broj_casova) {
	int i, sat, dan, min=100000, prvi_sat=25, zadnji_sat=-2, temp, temp2, prvi_predmet;
	char *dani[]={ "PON", "UTO", "SRI", "CET", "PET", "SUB" };
	printf("      ");
	for(i=0; i<6; i++) printf("%-10s", dani[i]);
	/*Naci cemo vrijeme pocinjanja prvog i zadnjeg casa*/
	for(i=0; i<broj_casova; i++) {
		temp=pretvori_u_sekunde(raspored[i].pocetak);
		temp2=pretvori_u_sekunde(raspored[i].kraj);
		if(temp<prvi_sat*3600) prvi_sat=temp/3600;
		if(temp2>(zadnji_sat+1)*3600) zadnji_sat=temp2/3600;
	}
	
	for(sat=prvi_sat; sat<=zadnji_sat; sat++) {
		printf("\n%d:00  ", sat);
		if(sat<10) printf(" ");
		/* Za svaki dan pojedinacno trazimo cas koji pocinje poslije 'i'-tog sata i ispisujemo prvi po redu od tog sata ako uopste postoji */
		for(dan=1; dan<7; dan++) {
			prvi_predmet=-1;
			min=100000;
			for(i=0; i<broj_casova; i++) {
				if(raspored[i].dan_u_sedmici==dan) {
					temp=pretvori_u_sekunde(raspored[i].pocetak);
					temp2=pretvori_u_sekunde(raspored[i].kraj);
					if(temp<=3600*sat && temp2>3600*sat) {
						prvi_predmet=i;
						break;
					}
					if(temp>=3600*sat && temp<3600*(sat+1)) {
						if(temp<min) {
							min=temp;
							prvi_predmet=i;
						}
					}
				}
			}
			if(prvi_predmet!=-1) printf("%-10s", raspored[prvi_predmet].predmet);
			else printf("          ");
		}
	}
}

void unesi(char *s) {
	/*Funkcija za unos stringa*/
	int i; char z=getchar();
	if(z=='\n') z=getchar();
	for(i=0; z!='\n'; i++) {
		if(i<9) {
			*s=z;
			s++;
		}
		z=getchar();
	}
	*s='\0';
}

int broj_casova_u_danu(struct Cas *raspored, int broj_casova, int dan) {
	int i, j=0;
	for(i=0; i<broj_casova; i++) {
		if(raspored[i].dan_u_sedmici==dan) j++;
	}
	return j;
}

void unos_vremena(struct Cas *cas) {
	int poc_h, kraj_h, poc_min, kraj_min;
	printf("Vrijeme pocetka: ");
	scanf("%d:%d", &poc_h, &poc_min);
	printf("Vrijeme zavrsetka: ");
	scanf("%d:%d", &kraj_h, &kraj_min);
	cas->pocetak.sati=poc_h;
	cas->pocetak.minute=poc_min;
	cas->kraj.sati=kraj_h;
	cas->kraj.minute=kraj_min;
	cas->pocetak.sekunde=0;
	cas->kraj.sekunde=0;
}

int dodaj_cas(struct Cas *raspored, int broj_casova, char *predmet, int trajanje_u_satima) {
	int pocetak, kraj, temp, temp2, i, dan, trajanje;
	struct Cas novi;
	trajanje=trajanje_u_satima*3600;
	if(trajanje>36000) return 0;
	
	for(dan=1; dan<7; dan++) {
		/*Idemo redom od dana 1 do 7. Pretpostavimo da ce nas cas pocinjati u 9:00 i onda provjeravamo da li se preklapa s nekim drugim.
		Ako se preklapa onda stavimo pocetak naseg casa na kraj tog casa s kojim se preklapao i nastavljamo da trazimo.
		Kada ponestane prostora u jednom danu prelazimo na drugi*/
		pocetak=32400; kraj=pocetak+trajanje;
		for(i=0; i<broj_casova; i++) {
			if(raspored[i].dan_u_sedmici==dan) {
				temp=pretvori_u_sekunde(raspored[i].pocetak);
				temp2=pretvori_u_sekunde(raspored[i].kraj);
				if(!((temp2<=pocetak) || (temp>=kraj))) {
					pocetak=temp2;
					if(pocetak>(19-trajanje_u_satima)*3600) break;
					kraj=pocetak+trajanje;
					i=0;
				}
			}
		}
		if(i==broj_casova) {
			for(i=0; i<9 && *predmet; i++) {
				novi.predmet[i]=*predmet;
				predmet++;
			}
			novi.predmet[i]='\0';
			
			novi.dan_u_sedmici=dan;
			novi.pocetak.sati=pocetak/3600;
			novi.pocetak.minute=(pocetak-novi.pocetak.sati*3600)/60;
			novi.pocetak.sekunde=pocetak-novi.pocetak.sati*3600-novi.pocetak.minute*60;
			novi.kraj.sati=kraj/3600;
			novi.kraj.minute=(kraj-novi.kraj.sati*3600)/60;
			novi.kraj.sekunde=kraj-novi.kraj.sati*3600-novi.kraj.minute*60;
			raspored[broj_casova]=novi;
			return 1;
		}
	}
	return 0;
}

int main() {
	struct Cas raspored[KAPACITET], zamjena;
	int unos, dan, redni_broj, trajanje, broj_casova, da_li_je_promijenjen=0;
	char ime_predmeta[10];
	broj_casova=ucitaj_datoteku(raspored);
	do {
		printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
		scanf("%d", &unos);
		
		if(unos==1) {
			printf("\n");
			ispis_rasporeda(raspored, broj_casova);
			printf("\n");
		}
		
		else if(unos==2) {
			printf("Unesite naziv predmeta: ");
			unesi(ime_predmeta);
			printf("Unesite broj casova: ");
			scanf("%d", &trajanje);
			if(dodaj_cas(raspored, broj_casova, ime_predmeta, trajanje)) broj_casova++;
			else printf("Nema dovoljno mjesta u rasporedu za %d casova.\n", trajanje);
		}
		
		else if(unos==3) {
			printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
			scanf("%d", &dan);
			ispisi_dan(raspored, broj_casova, dan);
			printf("Izaberite koji cas zelite promijeniti:  ");
			scanf("%d", &redni_broj);
			if(broj_casova_u_danu(raspored, broj_casova, dan)>redni_broj) printf("Neispravan redni broj casa.\n");
			else {
				while(!da_li_je_promijenjen) {
					zamjena.dan_u_sedmici=dan;
					printf("Naziv predmeta: ");
					unesi(zamjena.predmet);
					unos_vremena(&zamjena);
					if(preklapanje(raspored, broj_casova, zamjena)) printf("Promjena nije moguca jer dovodi do preklapanja\n");
					else {
						promijeni_cas(raspored, broj_casova, dan, redni_broj, zamjena);
						da_li_je_promijenjen=1;
					}
				}
				da_li_je_promijenjen=0;
			}
		}
		
		else if(unos==4) {
			printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
			scanf("%d", &dan);
			ispisi_dan(raspored, broj_casova, dan);
			printf("Izaberite koji cas zelite obrisati: ");
			scanf("%d", &redni_broj);
			if(broj_casova_u_danu(raspored, broj_casova, dan)>redni_broj) printf("Neispravan redni broj casa.\n");
			else {
				obrisi_cas(raspored, broj_casova, dan, redni_broj);
				if(broj_casova>0) broj_casova--;
				printf("Cas obrisan\n");
			}
			
		}
		
	} while(unos);
	zapisi_datoteku(raspored, broj_casova);
	
	return 0;
}
