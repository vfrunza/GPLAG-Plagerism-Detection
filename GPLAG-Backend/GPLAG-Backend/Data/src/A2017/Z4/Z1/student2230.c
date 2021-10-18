#include <stdio.h>
char* ubaci_broj(char*tekst,int broj){
	char*pocetak = tekst;
	int kopija=broj,brojCifara;
	int prosiri=1;
	
	brojCifara=0;
	while(kopija!=0){
		brojCifara++;
		kopija/=10;
	}
	if(broj<0)prosiri++;
	prosiri+=brojCifara;
	
	char*k;
	
	while(*tekst!='\0'){
		
		if(*tekst==' ' && *(tekst-1)!=' '){
			k=tekst;
			while(*k!='\0'){
				k++;
			}
			
			while(k!=tekst){
				*(k+prosiri)=*k;
				k--;
			}
			
			tekst+=prosiri;
			*tekst--=' ';
			
			kopija=broj;
			if(kopija<0)kopija*=-1;
			while(kopija!=0){
				*tekst-- = kopija%10+'0';
				kopija/=10;
			}
			if(broj<0){
				*tekst='-';
			}
			tekst+=prosiri;
		}
		
		
		tekst++;
	}
	
	return pocetak;
}
int main() {
	char tekst[100]=" da ";
	int a=20;
	ubaci_broj(tekst,a);
	printf("%s",tekst);
	return 0;
}
