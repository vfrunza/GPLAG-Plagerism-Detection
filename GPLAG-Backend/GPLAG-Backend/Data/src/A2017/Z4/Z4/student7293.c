#include <stdio.h>

int provjeri (char* s) {
	
	char *pom = s;
	int br1=0, br2=0;
	
	while(*pom!='\0') {
		if (*pom == '<') br1++;
		if (*pom == '>') br2++;
		pom++;
	}
	
	if (br1 != br2) return 0;
	
	while (*s!='\0') {
		if (*s=='<' && *(s+1)=='>') return 0;
		else if (*s=='>' && *(s+1)=='<') return 0;
		if (*s)
		s++;
	}
	
	return 1;
}

int main() {
	printf("Zadaća 4, Zadatak 4");
	return 0;
}
