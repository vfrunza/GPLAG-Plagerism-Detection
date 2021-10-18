#include <stdio.h>
#include <string.h>

/* Vrijeme: 14:54-, 2 minuta  */


struct Oblik {
	char naziv[20];
	int br_stranica;
	double stranice[300];
};

void zapisi_datoteku(struct Oblik* niz, int vel) {
	int i, j;
	FILE* fp = fopen("oblici.dat", "wb");
	unsigned short vel2=vel;
	fwrite(&vel2, 2, 1, fp);
	for (i=0; i<vel; i++) {
		fwrite(niz[i].naziv, 20, 1, fp);
		unsigned char br = niz[i].br_stranica;
		fwrite(&br, 1, 1, fp);
		for (j=0; j<niz[i].br_stranica; j++) {
			float stranica = niz[i].stranice[j];
			fwrite(&stranica, 4, 1, fp);
		}
	}
	fclose(fp);
}

int ucitaj_datoteku(struct Oblik* niz, int kap) {
	int i, j;
	unsigned short vel;
	FILE* fp = fopen("oblici.dat", "rb");
	fread(&vel, 2, 1, fp);
	for (i=0; i<vel; i++) {
		if (i==vel) break;
		fread(niz[i].naziv, 20, 1, fp);
		unsigned char br;
		fread(&br, 1, 1, fp);
		niz[i].br_stranica = br;
		for (j=0; j<br; j++) {
			float stranica;
			fread(&stranica, 4, 1, fp);
			niz[i].stranice[j] = stranica;
		}
	}
	fclose(fp);
	return vel;
}

double daj_povrsinu(struct Oblik o) {
	int i;
	double rez=0;
	for (i=0; i<o.br_stranica; i++)
		rez+=o.stranice[i];
	return rez;
}

struct Oblik daj_najveci() {
	struct Oblik niz[100] = {};
	int vel = ucitaj_datoteku(niz, 100);
	int i, max=0;
	double povrsina = daj_povrsinu(niz[0]);
	for (i=0; i<vel; i++) {
		if (daj_povrsinu(niz[i]) > povrsina) {
			povrsina = daj_povrsinu(niz[i]);
			max = i;
		}
	}
	return niz[max];
}

void dodaj_oblik(struct Oblik o) {
	struct Oblik niz[100] = {};
	int vel = ucitaj_datoteku(niz, 100);
	if (vel < 100)	
		niz[vel++] = o;
	zapisi_datoteku(niz, vel);
}

void izbaci_duple() {
	struct Oblik niz[100] = {};
	int vel = ucitaj_datoteku(niz, 100);
	int i,j, k;
	for (i=1; i<vel; i++) {
		for (j=0; j<i; j++)
			if (strcmp(niz[i].naziv, niz[j].naziv) == 0) {
				for (k=i; k<vel-1; k++)
					niz[k] = niz[k+1];
				vel--;
				i--;
				break;
			}
	}
	zapisi_datoteku(niz, vel);
}

int main() {
	/*
	struct Oblik nizw[] = {
		{"Kvadrat", 4, {5.5, 3.3, 1.9, 4.4}},
		{"Trougao", 3, {21.21, 18.18, 1.1}},
		{"Sestougao", 6, {4.4, 2.2, 5.5, 0.111, 3.4, 5}},
		{"Petougao", 5, {1,2,3,4,5}}
	};
	zapisi_datoteku(nizw, 4);
	printf("Zapisano\n");
	*/
	
/* AT6 (skriveni): Da li je broj stranica ispravno procitan iz datoteke (unsigned char) */
/*struct Oblik veliki = {"255ugao", 255, {} };
int i;
for (i=0; i<255; i++)
	veliki.stranice[i] = 0.0001;
veliki.stranice[254] = 10000;
dodaj_oblik(veliki);
	
struct Oblik rez = daj_najveci();
printf("%s", rez.naziv);
*/
	
	struct Oblik niz[100];
	int vel = ucitaj_datoteku(niz, 100);
	int i;
	printf("%d\n", vel);
	for (i=0; i<vel; i++) {
		printf("'%s'\n", niz[i].naziv);
	}
	
	return 0;
}
