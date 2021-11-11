#include <stdio.h>
#include <ctype.h>

char *izbaci_najcescu(char *s) {
	char *p=s;
	char *pr, *kr, *kt, *pt, *pn, *kn, *q, *r, *k;
	int a, i;
	char x[1000];
	int max=0, br=0;
	if(*s=='\0') return 0;
	do{
		if(*s>='A' && *s<='Z' || *s>='a' && *s<='z' && (*(s+1)!=' ' || (s+1)!='\0')) 
		{
			pr=s;
			br=1;
			do{
				s++;
			} while((*s>='a' && *s<='z') || (*s>='A' && *s<='Z'));
			
			kr=s;
			q=s;
			while(*q!='\0'){
				 if(*q>='A' && *q<='Z' || *q>='a' && *q<='z' && (*(q+1)!=' ' || *(q+1)!='\0'))
				 {
				 	pn=q;
				 
				 	do {
				 		q++;
				 	} while(*q>='A' && *q<='Z' || *q>='a' && *q<='z');
				 	kn=q;
				 	pt=pr;
				 	kt=kr;
				 	a=1;
				 	
				 	do{
				 		if(tolower(*pt)!=tolower(*pn))
				 		{
				 			a=0; break;
				 		}
				 		pt++;
				 		pn++;
				 	} while (pt!=kr);
				 	
				 	if(a==1)
				 	br++;
				 } else q++;
			} 
			
			if(br>max) 
			{
				max=br;
				r=pr;
				k=kr;
				i=0;
				do{
					x[i]=*r;
					i++;
					r++;
				} while(r!=k);
				x[i]='\0';
			}
		} else s++;
	} while(*s!='\0');
s=p;
do{
	if(*s>='A' && *s<='Z' || *s>='a' && *s<='z' && (*(s+1)!=' ' || (s+1)!='\0')) 
		{
			pr=s;
			q=s;
			do{
				s++;
			} while(*s>='A' && *s<='Z' || *s>='a' && *s<='z');
			kr=s;
			a=1;
			pt=x;
			kt=x+i;
			do{
				if (tolower(*pt)!=tolower(*pr))
				{
					a=0;
					break;
				}
				pt++;
				pr++;
			} while(pr!=kr);
			if(a==1)
			{
				while (*kr!='\0'){
					*q=*kr;
					q++; kr++;
				}
				*q='\0';
				s-=(kr-q);
			}
			
		} else s++;
		} while(*s!='\0');
		return p;
}


int main() {
	char primjer[]="Auto ide gore dolje gore";
	printf("%s", izbaci_najcescu(primjer));
	return 0;
}
