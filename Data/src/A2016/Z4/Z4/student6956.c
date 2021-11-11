#include <stdio.h>
#include <stdlib.h>
#define eps 0.0001

void izbaci(char*s, char*poc){
	char*hod=s+2;
	while(*hod!='\0'){
		*poc++=*hod++;
	}
		*poc='\0';
	
}
int imasmeca(char s){
	if(!((s>=48 && s<=87) || s=='-' || s=='.')) return 1;
	else return 0;
}

int br(char s){
	int broj=s-48;
	return broj;
}
int nijeslovo(char s){
	if(!(s>=48 && s<=87)) return 1;
	else return 0;
}
void mod1(char*s, double niz[]){
	int predznak=1, imadec=0;
	double o=0.1;
	
	while(*s!=','){
		if(!((*s>=48 && *s<=87) || *s=='-' || *s=='.')) return 0;
		
		if(nijeslovo(*s)){
			if(*s=='-') predznak=-1;
			if(*s=='.') imadec=1;
			s++;
			if(*s==',') break;
		}
		int cifra=br(*s);
		if(imadec==0){
			niz[0]=niz[0]*10+cifra;
		}
		if(imadec==1){
			niz[0]=niz[0]+cifra*o;
			o=o/10;
		}
		s++;
	}
	niz[0]*=predznak;
}
void mod2(char*s, double niz[]){
	int predznak=1, imadec=0;
	double o=0.1;
	while(*s!=')'){
		if(!((*s>=48 && *s<=87) || *s=='-' || *s=='.')) return 0;
		if(nijeslovo(*s)){
			if(*s=='-') predznak=-1;
			if(*s=='.') imadec=1;
			s++;
			if(*s==')') break;
		}
		int cifra=br(*s);
		if(imadec==0){
			float broj=niz[1]*10+cifra;
			niz[1]=broj;
		}
		if(imadec==1){
			float broj=niz[1]+cifra*o;
			niz[1]=broj;
			o=o/10;
		}
		s++;
	}
	niz[1]*=predznak;
}
char* obuhvat(char*tekst, double x1, double y1, double x2, double y2){
	char*krajprosle;
	char*s=tekst;
	char*zg=tekst;
	char*poce=tekst;
	
	double x=0, y=0, o;
	int otvorena=0, zatvorena=0, zarez=0;
	if(*zg!='(') return 0;
	while(*zg!='\0'){
		if(*zg=='(') otvorena++;
		if(*zg==')') zatvorena++;
		if(*zg==',') zarez++;
		if(*zg=='!') return 0;
		zg++;
	}
	zg--;
	if(*zg!=')') return 0;
	if(otvorena!=zatvorena) return 0;
	if((otvorena+zatvorena)/2+otvorena-1!=zarez) return 0;
	double niz[2]={0,0};
	while(*s!='\0'){
		char*poc;
		if(*s==','){ s++;
		if(*s!='(') return 0;
		}
		if(*s=='(') 
		poc=s;
		if(s!=tekst && *(s-1)!=',') return 0;
		s++;
		if(*s=='.' || *s==',') return 0;
		mod1(s, niz);
		while(*s!=',') s++;
		if(*(s+1)==')') return 0;
		s++;
		if(*(s)=='.') return 0;
		
		mod2(s,niz);
		while(*s!=')') s++;
		
		char*a=poc;
		int izb=0;
		if(niz[1]-y2>eps || y1-niz[1]>eps || x1-niz[0]>eps || niz[0]-x2>eps){
			izb=1;
			if(poc==tekst && *(s+1)=='\0'){
				*tekst='\0';
				return tekst;
			}
			
			if(*(s+1)=='\0'){
				*(poc-1)='\0';
				return tekst;
			}
			izbaci(s,poc);
		}
		if(izb) s=a;
		else s++;
		if(*s==',') s++;
		if(*s!='(') return 0;
		niz[0]=0;
		niz[1]=0;
		
		}
		return tekst;
}
int main() {
	char s[]="(0,-3.1),(-15.09,4),(-1.1,217)";
	char* rez=obuhvat(s, -3,-3,3,3);
	printf("%s %s", rez, s);
	return 0;
}
