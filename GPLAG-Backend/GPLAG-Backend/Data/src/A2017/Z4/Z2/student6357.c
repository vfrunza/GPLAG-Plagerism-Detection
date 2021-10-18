#include <stdio.h>
int provjeri_duzine(char* s, int niz[],int vel)
{
	int brojac=0,i=0;
	while(*s!='\0') {
		if(!((*s>='a' && *s<='z') || (*s>='A' && *s<='Z'))) {
			while(!((*s>='a' && *s<='z') ||(*s>='A' && *s<='Z'))) {
				s++;
				if(*s=='\0') break;
			}
		}
		if(*s=='\0' && i==vel) return 1;
		if((*s>='a' && *s<='z') || (*s>='A' && *s<='Z')) {
			while((*s>='a' && *s<='z') || (*s>'A' && *s<='Z')) {
				brojac++;
				s++;
			}
		}
		if(i<vel) {
			if(brojac!=niz[i] || brojac==0) return 0;
			i++;
			brojac=0;
		} else return 0;
	}
	if(i!=vel) return 0;
	return 1;
}

int main()
{
	char tekst[]= {"Kakav je ovo test!?!?"};
	int niz[]= {5,2,3,4,0};
	printf("%d",provjeri_duzine(tekst,niz,5));
	return 0;
}
