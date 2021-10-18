#include <stdio.h>

void unesi(char *s, int velicina)
{
	int i=0;
	char znak=getchar();
	if(znak=='\n') znak=getchar();
	while(i<velicina-1 && znak!='\n') {
		s[i]=znak;
		i++;
		znak=getchar();
	}
}

int velicina_stringa(char *s)
{
	int duz=0;
	while(*s!='\0') {
		if(((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) && (!((*(s+1)>='A' && *(s+1)<='Z') || (*(s+1)>='a' && *(s+1)<='z')))) {
			duz++;
		} 
		s++;
	}
	return duz;
}

int provjeri_duzine(char *s, int *niz, int velicina)
{

	int broj=0, index=0, k=0, brojac=0;
	k=velicina_stringa(s);
	if(k!=velicina) return 0;


	while(*s!='\0') {
		if((*s>='A' && *s<='Z') || (*s>='a' && *s<='z')) {
			broj=0;
			while(*s!='\0' && ((*s>='A' && *s<='Z') || (*s>='a' && *s<='z'))) {
				broj++;
				s++;
			}
			if(niz[index]!=broj) return 0;
			brojac++;
			if(brojac==k) return 1;
			index++;
		} else {
			s++;
		}
	}
	return 1;
}

int main()
{

	return 0;
}
