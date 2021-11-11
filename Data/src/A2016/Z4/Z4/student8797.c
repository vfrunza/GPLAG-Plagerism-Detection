#include <stdio.h>
#include <string.h>

/*funkcija koja provjerava da li je unijeti string ispravnog formata*/
int DaLiJeDobro(char*s, float x , float y , float a , float b){
	char*p=s;
	
	if(x>a) 
		return 0;
	if(y>b) 
		return 0;
	
	while(*p!='\0'){
		if(*p!='(') return 0;
		p++;
		if(*p=='\0') return 0;
		if(*p!='-'&& !(*p>='0'&&*p<='9')) return 0;
		p++;
		if(*p=='\0') return 0;
		while(*p>='0'&&*p<='9' && *p!='\0') p++;
		if(*p=='\0') return 0;
		if(*p!='.' && *p!=',') return 0;
		if(*p=='.'){
			p++;
			if(*p=='\0') return 0;
			while(*p>='0'&&*p<='9' && *p!='\0') p++;
			if(*p=='\0') return 0;
			if(*p!=',') return 0;
		}
		p++;
		if(*p=='\0') return 0;
		if(*p!='-'&& !(*p>='0'&&*p<='9')) return 0;
		p++;
		if(*p=='\0') return 0;
		while(*p>='0'&&*p<='9' && *p!='\0') p++;
		if(*p=='\0') return 0;
		if(*p!='.' && *p!=')') return 0;
		if(*p=='.'){
			p++;
			if(*p=='\0') return 0;
			while(*p>='0'&&*p<='9' && *p!='\0') p++;
			if(*p=='\0') return 0;
			if(*p!=')') return 0;
		}
		if(*p=='\0') return 0;
		p++;
		if(*p==',' && *(p+1)=='\0') return 0;
		if(*p!=','){
			if(*p=='\0') break;
            return 0;
		}
		p++;
	}
	return 1;
}
/*Funkcija koja vraca duzinu stringa*/
int Duzina(char*p){
	int i=0;
	while(*(p+i)!='\0'){
		i++;
	}
	return i;
}
/*funkcija koja provajerava da li su koordinate u opsegu*/
int DaLiJeUOpsegu(float x, float y , float x1, float y1, float x2, float y2){
	if(x<x1) return 0;
	if(x>x2) return 0;
	if(y<y1) return 0;
	if(y>y2) return 0;
	return 1; 
}
/*funkcija koja izbacuje koordinate koji nisu u opsegu*/
void izbaci(char*pocetak, int duzina){
	while(*(pocetak+duzina)!='\0'){
				*pocetak=*(pocetak+duzina);
				pocetak++;
			}
		*pocetak=*(pocetak+duzina);
}
/*glavna funkcija*/
char*obuhvat(char*text, float x, float y, float a, float b){
	char*p=text;
	int int_dio=0;
	float decimala=0;
	int k,duzina;
	int cifra;
	float x0, y0;
	int minus=0;
	char*pocetak;

    /* U slucaju da string nije ispravnog formata, isprazni ga i vraza \0 */
	if(DaLiJeDobro(p,  x  , y  , a  ,  b)==0){
		izbaci(p,Duzina(p)); 
		return '\0';
	}	
	
	
	while(*p!='\0'){
        pocetak=p;
		p++;
		if(*p=='-') {minus=1;p++;}
		int_dio=0;decimala=0;
		while(*p>='0'&&*p<='9'){
			int_dio=int_dio*10+(*p-'0');
			p++;
		}
		if(*p=='.'){
			p++;
			if(*p!=',') {
			k=10;
			while(*p>='0'&&*p<='9'){
				cifra=((*p-'0'));
				decimala=decimala+(float)(cifra)/k;
			    k*=10;
			    p++;
			}}
		}
		x0=int_dio+decimala;
		if(minus==1){
			x0=0-x0;
			minus=0;
		}
		p++;
		if(*p=='-') {minus=1;p++;}
		
		int_dio=0;decimala=0;
		while(*p>='0'&&*p<='9'){
			int_dio=int_dio*10+(*p-'0');
			p++;
		}
		if(*p=='.'){
			p++;
			if(*p!=')') {
			k=10;
			while(*p>='0'&&*p<='9'){
				cifra=((*p-'0'));
				decimala=decimala+(float)(cifra)/k;
			    k*=10;
				p++;
			}}
		}
		y0=int_dio+decimala;
		if(minus==1){
			y0=0-y0;
			minus=0;
		}
		p++;
		if(*p==0 && pocetak!=text) pocetak=pocetak-1;
		if(*p!='\0') p++;
		
		/* U slucaju ako su koordinate van opsega izbacuje ih */
		if(DaLiJeUOpsegu(x0,y0,x,y,a,b)==0){
			duzina=p-pocetak;
			izbaci(pocetak,duzina);
			p=pocetak;
		}
	}
	return text;
}
int main() {
	return 0;
}
