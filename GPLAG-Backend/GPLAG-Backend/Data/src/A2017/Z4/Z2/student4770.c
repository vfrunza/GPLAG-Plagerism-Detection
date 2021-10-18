#include <stdio.h>
int broj_rijeci(char *recenica){
	int rijeci=0,ne_slovo=1;
	while(*recenica!='\0'){
		if(!((*recenica>='a' && *recenica<='z')|| (*recenica>='A' && *recenica<='Z'))) ne_slovo=1;
		else if(ne_slovo==1){
			ne_slovo=0;
			rijeci++;
		}
		recenica++;
	}
	return rijeci;
}
int provjeri_duzine(char* recenica, int niz[],int vel){
	int br_slova=0,br_rijeci=0,true=1,i=0;
	char* p=recenica;
	char* k=recenica;
	br_rijeci=broj_rijeci(recenica);
	if(br_rijeci!=vel) return 0;
	while(*recenica!='\0'){
		if(!((*recenica>='a' && *recenica<='z') || (*recenica>='A' && *recenica<='Z')))
			while(!((*recenica>='a' && *recenica<='z') || (*recenica>='A' && *recenica<='Z')) && *recenica!='\0') recenica++;
		p=recenica;
		while(((*recenica>='A' && *recenica<='Z') ||(*recenica>='a'&&*recenica<='z')) && *recenica!='\0')recenica++;
		k=recenica;
		while(p<k){
			br_slova++;
			p++;
		}
		if(br_slova!=niz[i]) true=0;
		i++;
		if(i==vel) break;
		br_slova=0;
		if(*recenica!='\0')recenica++;
	}
	return true;
}
int main() {
	char tekst[] = "Kakav je ovo test!?!?";
	int niz[] = {5,2,3,4};	
	printf("\n%d ", provjeri_duzine(tekst, niz, 4));
	return 0;
}
