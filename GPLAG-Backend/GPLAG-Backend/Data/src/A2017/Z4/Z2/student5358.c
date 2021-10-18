#include <stdio.h>

int provjeri_duzine(char *s,int niz[],int velicina){
	int velicina_niza;
	char *pomocni=s;
	int neslovo=1;
	int broj_karaktera=0;
	int i=0;
	int broj_rijeci=0;
	
	
	while(*pomocni!='\0'){
		if(!((*pomocni>='A' && *pomocni<='Z') || (*pomocni>='a' && *pomocni<='z'))){
		neslovo=1;
		}
		else if(neslovo==1){
			neslovo=0;
			broj_rijeci++;
			while((*pomocni>='A' && *pomocni<'Z') || (*pomocni>='a' && *pomocni<='z') && *pomocni!='\0'){
				broj_karaktera++;
				pomocni++;
			}
			
			if(broj_karaktera==niz[i]){
				i++;
				pomocni--;
				broj_karaktera=0;
	
			}
			else{
				return 0;
			}
		}
		pomocni++;
	}
	
	if(broj_rijeci==velicina)
	return 1;
	else 
	return 0;
}


int main() {
	char tekst[]={"Napravicemo jos jedan primjer"};
	int niz[]={11,3,5,7};
	printf("%d",provjeri_duzine(tekst,niz,0));
	return 0;
}
