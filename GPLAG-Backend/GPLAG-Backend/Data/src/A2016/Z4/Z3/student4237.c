#include <stdio.h>
/*Funkcija koja vraca duzinu stringa*/
int Duzina(char*s){
	int i=0, duzina=0;
	while(*(s+i)!='\0'){
		duzina++;i++;
	}
	return duzina;
}
char*zamjena_rijeci(char*text, char**rijeci, char**zamijene, int broj_rijeci){

	int i,j,duzina1,duzina2;
    char*provjera=text;
    char*izbaci=text;
    char*ubacivac;
    char*kraj=text;;
    
    for(j=0; j<broj_rijeci; j++){
		duzina1=Duzina(rijeci[j]);
		duzina2=Duzina(zamijene[j]);
		provjera=text;
		while(*provjera!='\0'){
			char*p=provjera;
			char*q=rijeci[j];
			while(*p==*q && *q!='\0'){
				p++;q++;
				if(*p=='\0' && *q!='\0')
				break;
				/* Ako nadje rijec iz stringa rijeci zamijeni je sa odgovarajucom rijeci iz stringa zamjena */
				if(*q=='\0'&&(provjera==text||*(provjera-1)==' ')&&(*p==' '|| *p=='\0')){
						izbaci=provjera;
						while(*(izbaci+duzina1)!='\0'){
							*izbaci=*(izbaci+duzina1);
							izbaci++;
						}
						*(izbaci)=*(izbaci+duzina1);
						
						kraj=izbaci;
						
						while(kraj>provjera-1){
							*(kraj+duzina2)=*(kraj);
							kraj--;
						}
						ubacivac=provjera;
						for(i=0;i<duzina2;i++){
							*ubacivac=zamijene[j][i];
							ubacivac++;
						}}
				}
			provjera++;
		}
    } 

	return text;
}
int main() {
	char* rijeci[2] = { "auto", "stop" };
	char* zamjene[2] = { "vozilo", "start" };
	char tekst[100] = "auto-stop auto. stop auto kj stop";
	printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 2));
	return 0;
}
