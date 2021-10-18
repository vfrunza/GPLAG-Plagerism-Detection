#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Oblik {
	char naziv[20];
	int br_stranica;
	double stranice[300];
};
void dodaj_oblik(struct Oblik novioblik) {
	unsigned short brojoblika;
	unsigned char brojstranica;
	struct Oblik oblici[100];
	int i, j;
	float stranica;
	FILE* dat=fopen("oblici.dat", "rb");
	if (dat==NULL) {
		printf("Greska");
		exit(1);
	}
	
	// Algoritam za citanje podataka iz ove binarne datoteke u niz struktura, koji ce se ponavljati vise puta kroz program
	fread(&brojoblika, 2, 1, dat);
	for (i=0;i<brojoblika;i++) {
		fread(oblici[i].naziv, 1, 20, dat);
		fread(&brojstranica, 1, 1, dat);
		oblici[i].br_stranica=(int)brojstranica;
		for (j=0;j<brojstranica;j++) {
			fread(&stranica, 4, 1, dat);
			oblici[i].stranice[j]=(double)stranica;
		}
	} 
	oblici[i]=novioblik;
	brojoblika++; // Jednostavno dodavanje oblika na kraj niza struktura;
	
	FILE* dat2=fopen("oblici.dat", "wb");
	if (dat2==NULL) {
		printf("Greska");
		exit(1);
	}
	// Algoritam za zapisivanje niza struktura nazad u binarnu datoteku
	fwrite(&brojoblika, 2, 1, dat2);
	for (i=0;i<brojoblika;i++) {
		fwrite(oblici[i].naziv, 1, 20, dat2);
		brojstranica=(unsigned char)oblici[i].br_stranica;
		fwrite(&brojstranica, 1, 1, dat2);
		for (j=0;j<brojstranica;j++) {
			stranica=(float)oblici[i].stranice[j];
			fwrite(&stranica, 4, 1, dat2);
		}
	}
	fclose(dat);
	fclose(dat2);
}
void izbaci_duple() {
	int i, j, k;
	unsigned short brojoblika;
	unsigned char brojstranica;
	float stranica;
	struct Oblik oblici[100];
	FILE* dat=fopen("oblici.dat", "rb");
	if (dat==NULL) {
		printf("Greska");
		exit(1);
	}
	// Algoritam za citanje
	fread(&brojoblika, 2, 1, dat);
	for (i=0;i<brojoblika;i++) {
		fread(oblici[i].naziv, 1, 20, dat);
		fread(&brojstranica, 1, 1, dat);
		oblici[i].br_stranica=(int)brojstranica;
		for (j=0;j<brojstranica;j++) {
			fread(&stranica, 4, 1, dat);
			oblici[i].stranice[j]=(double)stranica;
		}
	}
	// Ako strcmp vrati 0, tj. ako su stringovi jednaki, izbacuje drugog koji je pronadjen
	for (i=0;i<brojoblika;i++) {
		for (j=i+1;j<brojoblika;j++) {
			if (!strcmp(oblici[i].naziv, oblici[j].naziv)) {
				for(k=j;k<brojoblika-1;k++) {
					oblici[k]=oblici[k+1];
				}
				brojoblika--;
				j--;
			}
		}
	}
	
	FILE* dat2=fopen("oblici.dat","wb");
	if (dat2==NULL) {
		printf("Greska");
		exit(1);
	}
	// Algoritam za zapisivanje
	fwrite(&brojoblika, 2, 1, dat2);
	for (i=0;i<brojoblika;i++) {
		fwrite(oblici[i].naziv, 1, 20, dat2);
		brojstranica=(unsigned char)oblici[i].br_stranica;
		fwrite(&brojstranica, 1, 1, dat2);
		for (j=0;j<brojstranica;j++) {
			stranica=(float)oblici[i].stranice[j];
			fwrite(&stranica, 4, 1, dat2);
		}
	}
	fclose(dat);
	fclose(dat2);
}
struct Oblik daj_najveci() {
	int i, j, brojoblika=0;
	float maxobim=0, obimoblika=0, stranica;
	struct Oblik maxoblik;
	struct Oblik oblici[100];
	unsigned char brojstranica;
	
	FILE* dat=fopen("oblici.dat","rb");
	if (dat==NULL) {
		printf("Greska");
		exit(1);
	}
	// Algoritam za citanje i pronalazanje strukture sa najvecim obimom
	fread(&brojoblika, 2, 1, dat);
	for (i=0;i<brojoblika;i++) {
		obimoblika=0;
		fread(oblici[i].naziv, 1, 20, dat);
		fread(&brojstranica, 1, 1, dat);
		oblici[i].br_stranica=(int)brojstranica;
		for (j=0;j<brojstranica;j++) {
			fread(&stranica, 4, 1, dat);
			oblici[i].stranice[j]=(double)stranica;
			obimoblika+=oblici[i].stranice[j];
		}
		if (obimoblika>maxobim) {
			maxobim=obimoblika;
			maxoblik=oblici[i];
		}
	}
	fclose(dat);
	return maxoblik;
}
int main() {
	int ucitano, i, j;
	unsigned short brojoblika;
	unsigned char brojstranica;
	float stranica;
	struct Oblik oblici[100];
	FILE* dat=fopen("oblici.dat", "rb");
	if (dat == NULL) {
		printf("Greska pri otvaranju datoteke");
		return 0;
	}
	i=0;
	/*do {
		ucitano=fread(&brojoblika, 2, 1, dat);
		fread(oblici[i].naziv, 1, 20, dat);
		fread(&brojstranica, 1, 1, dat);
		oblici[i].br_stranica=(int)brojstranica;
		for (j=0;j<oblici[i].br_stranica;j++) {
			fread(&stranica, 4, 1, dat);
			oblici[i].stranice[j]=(double)stranica;
		}
		i++;
	} while(ucitano);
	*/
	printf("Uspjesno ucitani");
	fclose(dat);
	return 0;
}