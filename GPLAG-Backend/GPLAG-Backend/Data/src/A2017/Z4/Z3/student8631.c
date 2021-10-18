#include <stdio.h>
#include <ctype.h>
PREDUGO IZVRSAVVANJE
/*
char* pomocna(char* s1, char*s2){
	char*pom=s1+1;
	char*p;
	while(pom!=s2){
		p=s1;
		while(p!=pom){
			if(*p==tolower(*pom)) {s2=pom;
			return s2;}
			p++;
		}
		pom++;
	}
	return s2;
}
void pomocna(char *s1, char *s2){
  	 char *pom=s1+1; 
  	 while (s2!=pom) {
  	 	if(*pom==(tolower(*s2))) 
  	 	s2=pom;
  	 }
	s1++;
}
*/
void najduzi_bp(char * s1, char *s2){
	char *s=s1; 
	char *pt; char *kt;
 	 char *pm, *km; 
 	 char *pom;
 	 char * novi_kt;
 	 int niz[200]={0};
 	 int i;
 	 int pret=0;
 	 int max=0;
 	 while (*s!='\0') {
 	 	if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))
 	 	{
 	 	pt=s;
 		while ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) 
 	 		s++;
 		if(*s==' ' || *s=='\0' ){ kt= s; 
 		}
      pom=pt+1; 
      while (pom!='\0') {
      	if(pom==niz[i]) 
      	pom++; pret=1; break;
      }
 if(pret){
 	kt=pom;
 	 if(kt-pt>max) 
 	 {
 	 	max=kt-pt; pm=pt; km=kt;
 	 }
 	 }
 	 	if(*s=='\0') break; 
 	 else s++;
 	 }}
pom=pm;
while (km!=pom) {
	*s2++=*pom++;
}
}
int main() {
	 char niz[10];
        najduzi_bp ("Ovo je neki primjer teksta", niz);
        printf ("Niz: '%s'", niz);
    
return 0;
}

