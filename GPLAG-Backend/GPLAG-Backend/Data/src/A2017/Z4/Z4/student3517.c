#include <stdio.h>

void unesi(char niz[], int velicina)
{
	int i;
	char znak=getchar();
	if (znak=='\n')
		znak=getchar();
	while(i<velicina-1 && znak!='\n')
	{
		niz[i]=znak;
		znak=getchar();
		i++;
	}
	niz[i]='\0';
}

int Slovo_broj(char c)
{
	if ((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>=48 && c<=58))
		return 1;
	return 0;	
}

int provjeri(char *s)
{
	int zatvoren=1;
	char *p, *q, *poc;
	
	while(*s==' ')
		s++;
	while(*s!='\0')
	{
		if (*s=='<' && Slovo_broj(*(s+1)))
		{
			p=s;
			p++;
			while(Slovo_broj(*p))
				p++;
			p=s;
			p--;
		}
		
		s++;
	}
}

int main() {
	printf("Zadaća 4, Zadatak 4");
	return 0;
}
