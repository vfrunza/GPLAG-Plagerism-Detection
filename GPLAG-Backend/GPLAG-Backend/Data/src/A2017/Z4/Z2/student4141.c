#include <stdio.h>


void unesi(char niz[],int velicina) {
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	int i=0;
	while(i<velicina-1 && znak!='\n') {
		niz[i]=znak;
		i++;
		znak=getchar();
	}
	niz[i]='\0';
}


int provjeri_duzine(char *string, int niz[], int duzina_niza) {
	int brojac=0,broj=0, slovo;
	while(*string!='\0') {
		slovo=0; 
		while((*string>='A' && *string<='Z') || (*string>='a' && *string<='z')) { 
			brojac++; 
			string++; 
			slovo=1; 
		}
		if(broj<=duzina_niza) { 
			if(slovo==1) 
				if(brojac!=niz[broj])
					return 0;  
			if(slovo==1) broj++; 
			if(*string!='\0') 
				string++; 
			brojac=0; 
		} else return 0; 
	}
	
	if(broj!=duzina_niza) return 0; 
	
	return 1; 
}

int main() {
	int niz[100],i,n;
	char string[100];
	printf("Unesite recenicu: ");
	unesi(string, 100);
	printf("Unesite velicinu niza: ");
	scanf("%d", &n);
	printf("Unesite niz: ");
	for(i=0; i<n; i++) {
		scanf("%d", &niz[i]);
	}
	provjeri_duzine(string, niz, n);
	return 0;
}
