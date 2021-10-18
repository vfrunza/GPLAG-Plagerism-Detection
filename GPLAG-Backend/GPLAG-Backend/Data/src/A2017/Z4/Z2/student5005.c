#include <stdio.h>

int provjeri_duzine(char* s,int* niz,int duzina){
	
	char* prvi=s;
	int rijec=0,duzina_rijeci=0,br_rijeci=0;
	
	while(*s!='\0')
	{
		if((*s<='Z' && *s>='A')||(*s<='z' && *s>='a')){
			duzina_rijeci++;
			if(*(s+1)=='\0') br_rijeci++;
		}
		else if(duzina_rijeci>0){
			duzina_rijeci=0;
			br_rijeci++;
		}
		s++;
	}
	s=prvi;
	duzina_rijeci=0;
	if(br_rijeci!=duzina) return 0;
	
	while(*s!='\0')
	{
		if((*s<='Z' && *s>='A')||(*s<='z' && *s>='a')){//Trazi rijeci
			duzina_rijeci++;
		}
		else if(duzina_rijeci>0)
		{
			if(niz[rijec]<1 || niz[rijec]!=duzina_rijeci) return 0;
			duzina_rijeci=0;
			rijec++;
			
		}
		s++;
	}
	return 1;
	
}

int main() {
	printf("Zadaća 4, Zadatak 2");
	return 0;
}
