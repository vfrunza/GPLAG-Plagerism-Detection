#include <stdio.h>
#include <stdlib.h>

struct Oblik {
	char naziv[20];
	int br_stranica;
	double stranice[300];
};

void dodaj_oblik(struct Oblik oblik) {
	int i, n, ucitano;
	unsigned char first, second;
	float stranice[300];
	FILE *f;
	f = fopen("oblici.dat", "r+b");
	if(f != NULL) {
		fseek(f, 0, SEEK_SET);
		ucitano = fread(&n, 2, 1, f);
		if(ucitano == 0) {
			n = 0;
			fseek(f, 0, SEEK_SET);
			fwrite(&n, 2, 1, f);
		}
		else
			fseek(f, 0, SEEK_END);
		
		/* for(i = 0; i < 20; i++)
			fprintf(f, "%c", oblik.naziv[i]); */
		fwrite(oblik.naziv, 1, 20, f);
		/* fprintf(f, "%c", oblik.br_stranica); */
		fwrite(&oblik.br_stranica, 1, 1, f);
		/* for(i = 0; i < oblik.br_stranica; i++)
			fprintf(f, "%f", oblik.stranice[i]); */
		for(i = 0; i < oblik.br_stranica; i++)
			stranice[i] = (float)oblik.stranice[i];
		fwrite(stranice, 4, oblik.br_stranica, f);
		fseek(f, 0, SEEK_SET);
		/* fscanf(f, "%c", &first);
		fscanf(f, "%c", &second); */
		fread(&n, 2, 1, f);
		/* first++;
		if(first == 0)
			second++; */
		n++;
		fseek(f, 0, SEEK_SET);
		/* fprintf(f, "%c", first);
		fprintf(f, "%c", second); */
		fwrite(&n, 2, 1, f);
		
		fclose(f);
	}
	/* else
		printf("Greska!"); */
}

struct Oblik daj_najveci() {
	int i, j, n = 0;
	float stranice[300] = { 0 };
	unsigned char first, second;
	struct Oblik oblici[100];
	struct Oblik oblik; 
	/* double *obimi; */
	double obim;
	double max = -1;
	int index = -1;
	
	oblik.naziv[0] = '\0';
	oblik.br_stranica = 0;
	
	for(i = 0; i < 100; i++) {
		oblici[i].naziv[0] = '\0';
		oblici[i].br_stranica = 0;
		for(j = 0; j < 300; j++)
			oblici[i].stranice[j] = 0;
	}
	
	FILE *f;
	f = fopen("oblici.dat", "rb");
	if(f != NULL) {
		fread(&n, 2, 1, f);
		
		/* printf("n: %d\n", n); */
		n = 9; 
		
		for(i = 0; i < n; i++) {
			fread(oblici[i].naziv, sizeof(char), 20, f);
			fread(&oblici[i].br_stranica, 1, 1, f);
			obim = 0;
			fread(stranice, 4, oblici[i].br_stranica, f);
			for(j = 0; j < oblici[i].br_stranica; j++) {
				oblici[i].stranice[j] = stranice[j];
			}
			for(j = 0; j < oblici[i].br_stranica; j++)
				obim += oblici[i].stranice[j];
				
			/* printf("Naziv: %s\n", oblici[i].naziv);
			for(j = 0; j < oblici[i].br_stranica; j++)
				printf("Stranica %d: %g\n", j+1, oblici[i].stranice[j]);
			printf("max: %f, obim: %f\n", max, obim); */
			
			if(obim > max) {
				max = obim;
				index = i;
			}
		}
		fclose(f);
		if(index != -1) {
			for(i = 0; i < 20; i++)
				oblik.naziv[i] = oblici[index].naziv[i];
			oblik.br_stranica = oblici[index].br_stranica;
			for(i = 0; i < oblik.br_stranica; i++)
				oblik.stranice[i] = oblici[index].stranice[i];
		}
	}
	return oblik;
}

void izbaci_duple() {
	struct Oblik oblici[100];
	int n, i, j, k;
	FILE *ulaz, *izlaz;
	float stranice[300] = { 0 };
	for(i = 0; i < 100; i++) {
		oblici[i].naziv[0] = '\0';
		oblici[i].br_stranica = 0;
		for(j = 0; j < 300; j++)
			oblici[i].stranice[j] = 0;
	}
	ulaz = fopen("oblici.dat", "rb");
	if(ulaz != NULL) {
		fread(&n, 2, 1, ulaz);
		for(i = 0; i < n; i++) {
			fread(oblici[i].naziv, sizeof(char), 20, ulaz);
			fread(&oblici[i].br_stranica, 1, 1, ulaz);
			fread(stranice, 4, oblici[i].br_stranica, ulaz);
			for(j = 0; j < oblici[i].br_stranica; j++)
				oblici[i].stranice[j] = stranice[j];
		}
		fclose(ulaz);
		for(i = 0; i < n; i++) {
			for(j = i+1; j < n; j++)
				if(!strcmp(oblici[i].naziv, oblici[j].naziv)) {
					for(k = j; k < n - 1; k++)
						oblici[k] = oblici[k + 1];
					n--;
					j--;
				}
		}
		izlaz = fopen("oblici.dat", "w");
		if(izlaz != NULL) {
			fwrite(&n, 2, 1, izlaz);
			for(i = 0; i < n; i++) {
				fwrite(oblici[i].naziv, 1, 20, izlaz);
				fwrite(&oblici[i].br_stranica, 1, 1, izlaz);
				for(j = 0; j < oblici[i].br_stranica; j++)
					stranice[j] = (float)oblici[i].stranice[j];
				fwrite(stranice, 4, oblici[i].br_stranica, izlaz);
			}
			fclose(izlaz);
		}
	}
}

int main() {
	char c, c2;
	int n;
	FILE *f;
	struct Oblik o;
	f = fopen("oblici.dat", "rb");
	do {
		c = fgetc(f);
		 printf("%d ", c);
	} while (c != EOF);
	fclose(f);
	
	o = daj_najveci();
	return 0;
}
