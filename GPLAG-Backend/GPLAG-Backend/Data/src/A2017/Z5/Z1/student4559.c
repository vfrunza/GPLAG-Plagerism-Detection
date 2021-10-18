#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

struct Datum {
	int dan, mjesec, godina;
};

struct Uposlenik {
	char ime_prezime[50];
	struct Datum datum_rodjenja;
};

/* PROTOTIPI */
int surnameExtractor(char[2][50], char[50]);
int daysOfDifference(struct Datum, struct Datum);
int suzi_listu(struct Uposlenik*, int, struct Uposlenik, int);

int main() {
	
	return 0;
}

int surnameExtractor(char surnames[2][50], char full_name[50]) {
	int numOfSurname = 0, copyPos = 0;
	int i;
	
	for (i = 0; i < 50 && full_name[i] != '\0'; i++) {
		/* Ako slucajno postoje razmaci prije imena */
		while (full_name[i] == ' ')
			i++;
			
		/* Ako je dosao do kraja stringa to je to (u slucaju da zavrsavaju sa razmacima) */
		if (full_name[i] == '\0')
			break;
			
		/* Resetuj kopiranje prezimena */
		copyPos = numOfSurname = 0;
		
		while (full_name[i] != ' ' && full_name[i] != '\0') {
			/* Duplo prezime */
			if (full_name[i] == '-') {
				/* Stavi '\0' na kraj prvog prezimena */
				surnames[numOfSurname][copyPos] = '\0';
				
				numOfSurname++;
				copyPos = 0;
			}
			else
				surnames[numOfSurname][copyPos++] = full_name[i];
				
			i++;
		}
		surnames[numOfSurname][copyPos] = '\0';
	}
	
	return numOfSurname + 1;
}

int daysOfDifference(struct Datum prior, struct Datum latter) {
	struct tm tmp_prior = {0, 0, 0, prior.dan, prior.mjesec - 1, prior.godina - 1900};
	struct tm tmp_latter = {0, 0, 0, latter.dan, latter.mjesec - 1, latter.godina - 1900};
	
	time_t first = mktime(&tmp_prior);
	time_t second = mktime(&tmp_latter);
	
	if (first == (time_t)(-1) || second == (time_t)(-1))
		exit(1);
	
	return (int)(difftime(second, first) / (60 * 60 * 24));
}

int suzi_listu(struct Uposlenik* candidates, int numOfCand, struct Uposlenik CEO, int days) {
	char surnamesOfCEO[2][50];
	char tmpSurname[2][50];
	int numOfCEOSurnames, numOfCandSurnames;
	int i, j, k, stela;
	
	/* Ekstraktuje prezime direktora */
	numOfCEOSurnames = surnameExtractor(surnamesOfCEO, CEO.ime_prezime);
	
	for (i = 0; i < numOfCand; i++) {
		numOfCandSurnames = surnameExtractor(tmpSurname, candidates[i].ime_prezime);
		
		stela = 0;
		for (j = 0; j < numOfCEOSurnames; j++)
			for (k = 0; k < numOfCandSurnames; k++)
				if (!strcmp(surnamesOfCEO[j], tmpSurname[k]))
					stela = 1;
					
		if (stela)
			continue;
		
		if (daysOfDifference(candidates[i].datum_rodjenja, CEO.datum_rodjenja) <= days)
			continue;
			
		for (j = i; j < numOfCand - 1; j++)
			candidates[j] = candidates[j + 1];
			
		i--;
		numOfCand--;
	}
	
	return numOfCand;
}