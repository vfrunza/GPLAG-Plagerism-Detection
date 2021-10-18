#include <stdio.h>
#include <string.h>
#define KAPACITET 200

struct Vrijeme {
	int sati,minute,sekunde;
};

struct Cas {
	char predmet[10];
	int dan_u_sedmici;
	struct Vrijeme pocetak,kraj;
};

int ucitaj_datoteku(struct Cas raspored[]){
	FILE *ulaz=fopen("raspored.dat","rb");
	if(!ulaz){
		return 0;
	}
	int br=fread(raspored,sizeof (struct Cas),KAPACITET,ulaz);
	fclose(ulaz);
	return br;
}

void ispis_rasporeda(struct Cas raspored[],int broj_casova){
	int i,j,zadnji=0,k,prvi=9;
	char razmak=' ';
	for(i=0; i<broj_casova; i++){
		if(raspored[i].kraj.sati>=zadnji){
			if(raspored[i].kraj.minute > 0)
				zadnji=raspored[i].kraj.sati+1;
			else zadnji=raspored[i].kraj.sati;
		}
		if(raspored[i].pocetak.sati<prvi)
			prvi=raspored[i].pocetak.sati;
	}
	printf("\n%7cPON%7cUTO%7cSRI%7cCET%7cPET%7cSUB\n",razmak,razmak,razmak,razmak,razmak,razmak);
	for(i=prvi; i<zadnji; i++){
			if(i<10)
				printf("%d:00   ",i);
			else
				printf("%d:00  ",i);
			for(j=0; j<6; j++){
				for(k=0; k<broj_casova; k++){
					if(raspored[k].dan_u_sedmici!=j+1) continue;
					if(raspored[k].pocetak.sati<=i && raspored[k].kraj.sati>i){
						printf("%-10s",raspored[k].predmet);
						break;
					}
					else if(raspored[k].kraj.sati==i){
							if (raspored[k].kraj.minute>0)
							printf("%-10s",raspored[k].predmet);
							break;
						}
				}
				if(k==broj_casova)
					printf("%10c",razmak);
			}
			printf("\n");
		}
}

void ispisi_dan(struct Cas raspored[], int broj_casova, int dan){
	int i,k=1;
	printf("Uneseni su casovi: \n");
	for(i=0; i<broj_casova; i++)
		if(raspored[i].dan_u_sedmici==dan){
			printf("%d) %s (",k++,raspored[i].predmet);
			if(raspored[i].pocetak.sati<10)
				printf("0%d:",raspored[i].pocetak.sati);
			else printf("%d:",raspored[i].pocetak.sati);
			if(raspored[i].pocetak.minute<10)
				printf("0%d-",raspored[i].pocetak.minute);
			else printf("%d-",raspored[i].pocetak.minute);
			if(raspored[i].kraj.sati<10)
				printf("%0d:",raspored[i].kraj.sati);
			else printf("%d:",raspored[i].kraj.sati);
			if(raspored[i].kraj.minute<10)
				printf("0%d)\n",raspored[i].kraj.minute);
			else
				printf("%d)\n",raspored[i].kraj.minute);
		}
}

void obrisi_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj){
	int i,k;
	for(i=0; i<broj_casova; i++){
		if (raspored[i].dan_u_sedmici==dan) redni_broj--;
		if (redni_broj==0){
			for(k=i; k<broj_casova-1;k++)
				raspored[k]=raspored[k+1];
			return;
		}
	}
}

int preklapanje(struct Cas raspored[], int broj_casova, struct Cas cas){
	int poc=cas.pocetak.sati*60+cas.pocetak.minute,kraj=cas.kraj.sati*60+cas.kraj.minute,i;
	for(i=0; i<broj_casova; i++){
		if(cas.dan_u_sedmici!=raspored[i].dan_u_sedmici) continue;
		int pom1=raspored[i].pocetak.sati*60+raspored[i].pocetak.minute,pom2=raspored[i].kraj.sati*60+raspored[i].kraj.minute;
		if ((poc<pom1 && kraj>pom1) || (poc<pom2 && kraj>pom2) || (poc<=pom1 && kraj>=pom2) || (pom1<=poc && pom2>=kraj)) return 1;
	}
	return 0;
}

