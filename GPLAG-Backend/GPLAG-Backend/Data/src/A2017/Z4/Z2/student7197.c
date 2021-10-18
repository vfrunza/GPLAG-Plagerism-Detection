#include <stdio.h>
int neslovo(char s)
{
	if((s>='a' && s<='z')||(s>='A' && s<='Z'))return 0;
	return 1;
}
int broj_rijeci(char *s)
{
	int brojac=0,rijec=0;
	while(*s)
	{
		if(*s==' ' || *s=='-') {
			while(*s==' ' || *s=='-')s++;
			rijec=0;
		}
		else {
			if(rijec==0){
				brojac++;
				rijec=1;
			}
			s++;
		}
	}
	return brojac;
}


int provjeri_duzine(char *s, int *n, int vel)
{
	int brojac=0,i=0;
	if(vel != broj_rijeci(s))return 0;
	while(1){
		while(*s){
			if((*s>='a' && *s<='z') || (*s>='A' && *s<='Z'))brojac++;
			if(*s==' ' || *s=='-')break;
			s++;
		}
		if(brojac!=n[i])return 0;
		brojac=0;
		i++;
		if(i>vel)return 0;
		if(*s=='\0')break;
		s++;
	}
	return 1;
}

int main() {
	return 0;
}
