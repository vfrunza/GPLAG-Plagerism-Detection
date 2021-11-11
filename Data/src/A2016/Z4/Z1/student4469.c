#include <stdio.h>

void unesi(char niz[], int velicina){
    
	char znak = getchar();
	if (znak == '\n') znak=getchar();
	int i = 0;
	while (i < velicina-1 && znak != '\n') {
		niz[i] = znak;
		i++;
		znak = getchar();
	}
	niz[i]='\0';

}


char* izbaci_najcescu(char* s) {
	char*q,*vratis;
	vratis=s;
	while((*s<65 || (*s>90 && *s<97) || *s>122) && (*s!='\0')) {
	
	s++;                                            //pomjeramo s sve dok ne pokazuje na slovo
	}

if(*s=='\0') {
	s=vratis;    //ako u stringu nema slova, vracamo s na pocetak stringa i nazad u main
	return s;
}

while(*s!=' ' && *s!='\0'){
s++;	                           //Ako s pokazuje na slovo, da li je cijeli string jedna rijec?
}

if(*s=='\0'){                //ako je while prosao do kraja, s sada pokazuje na '\0', string je jedna rijec, vracamo s na pocetak rijeci i nazad u main 
s= vratis;
s[0]='\0';
return s;
}

s=vratis;



}

int main() {
	
	
	char recenica[100];
	
	unesi(recenica,100);

	
izbaci_najcescu(recenica);
	return 0;
}
