#include <stdio.h>

int provjeri_duzine (char string[], int niz[], int duzina)
{
	int brojac,redni_broj;
	char *p=string;
	redni_broj=0;
	brojac=0;
	
		while(*p!='\0' )
		{
			
			if((*p<='Z' && *p>='A')|| (*p>='a' && *p<='z'))
			brojac++;
			else if(brojac!=0) 
			{
				
				if(brojac!=niz[redni_broj]) return 0;
				redni_broj++;
				brojac=0;
			}
			p++;
		}
		p--;
		if((*p<='Z' && *p>='A')|| (*p>='a' && *p<='z'))
		{
			if(brojac!=niz[redni_broj]) return 0;
			
		}
		if(redni_broj+1!=duzina)return 0;
		
	return 1;
}

int main() {
	printf("Zadaća 4, Zadatak 2");
	return 0;
}
