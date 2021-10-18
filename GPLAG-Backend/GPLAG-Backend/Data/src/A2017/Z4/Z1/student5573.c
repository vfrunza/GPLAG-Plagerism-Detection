#include <stdio.h>

char* ubaci_broj(char* tekst,int broj)
{
	char *s=tekst,*hodajuci=tekst,*kraj=tekst;
	int b,duzina=0,a=broj,brojac=0,cifra;
	while(*s!='\0')	
	{
		s++;
		hodajuci++;
		kraj++;
	}
	while(a!=0)
	{
		a=a/10;
		duzina++;
	}
	if(broj<0)
	{
		duzina++;
		a=-broj;
	}
	else
	{
		a=broj;
	}
	b=a;
	s--;
	while(s!=tekst)
	{
		while(*s==' ' && s!=tekst)	s--;
		while(*s!=' ' && s!=tekst)	s--;
		while(*s==' ' && s!=tekst)
		{
			brojac++;
			s--;
		}
		if(s==tekst)	break;
		s++;
		while(hodajuci!=s)
		{
			if(brojac==1)
			{
				*(hodajuci+duzina+1)= *hodajuci;
				hodajuci--;
			}
			else if(brojac!=1)
			{
				*(hodajuci+duzina)= *hodajuci;
				hodajuci--;
			}
		}
		if(brojac==1)
		{
			kraj=kraj+duzina+1,
			hodajuci=kraj;
			s=s+duzina+1;
			*s=' ';
			s--;
		}
		else
		{
			kraj=kraj+duzina;
			hodajuci=kraj;
			s=s+duzina;
		}
		while(b!=0)
		{
			cifra=b%10;
			*s=cifra+'0';
			b=b/10;
			s--;
		}
		if(broj<0)
		{
			*s='-';
			s--;
		}
		b=a;
		brojac=0;
		s--;
	}
	if(brojac!=0 && *s!=' ')
	{
		s++;
		while(hodajuci!=s)
		{
			if(brojac==1)
			{
				*(hodajuci+duzina+1)= *hodajuci;
			}
			else if(brojac!=1)
			{
				*(hodajuci+duzina)= *hodajuci;
			}
			hodajuci--;
		}
		if(brojac==1)
		{
			s=s+duzina+1;
			*s=' ';
			s--;
		}
		else
		{
			s=s+duzina;
		}
		while(b!=0)
		{
			cifra=b%10;
			*s=cifra+'0';
			b=b/10;
			s--;
		}
		if(broj<0)
		{
			*s='-';
		}
	}
	return tekst;
}
int main() {
	char s[66] = "a sada i primjer koji se zavrsava razmacima       ";
printf("\"%s\"", ubaci_broj(s, 1));
	/*printf("Zadaća 4, Zadatak 1");*/
	return 0;
}
