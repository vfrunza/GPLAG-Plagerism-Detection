#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Oblik {
	char naziv[20];
	int br_stranica;
	double stranice[300];
};

/* PROTOTIPI */
void dodaj_oblik(struct Oblik);
void izbaci_duple();
struct Oblik daj_najveci();

/* Pomocne funkcije */
double obim(struct Oblik);

int main() {
	struct Oblik t;
	struct Oblik tmp = { "Trougao", 3, { 100.1, 100.1, 100.1 } };
	
	printf("TEST, moras izbrisati sve\n");
	
	dodaj_oblik(tmp);
	t = daj_najveci();
	printf("%s %g\n", t.naziv, t.stranice[0]);
	
	izbaci_duple();
	printf("DUPLI IZBACENI\n");
	t = daj_najveci();
	printf("%s %g\n", t.naziv, t.stranice[0]);
	
	return 0;
}

double obim(struct Oblik shape) {
	int i;
	double circ = 0.0;
	
	for (i = 0; i < shape.br_stranica; i++)
		circ += shape.stranice[i];
		
	return circ;
}

void dodaj_oblik(struct Oblik shape2BAdded) {
	FILE *io;
	unsigned short n;
	int i;
	char buffer;
	float tmp;
	
	/* Prvo procitajmo broj oblika i izmjenimo ga, te nastavimo citati sve ostalo */
	if ((io = fopen("oblici.dat", "rb+")) == NULL) {
		printf("Greska pri otvaranju datoteke oblici.dat\n");
		exit(1);
	}
	
	fseek(io, 0, SEEK_SET);
	fread(&buffer, 1, 1, io);
	n = buffer;
	fread(&buffer, 1, 1, io);
	n += buffer << 8;
	
	n++;
	
	fseek(io, 0, SEEK_SET);
	fwrite(&n, 2, 1, io);
	
	/* Koristio bih SEEK_END, ali nije standardizovana implementacija */
	while (fread(&buffer, 1, 1, io) && buffer != EOF);
	
	fwrite(shape2BAdded.naziv, 20, 1, io);
	
	n = shape2BAdded.br_stranica;
	fwrite(&n, 1, 1, io);
	
	for (i = 0; i < n; i++) {
		tmp = (float)shape2BAdded.stranice[i];
		fwrite(&tmp, 4, 1, io);
	}
		
	if (ferror(io)) {
		printf("Oblik nije upisan u datoteku oblici.dat\n");
		exit(1);
	}
	
	fclose(io);
}

struct Oblik daj_najveci() {
	FILE *io;
	
	unsigned short n = 0;
	struct Oblik tmp, max;
	double max_obim = -1.0, tmp_obim;
	
	char buffer[20], buff;
	short numSides = 0;
	float side = 0.0;
	
	int i, j;
	
	if ((io = fopen("oblici.dat", "rb")) == NULL) {
		printf("Greska pri otvaranju datoteke oblici.dat\n");
		exit(1);
	}
	
	fseek(io, 0, SEEK_SET);
	fread(&buff, 1, 1, io);
	n = buff;
	fread(&buff, 1, 1, io);
	n += buff << 8;
	
	for (i = 0; i < n; i++) {
		fread(buffer, 1, 20, io);
		
		for(j = 0; j < 20; j++)
			tmp.naziv[j] = buffer[j];
		
		fread(&numSides, 1, 1, io);
		tmp.br_stranica = numSides;
		
		for (j = 0; j < numSides; j++) {
			fread(&side, 4, 1, io);
			tmp.stranice[j] = side;
		}
		
		tmp_obim = obim(tmp);
		if (tmp_obim > max_obim) {
			max = tmp;
			max_obim = tmp_obim;
		}
	}
	
	fclose(io);
	
	return max;
}

void izbaci_duple() {
	FILE *io, *helper;
	unsigned short n, numSides;
	char name[20], tmp_name[20], buffer;
	float side;
	
	int i, j, k, currPos;
	
	if ((io = fopen("oblici.dat", "rb+")) == NULL) {
		printf("Greska pri otvaranju datoteke oblici.dat\n");
		exit(1);
	}
	
	if ((helper = fopen("copy.dat", "wb+")) == NULL) {
		printf("Greska pri kreiranju/otvaranju pomocne datoteke\n");
		exit(1);
	}
	
	fseek(io, 0, SEEK_SET);
	fseek(helper, 0, SEEK_SET);
	
	fread(&buffer, 1, 1, io);
	printf("%d\n", buffer);
	n = buffer;
	fread(&buffer, 1, 1, io);
	n += buffer << 8;
	
	printf("%d\n", n);
	currPos = 2;
	
	for (i = 0; i < n; i++) {
		fread(name, 20, 1, io);
		currPos += 20;
		
		if (name[0] == EOF)
			break;
		
		if (name[0] == 27) {
			while (fread(&buffer, 1, 1, io) && buffer == 27);
			fseek(io, -1, SEEK_CUR);
			i--;
			continue;
		}
		
		//printf("%s: \n", name);
		
		fwrite(name, 20, 1, helper);
		
		fread(&numSides, 1, 1, io);
		currPos++;
		
		fwrite(&numSides, 1, 1, helper);
		
		currPos += 4 * numSides;
		
		for(j = 0; j < 4 * numSides; j++) {
			fread(&buffer, 1, 1, io);
			fwrite(&buffer, 1, 1, helper);
		}
		
		for (j = i + 1; j < n; j++) {
			fread(tmp_name, 20, 1, io);
			//printf("\t%s\n", tmp_name);
			
			fread(&numSides, 1, 1, io);
			
			if (!strcmp(name, tmp_name)) {
				//printf("%d -> %d\n", i, j);
				buffer = 27;
				
				fseek(io, -21, SEEK_CUR);
				for (k = 0; k < 21 + numSides * 4; k++)
					fwrite(&buffer, 1, 1, io);
					
				n--;
				j--;
			}
			else
				fseek(io, 4 * numSides, SEEK_CUR);
		}
		
		fseek(io, currPos, SEEK_SET);
	}
	
	fclose(io);
	
	if ((io = fopen("oblici.dat", "wb")) == NULL) {
		printf("Greska pri otvaranju datoteke oblici.dat\n");
		exit(1);
	}
	
	fseek(io, 0, SEEK_SET);
	fseek(helper, 0, SEEK_SET);
	
	printf("%d\n", n);
	fwrite(&n, 2, 1, io);
	
	while(fread(&buffer, 1, 1, helper) && buffer != EOF) {
		fwrite(&buffer, 1, 1, io);
	}
	
	fclose(io);
	fclose(helper);
}