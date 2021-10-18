#include <stdio.h>

int provjeri(char *pok) {
	char *s;
	char mat[20][20];
	int i=0,j;
	while (*pok != '\0') {
		while (*pok != '<' && *pok != '\0') {
			pok++;
		}
		if (*pok != '<') return 0;
		pok++;
		
		while (((*pok >= 'A' && *pok<='Z') ||(*pok>='a' && *pok<='z') || (*pok>='0' && *pok<='9')) && (*pok !='\0')) {
			mat[i][j]=*pok;
			j++;
			pok++;
		}
		mat[i][j]='\0';
		s=mat[i];
		if (*pok == '/') {
			pok++;
			if (*pok != *s) return 0;
		} 
		while(*pok++ == *s++);
		if (*s=='\0') { i--;}
		if (*pok != '>') {return 0;}
		
		pok++;
	}
return 1;
}