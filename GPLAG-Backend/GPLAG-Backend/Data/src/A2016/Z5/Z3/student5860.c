#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>
#include <string.h>



#define KAPACITET           200

#define datoteka            "C:\\Users\\damir\\Desktop\\New folder (2)\\raspored.dat"

#define VRIJEME_MAKSIMALNO				23

#define VRIJEME_MAKSIMALNO_MIN			59

#define VRIJEME_MAKSIMALNO_SEC			59






#define PRVO_VRIJEME     9
 
#define ZAVRSNO_VRIJEME     18
 
#define KRAJ_VREMENA      19

char* SEDMICA[6] = {"PON", "UTO", "SRI", "CET", "PET", "SUB"};

int PomocnaVarijabla = -1;





struct Vrijeme {

    int sati, minute, sekunde;

};



struct Cas {

    char predmet[10];

    int dan_u_sedmici;

    struct Vrijeme pocetak, kraj;

};






bool TacnoVrijeme(int sat, int minut, int sekund) {

	if(	sat <= VRIJEME_MAKSIMALNO && sat >= 0 &&  minut <= VRIJEME_MAKSIMALNO_MIN && minut >= 0 &&	sekund <= VRIJEME_MAKSIMALNO_SEC && sekund >= 0)

			return true;

	else

		return false;

}





void ispisi_red(struct Cas raspored[], int broj_casova, int sat) {

	int n=0;
	int dan=0;

	bool postavljen;

	struct Cas ObjekatCasa;

	for(dan = 1; dan <= 6; dan++) {

		strcpy(ObjekatCasa.predmet , "");

		postavljen = false;

		

		for(n = 0; n < broj_casova; n++) {

			if(raspored[n].dan_u_sedmici == dan && raspored[n].pocetak.sati <= sat) {

				if (!postavljen) 

					if(raspored[n].pocetak.sati == sat) {

						ObjekatCasa = raspored[n];

						postavljen;

					}

				else {

					if((raspored[n].pocetak.sati != raspored[n].kraj.sati && raspored[n].kraj.sati > sat && raspored[n].pocetak.sati <= sat)||

						 (raspored[n].kraj.minute == 0  && raspored[n].pocetak.sati == ObjekatCasa.pocetak.sati) ||

						(raspored[n].pocetak.minute < ObjekatCasa.pocetak.minute && raspored[n].pocetak.sati == ObjekatCasa.pocetak.sati  ) ||

						(raspored[n].kraj.minute > 0 && raspored[n].kraj.minute <= ObjekatCasa.pocetak.minute && raspored[n].pocetak.sati <= sat) ||
						(raspored[n].pocetak.minute < ObjekatCasa.pocetak.minute && raspored[n].kraj.sati >= ObjekatCasa.kraj.sati && raspored[n].pocetak.sati <= ObjekatCasa.pocetak.sati) 

						)

							ObjekatCasa = raspored[n];

				}

			}

		}

		printf("%-10s", ObjekatCasa.predmet);

	}

}




int ucitaj_datoteku(struct Cas raspored[]) {
	
	FILE *FajlOtvoren;
    int i = 0;

    

    if((FajlOtvoren = fopen(datoteka, "r+")) == NULL) {

       

        exit(1);

    }

    int VarijablaJedan=0;

    while ((VarijablaJedan = fscanf(FajlOtvoren, "%9s %d %d %d %d %d %d %d\n",   &raspored[i].predmet, &raspored[i].dan_u_sedmici,

        &raspored[i].pocetak.sati, &raspored[i].pocetak.minute, &raspored[i].pocetak.sekunde,

        &raspored[i].kraj.sati, &raspored[i].kraj.minute, &raspored[i].kraj.sekunde)) != EOF) {

        

		if(i >= KAPACITET)

            break;

            

        if(VarijablaJedan == 8)

        	if(
        		raspored[i].pocetak.sati <= raspored[i].kraj.sati && 
        		
        	raspored[i].pocetak.sati <= ZAVRSNO_VRIJEME	 &&

	        	raspored[i].dan_u_sedmici >= 1 &&

	        	raspored[i].pocetak.sati >= PRVO_VRIJEME && 
	        	
	        	raspored[i].dan_u_sedmici <= 6 &&

	        	raspored[i].kraj.sati >= PRVO_VRIJEME && 
	        	TacnoVrijeme(raspored[i].kraj.sati, raspored[i].kraj.minute, raspored[i].kraj.sekunde) &&

				TacnoVrijeme(raspored[i].pocetak.sati, raspored[i].pocetak.minute, raspored[i].pocetak.sekunde) &&

				raspored[i].kraj.sati <= KRAJ_VREMENA
				
				) 

        			i++;

    }

    return i;

}





