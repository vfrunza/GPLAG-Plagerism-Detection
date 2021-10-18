#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* pocetna_slova(char* string, char* prazni, int k)
{
	char* pr = prazni;
	char* vrati = prazni;
	char* p = string;
	char* prvo_slovo;
	int brojac = 0;
	//char *s=nova;
	int i=0,br,cifra;
	while(*p!='\0') {
		if(((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) && *p != '\0') {
			brojac=0;
			prvo_slovo = p;
			while(((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) && *p != '\0') {
				brojac++;
				p++;
			}
			if(brojac>k) { /* za slovo */
				*prazni = *prvo_slovo;
				prazni++;
			}
		}
		p++;
	}
	*prazni = '\0';


//strcpy(string, nova);
return vrati;
}
int main()
{
	char rijec[88]= {"Amar ide u Zenicu brate"};
	char nova[88];
	char* p=nova;
	p=pocetna_slova(rijec,nova,3);
	printf("%s",p);
	
	return 0;
}