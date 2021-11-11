#include <stdio.h>
int JelSlovo(char x){ 
	if(x==0) return 0;
	if(x<65 || x>122) return 0;
	if(x>90 && x<97) return 0;
	return 1;
}
int BrojSlova (char *x){ 
	int brojac=0;
	while (x[brojac]!='\0'){
		brojac++;
	}
	return brojac;
}
int NebitanCaps(char x, char y){ 
	if (x>=65 && x<=90){
		if(x==y || x+32==y) return 1;
	}
	if (x>=97 && x<=122){
		if (x==y || x-32==y) return 1;
	}
	return 0;
}
int RijecNebitanCaps(char *pocetak,char *izakraja,char *pocetak2, char *kraj2){ 
	char *pomocni=pocetak;
	char *pomocnarijec=pocetak2;
	if (izakraja-pocetak!=kraj2-pocetak2) return 0;
	while (pomocni!=izakraja){
		if(!NebitanCaps(*pomocni,*pomocnarijec)) return 0;
		pomocni++;
		pomocnarijec++;
	}
	return 1;
}
int Prebroji (char *tekst, char *poc, char *kraj){
	int brojac_ponavljanja_rijeci=0;
	char *pocetak=tekst;
	while (*pocetak!='\0'){
		while(*pocetak!='\0' && !NebitanCaps(*pocetak,*poc)){
			pocetak++;
		}
		if (pocetak==tekst || JelSlovo(*(pocetak-1))==0){
			char *POMOCNI=pocetak;
			while (*POMOCNI!='\0' && JelSlovo(*POMOCNI)==1){
				POMOCNI++;
			}
			if (RijecNebitanCaps(pocetak,POMOCNI,poc,kraj)){
				brojac_ponavljanja_rijeci++;
			}
		}
		if(*pocetak!='\0')
		pocetak++;
	}
	return brojac_ponavljanja_rijeci;
}
char *IzbaciRijeci(char *pocetak, char *izakraja, char *tekst){ 
	int broj_slova=izakraja-pocetak;
	char *pomocni=pocetak;
	while (*(pomocni+broj_slova-1)!='\0'){
		*pomocni=*(pomocni+broj_slova);
		pomocni++;
	}
	return pocetak;
}
char *izbaci_najcescu(char *s){
	char *pom=s;
	char *izakraja,*pmax,*kmax,*dalje,*dostaba;
	int a;
	int max=0;
	while(*pom!='\0'){
		while(*pom!='\0' && JelSlovo(*pom)==0) pom++;
		izakraja=pom;
		while(*izakraja!='\0' && JelSlovo(*izakraja)==1) izakraja++;
		a=Prebroji(s,pom,izakraja);
		if(a>max){
			max=a;
			pmax=pom;
			kmax=izakraja;
		}
		pom=izakraja;
	}
	dalje=kmax+1;
	while(max>1){
		while(*dalje!='\0' && !NebitanCaps(*dalje,*pmax)) dalje++;
		if(dalje==s || JelSlovo(*(dalje-1))==0){
		dostaba=dalje;
		while(*dostaba!='\0' && JelSlovo(*dostaba)==1) dostaba++;
		if(RijecNebitanCaps(pmax,kmax,dalje,dostaba)){
		IzbaciRijeci(dalje,dostaba,s);
		max--;
	}
		
	else dalje++;
		}
		else dalje++;
}
if (max){
	IzbaciRijeci(pmax,kmax,s);
}
return s;
}
int main() {
	char tekstic[]="Svak-svak suncan suncan svak-svak dan dan dan";
	printf("%s",izbaci_najcescu(tekstic));
	return 0;
}