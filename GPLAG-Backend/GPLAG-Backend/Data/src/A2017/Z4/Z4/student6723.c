#include <stdio.h>

int provjeri(char* tekst) {
	char tagovi[100] = {48};
	int i, j, n = 0;

	for(i=0;; i++) {
		if(*tekst == '<') {
			if(*(++tekst) == '/') tekst++;
			while(*tekst != '\0') {
				if(*tekst != 32) {
					if(*tekst == '>') break;
					tagovi[n] = *tekst;
					n++;
					tekst++;
				} else {
					tekst++;
					break;
				}
			}
		} else if (*tekst == '\0') {
			break;
		} else {
			tekst++;

		}
	}
	j=0;
	for(i=0; i<n; i++) {
		//if(j+1>n) break;
		if(tagovi[j] == tagovi[j+1])
			j--;
		else if(tagovi[j] == tagovi[j+2])
			return 0;
		else
			j++;

	}
	if(j%2!=0) return 0;
	return 1;
}

int main() {
	return 0;
}