#include <stdio.h>

#include <string.h>

char* naziv(char * s){
		
	char pomocni_string[100];
	char*pom=pomocni_string;
	


		s++;
		
		while(*s!=' ' && ((*s<='z' && *s>='a') ||(*s<='Z' && *s>='A') || (*s<=0 && *s>=9) ) ){
		
		*pom++=*s++;
	}
	*pom='\0';
	pom--;
	return pom;
}


int provjeri(char string []){
	
char *s= string;

while(*s!='\0'){
	
	if(*s=='<') {
	
	char* p = naziv(s);
	
	
	if(*s=='<'){
		s++;
		if(*s=='/') {
			while(*s!='>' && *s!='\0') s++;
			s--;
			if(*s!=*p) return 0;
			while(*s--==*p--); 
		  if(*s!='/') return 0;
		}
	}
	
	}
	s++;
}
return 1;
}



int main() {
char etfunsaba[] = "<center>"
	"<a href=\"http://icat.etf.unsa.ba/\">"
       "</a>"
    "</center>";
    printf ("Provjera 1: %d\n", provjeri (etfunsaba));
	return 0;
}
