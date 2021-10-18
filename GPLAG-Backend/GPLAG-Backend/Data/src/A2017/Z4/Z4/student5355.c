#include <stdio.h>

int provjeri(char *s) {
	char *poc, *kraj;
	int pom = 0;
	char *s1 = s;
	
	while(*s != '\0') {
		if(*s == '<') {
			kraj = s; kraj++;
			
				if(*kraj != '\0' && *kraj != '>' && *kraj != '<') kraj++;
				if(*kraj != '>') return 0;
		}
		s++;
	}
	s=s1;
	while(*s != '\0') {
		pom = 0;
		if(*s == '<') {
			pom = 1;
			poc = s;
			kraj = s;
			kraj++;
			while(*kraj != '\0' && *kraj != '>') kraj++;
			if(*kraj != '\0') kraj++;
			while(*kraj != '\0') {
				*poc = *kraj;
				poc++;
				kraj++;

			}
			*poc = '\0';
		}
		s++;
		if(pom == 1) s--;
	}
	return 1;
}
int main() {
	
	return 0;
}
