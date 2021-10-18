#include <stdio.h>

/*funkcija za brojanje rijeci u stringu*/
int broj_rijeci(char *s){
	char *p=s;
	int br=0;
	while( *p !='\0'){
		if((*p>='A' && *p<='Z')||(*p>='a' && *p<='z')){
			while((*p>='A' && *p<='Z')||(*p>='a' && *p<='z'))p++;
			if(!((*p>='A' && *p<='Z')||(*p>='a' && *p<='z')) || *p=='\0') br++;
			p--;
		}
		p++;
	}
	return br;
}

int provjeri_duzine(char *s, int niz[], int velicina){
	char *p=s;
	int br_rijeci;
	int br_slova=0;
	int i=0, br_isto=0,broj;
	br_rijeci=broj_rijeci(p);
	/*provjera da li je velicina niza manja ili veca od broja rijeci u stringu*/
	if(br_rijeci!=velicina) return 0;
	/*ako je velicina niza ista kao i broj rijeci provjera duzine rijeci*/
	if(br_rijeci==velicina){
		while(*p!='\0'){
			if((*p>='A' && *p<='Z') ||(*p>='a' && *p<='z')){
				while((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) {
					br_slova++;
				    p++;
					}
					if(!((*p>='A' && *p<='Z') ||(*p>='a' && *p<='z')) || *p=='\0'){
						broj=niz[i];
					   if(br_slova==broj){ 
					   	br_isto++;
					    br_slova=0;
					   }
					   i++;
					   
					}
					p--;
			}
			p++;
		}
		if(br_isto==velicina) return 1;
	}
	return 0;
}
int main() {
	char tekst[]="Ovo je neki primjer teksta";
	int niz[]={3, 2, 4, 7, 6};
	int niz2[]={1, 2, 3, 4, 5};
	printf("%d ", provjeri_duzine(tekst, niz, 5));
	printf("%d ", provjeri_duzine(tekst, niz2, 5));
	printf("%d ", provjeri_duzine(tekst, niz, 3));
	return 0;
}
