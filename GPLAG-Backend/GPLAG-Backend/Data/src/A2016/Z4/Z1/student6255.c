#include <stdio.h>
#include <stdlib.h>
void unesi(char niz[], int velicina)
{
	char znak = getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}
char* izbaci_najcescu(char *s)
{
	char *pocetak=s;
	char *pt=NULL, *kraj=NULL, *novi=NULL, *poc=NULL, *pocmax=NULL, *krajmax=NULL, *izbacivanje=NULL;
	int broj=0, max=0;
	while(*s!='\0') {
		if((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')) {
			pt=s;
			poc=s;
			while((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')) s++;
			kraj=s;
			novi=s;
			broj=0;
			while(*novi!='\0') {
				if(pt==kraj && !((*novi>='a' && *novi<='z') || (*novi>='A' && *novi<='Z')) && ( *(novi-kraj+poc-1)==' ' || *(novi-kraj+poc-1)=='3')) {
					broj++;
					pt=poc;
					if(broj>max) {
						max=broj;
						pocmax=poc;
						krajmax=kraj;
					}
					continue;
				}
				if(*novi!=*pt && *novi!=*pt+'A'-'a' && *novi!=*pt+'a'-'A') {
					pt=poc;
					novi++;
					continue;
				}
				pt++;
				novi++;
			}
			if(pt==kraj) {
				broj++;
				pt=poc;
				if(broj>max) {
					max=broj;
					pocmax=poc;
					krajmax=kraj;
				}
			}
		} else s++;
	}
	if(pocmax==NULL) {
		pocmax=pocetak;
		while((*pocmax>='a' && *pocmax<='z') || (*pocmax>='A' && *pocmax<='Z')) pocmax++;
		krajmax=pocmax;
		pocmax=pocetak;
	}
	poc=pocmax;
	novi=krajmax;
	kraj=krajmax;
	if(novi!=NULL) {
		while(*novi!='\0') {
			if(pocmax==kraj && !((*novi>='a' && *novi<='z') || (*novi>='A' && *novi<='Z')) && (*(novi-kraj+poc-1)==' ' || *(novi-kraj+poc-1)=='3')) {
				pocmax=poc;
				izbacivanje=novi;
				while(*izbacivanje!='\0') {
					*(izbacivanje-kraj+pocmax)=*izbacivanje;
					izbacivanje++;
				}
				*(izbacivanje-kraj+pocmax)='\0';
				novi--;
				novi--;
				novi--;
				continue;
			}
			if(*novi!=*pocmax && *novi!=*pocmax+'A'-'a' && *novi!=*pocmax+'a'-'A') {
				pocmax=poc;
				novi++;
				continue;
			}
			pocmax++;
			novi++;
		}
		if(pocmax==kraj && (*novi==*kraj || *novi=='\0')) {
			pocmax=poc;
			izbacivanje=novi;
			while (izbacivanje!='\0') {
				*(izbacivanje-kraj+pocmax)=*izbacivanje;
				izbacivanje++;
			}
			*(izbacivanje-kraj+pocmax)='\0';

		}
	}
		if(kraj!=NULL) {
			while(*kraj='\0') {
				*poc=*kraj;
				poc++;
				kraj++;
			}
			*poc='\0';
		}
		return pocetak;
	}

	int main() {
		char ime[90];
		printf("Unesite ime: ");
		unesi(ime,90);
		printf("%s",izbaci_najcescu(ime));
		return 0;
	}
