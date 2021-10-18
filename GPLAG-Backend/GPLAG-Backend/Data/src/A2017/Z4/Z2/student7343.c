/*
#include <stdio.h>

int jel_slovo (char c){
	if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) return 1;
	return 0;
}

int koliko_slova(char *pok){
	int broj=0; 
	while(*pok != '\0' && jel_slovo(*pok)){
		pok++;
		broj++;
	}
	return broj;
}

int prebroji_rijeci(char *s){
	int razmak=1,br_r=0;
	while(*s != '\0'){
		if(!jel_slovo(*s)) razmak =1;
		else if(razmak){
			razmak=0;
			br_r++;
		}
		s++;
	}
	return br_r;
}

int provjeri_duzine(char*s, int*niz, int vel){
	int neslovo = 1; 
	int i = 0, broj_rijeci=prebroji_rijeci(s);

	while(*s != '\0'){
		if(!jel_slovo(*s)) neslovo = 1;
		else if(neslovo) {
			neslovo = 0;
				if(niz[i] != koliko_slova(s)) return 0;
				i++; 
				s--;
				
			}
		s++;
	}
	if(broj_rijeci != vel) return 0;
	return 1;
}
int main() {
	printf("Zadaća 4, Zadatak 2");
	return 0;
}*/



#include <stdio.h>

void unesi(char niz[], int vel){
	char znak = getchar();
	int i=0;
	if(znak == '\n') znak = getchar();
	while(i<vel-1 && znak != '\n'){
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';
}
int jel_slovo (char c){
	if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) return 1;
	return 0;
}

int koliko_slova(char *pok){
	int broj=0; 
	while(*pok != '\0' && jel_slovo(*pok)==1){
		pok++;
		broj++;
	}
	return broj;
}


void pocetna_slova(char *s, char *buf, int k){
	int neslovo =1;
	while (*s != '\0') {
		if(!jel_slovo(*s)) neslovo = 1;
		else if(neslovo==1){
			neslovo =0;
			if(koliko_slova(s) > k){
				*buf = s[0];
				buf++;
			}
			s--;
		}
		*buf = '\0';
		s++;
	}
}


int main() {
	char niz[100], buf[20]={'\0'};
	int k=0;
	printf("Unesi tekst: ");
	unesi(niz,100);
	printf("Unesi k: ");
	scanf("%d", &k);
	pocetna_slova(niz,buf, k);
	printf("%s", buf);
	return 0;
}
