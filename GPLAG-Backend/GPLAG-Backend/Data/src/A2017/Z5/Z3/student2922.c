#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define epsilon 0.001

struct Oblik {
	char naziv[20];
	int br_stranica;
	double stranice[300];
};

void dodaj_oblik(struct Oblik a)
{
	int i=0,j=0;
	float temp=0;
	unsigned short int N=0;
	struct Oblik oblici[50]= {{"Trougao"},{3},{1.1,1.1,1.1}};
	FILE *ulaz=fopen("oblici.dat","rb");
	if (ulaz == NULL) {
		exit (1);
	}
	fseek(ulaz, 0, SEEK_SET);
	fread(&N,2,1,ulaz);
	/*Kroz petlju prolazimo onoliko puta koliko ima oblika, te posebno svaki element svakog oblika upisujemo u niz*/
	for(i=0; i<N; i++) {
		fread(&oblici[i].naziv,20,1,ulaz);
		fread(&oblici[i].br_stranica,1,1,ulaz);
		/*Svaku stranicu moramo posebno upisati u niz*/
		for(j=0; j<oblici[i].br_stranica; j++) {
			fread(&temp,4,1,ulaz);
			oblici[i].stranice[j]=temp;
		}
	}
	fclose(ulaz);
	oblici[i]=a; /*Dodajemo u niz oblik koji treba unijeti u datoteku*/
	N++; /*Broj oblika se poveca za jedan*/
	ulaz=fopen("oblici.dat","wb");
	if(ulaz==NULL) {
		exit(1);
	}
	/*Vrsimo upis elemenata u datoteku iz niza*/
	fwrite(&N,2,1,ulaz);
	for(i=0; i<N; i++) {
		fwrite(&oblici[i].naziv,20,1,ulaz);
		fwrite(&oblici[i].br_stranica,1,1,ulaz);
		/*Potrebno je svaku stranicu posebno unijeti*/
		for(j=0; j<oblici[i].br_stranica; j++) {
			temp=oblici[i].stranice[j];
			fwrite(&temp,4,1,ulaz);
		}
	}
	fclose(ulaz);
}
void izbaci_duple()
{
	unsigned short int N=0;
	int j=0,k=0,T=0,m=0,i=0;
	float temp=0;
	struct Oblik oblici[50]= {{"Trougao"},{3},{1.1,1.1,1.1}};
	FILE *ulaz=fopen("oblici.dat","rb");
	if (ulaz == NULL) {
		exit (1);
	}
	/*Ucitamo elemente datoteke u niz*/
	fseek(ulaz, 0, SEEK_SET);
	fread(&N,2,1,ulaz);
	for(i=0; i<N; i++) {
		fread(&oblici[i].naziv,20,1,ulaz);
		fread(&oblici[i].br_stranica,1,1,ulaz);
		for(j=0; j<oblici[i].br_stranica; j++) {
			fread(&temp,4,1,ulaz);
			oblici[i].stranice[j]=temp;
		}
	}
	fclose(ulaz);
	/*Prolazimo kroz sve elemente niza osim provg (zato sto on sigurno ostaje u datoteci), te provjeravamo da li ima prethodnika sa istim nazivom*/
	for(j=1; j<N; j++) {
		for(k=0; k<j; k++) {
			T=strcmp(oblici[j].naziv,oblici[k].naziv); /*Funkcija vraca nulu ako su stringovi jednaki*/
			if(T==0) {
				/*Petlja koja izbacuje element iz niza*/
				for(m=j; m<N-1; m++)
					oblici[m]=oblici[m+1];
				N--; /*Broj elementa smanjujemo za jedan*/
				j--; /*Brojac smanjujemo za jedan kako bi ispitali element koji je dosao na mjesto izbacenog*/
				break;
			}
		}
	}
	ulaz=fopen("oblici.dat","wb");
	if (ulaz == NULL) {
		exit (1);
	}
	/*Upisujemo elemente niza u datoteku*/
	fseek(ulaz, 0, SEEK_SET);
	fwrite(&N,2,1,ulaz);
	for(i=0; i<N; i++) {
		fwrite(&oblici[i].naziv,20,1,ulaz);
		fwrite(&oblici[i].br_stranica,1,1,ulaz);
		for(j=0; j<oblici[i].br_stranica; j++) {
			temp=oblici[i].stranice[j];
			fwrite(&temp,4,1,ulaz);
		}
	}
	fclose(ulaz);
}
struct Oblik daj_najveci()
{
	struct Oblik oblici[50]= {{"Trougao"},{3},{1.1,1.1,1.1}};
	struct Oblik trazeni;
	int j=0,k=0,i=0;
	float temp=0;
	double obim=0,max=0;
	unsigned short int N=0;
	FILE *ulaz=fopen("oblici.dat","rb");
	if (ulaz == NULL) {
		exit (1);
	}
	/*Ucitavamo elemente datoteke u niz*/
	fseek(ulaz, 0, SEEK_SET);
	fread(&N,2,1,ulaz);
	for(i=0; i<N; i++) {
		fread(&oblici[i].naziv,20,1,ulaz);
		fread(&oblici[i].br_stranica,1,1,ulaz);
		for(j=0; j<oblici[i].br_stranica; j++) {
			fread(&temp,4,1,ulaz);
			oblici[i].stranice[j]=temp;
		}
	}
	fclose(ulaz);
	/*Petljom trazimo obim prvog elementa i postavljamo ga za maksimalni obim, kako bi poslije ostale elemente mogli poredit s prethodnim*/
	for(k=0; k<oblici[0].br_stranica; k++)
		max+=oblici[0].stranice[k];
	trazeni=oblici[0];
	for(j=1; j<N; j++) {
		/*Racnuamo obim svakog oblika*/
		for(k=0; k<oblici[j].br_stranica; k++)
			obim+=oblici[j].stranice[k];
		/*Svaki izracunati obim uporedjujemo s trenutno najvecim obimom*/
		if((obim-max)>=epsilon) {
			max=obim;
			trazeni=oblici[j];
		}
		obim=0;
	}
	return trazeni;
}
int main()
{
	return 0;
}
