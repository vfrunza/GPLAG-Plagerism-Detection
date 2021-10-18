#include <stdio.h>

int provjeri_duzine(char * recenica, int * niz,int n)
{

	int i,j=0;
	while(*recenica!='\0') {
		for(i=0; i<80; i++) {
			if((*recenica>='A' && *recenica<='Z') || (*recenica>='a' && *recenica<='z')) break;
			recenica++;
			if(*recenica=='\0') break;
		}
		for(i=0; i<80; i++) {
			if(*recenica<'A' || (*recenica>'Z' && *recenica<'a') || *recenica>'z') break;
			recenica++;
		}
		if(i==0) continue;
		if(i==niz[j]) j++; /*broj slova jedne rijeci je "i" provjerava se da li odgovara određenom broju niza (broj slova jedne rijeci je "i") */
		else return 0;
	}
	if(n!=j) return 0; /*prekida program i ispisuje nulu ukoliko se prebrojane rijeci ne poklapaju sa broje elemenata niza brojeva*/
	return 1;
}
int main()
{
	return 0;
}