#include<stdio.h>
int provjeri_duzine(char *s, int *p, int vel) {
	int rijec_duz,i=0,broj=0;
	char *tmp=s;
	while (*tmp!='\0') {
		if((*tmp>='A' && *tmp<='Z') || (*tmp>='a' && *tmp<='z')) {
			while((*tmp>='A' && *tmp<='Z') || (*tmp>='a' && *tmp<='z')) tmp++;
			broj++;
			tmp--;
		}
		tmp++;
	}
	if(broj!=vel) return 0;
	while(*s!='\0') {
		rijec_duz=0;
		if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			while((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
				rijec_duz++;
				s++;
			}
			if(rijec_duz!=p[i]) return 0;
			i++;
		}
		if(*s=='\0') break;
		s++;
	}
	return 1;
}
int main() {
	char stihovi1[]="Je l' Sarajevo gdje je nekad bilo, il' se mome srcu ucinilo...";
	char stihovi2[]="Zatvori oci zelenooka nocas opet igra stari film...";
	int broj_rijeci1[]={2,1,8,4,2,5,4,2,2,4,4,7};
	int broj_rijeci2[]={7,3,9,5,4,4,5,4};
	int proba1,proba2,proba3,proba4;
	proba1=provjeri_duzine(stihovi1,broj_rijeci1,12);
	proba2=provjeri_duzine(stihovi1,broj_rijeci2,8);
	proba3=provjeri_duzine(stihovi2,broj_rijeci1,8);
	proba4=provjeri_duzine(stihovi2,broj_rijeci2,8);
	printf("%d\n%d\n%d\n%d",proba1,proba2,proba3,proba4);
	
	return 0;
}
