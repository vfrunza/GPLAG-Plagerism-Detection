#include <stdio.h>

int provjeri_duzine(char *string, int niz[], int duzina_niza) {
	int i = 0, j = 0, a = 0;
	while (*string != '\0') {
		i = 0;
		while((*string >= 'A' && *string <= 'Z') || (*string >= 'a' && *string <= 'z')) {
			i++;
			string++;
		}
		if(i != 0) {
			a++;
			j++;
			i = 0; }
			else
			string++;
	}
	if(a == duzina_niza && *string=='\0')
	return 1;
	return 0;
}
int main() {
	return 0;
}