int zapisi_datoteku(struct Cas raspored[], int broj_casova) {

	FILE *FajlOtvoren = fopen(datoteka, "ab+");

	if (FajlOtvoren == NULL)

	{

	    

	    exit(1);

	}

	int i;

	int Sacuvano = 0;

	for(i = 0; i < broj_casova; i++) {

		fprintf(FajlOtvoren, "%-9s %d %d %d %d %d %d %d\n", raspored[i].predmet, raspored[i].dan_u_sedmici,

    	raspored[i].pocetak.sati, raspored[i].pocetak.minute, raspored[i].pocetak.sekunde,

        raspored[i].kraj.sati, raspored[i].kraj.minute, raspored[i].kraj.sekunde);

        fprintf(FajlOtvoren, "\n");

        Sacuvano++;

	}



	fclose(FajlOtvoren);

}





int dodaj_cas(struct Cas raspored[], int broj_casova,

    const char* predmet, int trajanje) {

	int dan;
	int j;
	int i;

	int vrijeme;

	



	bool NijeSlobodno[7][20];

	for(i = PRVO_VRIJEME; i <= KRAJ_VREMENA; i++) 

		for(j = 1; j <= 6; j++) 

			NijeSlobodno[j][i] = false;	

			



	for(i = 0; i < broj_casova; i++) {

		if(raspored[i].predmet != "") {

			NijeSlobodno[raspored[i].dan_u_sedmici][raspored[i].pocetak.sati] = true;

			

			if(raspored[i].kraj.sati > raspored[i].pocetak.sati) {

				int j;

				for(j = raspored[i].pocetak.sati; j < raspored[i].kraj.sati; j++) 

					NijeSlobodno[raspored[i].dan_u_sedmici][j] = true;

				if(raspored[i].kraj.minute > 0) 

					NijeSlobodno[raspored[i].dan_u_sedmici][raspored[i].kraj.sati] = true;	

			}

			else {

				if(raspored[i].kraj.minute > 0) 

					NijeSlobodno[raspored[i].dan_u_sedmici][raspored[i].kraj.sati] = true;

			}

		}

	}

	



	for(dan = 1; dan <= 6; dan++) {

		int Udaljenos = 0;

		vrijeme = PRVO_VRIJEME;

		while(vrijeme <= ZAVRSNO_VRIJEME)

		{

			Udaljenos = 0;

			while(!NijeSlobodno[dan][vrijeme] && vrijeme-trajanje <= ZAVRSNO_VRIJEME) {

				Udaljenos++;

				vrijeme++;

				if(Udaljenos == trajanje && vrijeme-trajanje <= ZAVRSNO_VRIJEME) {

					if(broj_casova+1 < KAPACITET) {

						

						struct Cas VrijemeN;

						strcpy(VrijemeN.predmet, predmet);

						VrijemeN.dan_u_sedmici = dan;

						VrijemeN.pocetak.sati = vrijeme-trajanje; VrijemeN.pocetak.minute = 0; VrijemeN.pocetak.sekunde = 0;

						VrijemeN.kraj.sati = vrijeme; VrijemeN.kraj.minute = 0; VrijemeN.kraj.sekunde = 0;

				

						raspored[broj_casova] = VrijemeN;

						return 1;

					}

					else {

					

						return 0;

					}

				}

			}

			vrijeme++;

		}

	}

	return 0;

}





