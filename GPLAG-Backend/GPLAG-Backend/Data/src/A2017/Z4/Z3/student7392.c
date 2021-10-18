#include <stdio.h>
void najduzi_bp(char* s1,char* s2){
	int niz[5000];
	char *a=s1;
	char *b=s1;
	char *c=s1;
	char *poin=s1;
	char *pocetak=s1;
	int duzina=0,i=0;
	int ran;
	while(*s1!='\0'){
		pocetak=s1;
		a=pocetak;
		while(*pocetak!='\0' && *pocetak!=' ' && ((*pocetak>='A'&&*pocetak<='Z')||(*pocetak>='a'&&*pocetak<='z'))){
			if(niz[*pocetak]==0){
				if(*pocetak>='A' && *pocetak<='Z'){
				ran=*pocetak+('a'-'A');
				niz[ran]++;
				}
				else{
					niz[*pocetak]++;
				}
				pocetak++;
			}
			else break;
		}
		
		b=pocetak;
		if(b-a>duzina){
			duzina=b-a;
			c=a;
			poin=b;
		}
		for(i=0;i<5000;i++) niz[i]=0;
		s1++;
		if(*s1==' ') s1++;
	}
	while(c!=poin){
		*s2=*c;
		c++;
		s2++;
		
	}
	
	
}
int main() {
	char niz[10];
	najduzi_bp("ovo je neki primjer teksta",niz);
	printf("Niz: '%s'",niz);
	return 0;
}
