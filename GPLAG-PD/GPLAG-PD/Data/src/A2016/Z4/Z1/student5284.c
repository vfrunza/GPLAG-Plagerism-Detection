#include <stdio.h>
#include <ctype.h>
char *izbaci_najcescu(char *s) {
	char *p=s, *pr, *kr, *kt, *pt, *pn, *kn, *q, *r, *k;
	int pret;
	int i;
	char niz[1000];
	int max=0;
	int br=0;
	if(*s=='\0') return 0;
	while(*s!='\0') {
		if(toupper(*s)>='A' && toupper(*s)<='Z' && (*(s+1)!=' ' || *(s+1)!='\0')) {
			pr=s;br=1;

			while((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')) {
				s++;
			}
			
			kr=s;
			q=s;
			
			while(*q!='\0') {
				if(toupper(*q)>='A' && toupper(*q)<='Z' && (*(q+1)!=' ' || *(q+1)!='\0')) {
					pn=q;
					while((*q>='a' && *q<='z') || (*q>='A' && *q<='Z')) {
						q++;			
					}
					kn=q;
					
					pt=pr;
					kt=kr;
					pret=1;
					
					while(pt!=kr) {
						if(tolower(*pt)!=tolower(*pn)){ pret=0;break;}
						pt++;
						pn++;
					}
					
					if(pret==1)
					br++;
			}else q++;
		}
		
		if(br>max) {
			max=br;
			r=pr;
			k=kr;
			
			i=0;
		while(r!=k) {
			niz[i]=*r;
			i++;
			r++;
				
		}
		niz[i]='\0';
		}
		
		}else s++;
	}
		
		
		
		
	s=p;
	while(*s!='\0') {
	 	
		if(toupper(*s)>='A' && toupper(*s)<='Z' && (*(s+1)!=' ' || *(s+1)!='\0')) {
			pr=s;
			q=s;
			while((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')) s++;
			kr=s;
			pret=1;
			pt=niz;
			kt=niz+i;
			
			while(pr!=kr) {
				if(tolower(*pt)!=tolower(*pr) ) { pret=0; break;}
					pt++;
					pr++;
			
			}
			
			if(pret==1) {
				
				while(*kr!='\0')  *q++=*kr++;
				*q='\0';
				s=s-(kr-q);
			}
			
		} else s++;
		
	}
	return p;
}


int main() {
	
	char a[]="Ovo je neki bezvezni tekst neki neki";
	printf("%s", izbaci_najcescu(a));
	
return 0;
}
