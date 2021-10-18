#include <stdio.h>

void unesi(char niz[], int velicina)
{
	char znak=getchar();
	if(znak=='\n')znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int provjeri_duzine(char* neki_string, int niz_brojeva[], int vel)
{
	int niz_duzina[1000];
	int nije_slovo=1;
	int duzina=0,i=0,j=0;
	int broj_rijeci=0;
	char* p=neki_string;
	while(*neki_string!='\0') {
		if(!((*neki_string>='A' && *neki_string<='Z') || (*neki_string>='a' && *neki_string<='z')))nije_slovo=1;
		else if(nije_slovo==1) {
			nije_slovo=0;
			broj_rijeci++;
		}
		neki_string++;
	}
	neki_string=p;
	while(*neki_string!='\0') {
		if((*neki_string>='A' && *neki_string<='Z') || (*neki_string>='a' && *neki_string<='z'))
			duzina++;
		if(!((*neki_string>='A' && *neki_string<='Z') || (*neki_string>='a' && *neki_string<='z'))){
			niz_duzina[i]=duzina;
			i++;
			duzina=0;
		}
		neki_string++;
	}
	i=0;
	j=0;
	do {
		if(broj_rijeci==vel && niz_duzina[i]==niz_brojeva[j] && j<vel)return 1;
		return 0;
		i++;
		j++;
	} while(i==j && i<broj_rijeci-1);
}

int main()
{
	printf("Zadaća 4, Zadatak 2");
	return 0;
}
