#include <stdio.h>


char* vratinapocetak(char* s,char* pocetak) {
	while(!((*s>= 'A' && *s<= 'Z') || (*s>= 'a' && *s<= 'z'))) s--;
	if(!((*(s-1)>= 'A' && *(s-1)<= 'Z') || (*(s-1)>= 'a' && *(s-1)<= 'z')) ) return s; 
	while((*s>= 'A' && *s<= 'Z') || (*s>= 'a' && *s<= 'z')) {
		if(s==pocetak) break;
		if(!((*(s-1)>= 'A' && *(s-1)<= 'Z') || (*(s-1)>= 'a' && *(s-1)<= 'z')) )break;
		s--; 
	 }
	
	return s;
	
}
char* sljedecarijec(char* s) { 
	
	if(*s =='\0') return s;
	while((*s>= 'A' && *s<= 'Z') || (*s>= 'a' && *s<= 'z'))  { s++; if(*s=='\0') return s; }
	while(!((*s>= 'A' && *s<= 'Z') || (*s>= 'a' && *s<= 'z'))) { s++; if(*s=='\0') return s; }
	
	return s;
	
}

char* izbaci_najcescu(char* s) {
	char rijec[100] = { '\0' };
	int i=0,brr=1,max=1,j;

	char *m, *n, *v, *p, *q, *pocetak;
	p=s; q=s; m=s; n=s; v=s; pocetak=s;
	
	while(!((*q >= 'A' && *q<= 'Z') || (*q>='a' && *q<='z'))) { q++; if(*q== '\0') return s; }
	
	q=sljedecarijec(q);
	if (*q== '\0') {
		s=vratinapocetak(q,v); pocetak=s;
		
			while(*s!='\0') {
				pocetak=s;
				while (*pocetak!= '\0') {
					*pocetak=*(pocetak+1);
					pocetak++;
				}
				s++;
			}
	return s;
	}
	if(!((*s >= 'A' && *s<= 'Z') || (*s>='a' && *s<='z'))) s=sljedecarijec(s);
	pocetak=s;
	while((*s!= '\0')) {
			
			if(*s==*q || *s+32==*q || *s-32==*q) { s++; q++; }
			else { s=vratinapocetak(s,pocetak); q=sljedecarijec(q); }
			if((*s<'A' || (*s>'Z' && *s<'a') || *s>'z') && (*q<'A' || (*q>'Z' && *q<'a') || *q>'z') )  {
				brr++; s=vratinapocetak(s,pocetak); q=sljedecarijec(q); 
				if(brr>max) { max=brr; m=s;};
				}
			if(*q== '\0') {s=sljedecarijec(s); q=s; q=sljedecarijec(q); if(*q == '\0') break; brr=1;}
			 
			
	}
	
	
	n=m;
	v=m;

	while((*n>= 'A' && *n<= 'Z') || (*n>='a' && *n<='z')) { 
		rijec[i]=*n; 
		n++; 
		i++;
		}
	rijec[i]='\0';
	while(*m != '\0'  ) {
		i=0;
		
		while(rijec[i] != '\0') {
			if(*(m+i)==rijec[i] || *(m+i)+32==rijec[i] || *(m+i)-32==rijec[i]) {
				i++;
				if((*(m+i)<'A' || (*(m+i)>'Z' && *(m+i)<'a') || *(m+i)>'z')  && rijec[i]=='\0') {
					
					for(j=0;j<i;j++) {
						v=m;
						while(*v != '\0') {
							v++;
							*(v-1)=*v;
							
						}
					}
				}
			}
			else {m=sljedecarijec(m); i=0; if(*m == '\0') return p; }
		}
		m=sljedecarijec(m);
	}
	return p;
}

int main() {
	char t[]="JednaVeeeeeeeeeelikaRiiiiiiiiijec";
printf("'%s'", izbaci_najcescu(t));
	return 0;
}
