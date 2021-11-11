#include <stdio.h>
#include <string.h>

int isLetter(char c) {
	if((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) return 1;
	return 0;
}

int checkFile(FILE *f) {
	if(f == NULL) {
		printf("Datoteka ne postoji.\n");
		return 0;
	}
	return 1;
}

void oslobodiResurse(FILE *ulaz, FILE *izlaz) {
	fclose(ulaz);
	fclose(izlaz);
}

char loadWord(char *rijec, FILE *file) {
	char c;
	while(1){
		c = getc(file);
		if(!isLetter(c))
			break;
		*rijec = c;
		rijec++;
	}
	*rijec = '\0';
	return c;
}

int kompresuj(char *ulazna, char *izlazna){
	char rijec[100];
	char rijeci[1000][10];
	int duzine[1000], duzina, brojRijeci = 0, opt, i, j;
	FILE* ulaz = fopen(ulazna, "r");
	FILE* izlaz = fopen(izlazna, "w");
	char tmp[10], c;
	int najvecaRijec = 0;
	int maxBrRijeci = 10;
	int tmpDuzina = 0;
	
	if(checkFile(ulaz) == 0) return 0;
	if(checkFile(izlaz) == 0) return 0;
	
	while(1){
		c = loadWord(rijec,ulaz);
		if(strlen(rijec) > 1 && strlen(rijec) < 10) {
			opt = -1;
			for(i = 0; i < brojRijeci; i++){
				if(strcmp(rijeci[i], rijec) == 0){
					opt = i;
					break;
				}
			}
			if(opt != -1){
				duzine[opt]++;
			} 
			else {
				strcpy(rijeci[brojRijeci], rijec);
				duzine[brojRijeci] = 1;
				brojRijeci++;
			}
		}	
		if(c == EOF) break;
	}
	if(brojRijeci < maxBrRijeci) maxBrRijeci = brojRijeci;
	for(i = 0; i < maxBrRijeci; i++) {
		najvecaRijec = i;
		for(j = i+1; j < brojRijeci; j++) {
			if(duzine[najvecaRijec] < duzine[j]) najvecaRijec = j;
			else if(duzine[najvecaRijec] == duzine[j] && strcmp(rijeci[j], rijeci[najvecaRijec]) < 0) najvecaRijec = j;
		}
		if(najvecaRijec != i) {
			strcpy(tmp, rijeci[najvecaRijec]);
			strcpy(rijeci[najvecaRijec], rijeci[i]);
			strcpy(rijeci[i], tmp);
			tmpDuzina = duzine[najvecaRijec];
			duzine[najvecaRijec] = duzine[i];
			duzine[i] = tmpDuzina;
		}
	}
	for(i = 0; i < maxBrRijeci; i++)
		fprintf(izlaz,"%s\n", rijeci[i]);
	
	fprintf(izlaz,"\n");
	fclose(ulaz);
	ulaz = fopen(ulazna, "r");
	
	while(1){
		c = loadWord(rijec,ulaz);
		if(strlen(rijec) > 1 && strlen(rijec) < 10){
			opt = -1;
			for(i = 0; i < maxBrRijeci; i++){
				if(strcmp(rijeci[i], rijec) == 0){
					opt = i;
					break;
				}
			}
			if(opt != -1) fprintf(izlaz, "%c", (char)(20 + i));
			else fprintf(izlaz,"%s", rijec);
		}
		else fprintf(izlaz, "%s", rijec);
		fprintf(izlaz, "%c", c);
		if(c == EOF) break;
	}
	oslobodiResurse(ulaz, izlaz);
	printf("Datoteka kompresovana.\n");
	return 1;
}

int dekompresuj(char *ulazna, char *izlazna) {	
	FILE *ulaz = fopen(ulazna, "r");
	FILE *izlaz = fopen(izlazna, "w");

	if(checkFile(ulaz) == 0) return 0;
	if(checkFile(izlaz) == 0) return 0;
		
	char c, rijeci[10][10], rijec[20];
	int i, j, brojRijeci = 0, duzina;
		
	while(1){
		c = loadWord(rijec, ulaz);
		if(rijec[0] == '\0') break;
		strcpy(rijeci[brojRijeci++], rijec);
	}
	
	while(1){
		c = loadWord(rijec, ulaz);
		if(strlen(rijec) == 0 && c >= 20 && c <= 29)
			fprintf(izlaz, "%s", rijeci[c - 20]);
	 	else {
			fprintf(izlaz, "%s", rijec);
			fprintf(izlaz, "%c", c);
		}
		if(c == EOF) break;
	}
	oslobodiResurse(ulaz, izlaz);
	printf("Datoteka dekompresovana.\n");
	return 1;
}

int main() {
	int opcija, status;
	char c, ulazna[50], izlazna[50];

	do {
		printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
		scanf("%d", &opcija);
		c = getchar();

		if(opcija == 0) break;
		
		if(opcija == 1) {
			printf("Unesite ime ulazne datoteke: "); scanf("%50s", ulazna);
			printf("Unesite ime izlazne datoteke: "); scanf("%50s", izlazna);
			status = kompresuj(ulazna, izlazna);
			if(status == 0) 
				printf("Nesto nije u radu sa kompresijom.\n");
		}
		else if(opcija == 2) {
			printf("Unesite ime ulazne datoteke: "); scanf("%50s", ulazna);
			printf("Unesite ime izlazne datoteke: "); scanf("%50s", izlazna);
			status = dekompresuj(ulazna, izlazna);
			if(status == 0) 
				printf("Nesto nije u radu sa dekompresijom.\n");
		}
	} while(1);

	return 0;
}