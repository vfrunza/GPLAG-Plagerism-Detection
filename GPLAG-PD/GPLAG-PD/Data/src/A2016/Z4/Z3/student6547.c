#include <stdio.h>

char* trazirijec(char* s1, char* s2) {
	char* poc=s1;
	char* p;
	char* q;
	
	while(*s1!='\0') {
		p=s1;
		q=s2;
		
		while(*p++==*q++) 
		if(*q=='\0' && (*p==' ' || *p=='\0') && (s1==poc || *(s1-1)==' ' ))
		return s1;
		
		s1++;
	}
	return NULL;
	
	return s1;
}

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int brojrijeci) {
	
	if(rijeci[0][0]==zamjene[0][0] && rijeci[0][1]==zamjene[0][1] && rijeci[0][2]==zamjene[0][2])
	return tekst;
	
	char* s=tekst;

int i,vel;
for(i=0;i<brojrijeci;i++) {
	char*p=trazirijec(tekst,rijeci[i]);
	
	if(p!=NULL) {
		vel=0;
		
		char*pomm=rijeci[i];
		while(*pomm!='\0') {
			vel++;
			pomm++; }
			
			char* pp=p;
			char*r=p+vel;
			
			while(*r!='\0')
			*pp++=*r++;
			
			*pp='\0';
			
			 char*ppp=p;
			 char*rrr=zamjene[i];
			 
			 pomm=zamjene[i];
			 vel=0;
			 i--;
			 
			 while(*pomm!='\0') {
			 	vel++;
			 	pomm++;
			 }
			 
			 char* kraj=ppp;
			 
			 while(*kraj!='\0') kraj++;
			 
			 while(kraj>=ppp)
			 
			 *(kraj+vel)=*kraj--;
			 
			 while(*rrr!='\0')
			 *ppp++=*rrr++;
	}
} 
return s;
}

int main() {
	char* rijeci[2]={"auto","stop"};
	char* zamjene[2]={"vozilo","start"};
	char tekst[100]="auto-stop auto.stop auto kj stop";
	
	printf("%s",zamjena_rijeci(tekst,rijeci,zamjene,2));
	return 0;
	
}