int preklapanje(struct Cas raspored[], int broj_casova,

    struct Cas cas) {

	int i;

	int dan = cas.dan_u_sedmici;

	for(i = 0; i < broj_casova; i++) {

		if(raspored[i].dan_u_sedmici == dan) {

		

			if(!(((cas.kraj.sati < raspored[i].pocetak.sati) || ((cas.kraj.sati == raspored[i].pocetak.sati) && (cas.kraj.minute <= raspored[i].pocetak.minute))) ||

			((raspored[i].kraj.sati < cas.pocetak.sati) || ((cas.pocetak.sati == raspored[i].kraj.sati) && (cas.pocetak.minute >= raspored[i].kraj.minute)))))

			{

				PomocnaVarijabla = i;

				return 1;

			}

		}

	}

	return 0;    	

}





void ispis_rasporeda(struct Cas raspored[], int broj_casova) {

	

	int i;

	printf("%-7s", "");

	for(i = 1; i <= 5; i++) {

		printf("%-10s", SEDMICA[i-1]);

	}
	printf("%s", SEDMICA[5]);
	printf("\n");

	



	int sati;

	for(sati = PRVO_VRIJEME; sati <= ZAVRSNO_VRIJEME; sati++) {

		if(sati == PRVO_VRIJEME) 

			printf("%d:00   ", sati);

		else

			printf("%d:00  ", sati);

			

		ispisi_red(raspored, broj_casova, sati);

		printf("\n");

	}

	printf("\n");

}





void ispisi_dan(struct Cas raspored[], int broj_casova, int dan) {

	int i;

	int NekaVarijabla = 0;

	printf("Uneseni su casovi:\n");

	for(i = 0; i < broj_casova; i++)

		if(raspored[i].dan_u_sedmici == dan)  {

			NekaVarijabla++;

			printf("%d) %s (%02d:%02d-%02d:%02d)\n", NekaVarijabla, raspored[i].predmet, raspored[i].pocetak.sati, raspored[i].pocetak.minute, raspored[i].kraj.sati, raspored[i].kraj.minute);

		}

}




void promijeni_cas(struct Cas raspored[], int broj_casova, int dan,

    int redni_broj, struct Cas promjena) {

    int i = 0;

	

	bool NalaziSe = false;
 int pozicija = 0;
	for(i = 0; i < broj_casova; i++) {

		if(raspored[i].dan_u_sedmici == dan) {

			pozicija++;

			if(pozicija == redni_broj) {

				NalaziSe = true;

				if(preklapanje(raspored, broj_casova, promjena) == 0) {

					raspored[i] = promjena;

					

				}

				else if(PomocnaVarijabla == i) {

					raspored[i] = promjena;

					

				}

				

				break;

			} 

		} 	

	}

	if(!NalaziSe) {

		printf("Neispravan redni broj casa.\n");

	}

}





void obrisi_cas(struct Cas raspored[], int broj_casova, int dan,

    int redni_broj) {
	bool NalaziSe = false;
    

	int pozicija = 0;

	int i = 0;

	for(i = 0; i < broj_casova; i++) {

		if(raspored[i].dan_u_sedmici == dan) {

			pozicija++;

			if(pozicija == redni_broj) {

				int j;

				for(j = i; j < broj_casova-1; j++)

					raspored[j]=raspored[j+1];

				NalaziSe = true;

			

				PomocnaVarijabla = 1;

				break;

			} 

		} 	

	}

	if(!NalaziSe) {

		printf("Neispravan redni broj casa.\n");

	}	

}




