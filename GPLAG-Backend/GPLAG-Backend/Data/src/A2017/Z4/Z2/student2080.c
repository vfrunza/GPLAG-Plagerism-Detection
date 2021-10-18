#include <stdio.h>

int prebroji_slova(char *s){
	int broj_slova=0;
	while (((*s>='A' && *s<='Z')||(*s>='a' && *s<='z'))) {
		broj_slova++;
		s++;
	}
	return broj_slova;
}

int provjeri_duzine( char *s, int niz[], int vel){
	int i=0,broj_slova;
	
	while(1){
		

		if((*s>='a' && *s<='z')|| (*s>='A' && *s <='Z')) {
			
			broj_slova=prebroji_slova(s);
			
			if	(broj_slova==niz[i]){
		    	i++;
		    	if(*(s+broj_slova) == '\0')
		    	{
		    		s+=broj_slova;
		    	}
		    	else
		    	{
		    		s+=broj_slova+1;
		    	}
			}
			else 
			{
		    	return 0;
			}
		}
		else {
			if(*s == '\0')
	    	{
	    		break;
	    	}
			
			s++;
		}
	}
			if (vel != i)
			{
        		return 0;
			}
		return 1;
}

int main() {
char tekst[] = "...i tako smo dosli do petog testa";
int niz[] = {1,4,3,5,2,5,5};
int niz2[] = {4,4,3,5,2,5,5};
int niz3[] = {0,1,4,3,5,2,5,5};

printf("%d ", provjeri_duzine(tekst, niz3, 8));
printf("%d ", provjeri_duzine(tekst, niz2, 7));
printf("%d ", provjeri_duzine(tekst, niz, 7));
	return 0;
}
