#include <stdio.h>

void unesi(char niz[], int velicina) {
	char znak=getchar();
	int i=0;
	if(znak=='\n') znak=getchar();
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}

int provjeri_duzine(char* s, int niz[], int n) {
	
	int brojac=0, i=0, broj_rijeci=0;
	char*poc=s;
	
	while(*poc!='\0') {
		if((*poc>='A' && *poc<='Z') || (*poc>='a' && *poc<='z')) {
			while((*poc>='A' && *poc<='Z') || (*poc>='a' && *poc<='z')) {
				poc++;
			}
			broj_rijeci++;
		}
		if(*poc=='\0') poc--;
		poc++;
	}
	
	if(broj_rijeci!=n) return 0;
	
	while(*s!='\0') {
		if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
				brojac++;
				s++;
			}
			if(brojac==niz[i] && *s=='\0') {
				return 1;
			}
			
			else if(brojac==niz[i])
			{
				brojac=0;
				s++;
				i++;
			}
			else return 0;
		}
		else s++;
	}
	return 1;
}

int main() {
	char tekst[1000000];
	int niz[1000000], n, i;
	printf("Unesite string: ");
	unesi(tekst,1000000);
	printf("Unesite broj rijeci: ");
	scanf("%d", &n);
	printf("Unesite duzine rijeci: ");
	for(i=0; i<n; i++)
	scanf("%d", &niz[i]);
	printf("%d", provjeri_duzine(tekst,niz,n));
	
	return 0;
}







