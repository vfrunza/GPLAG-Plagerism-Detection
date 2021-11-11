#include <stdio.h>
void unesi(char *niz, int velicina)
{
	char znak=getchar();
	int i=0;
	if(znak=='\n') znak=getchar();
	while(i<velicina-1 && znak!='\n')
	{
		niz[i]=znak;
		i++;
	znak=getchar();
	}
	niz[i]='\0';
}

int DaLiSuIsti(char *s, char *pomocni)
{
	int isti=1;
	while(*pomocni!='\0')
	{
		if(*pomocni++!=*s++)
		{
			isti=0;
			break;
		}
if(*pomocni=='\0' && (*s!=' ' && *s!='\0' ) )
{
	isti=0;
	break;
}
	}
	return isti;
}

void ZamijeniRijec(char *recenica, 	char *rijec)
{
	while(*rijec!='\0')
	{
		*recenica++=*rijec++;
	}
	recenica++;
}

int Rjecnik(char **rijeci, char ** zamjene, int broj_rijeci)
{
	int i, isti=1;
	char *pomocni, *temp;
	for(i=0;i<broj_rijeci;i++)
	{
		pomocni=rijeci[i];
		temp=zamjene[i];
		while(*pomocni!='\0' || *temp!='\0')
		{if(*pomocni++!=*temp++) isti=0;
		
	}
	if(isti==0) break;
}
return isti;}

char *zamjena_rijeci(char *tekst, char **rijeci, char **zamjene, int broj_rijeci)
{
char *s=tekst;
char *pomocni, *pok, *kpok, *temp;
int i, broj;
if(Rjecnik(rijeci, zamjene, broj_rijeci)) return tekst;
while(*s!='\0')
{if(s==tekst || *(s-1)==' ')
{
	while(*s==' ') s++;
	pok=s;
	for(i=0;i<broj_rijeci;i++)
	{
		broj=0;
		s=pok;
		temp=rijeci[i];
		if(DaLiSuIsti(s,pomocni))
		{
			kpok=pok;
			while(*pomocni!='\0')
			{
				broj++;
				pomocni++;
		}
		temp=kpok+broj;
		s--;
		while(kpok!=s)
		{
			*temp--=*kpok--;
		}
		pomocni=zamjene[i];
		ZamijeniRijec(pok, pomocni);
	}
}
}
s++;
}
return tekst;
}
int main() {
	int i;
char text[100];
printf("Unesite neki text: ");
unesi(text, 100);
char *rijeci[3]={"Zasto", "me", "rani"};
char *zamjene[3]={"Izdrzati", "necu", "moci"};
printf("%s", zamjena_rijeci(text, rijeci, zamjene, 3));
return 0;
}
