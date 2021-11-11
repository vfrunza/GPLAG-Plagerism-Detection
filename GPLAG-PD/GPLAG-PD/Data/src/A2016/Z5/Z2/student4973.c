#include <stdio.h>
#include <string.h>
char ucitajJednuRijec(char *buffer, FILE* datoteka){
	int i = 0;
	char c;
	while(1){
		c = getc(datoteka);
		if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
			break;
		if(i < 500);
			buffer[i++] = c;
	}
	buffer[i] = '\0';
	return c;
}


int kompresuj(char *ulaznaDatoteka,char *izlaznaDatoteka){
	char buffer[100];
	FILE* ulaz = fopen(ulaznaDatoteka, "r");
	FILE* izlaz = fopen(izlaznaDatoteka,"w");
	char tmp[15];
	int najveca = 0,maxrijeci = 10, tmpduzina;
	if(ulaz == NULL) return 0;
	char rijeci[1000][15];
	int duzine[1000], duzina, brojrijeci = 0, pomocna, i, j;
	char c;
	while(1){
		c = ucitajJednuRijec(buffer,ulaz);
		duzina = strlen(buffer);
		if(duzina > 1 && duzina < 10){
			pomocna = -1;
			for(i = 0; i < brojrijeci; i++){
				if(strcmp(rijeci[i],buffer) == 0){
					pomocna = i;
					break;
				}
			}
			if(pomocna != -1){
				duzine[pomocna]++;
			} else {
				strcpy(rijeci[brojrijeci],buffer);
				duzine[brojrijeci] = 1;
				brojrijeci++;
			}
		}
		if(c == EOF) break;
	}
	if(brojrijeci < maxrijeci) maxrijeci = brojrijeci;
	for(i = 0; i < maxrijeci; i++){
		najveca = i;
		for(j = i+1; j < brojrijeci; j++){
			if(duzine[najveca] < duzine[j]){
				najveca = j;
			} else if( duzine[najveca] == duzine[j] && strcmp(rijeci[j],rijeci[najveca]) < 0){
				najveca = j;
			}
		}
		if(najveca != i){
			strcpy(tmp,rijeci[najveca]);
			strcpy(rijeci[najveca],rijeci[i]);
			strcpy(rijeci[i],tmp);
		
			tmpduzina = duzine[najveca];
			duzine[najveca] = duzine[i];
			duzine[i] = tmpduzina;
		}
	}
	for(i = 0; i < maxrijeci; i++){
		fprintf(izlaz,"%s\n",rijeci[i]);
	}
	fprintf(izlaz,"\n");
	fclose(ulaz);
	ulaz = fopen(ulaznaDatoteka, "r");
	while(1){
		c = ucitajJednuRijec(buffer,ulaz);
		duzina = strlen(buffer);
		if(duzina > 1 && duzina < 10){
			pomocna = -1;
			for(i = 0; i < maxrijeci; i++){
				if(strcmp(rijeci[i],buffer) == 0){
					pomocna = i;
					break;
				}
			}
			if(pomocna != -1){
				fprintf(izlaz,"%c", (char)(20 +i));
			}
			else {
				fprintf(izlaz,"%s", buffer);
			}
		} else {
			fprintf(izlaz,"%s",buffer);
		}
		fprintf(izlaz, "%c", c);
		if(c == EOF) break;
		
	}
	fclose(izlaz);
	printf("Datoteka kompresovana.\n");
	return 1;
}

int dekompresuj(char *ulaznaDatoteka,char *izlaznaDatoteka){
	//return 1;
	FILE *ulaz, *izlaz;
	ulaz = fopen(ulaznaDatoteka, "r");
	if(ulaz == NULL) return 0;
	izlaz = fopen(izlaznaDatoteka,"w");
	if(izlaz == NULL){
		fclose(ulaz);
		return 0;
	}
	char c, rijeci[15][10], buffer[50];
	int i, j, brojrijeci = 0,duzina;
	while(1){
		c = ucitajJednuRijec(buffer,ulaz);
		if(buffer[0] == '\0'){
			break;
		}
		strcpy(rijeci[brojrijeci++],buffer);
	}
	while(1){
		c = ucitajJednuRijec(buffer,ulaz);
		duzina = strlen(buffer);
		if(duzina == 0 && c>= 20 && c <=29){
			fprintf(izlaz,"%s",rijeci[c - 20]);
		} else {
			fprintf(izlaz,"%s",buffer);
			
		fprintf(izlaz,"%c",c);
			
		}
		if(c == EOF) break;
	}
	fclose(ulaz);
	fclose(izlaz);
	printf("Datoteka dekompresovana.\n");
	return 1;
}

int main() {
	int pom, rezultat;
	char c;
	char ulaznaDatoteka[50],izlaznaDatoteka[50];
	do{
	printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
	scanf("%d", &pom);
	c = getchar();
	if(pom == 0)
		return 0;
	printf("Unesite ime ulazne datoteke: ");
	scanf("%50s",ulaznaDatoteka);
	printf("Unesite ime izlazne datoteke: ");
	scanf("%50s",izlaznaDatoteka);
	if(pom == 1){
		rezultat = kompresuj(ulaznaDatoteka,izlaznaDatoteka);
	}
	if(pom == 2){
		rezultat = dekompresuj(ulaznaDatoteka,izlaznaDatoteka);
	}
	}while(pom != 0);		
	return 0;
}
