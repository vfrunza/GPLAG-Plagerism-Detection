#include <stdio.h>
#include <string.h>
#include <ctype.h>

int provjeri(const char* tekst);
int razdvoji(char* tekst, char** tokeni);
void ukloni_el(char** tokeni, int poz, int vel);

int main() {
	printf ("Provjera  6: %d\n", provjeri("< p> razmak prije p </p>"));
	
	return 0;
}

int provjeri(const char* tekst) {
	int i;
	int broj_tokena, poz_trenutnog = -1;
	char* tokeni[100];
	char var_tekst[1000] = "";
	strcpy(var_tekst, tekst);
	
	broj_tokena = razdvoji(var_tekst, tokeni);
	
	if (broj_tokena == 0)
		return 1;
	
	if (broj_tokena % 2 == 1)
		return 0;
		
	for (i = 0; i < broj_tokena; i++) {
		if (tokeni[i][0] != '/')
			poz_trenutnog = i;
		else {
			if (strcmp(tokeni[poz_trenutnog], tokeni[i] + 1) == 0) {
				ukloni_el(tokeni, i, broj_tokena);
				broj_tokena -= 1;
				ukloni_el(tokeni, poz_trenutnog, broj_tokena);
				broj_tokena -= 1;
				i = -1;
			} else {
				return 0;
			}
		}
	}
	
	return (broj_tokena == 0);
}

int razdvoji(char* tekst, char** tokeni) {
	char* token;
	int i = 0, j;
	
	for (j = 0; tekst[j] != '\0'; j++)
		tekst[j] = tolower(tekst[j]);
	
	if (strchr(tekst, '<') == NULL)
		return 0;
		
	while (isspace(*tekst))
		tekst += 1;
	
	token = strtok(tekst, "<");
	
	if (!isalpha(token[0]))
		return 1;
	
	tokeni[i] = token;
	i += 1;
	
	while (token != NULL) {
    	token = strtok(NULL, "<");
    	tokeni[i] = token;
    	i += 1;
	}
	
	for (j = 0; j < i - 1; j++)
		tokeni[j] = strtok(tokeni[j], "> ");
	
	return i - 1;
}

void ukloni_el(char** tokeni, int poz, int vel) {
	int i;
	
	for (i = poz; i < vel - 1; i++)
		tokeni[i] = tokeni[i + 1];
}
