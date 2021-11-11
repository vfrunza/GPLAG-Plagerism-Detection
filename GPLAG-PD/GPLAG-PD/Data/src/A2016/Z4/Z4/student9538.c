#include <stdio.h>
#include<stdlib.h>
#define eps 0.0001

int dalitrebaizbacit(double x,double y,double x1, double y1, double x2, double y2) {
	if(y>y2 || y<y1 || x<x1 || x>x2)
	return 1;
	else return 0;
} double napravibroj(double cijelidio, double ostatak, int predznak) {
	double broj=(cijelidio+ostatak)*predznak;
	return broj;
}
int losformat (char znak) {
	if(!((znak>=48 && znak<=87) || znak=='-' || znak=='.'))
	return 1;
	else return 0;
}
char* obuhvat(char*tekst, double x1, double y1, double x2, double y2){//donji lijevi i gornjidesni

		char*s=tekst;
	    char*poc;
		
	double x,y,o,ostatak;
	int imadec, predznak,cijelidio;
		while(*s!='\0' ){
		if(*s=='(' && s!=tekst && *(s-1)!=',') return 0;
		if(*s='(') {poc=s;   s++;}
		if(*s=='.' || *s==',') return 0;
		x=0; ostatak=0; cijelidio=0; o=0.1;  imadec=0; predznak=1;
		while(*s!=',') {
			if(losformat(*s)==1) return 0;
			if(*s=='-'){ if(*(s-1)==',') return 0;  s++; predznak=-1;}
			if(*s=='.') {imadec=1; s++;}
			if(*s==',') break;
			
			if(imadec==0){
				cijelidio=cijelidio*10+(*s-48);
			}
			if(imadec==1){
				ostatak=ostatak+(*s-48)*o;
				o=o/10;
			}
			
			s++;
		}
		x=napravibroj(cijelidio,ostatak,predznak);
		
		s++;
		 if(*s=='.' ||*s==')') return 0;
            y=0; o=0.1; cijelidio=0; ostatak=0; imadec=0; predznak=1;
			while(*s!=')') {
				if(losformat(*s)==1) return 0;
			    if(*s=='-'){s++; predznak=-1;}
			    if(*s=='.') {imadec=1; s++;}
			
		
			if(imadec==0){
				cijelidio=cijelidio*10+(*s-48);
			}
			if(imadec==1){
				ostatak=ostatak+(*s-48)*o;
				o=o/10;
			}
			s++;
		}
	    y=napravibroj(cijelidio,ostatak,predznak);
		
		
		
	char*a=poc;
	int izb=0;
	int vr= dalitrebaizbacit(x,y,x1,y1,x2,y2);
	int zadnjarijec=0,jedinarijeczaizbacit=0;
		if(vr==1){
		    
			izb=1;
			if(poc==tekst && *(s+1)=='\0') {
				    jedinarijeczaizbacit=1;
				}
				
			if (*(s+1)=='\0') {
			    zadnjarijec=1;
			}
		
			
			if(jedinarijeczaizbacit==1){
			    *tekst='\0'; return tekst;
			}
			else if(zadnjarijec==1){
			    *(poc-1)='\0';  return tekst;
			}
			else {
			char*hod=s+2;
			while(*hod!='\0') {
			    *poc=*hod;
				poc++;hod++;
			}
			*poc='\0';
		
			}
		}
		
		
		if(izb==1){
		    s=a; 
		}
		
		else if(*(s+1)=='\0')  
		            s++;
		else s+=2;
		if(*s!='(') return 0;
	//	printf("%c",s);

		}
			
		//s na \0
		if(s!=tekst)
		s--;
		if(*s!=')') return 0;
		return tekst;
}
int main() {
	char s[]="(0,-3.1),(-15.09,4),(2.,2),(-1.1,217)";
	char*rez=obuhvat(s,-3,-3,3,3);
	printf("%s %s",rez,s);
	return 0;
}