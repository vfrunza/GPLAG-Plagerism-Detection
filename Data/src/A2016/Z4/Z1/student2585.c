#include <stdio.h>
int broj_rijeci(char* s)
{
	int br=0;
	char* pocetak=s;
	while(*pocetak)
	{
		if(*pocetak==' ' || *pocetak=='-')
		{
			br++;
		}
		pocetak++;
	}
	br++;
	return br;
}
int broj_slova(char* s)
{
	int br=0;
	char* pocetak=s;
	while(*pocetak)
	{
		if((*pocetak='a' && *pocetak<='z') || (*pocetak>='A' && *pocetak<='Z')) br++;
		pocetak++;
	}
	br++;
	return br;
}
char* izbaci_najcescu(char* string)
{
	char* pocetak=string;
	int ima_slovo=0;
	int brrijeci=broj_rijeci(string);
	if(brrijeci==1)
	{
		string[0]='\0';
		return string;
	}
	string=pocetak;
	while(*string!='\0')
	{
		if((*string>='a' && *string<='z') || (*string>='A' && *string<='Z'))
		{
			ima_slovo=1;
			break;
		}
		string++;
	}
	if(ima_slovo==0) return pocetak;
	else
	{
		
		
			while(*pocetak!=' ') pocetak++;
		
	}
	
	
	
	return pocetak;
}

int main()
{
	return 0;
}