void NapraviTabelu(struct Cas raspored[], int broj_casova) {
 int dan;
	int IzabranaVrijednost;

	int cas;

	

	printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");

	scanf("%d", &IzabranaVrijednost);

	

	if(IzabranaVrijednost == 1) {

		ispis_rasporeda(raspored, broj_casova);

		NapraviTabelu(raspored, broj_casova);

	}

	else if(IzabranaVrijednost == 2) {

		char naziv[10];

		int Udaljenos;

		printf("Unesite naziv predmeta: "); scanf("%9s", &naziv);

		printf("Unesite broj casova: "); scanf("%d", &Udaljenos);

		if(naziv == "" || Udaljenos > 10 || Udaljenos < 1  ) {


			NapraviTabelu(raspored, broj_casova);

		}

		else {

			int dodano = dodaj_cas(raspored, broj_casova, naziv, Udaljenos);

			if(dodano == 1) broj_casova++;

			else printf("Nema dovoljno mjesta u rasporedu za %d casova.", Udaljenos);

			ispis_rasporeda(raspored, broj_casova);

			NapraviTabelu(raspored, broj_casova);

		}

	}

	else if(IzabranaVrijednost == 3) {

	
		
		int ZadnjimM = 0;
		int ZavrsniH = 0;
		int PocetnoM = 0;
		
		int PocetnoH = 0;
		char naziv[10];
		

		printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): "); scanf("%d", &dan);

		if(dan >= 1 && dan <= 6) {

			ispisi_dan(raspored, broj_casova, dan);

		}

		else {

	

			NapraviTabelu(raspored, broj_casova);	

		}

		printf("Izaberite koji cas zelite promijeniti: "); scanf("%d", &cas);

		printf("Naziv predmeta: "); scanf("%s", &naziv);

		printf("Vrijeme pocetka: "); scanf("%d : %d", &PocetnoH, &PocetnoM);

		printf("Vrijeme zavrsetka: "); scanf("%d : %d", &ZavrsniH, &ZadnjimM);

		if(PocetnoH >= PRVO_VRIJEME && PocetnoH <= ZAVRSNO_VRIJEME && 

			TacnoVrijeme(PocetnoH, PocetnoM, 0) && TacnoVrijeme(ZavrsniH, ZadnjimM, 0) && naziv != "" && 

			ZavrsniH >= PRVO_VRIJEME && ZavrsniH <= KRAJ_VREMENA) 

		{

			struct Cas VrijemeN;

			

			strcpy(VrijemeN.predmet, naziv);

			VrijemeN.dan_u_sedmici = dan;

			VrijemeN.pocetak.sati = PocetnoH; VrijemeN.pocetak.minute = PocetnoM; VrijemeN.pocetak.sekunde = 0;

			VrijemeN.kraj.sati = ZavrsniH; VrijemeN.kraj.minute = ZadnjimM; VrijemeN.kraj.sekunde = 0;

			

			promijeni_cas(raspored, broj_casova, dan, cas, VrijemeN);	

			NapraviTabelu(raspored, broj_casova);

		}

		else {

			printf("Neispravan redni broj casa.\n");

			NapraviTabelu(raspored, broj_casova);

		}	

	}

	else if(IzabranaVrijednost == 4) {

		printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): "); scanf("%d", &dan);

		if(dan <= 6  && dan >= 1 ) {

			ispisi_dan(raspored, broj_casova, dan);

		}

		else {

			printf("Pogresan unos.\n");

			NapraviTabelu(raspored, broj_casova);	

		}



		printf("Izaberite koji cas zelite obrisati: "); scanf("%d", &cas);

		PomocnaVarijabla = 0;

		obrisi_cas(raspored, broj_casova, dan, cas);

		if(PomocnaVarijabla == 1) broj_casova--;

		NapraviTabelu(raspored, broj_casova);

	}

	else if(IzabranaVrijednost == 0) {

		zapisi_datoteku(raspored, broj_casova);

		exit(0);

	}

	else {

		printf("Pogresan unos.");

		exit(1);

	}

}





int main() {



    exit(0);

}