#include <stdio.h>

int provjeri_duzine(char* recenica,int niz[],int duzina){
	int razmak=1,broj_rijeci=0,br_znakova=0,i=0,indikator=0,brojac=0;
	//stavi pokazivac na prvo slovo u stringu
	while(!((*recenica>='A' && *recenica<='Z') || (*recenica>='a' && *recenica<='z'))){
		recenica++;
		brojac++;
	}
	while(*recenica!='\0'){
		if(!((*recenica>='A' && *recenica<='Z') || (*recenica>='a' && *recenica<='z'))){
			razmak=1;
		}else if(razmak==1){
			razmak=0;
			broj_rijeci++;
		}
		recenica++;
		brojac++;
	}
	while(brojac!=0){
		recenica--;
		brojac--;
	}
	//ukoliko je duzina stringa manja od broja rijeci prekini program
	if(broj_rijeci!=duzina){
		return 0;
	}
	razmak=1;
	while(!((*recenica>='A' && *recenica<='Z') || (*recenica>='a' && *recenica<='z'))){
		recenica++;
	}
	broj_rijeci=0;
	while(*recenica!='\0'){
		if(!((*recenica>='A' && *recenica<='Z') || (*recenica>='a' && *recenica<='z'))){
			razmak=1;
			//ukoliko je indikator jednak 0 znaci da  pokazivac na prethodni znak ima vrijednost  slova
			if(indikator==0){
			for(i=0;i<duzina;i++){
				if(niz[broj_rijeci-1]!=br_znakova){
					return 0;
				}
			}
			}
			br_znakova=0;
			indikator+=1;
		}else if(razmak==1){
			indikator=0;
			broj_rijeci++;
			razmak=0;
		}
		//ukoliko je razmak 0 znaci da je pokazivac pokazuje na slovo 
		if(razmak==0){
		br_znakova++;
		}
		recenica++;
	}
	return 1;
}
int main() {
	char tekst[100]="Ovo...  je neki primjer teksta";
	int niz[5]={3, 2, 4, 7, 6};
	int br=provjeri_duzine(tekst,niz,5);
	printf("%d",br);
	return 0;
}
