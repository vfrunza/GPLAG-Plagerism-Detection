#include <stdio.h>

char* sljedecarijec(char* s) { 
	
	if(*s =='\0') return s;
	while(*s != '\0' && *s != ' ')  { s++; if(*s=='\0') return s; }
	while(*s == '\0' || *s == ' ') { s++; if(*s=='\0') return s; }
	
	return s;
	
}

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci) {
	char* p, *s1, *q, *q1, *kraj, *s, *pr, *pz;
	int i=0;
	int zamjeni=0;
	p=tekst;
	
	while (*p != '\0') {
		
		while(i< broj_rijeci) {
		
			if(*p == *rijeci[i]) {
		 		 q=rijeci[i]; pr=rijeci[i];
		 		s1=p; q1=zamjene[i]; pz=zamjene[i];
				while( *p == *rijeci[i]) {
					
					p++; rijeci[i]++;
					if(!(*p== ' ' || *p == '\0') && *rijeci[i]== '\0')  rijeci[i]=pr;
					if((*p== ' ' || *p == '\0') && *rijeci[i]== '\0') {
						zamjeni=1;
					
						
						while(*q != '\0'){
							s=s1;
							while(*s != '\0')	{
								
								*s=*(s+1);
								s++;
								
							}
							q++;
							p--;
					
						}
						kraj=s;
						q1=pz;
						while(*q1 != '\0') {
							s=kraj;
							kraj++;
							
							do{
								
								*s=*(s-1);
								s--;
							}
							while (s!=s1);
							*s1=*zamjene[i];
							s1++; zamjene[i]++;
							q1++;
							
						}
						
					}
					
					
				}
			
			}
			if (zamjeni==1) {
			rijeci[i]=pr;
			zamjene[i]=pz;
			zamjeni=0;
			}
			i++;
			
		 }
		i=0;
		p=sljedecarijec(p);
	}
	return tekst;
	
}


int main() {
char* rijeci[2] = {"testiranje", "test"};
char* zamjene[2] = {"zamjena", "swap"};
char tekst[] = "test testiranje test";
printf("'%s'", zamjena_rijeci(tekst, rijeci, zamjene, 2));

	return 0;
}
