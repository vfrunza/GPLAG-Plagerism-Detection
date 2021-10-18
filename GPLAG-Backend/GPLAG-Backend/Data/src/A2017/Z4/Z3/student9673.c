#include <stdio.h>
#include <math.h>

void najduzi_bp(char* s1, char* s2){
	
	
	char* pocetni2 = s2;
	char* p = s1;
	char* q = s1;
	char* r = s1;
	char* s = s1;
	int brojac=1; 
	int max=0;
	int i,tacno=1;
	int j,ima_niz=1;
	
	

		while(*p!='\0'){
			
		while(!((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) && *p!='\0') p++; /* p na pocetak niza slova */
		
		
		if(*p!='\0') q=p+1; /* q na sljedeci clan */
		
		
		brojac=1; /* svaki niz ce minimalno imati duzinu 1 */
		
		while(((*q>='A' && *q<='Z') || (*q>='a' && *q<='z')) && *q!='\0'){
			
			for(j=0;j<brojac;j++){ 
				
			for(i=0;i<brojac;i++){
				
				if( *q!=*(p+i) &&  (*q-*(p+i))!=32 && (*q-*(p+i))!=-32 && *q!='\0' && ((*q>='A' && *q<='Z') || (*q>='a' && *q<='z')) ){
				tacno=1; /* poredimo q sa svakim svojim prethodnikom */
				}
				else {tacno=0; break;} /* kada pronađe svog istog prethodnika prekida se petlja */
			}
			
				if(tacno) {brojac++; q++;} /* sve dok je razlicit povecavamo brojac */
				
				else break;
			}
			if(tacno==0) break;
		}
		
	
	
	
		
		if (brojac>max) max=brojac; /* Pamtimo najvecu duzinu */
		
		
		p++; 
		}
		
		
		
		p=s1;
		q=s1;
		
		/* Ponovo ista petlja */
		while(*p!='\0'){
			
		while(!((*p>='A' && *p<='Z') || (*p>='a' && *p<='z')) && *p!='\0') p++;
		
		
		if(*p!='\0') q=p+1;
		
		
		brojac=1;
		
		while(((*q>='A' && *q<='Z') || (*q>='a' && *q<='z')) && *q!='\0'){
			
			for(j=0;j<brojac;j++){
				
			
				
			for(i=0;i<brojac;i++){
				
				if( *q!=*(p+i) &&  (*q-*(p+i))!=32 && (*q-*(p+i))!=-32 && *q!='\0' && ((*q>='A' && *q<='Z') || (*q>='a' && *q<='z')) ){
				tacno=1;
				}
				else {tacno=0; break;}
			}
			
				if(tacno) {brojac++; q++;}
				
				else{
				break;}
			}
			if(tacno==0) break;
		}
		
	
	
	
		
		if (brojac==max) {r=p; s=q; break;} /* Pamtimo gdje se nalazi najduzi niz */
		
		
		p++;
		}
		
		brojac=0;
		
		p=s1;
		
		if(s1=='\0'){ima_niz=0;}
		
		while(*p!='\0'){
			if(((*p>='A' && *p<='Z') || (*p>='a' && *p<='z'))) brojac++;
			p++;
		}
		
		if(brojac==0) ima_niz=0; /* Da li tekst uopste sadrzi niz slova? */
		
		if(ima_niz){ /* Ako ima, onda najduzi upisujemo u dati string */
		while(pocetni2!='\0' && r<s){
			*pocetni2=*r;
			pocetni2++;
			r++;
		}
		
		*pocetni2='\0';
		}
		
		
}





int main() {
	
	char tekst[100]=" ";
	char string[100];
	najduzi_bp(tekst,string);
	return 0;
}
