#include <stdio.h>
#include <string.h>
#define KAPACITET 200
struct Vrijeme{
	int sati, minute, sekunde;
};
struct Cas{
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak, kraj;
};

int manjeod(const struct Vrijeme prvo,const struct Vrijeme drugo){
	// 0 - ako su jednaki, 1 - ako je prvi manji od drugog, -1 - ako je prvi veci od drugog
	if(prvo.sati == drugo.sati && prvo.minute == drugo.minute && prvo.sekunde == drugo.sekunde) return 0;
	
	if( prvo.sati < drugo.sati) return 1;
	else if( prvo.sati == drugo.sati && prvo.minute < drugo.minute) return 1;
	else if ( prvo.sati == drugo.sati && prvo.minute == drugo.minute && prvo.sekunde < drugo.sekunde) return 1;
	
	return -1;
}
int preklapanje(struct Cas raspored[], int broj_casova, struct Cas predmet){
	int i;
	for(i = 0; i < broj_casova; i++){
	//	printf("U funkciji preklapanje testiramo %s sa %s , vrijeme prvog %d - %d , vrijeme drugog %d - %d\n",raspored[i].predmet, predmet.predmet, raspored[i].pocetak.sati,raspored[i].kraj.sati, predmet.pocetak.sati,predmet.kraj.sati);
		if(predmet.dan_u_sedmici == raspored[i].dan_u_sedmici && 
		!(manjeod(raspored[i].kraj,predmet.pocetak ) == 1 ||
	 	  manjeod(raspored[i].kraj,predmet.pocetak ) == 0 ||
	 	  manjeod(predmet.kraj,raspored[i].pocetak ) == 1 ||
		  manjeod(predmet.kraj,raspored[i].pocetak ) == 0))
		{
			return 1;
		}
	}
	return 0;
}


int ucitaj_datoteku(struct Cas raspored[]){
int broj_casova;
FILE* upis = fopen("raspored.dat","rb");
fread(&broj_casova,sizeof(int),1,upis);
fread(raspored,sizeof(struct Cas),broj_casova,upis);
fclose(upis);

return broj_casova;	
}
int zapisi_datoteku(struct Cas raspored[],int broj_casova){
	FILE* ispis = fopen("raspored.dat","wb");
	if(ispis == NULL) return 0;
	if(broj_casova > 200) broj_casova = 200;
	fwrite(&broj_casova,sizeof(int),1,ispis);
	fwrite(raspored,sizeof(struct Cas),broj_casova,ispis);
	fclose(ispis);
	return 1;
}
int dodaj_cas(struct Cas raspored[],int broj_casova, const char* predmet, int trajanje){
	int i ,j ,k;
	struct Cas pr;
	strcpy(pr.predmet,predmet);
	pr.pocetak.sati = 0, pr.pocetak.minute = 0, pr.pocetak.sekunde = 0;
	pr.kraj.sati = 0, pr.kraj.minute = 0, pr.kraj.sekunde = 0;
	for(i = 1; i <= 6; i++){
		pr.dan_u_sedmici = i;
		for(j = 0; j <= 10 - trajanje; j++){
			pr.pocetak.sati = 9 + j;
			pr.kraj.sati = 9 + j + trajanje;
			k = preklapanje(raspored,broj_casova,pr);
			if(k == 0){
				strcpy(raspored[broj_casova].predmet,predmet);
				raspored[broj_casova].pocetak = pr.pocetak;
				raspored[broj_casova].kraj = pr.kraj;
				raspored[broj_casova].dan_u_sedmici = pr.dan_u_sedmici;
				
				return 1;
			}
		}
	}
	
	
	return 0;
}

int roundnadole(struct Vrijeme vr){
	if(vr.minute == 0 && vr.sekunde == 0) return vr.sati;
	 return vr.sati +1;
}

