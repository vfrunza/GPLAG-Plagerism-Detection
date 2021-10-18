#include <stdio.h>

int DaLiJeSloVo(char *s)
{
	while(*s != '\0')
	{
		if((*s >= 'A' && *s <= 'Z') || (*s >= 'a' && *s <= 'z'))
			return 1;
		else
			return 0;
		s++;
	}
	return 0;
}

int provjeri_duzine(char *s, int niz[], int vel)
{
	int p = 0;
	int velicina = 0;
	while(*s != '\0')
	{
		if(vel <= p) return 0;
		while(!DaLiJeSloVo(s) && *s != '\0') s++;
		while(DaLiJeSloVo(s) && *s != '\0') 
		{
			velicina++;
			s++;
		}
		if(velicina != niz[p]) return 0;
		while(!DaLiJeSloVo(s) && *s != '\0') s++;
		velicina = 0;
		p++;
	}
	if(p != vel) return 0;
	return 1;
}

int main()
{
	char tekst[] = "Ovo je neki primjer teksta";
	int niz[] = {3, 2, 4, 7, 6};
	printf("%d ", provjeri_duzine(tekst, niz, 5));
	return 0;
}