/*int uklop(struct Cas raspored[], int broj_casova, struct Cas cas){
	int poc=cas.pocetak.sati*60,kraj=cas.kraj.sati*60,i;
	for (i=0; i<broj_casova; i++){
		if (cas.dan_u_sedmici!=raspored[i].dan_u_sedmici) continue;
		int pom1=raspored[i].pocetak.sati*60+raspored[i].pocetak.minute,pom2=raspored[i].kraj.sati*60+raspored[i].kraj.minute;
		if ((poc<pom1 && kraj>pom1) || (poc<pom2 && kraj>pom2) || (poc<=pom1 && kraj>=pom2) || (pom1<=poc && pom2>=kraj)) return 1;
	}
	return 0;
}*/

int dodaj_cas(struct Cas raspored[], int broj_casova, const char *predmet, int trajanje){
	int i,k;
	struct Cas cas;
	strcpy(cas.predmet,predmet);
	for (i=1; i<7; i++)
		for(k=9; k<=19-trajanje;k++){
			cas.dan_u_sedmici=i;
			cas.pocetak.sati=k;
			cas.kraj.sati=k+trajanje;
			cas.pocetak.minute=cas.kraj.minute=0;
			if (preklapanje(raspored,broj_casova,cas)==0){
				raspored[broj_casova]=cas;
				return 1;
			}
		}
	
	return 0;			
}

void promijeni_cas(struct Cas raspored[], int broj_casova, int dan, int redni_broj, struct Cas promjena){
	int i;
	for(i=0; i<broj_casova; i++){
		if(raspored[i].dan_u_sedmici==dan) redni_broj--;
		if(redni_broj==0){
			raspored[i]=promjena;
			return;
		}
	}
}

int zapisi_datoteku(struct Cas raspored[], int broj_casova){
	FILE *ulaz=fopen("raspored.dat","wb");
	if(!ulaz)
		return 0;
	int br=fwrite(raspored,sizeof (struct Cas), broj_casova,ulaz);
	fclose(ulaz);
	if (br) return 1;
	return 0;
}

int main() {
	int n,broj_casova=0;
	struct Cas raspored[KAPACITET];
	ucitaj_datoteku(raspored);
	do {
		printf("1) Ispis rasporeda\n2) Dodavanje casa\n3) Promjena casa\n4) Brisanje casa\n0) Kraj rada\nIzaberite opciju: ");
		scanf("%d",&n);
		switch (n){
			case 0: {
				zapisi_datoteku(raspored,broj_casova);
				break;
			}
			case 1: 
				ispis_rasporeda(raspored,broj_casova);
				break;
			case 2:{
				int i=0,trajanje;
				char naziv[10];
				printf("Unesite naziv predmeta: ");
				char c=getchar();
				c=getchar();
				do {
					if (i<9)
						naziv[i++]=c;
					c=getchar();
				} while (c!='\n');
				naziv[i]='\0';
				printf("Unesite broj casova: ");
				scanf("%d",&trajanje);
				if(dodaj_cas(raspored,broj_casova,naziv,trajanje))
					broj_casova++;
				else
					printf("Nema dovoljno mjesta u rasporedu za %d casova.\n",trajanje);;
				break;
			}
			case 3:{
				struct Cas cas;
				int d,k,i=0;
				printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
				scanf("%d",&d);
				ispisi_dan(raspored,broj_casova,d);
				printf("Izaberite koji cas zelite promijeniti: ");
				scanf("%d",&k);
				printf("Naziv predmeta: ");
				char naziv[10];
				char c=getchar();
				c=getchar();
				do {
					if (i<9)
						naziv[i++]=c;
					c=getchar();
				} while (c!='\n');
				naziv[i]='\0';
				strcpy(cas.predmet,naziv);
				cas.dan_u_sedmici=d;
				printf("Vrijeme pocetka: ");
				scanf("%d%c%d",&cas.pocetak.sati,&c,&cas.pocetak.minute);
				printf("Vrijeme zavrsetka: ");
				scanf("%d%c%d",&cas.kraj.sati,&c,&cas.kraj.minute);
				/*if(preklapanje(raspored,broj_casova,cas)==1) {
					printf("Promjena nije moguca jer dovodi do preklapanja");
					break;
				}*/
				promijeni_cas(raspored,broj_casova,d,k,cas);
				break;
			}
			case 4:{
				int d,k;
				printf("Unesite dan (1=ponedjeljak, 2=utorak..., 6=subota): ");
				scanf("%d",&d);
				ispisi_dan(raspored,broj_casova,d);
				printf("Izaberite koji cas zelite obrisati: ");
				scanf("%d",&k);
				obrisi_cas(raspored,broj_casova,d,k);
				printf("Cas obrisan\n");
				broj_casova--;
				break;
			}
			default: break;
		}
	} while (n!=0);

	return 0;
}
