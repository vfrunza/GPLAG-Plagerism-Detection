#include <stdio.h>

char* izbaci_najcescu(char* s) {
	char* tmp=s;
	
	/* Provjera da li je string prazan. */
	
	if(*s=='\0') {
		printf("");
	}
	return tmp;
}

int main() {

	char t[10] = "";
	izbaci_najcescu(t);
	printf("%d '%s'", t[0], t);

	return 0;
}
