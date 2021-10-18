#include <stdio.h>

int provjeri_duzine(char* s,int* duzina,int duz)
{
	char* pocetak=s;
	int i=0,brojac=0;
	int broj_rijeci=0;
	
		while(*s!='\0')
		{
		if((*s<='Z' && *s>='A')|| (*s<='z' && *s>='a'))
		{
			brojac++;
			if (*(s+1)=='\0') broj_rijeci++;
		}
		else if(brojac>0)
		{
			broj_rijeci++;
			brojac=0;
		}
		s++;
		}
		
	s=pocetak;
	
	brojac=0;
	
	if(broj_rijeci!=duz)return 0;
	
	while(*s!='\0')
	{
		if((*s<='Z' && *s>='A')|| (*s<='z' && *s>='a'))brojac++;
		else if(brojac>0)
		{
			if (i>=duz) return 0;
			
			if(duzina[i]!=brojac || duzina[i]==0)return 0;
			i++;
			brojac=0;
		}
		s++;
	}
	return 1;
}

int main() {

	return 0;
}