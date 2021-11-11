#include <stdio.h>
#include <string.h>
int je_slovo(char c){
	
	if((c >= 'a' && c <= 'z' ) || (c >= 'A' && c <= 'Z')) return 1;
	return 0;
}

int broj_ponavljanja(FILE * ulaz, char rijec[], int pocetak){
	char trenutna_rijec[20];
	int trenutna_duzina;
	int ponavljanje = 1;
	char c;
	while(1){
		c = fgetc(ulaz);
		if(c == EOF) break;
		if(!je_slovo(c)){
			continue;
		}
		if(je_slovo(c)){
			trenutna_duzina = 0;
			while(je_slovo(c) && trenutna_duzina <= 10){
				trenutna_rijec[trenutna_duzina] = c;
				trenutna_duzina++;
				
				c = fgetc(ulaz);
			}
			if(trenutna_duzina > 10){
				while(c != EOF && je_slovo(c)){
					c = fgetc(ulaz);
				}
			} else {
				trenutna_rijec[trenutna_duzina] = '\0';
				if(strcmp(trenutna_rijec,rijec) == 0) ponavljanje ++;
			}
		}
	}
	return ponavljanje;
}

void kompresuj(char ulazna[], char izlazna[]){
	FILE* ulaz = fopen(ulazna, "r");
	int i = 0, j = 0;
	if(ulaz == NULL) {
		printf("File se nije mogao otvoriti\n");
		return;
	}
	char najcesce[100][20];
	int duzine[100], broj_rijeci = 0;
	char trenutna_rijec[20] = "";
	int trenutna_duzina;
	
	char c;
	while(1){
		
		c = fgetc(ulaz);
		if(c == EOF) break;
		
		if(!je_slovo(c)){
			continue;
		}
		
		if(je_slovo(c)){
			trenutna_duzina = 0;
			while(je_slovo(c) && trenutna_duzina <= 10){
				trenutna_rijec[trenutna_duzina] = c;
				trenutna_duzina++;
				
				c = fgetc(ulaz);
				
			}
			
			if(trenutna_duzina >= 10){
				while(c != EOF && je_slovo(c)){
					c = fgetc(ulaz);
				}
			} else{
				trenutna_rijec[trenutna_duzina] = '\0';
				int found = 0;
				for(i = 0; i < broj_rijeci; i ++){
					if(strcmp(trenutna_rijec,najcesce[i]) == 0){
						duzine[i]++;
						found = 1;
						break;
					}
				}
				
				if(found == 0){
					if(broj_rijeci < 100){
						strcpy(najcesce[broj_rijeci],trenutna_rijec);
						duzine[broj_rijeci] = 1;
						broj_rijeci++;
						
					}
				}
			}
			
		}
		if(c == EOF) break;
	}
	for(i = 0; i < broj_rijeci; i++){
		for(j = 1; j < broj_rijeci; j++){
			if(duzine[j - 1] < duzine[j] || (duzine[j -1] == duzine[j] && strcmp(najcesce[j],najcesce[j - 1]) < 0)){
				strcpy(trenutna_rijec, najcesce[j -1]);
				strcpy(najcesce[j - 1],najcesce[j]);
				strcpy(najcesce[j],trenutna_rijec);
				trenutna_duzina = duzine[j -1];
				duzine[j - 1] = duzine[j];
				duzine[j] = trenutna_duzina;
			}
		}
	}
	
	FILE* izlaz = fopen(izlazna, "w");
	int br_najcesce = 10;
	if(broj_rijeci < 10) br_najcesce = broj_rijeci;
	for(i = 0; i < br_najcesce; i++){
//		printf("%s se ponavlja %d puta\n",najcesce[i],duzine[i]);
		fprintf(izlaz,"%s\n",najcesce[i]);
		
	}
	fprintf(izlaz,"\n");
	rewind(ulaz);
	while(1){
		if(!je_slovo(c))
			c = fgetc(ulaz);
		
		if(c == EOF) break;
		
		if(!je_slovo(c)){
			fputc(c,izlaz);
			continue;
		}
		
		if(je_slovo(c)){
			trenutna_duzina = 0;
			while(je_slovo(c) && trenutna_duzina <= 10){
				trenutna_rijec[trenutna_duzina] = c;
				trenutna_duzina++;
				c = fgetc(ulaz);
			}
			
			trenutna_rijec[trenutna_duzina] = '\0';
				
			if(trenutna_duzina >= 10){
				fputs(trenutna_rijec,izlaz);
				do{
					if(c != EOF && je_slovo(c)) break;
					fputc(c,izlaz);
					c = fgetc(ulaz);
				}while(c != EOF && je_slovo(c));
			} else {
			//	printf("%s",trenutna_rijec);
				int found = 0;
				for(i = 0; i < br_najcesce; i++){
					if(strcmp(najcesce[i],trenutna_rijec) == 0){
					//	printf("nasao");
						found = 20+i;
						break;
					}
				}
				if(found == 0){
					fprintf(izlaz,"%s",trenutna_rijec);
				} else {
					fprintf(izlaz,"%c",found);
				}
			}
			if(!je_slovo(c))
				fputc(c,izlaz);
		}
	}

	fclose(ulaz);
	fclose(izlaz);
	printf("Datoteka kompresovana.\n");

}

void dekompresuj(char ulazna[],char izlazna[]){
	FILE* ulaz = fopen(ulazna, "r");
	FILE* izlaz = fopen(izlazna, "w");
	char najcesci[10][11], buffer[11];
	int i = 0,br_rijeci = 0,j = 9;
	char c;
	for(i = 0; i < 10; i++)
	{
		char c;
		j = 0;
		do{
			c = getc(ulaz);
			buffer[j] = c;
			j++;
		
		}while(c != '\n');
		if(j == 1) break;
		buffer[j - 1] = '\0';
		strcpy(najcesci[i],buffer);
		br_rijeci++;
		
	}
	do{
		c = fgetc(ulaz);
		if(c == EOF) break;
		
		if(c >= 20 && c <=29){
			fprintf(izlaz,"%s",najcesci[c-20]);
		} else {
			fputc(c,izlaz);
		}
	}while(c != EOF);
	
	fclose(ulaz);
	fclose(izlaz);

	printf("Datoteka dekompresovana.\n");

	
}



int main() {
	/*
	FILE* ulaz = fopen("z.txt", "w");
	fputs("Proba proba proba proba proba proba...", ulaz);
	fclose(ulaz);

	kompresuj("z.txt","g.zip");
	
	printf("\nWaa\n");
	*/
	int izbor;
	char ulazna[100];
	char izlazna[100];
	///*
	while(1){
		printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
		scanf("%d",&izbor);	
		
		if(izbor == 1){
			printf("Unesite ime ulazne datoteke: ");
			scanf("%100s",ulazna);
			printf("Unesite ime izlazne datoteke: ");
			scanf("%100s",izlazna);
			kompresuj(ulazna,izlazna);
			
		} else if(izbor == 2) {
			printf("Unesite ime ulazne datoteke: ");
			scanf("%100s",ulazna);
			printf("Unesite ime izlazne datoteke: ");
			scanf("%100s",izlazna);
			dekompresuj(ulazna,izlazna);
		} else if(izbor == 0){
			break;
		}
	}
	//*/
	/*
	char c;
	ulaz = fopen("g.zip", "r");
	do {
	    c=fgetc(ulaz);
	    if (c >= 20 && c<=29) printf("[%d]", c);
	    else if (c != EOF) printf("%c", c);
	} while (c != EOF);
	fclose(ulaz);
	*/
	
	return 0;
}