void ispis_rasporeda(struct Cas raspored[],int broj_casova){
	int minsat = 24,maxsat = 0, i, j, k;
	struct Vrijeme poc = {0,0,0},kraj = {0,0,0};
	for(i = 0; i < broj_casova; i++){
		if(raspored[i].pocetak.sati < minsat) minsat = raspored[i].pocetak.sati;
		if(roundnadole(raspored[i].kraj) > maxsat) maxsat = roundnadole(raspored[i].kraj);
	}
	printf("       ");
	printf("%-10s%-10s%-10s%-10s%-10s%-10s\n","PON","UTO","SRI","CET","PET","SUB");
	for(j = minsat; j < maxsat; j++)
	{
		poc.sati = j;
		kraj.sati = j +1;
		printf("%d:00  ",j);
		if( j < 10) printf(" ");
		for(i = 1; i <= 6; i++){
			int found = 0;
			for(k = 0;k < broj_casova; k++){
				if(!(manjeod(raspored[k].kraj,poc ) == 1 ||
	 				 manjeod(raspored[k].kraj,poc ) == 0 ||
				 	 manjeod(kraj,raspored[k].pocetak ) == 1 ||
					 manjeod(kraj,raspored[k].pocetak ) == 0) && 
				raspored[k].dan_u_sedmici == i){
					printf("%-10s",raspored[k].predmet);
					found = 1;
					
				}
			}
			if(found == 0) printf("          ");
		}
		
		printf("\n");
	}
}
void ispisi_dan(struct Cas raspored[],int broj_casova,int dan){
	int i, counter = 1;
	printf("Uneseni su casovi: \n");
	for(i = 0; i < broj_casova; i++){
		if(raspored[i].dan_u_sedmici == dan){
			printf("%d) %s (",counter,raspored[i].predmet);
			if(raspored[i].pocetak.sati < 10) printf("0");
			printf("%d:",raspored[i].pocetak.sati);
			if(raspored[i].pocetak.minute < 10) printf("0");
			printf("%d-",raspored[i].pocetak.minute);
			
			if(raspored[i].kraj.sati < 10) printf("0");
			printf("%d:",raspored[i].kraj.sati);
			if(raspored[i].kraj.minute < 10) printf("0");
			printf("%d)\n",raspored[i].kraj.minute);
			counter++;
		}
		
	}
}
void promijeni_cas(struct Cas raspored[],int broj_casova,int dan,int redni_broj,struct Cas promjena){
	int i, counter = 0, uspjeh;
	for(i = 0; i < broj_casova; i++){
		if(dan == raspored[i].dan_u_sedmici){
			counter++;
			if(counter == redni_broj){
				struct Vrijeme poc,kraj;
				poc = raspored[i].pocetak;
				kraj = raspored[i].kraj;
				raspored[i].pocetak.sati = 0;
				raspored[i].kraj.sati = 0;
				strcpy(raspored[i].predmet, promjena.predmet);
				raspored[i].pocetak = promjena.pocetak;
				raspored[i].kraj = promjena.kraj;
				return;
			}
		}
	}
}
int temp_promjeni(struct Cas raspored[],int broj_casova,int dan,int redni_broj, struct Cas promjena){
	//printf("U funkciji temp_promjeni dan je %d, a redni_broj je %d\n",dan,redni_broj);
	int i, counter = 0, uspjeh;
	for(i = 0; i < broj_casova; i++){
		if(dan == raspored[i].dan_u_sedmici){
			counter++;
			if(counter == redni_broj){
			//	printf("U funkciji temp_promjeni mijenjamo predmet %s\n",raspored[i].predmet);
				struct Vrijeme poc,kraj;
				poc = raspored[i].pocetak;
				kraj = raspored[i].kraj;
				raspored[i].pocetak.sati = 0;
				raspored[i].kraj.sati = 0;
				promjena.dan_u_sedmici = dan;
				uspjeh = preklapanje(raspored,broj_casova,promjena);
				raspored[i].pocetak = poc;
				raspored[i].kraj = kraj;
				return uspjeh;
			}
		}
	}
	return -1;
}
void obrisi_cas(struct Cas raspored[],int broj_casova,int dan,int redni_broj){
	int i, counter = 0;
	for(i = 0; i < broj_casova; i++){
		if(dan == raspored[i].dan_u_sedmici){
			counter++;
			if(counter == redni_broj && i != broj_casova -1){
				raspored[i] = raspored[broj_casova - 1];
				return;
			}
		}
	}
}
void unosnaziva(char* pok){
	int i = 0;
	char c;
	while(1){
		c = getchar();
		if(c == '\n' && i==0) c = getchar();
		if(c == '\n') break;
		if(i < 9){
			pok[i] = c;
			i++;
		}
	}
	pok[i] = '\0';
}

int main() {
	
	struct Cas raspored[KAPACITET];
	char predmet[10];
	int izbor, broj_casova = 0, trajanje, uspjeh, dan, promjena;
	struct Cas pomocni = {"X",0,{0,0,0},{0,0,0}};
	while(1){
		printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
		scanf("%d",&izbor);
		if(izbor == 1){
			printf("\n");
			ispis_rasporeda(raspored,broj_casova);
		} else if (izbor == 2) {
			
			printf("Unesite naziv predmeta: ");
			unosnaziva(predmet);
			printf("Unesite broj casova: ");
			scanf("%d", &trajanje);
			uspjeh = dodaj_cas(raspored, broj_casova, predmet, trajanje);
			broj_casova += uspjeh;
			if(uspjeh == 0){
				printf("Nema dovoljno mjesta u rasporedu za %d casova.\n",trajanje);
			}
			
		} else if (izbor == 3){
			while(1){
				printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
				scanf("%d", &dan);
				ispisi_dan(raspored,broj_casova,dan);
				printf("Izaberite koji cas zelite promijeniti: ");
				scanf("%d",&promjena);
				printf("Naziv predmeta: ");
				unosnaziva(pomocni.predmet);
				printf("Vrijeme pocetka: ");
				scanf("%d:%d",&pomocni.pocetak.sati,&pomocni.pocetak.minute);
				printf("Vrijeme zavrsetka: ");
				scanf("%d:%d",&pomocni.kraj.sati,&pomocni.kraj.minute);
			//	printf("Funkcija temp_promjeni pozvana sa dan: %d, promjena: %d, pocetak %d:%d , kraj %d:%d\n",dan,promjena,pomocni.pocetak.sati,pomocni.pocetak.minute, pomocni.kraj.sati,pomocni.kraj.minute);
				uspjeh = temp_promjeni(raspored,broj_casova,dan,promjena,pomocni);
			//	printf("temp_promjeni daje %d\n",uspjeh);
				if(uspjeh == 0){
					promijeni_cas(raspored,broj_casova,dan,promjena,pomocni);
					break;
				} else {
					printf("Promjena nije moguca jer dovodi do preklapanja\n");
				}
			}			
			
		} else if (izbor == 4) {
			printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
			scanf("%d", &dan);
			ispisi_dan(raspored,broj_casova,dan);
			printf("Izaberite koji cas zelite obrisati: ");
			scanf("%d",&promjena);
			obrisi_cas(raspored,broj_casova,dan,promjena);
			printf("Cas obrisan\n");
			broj_casova--;
			
		} else if (izbor == 0) {
			zapisi_datoteku(raspored,broj_casova);
			break;
		}
	}
	

	return 0;
}
