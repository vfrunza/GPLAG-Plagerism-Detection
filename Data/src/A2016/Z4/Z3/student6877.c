#include <stdio.h>
int slovo(char c){
	if((c>=65 && c<=90)||(c>=97 && c<=122)) return 1;
	return 0;
}
int mjenjati(char *tekst, char *rijec){
	char *pocetak=tekst;
	char *pocetakrijeci=rijec;
	int isto=1;
	while (*tekst!='\0' && *rijec!='\0') {
		if(*tekst!=*rijec) isto=0;
		tekst++;
		rijec++;
	}
	if((*tekst!='\0' && *tekst!=' ') || (*rijec!='\0' )) isto=0;
	tekst=pocetak;
	rijec=pocetakrijeci;
	return isto;
}
void zamjeni(char* tekst, char* rijec, char* novarijec){
	char* temp=tekst,*a=tekst,*rijtemp=rijec,*novatemp=novarijec;
	int visak=0,i,nastavi=1;
	while(*tekst!='\0'){
		nastavi=0;
		while(*tekst!=*rijec && *tekst!='\0'){
			tekst++;
		}
		if(*tekst!='\0' && (tekst==temp || *(tekst-1)==' ') && mjenjati(tekst,rijec)){
		   while(*novarijec!='\0'){
		   	if(*tekst==' '|| *tekst=='\0'){
		   		a=tekst;
		   		while(*tekst!='\0') tekst++;
		   		tekst++;
		   		while(tekst>a){
		   			*tekst=*(tekst-1);
		   			tekst--;
		   		}
		   	}
		   	*tekst=*novarijec;
		   	tekst++;
		   	novarijec++;
		   }	
		   nastavi=1;
		}
		if(*tekst!=' ' && *tekst!='\0' && nastavi==1){
			a=tekst;
			while(*tekst!=' ' && *tekst!='\0'){
				visak++;
				tekst++;
			}
		
		tekst=a;
		for(i=0;i<visak;i++){
			tekst=a;
			while(*tekst!='\0'){
				*tekst=*(tekst+1);
				tekst++;
			}
		}
		tekst=a;
	}
	if(*tekst!=' ' && *tekst!='\0') tekst++;
	rijec=rijtemp;
	novarijec=novatemp;
	}
	tekst=temp;
	rijec=rijtemp;
	novarijec=novatemp;
}
char* zamjena_rijeci(char* tekst, char**rijeci, char**zamjene , int broj_rijec){
	char* temptekst=tekst;
	int i;
	for(i=0;i<broj_rijec;i++){
		tekst=temptekst;
		while(*tekst!='\0'){
			while(*tekst==' ' && *tekst!='\0') tekst++;
			if(mjenjati(tekst,rijeci[i])){
				zamjeni(tekst,rijeci[i],zamjene[i]);
			}
			while(*tekst!=' ' && *tekst!='\0') tekst++;
		}
	}
	return temptekst;
}

int main() {
	char* rijeci[2] = {"", ""};
	char* zamjene[2] = {"", ""};
	char tekst[100] = "";
	printf("%s",zamjena_rijeci(tekst,rijeci,zamjene,2));
	return 0;
}
