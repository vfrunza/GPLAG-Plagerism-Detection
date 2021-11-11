#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Rijec {
	char text[11];
	int count;
	int duzina;
};
int slovo(char c) {
	return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z');
}
void unesi(char niz[], int velicina) {
    char znak = getchar();
    if (znak == '\n') znak=getchar();
    int i = 0;
    while (i < velicina-1 && znak != '\n') {
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i]='\0';
}
void ocisti_niz(char *c) {
	int i;
	for (i = 0; i < 14; i++) c[i] = '\0';
}
int isti(char *s1, char *s2, int len1, int len2) {
	if (len1 != len2) return 0;
	int i;
	for (i = 0; i < len1; i++)
		if (s1[i] != s2[i]) return 0;
	return 1;
}
void kompresuj(char *ime_ulazne, char *ime_izlazne) {
	FILE *f1, *f2;
	f1 = fopen(ime_ulazne, "r");
	if (f1 == NULL) {
		printf("Greska pri otvaranju datoteke!\n");
		exit(1);
	}
	
	char znak;
	int razmak = 1, broj_znakova = 0, broj_rijeci = 0;
	int gledam_rijec = 1;
	int i, j;
	char trenutna_rijec[15];
	char word_list[1010][15];
	int word_len[1010];
	int word_count = 0;
	memset(word_len, 0, sizeof word_len);
	
	ocisti_niz(trenutna_rijec);
	while ((znak = fgetc(f1)) != EOF) {
		if (!slovo(znak)) {
			razmak = 1;
			if (gledam_rijec) {
				if (broj_znakova >= 1) {
					for (i = 0; i < broj_znakova; i++)
						word_list[word_count][i] = trenutna_rijec[i];
					word_list[word_count][i] = '\0';
					word_len[word_count] = broj_znakova;
					word_count++;
				}
			}
			ocisti_niz(trenutna_rijec);
			gledam_rijec = 1;
			broj_znakova = 0;
		}
		else {
			broj_znakova++;
			if (broj_znakova > 10) gledam_rijec = 0;
			if (gledam_rijec) trenutna_rijec[broj_znakova - 1] = znak;
			else {
				ocisti_niz(trenutna_rijec);
			}
			if (razmak == 1) broj_rijeci++;
			razmak = 0;
		}
	}
	if (broj_znakova >= 1 && broj_znakova <= 10) {
		for (i = 0; i < broj_znakova; i++)
				word_list[word_count][i] = trenutna_rijec[i];
			word_list[word_count][i] = '\0';
			word_len[word_count] = broj_znakova;
			word_count++;
	}
	fclose(f1);
	
	int broj_ponavljanja[1010];
	int vec_bila[1010];
	memset(broj_ponavljanja, 0, sizeof broj_ponavljanja);
	memset(vec_bila, 0, sizeof vec_bila);
	
	for (i = 0; i < word_count; i++) {
		for (j = i; j < word_count; j++)
			if (strcmp(word_list[i], word_list[j]) == 0) {
				broj_ponavljanja[i]++;
				if (i != j) vec_bila[j] = 1;
			}
	}
	struct Rijec konacna_lista[1010];
	int N = 0;
	for (i = 0; i < word_count; i++) 
		if (!vec_bila[i]) {
			for (j = 0; j < strlen(word_list[i]); j++)
				konacna_lista[N].text[j] = word_list[i][j];
			konacna_lista[N].count = broj_ponavljanja[i];
			konacna_lista[N].duzina = word_len[i];
			N++;
		}
	
	for (i = 0; i < N; i++)
		for (j = 0; j < N - 1; j++) 
			if (konacna_lista[j].count < konacna_lista[j + 1].count) {
				struct Rijec temp = konacna_lista[j];
				konacna_lista[j] = konacna_lista[j + 1];
				konacna_lista[j + 1] = temp;
			}
	for (i = 0; i < N; i++)
		for (j = 0; j < N - 1; j++) {
			if (konacna_lista[j].count == konacna_lista[j + 1].count) {
				if (strcmp(konacna_lista[j].text, konacna_lista[j + 1].text) > 0) {
					struct Rijec temp = konacna_lista[j];
					konacna_lista[j] = konacna_lista[j + 1];
					konacna_lista[j + 1] = temp;
				}
			}
		}
	f1 = fopen(ime_izlazne, "w");
	f2 = fopen(ime_ulazne, "r");
	if (f1 == NULL) {
		printf("Greska pri otvaranju datoteke!\n");
		exit(1);
	}
	if (f2 == NULL) {
		printf("Greska pri otvaranju datoteke!\n");
		exit(1);
	}
	int limit = N;
	int ascii[11];
	if (N > 10) limit = 10;
	for (i = 0; i < N; i++) {
		for (j = 0; j < konacna_lista[i].duzina; j++)
			fputc(konacna_lista[i].text[j], f1);
		fputc('\n', f1);
		ascii[i] = 20 + i;
	}
	fputc ('\n', f1);
	
	gledam_rijec = 1;
	ocisti_niz(trenutna_rijec);
	while ((znak = fgetc(f2)) != EOF) {
		if (!slovo(znak)) {
			trenutna_rijec[broj_znakova] = '\0';
			razmak = 1;
			
			if (gledam_rijec) {
				if (broj_znakova >= 1) {
					int nasao = 0;
					for (i = 0; i < N; i++)
						if (isti(konacna_lista[i].text, trenutna_rijec, konacna_lista[i].duzina, broj_znakova)) {
							fprintf(f1,"%c", ascii[i]);
							nasao = 1;
						}
					if (!nasao) fprintf(f1, "%s", trenutna_rijec);
				}
			}
			fprintf(f1, "%c", znak);
			ocisti_niz(trenutna_rijec);
			gledam_rijec = 1;
			broj_znakova = 0;
		}
		else {
			broj_znakova++;
			if (broj_znakova > 10) gledam_rijec = 0;
			if (gledam_rijec) trenutna_rijec[broj_znakova - 1] = znak;
			if (razmak == 1) broj_rijeci++;
			razmak = 0;
		}
	}
	if (broj_znakova >= 1 && broj_znakova <= 10) {
		int nasao = 0;
		for (i = 0; i < N; i++)
			if (isti(konacna_lista[i].text, trenutna_rijec, konacna_lista[i].duzina, broj_znakova)) {
				fprintf(f1,"%c", ascii[i]);
				nasao = 1;
			}
		if (!nasao) fprintf(f1, "%s", trenutna_rijec);
	}
	fclose(f2);
	
	fclose(f1);
	printf("Datoteka kompresovana.\n");
}
void dekompresuj(char *ime_ulazne, char *ime_izlazne) {
	
}
int main() {
	int opcija;
	opcija = -1;
	while (opcija != 0) {
		printf("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
		scanf("%d", &opcija);
		if (opcija == 1) {
			char ime_ulazne[500], ime_izlazne[500];
			printf("Unesite ime ulazne datoteke: ");
			unesi(ime_ulazne, 500);
			printf("Unesite ime izlazne datoteke: ");
			unesi(ime_izlazne, 500);
			kompresuj(ime_ulazne, ime_izlazne);
			
		}
		else if (opcija == 2) {
			char ime_ulazne[500], ime_izlazne[500];
			printf("Unesite ime ulazne datoteke: ");
			unesi(ime_ulazne, 500);
			printf("Unesite ime izlazne datoteke: ");
			unesi(ime_izlazne, 500);
			dekompresuj(ime_ulazne, ime_izlazne);
			printf("Datoteka dekompresovana.\n");
		}
		else break;
		
	}
	return 0;
}
