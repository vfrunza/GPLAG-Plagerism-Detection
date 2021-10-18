#include <stdio.h>
char* izbaci_najcescu(char* s){
	char* pocetak=s;
	char*p=NULL,*kraj=NULL,*novi=NULL,*pocmax=NULL,*krajmax=NULL,*izbacivanje=NULL,*poc=NULL;
	int broj=0,max=0;
	while(*s!='\0'){
		if((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')){
			p=s;
			poc=s;
			while((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')) s++;
			kraj=s;
			novi=s;
			broj=0;
			while(*novi!='\0'){
				if(p==kraj && !((*novi>='a' && *novi<='z')||(*novi>='A' && *novi<='Z')) && (*(novi-kraj+poc-1)==' ' || *(novi-kraj+poc-1)=='3'))
				{ broj++; p=poc;
				if(broj>max){ max=broj; pocmax=poc; krajmax=kraj;}
				continue;}
				if(*novi!=*p && *novi!=*p+'A'-'a' && *novi!=*p+'a'-'A'){p=poc; novi++; continue;}
				p++;
				novi++;
			}
			if(p==kraj){ broj++; p=poc;
			if(broj>max){ max=broj; pocmax=poc; krajmax=kraj;}
		}
	}
	else s++;
}
if(pocmax==NULL){
pocmax=pocetak;
while((*pocmax>='a' && *pocmax<='z') || (*pocmax>='A' && *pocmax<='Z')) pocmax++;
krajmax=pocmax;
pocmax=pocetak;
}
poc=pocmax;
novi=krajmax;
kraj=krajmax;
if(novi!=NULL){
while(*novi!='\0'){
	if(pocmax==kraj && !((*novi>='a' && *novi<='z')||(*novi>='A' && *novi<='Z')) && (*(novi-kraj+poc-1)==' ' || *(novi-kraj+poc-1)=='3'))
	{ pocmax=poc;
	izbacivanje=novi;
	while(*izbacivanje!='\0'){
		*(izbacivanje-kraj+pocmax)=*izbacivanje;
		izbacivanje++;}
		*(izbacivanje-kraj+pocmax)='\0';
		novi--; novi--; novi--;
		continue;}
		if(*novi!=*pocmax && *novi!=*pocmax+'A'-'a' &&  *novi!=*pocmax+'a'-'A')
		{pocmax=poc; novi++; continue;}
		pocmax++;
		novi++;
	}
	
	if(pocmax==kraj && (*novi==*kraj || *novi=='\0')){pocmax=poc;
	izbacivanje=novi;
	while(*izbacivanje!='\0'){
		*(izbacivanje-kraj+pocmax)=*izbacivanje;
		izbacivanje ++;
	}
	*(izbacivanje-kraj+pocmax)='\0';
	}
}
	
	if(kraj!=NULL){
	while(*kraj!='\0'){
		*poc=*kraj;
	    poc++;
	    kraj ++;
	}
	*poc='\0';
	}
	return pocetak;
	
}


int main() {
	char ime[]="Danas je je je lijep lijep dan";
	printf("%s",izbaci_najcescu(ime));
	return 0;
}
