#include <stdio.h>
#include <ctype.h>
#include <string.h>

void najduzi_bp(char* s1, char* s2);
int sadrzi_slovo(char* tekst, char slovo);

int main() {
	char niz[10];
	najduzi_bp ("Ovo je neki primjer teksta", niz);
	printf ("Niz: '%s'", niz);

	return 0;
}

/* zanemaruje se case slova */
int sadrzi_slovo(char* tekst, char slovo) {
	int i;

	slovo = tolower(slovo);
	
	for (i = 0; tekst[i] != '\0'; i++)
		if (tolower(tekst[i]) == slovo)
			return 1;

	return 0;
}

void najduzi_bp(char* s1, char* s2) {
	int i, j;
	int s2_i = 0, najduzi = 0;
	char temp[100] = "";
	
	for (i = 0; s1[i] != '\0'; i++) {
		if (isalpha(s1[i])) {
			s2_i = 0;
			
			for (j = 0; j < 100; j++)
				temp[j] = '\0';
			
			for (j = i; s1[j] != '\0' && isalpha(s1[j]); j++) {
				if (sadrzi_slovo(temp, s1[j]))
					break;
					
				temp[j - i] = s1[j];
			}
			
			s2_i = j - i;
			temp[s2_i] = '\0';
			
			if (s2_i > najduzi) {
				strcpy(s2, temp);
				najduzi = s2_i;
			}
			
		}
	}
}
