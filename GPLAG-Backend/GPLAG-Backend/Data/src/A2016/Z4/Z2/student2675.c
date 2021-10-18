#include <stdio.h>

char* kodiraj(char* s,char* kod)
{
	int broj[96]={0},i,j,pomi;
	char* pom=s;
	char pomc=' ';
	//generise sifrarnik kao niz ASCII znakova
	for(i=0;i<95;i++,pomc++)
	{
		kod[i]=pomc;
	}
	//broji koliko se puta koji clan pojavljuje
	while(*s!='\0')
	{
		for(i=0;i<95;i++)
		{
			if(*s==kod[i])
			{
				broj[i]++;
				break;
			}
		}
		s++;
	}
	//sortira clanove po ucestalosti
	for(i=0;i<94;i++)
	{
		for(j=i;j<95;j++)
		{
			if(broj[i]<broj[j]||(broj[i]==broj[j] && kod[i]>kod[j]))
			{
				pomc=kod[i];
				kod[i]=kod[j];
				kod[j]=pomc;
				pomi=broj[i];
				broj[i]=broj[j];
				broj[j]=pomi;
			}
		}
	}
	s=pom;
	//mijenja clanove za clanove iz tabele po ucestalosti
	while(*s!='\0')
	{
		for(i=0;i<95;i++)
		{
			if(*s==kod[i])
			{
				*s='~'-i;
				break;
			}
		}
		s++;
	}
	return pom;
}

char* dekodiraj(char *s,char *kod)
{
	int i;
	char* pom=s;
	while(*s!='\0')
	{
		//mijenja clanove za one od kojih ih je napravio
		for(i=0;i<95;i++)
		{
			if(*s==126-i)
			{
				*s=kod[i];
				break;
			}
		}
		s++;
	}
	return pom;
}

int main() {
	char s[]="ssUU",kod[96];
	char *p=s;
	int i;
	p=kodiraj(s,kod);
	for(i=0;i<4;p++,i++)
	{
		printf("%c",*p);
	}
	return 0;
}
