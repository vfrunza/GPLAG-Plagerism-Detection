#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Nou tajm sedli :/ */

/* globalna varijabla */
int brojac = 0;

/* Struktura koja broji ponavljanja */
typedef struct rijec {
	char string[200];
	int ponavljanja;
} struktura;

/* Funkcija za unos imena datoteke */
void unesi(char niz[], int velicina) {
    char znak = getchar();
    int i;
    
    if (znak == '\n') znak = getchar();
    i = 0;
    while (i < velicina-1 && znak != '\n')	{
        niz[i] = znak;
        i++;
        znak = getchar();
    }
    niz[i] = '\0';
}

/* Podfunkcije funkcije kompresuj */
void strukturiraj (char *string, struktura *rijeci) {
	int i;
	
	/* Prazan string ? */
	if (strcmp(string, "") == 0)
		return;
	
	/* Duza rijec od 10 ? */
	if (strlen(string) >= 10)
		return;
	
	/* Ponavljanje rijeci u strukturi ? */
	for (i=0;  i<brojac;  i++) {
		if (strcmp(rijeci[i].string, string) == 0) {
			rijeci[i].ponavljanja++;
			return;	
		}
	}
	
	strcpy (rijeci[i].string, string);
	rijeci[brojac].ponavljanja = 1;
	brojac++;
}

/* Sortbot funkcije kompresuj */
void sortbot (struktura *rijeci) {
	int i, j;
	
	struktura temp;
	
	/* Naci max ponavljanja i poredat ih */
	for (i=0; i<brojac; i++) {
		for (j=i+1; j<brojac; j++) {
			if (rijeci[i].ponavljanja < rijeci[j].ponavljanja) {
				temp = rijeci[i];
				rijeci[i] = rijeci[j];
				rijeci[j] = temp;
			}
		}
	}
	/* Sad ista ponavljanja sortiraj */
	for (i=0; i<brojac; i++) {
		for (j=i+1; j<brojac; j++) {
			if (rijeci[i].ponavljanja == rijeci[j].ponavljanja) {
				if (strcmp(rijeci[i].string, rijeci[j].string) > 0) {
					temp = rijeci[i];
					rijeci[i] = rijeci[j];
					rijeci[j] = temp;
				}
			}
		}
	}
}

/* Funkcija koja kompresuje proizvoljnu datoteku */
void kompresuj (char input[], char output[]) {
	
	struktura rijeci[1000];
	char slovo, znak;
	char string[200];
	char *poks = string;
	char inputlinija[1000];
	char *pokinput = inputlinija;
	char tempinput[1000];
	char maliniz[50];
	char *pokniz = maliniz;
	int i, j;
	char c, *pok;
	int kontrolna;
	
	/* Unos datoteke preko stringa */
	FILE *ulaz = fopen (input, "r+");
	if (!ulaz) {
		printf ("Greska pri otvaranju datoteke");
		exit (1);
	}
	/* Otvaram drugu datoteku "w+" u writing & read modu da ubacim top rijeci */
	FILE *izlaz = fopen(output, "w+");
	if (!izlaz) {
		fclose(ulaz);
		printf ("Greska pri otvaranju datoteke");
		exit (2);
	}
	
	FILE *tempdat = fopen ("tempdat.txt", "w+");
	if (!tempdat) {
		fclose (ulaz);
		fclose (izlaz);
		printf ("Greska pri otvaranju datoteke");
		exit (3);
	}
	
	do {
		slovo = fgetc(ulaz);
		
		if ((slovo >= 'a' && slovo <= 'z')||(slovo >= 'A' && slovo <= 'Z')) {
			*poks = slovo;
			poks++;
		}
		else {
			*poks = '\0';
			poks = string;	/* Funkcija koja ubacuje razlicite rijeci u strukturu */
			strukturiraj(string, rijeci);
		}
		
	} while (slovo != EOF);
	
	sortbot(rijeci);
	
	if (brojac > 10)
	brojac = 10;
	
	slovo = '\n';
	for (i = 0;  i < brojac; i ++) {
		fputs (rijeci[i].string, izlaz);
		fputc (slovo, izlaz);
	}
	
	/* Kopirati u fajl txt sa ascijevim kodovima umjesto rijeci */
//	for (i = 0; i < brojac; i ++)
		fseek(ulaz, 0, SEEK_SET); 
		while (fgets (inputlinija, 1000, ulaz)) {
		fputs (inputlinija, tempdat);
		}

	
	/* kopira u main dat */
	fseek (ulaz, 0, SEEK_SET);
	fseek (tempdat, 0, SEEK_SET);
	do {
		c = fgetc (tempdat);
		if (c != EOF) fputc (c, ulaz);
		if (ferror (tempdat) || ferror (ulaz))
		break;
	} while (!feof(tempdat));
	
	fclose(ulaz);
	fclose(izlaz);
	fclose(tempdat);
	
	brojac = 0;
	
	printf ("Datoteka kompresovana.\n");
}

int main() {
	int kontrolna = 0;
	char datinput[1000];
	char datoutput[1000];
	
	do {
	printf ("Odaberite: 1 - kompresuj, 2 - dekompresuj, 0 - izlaz: ");
	scanf ("%d", &kontrolna);
	
	if (kontrolna == 0)
	break;
	
	printf ("Unesite ime ulazne datoteke: ");
	unesi (datinput, 1000);
	printf ("Unesite ime izlazne datoteke: ");
	unesi (datoutput, 1000);
	
	if (kontrolna == 1)
		kompresuj (datinput, datoutput);
/*	else if (kontrolna == 2)
		dekompresuj(datoutput, datinput);
										*/
	} while (kontrolna != 0);
	
	return 0;
}