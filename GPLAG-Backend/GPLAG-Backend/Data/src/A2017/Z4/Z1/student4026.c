#include <stdio.h>

int duzina(char *a)
{
	int broj=0;
	while(*a++!='\0') broj++;
	return broj;
}

char* ubaci_broj (char* tekst, int broj)
{
	int dodaj=0;
	int brojac=0;
	int razmak=0;
	int brojac2=0;
	int brojac3=0;
	int lengt=duzina(tekst);
	int temp=broj;
	int temp2=0;
	int i;
	if(temp<0)
	{
		brojac2++;
		temp*=-1;
	}
	while(temp>0)
	{
		temp2+=temp%10;
		temp2*=10;
		temp/=10;
		brojac2++;
	}
	temp2/=10;
	brojac2++;
	while(*tekst!='\0')
	{
		if(*tekst!=' ' && *(tekst+1)==' ')
		{
			brojac3=0;
			dodaj=0;
			tekst++;
			brojac++;
			razmak=0;
			if(*(tekst+1)==' ') razmak=1;
			while(*tekst!='\0')
			{
				if(*tekst!=' ' && *tekst!='\0') dodaj=1;
				
				tekst++;
				brojac3++;
			}
			tekst-=brojac3;
			
			if(dodaj)
			{
				char* kraj=tekst;
				while(*kraj != '\0') kraj++;
				while(kraj > tekst)
				{
					*(kraj+brojac2)=*kraj;
					kraj--;
				}
				temp=temp2;
			
				for(i=0;i<brojac2-1;i++)
				{
					if(i==0 && broj<0) *(tekst+i+1)='-';
					else
					{
						int cifra=temp%10;
						temp/=10;
						*(tekst+i+1)=cifra+48;
					}
				}
				brojac3=0;
				if(!razmak) *(tekst+i+1)=' ';
				else 
				{
					tekst+=i+1;
					brojac3+=i+1;
					while(*tekst!='\0')
					{
						*tekst=*(tekst+1);
						tekst++;
						brojac3++;
					}
					
				}
				tekst-=brojac3;
				tekst+=brojac2;
				brojac+=brojac2;
			}
		}
		tekst++;
		brojac++;
	}
	tekst-=brojac;
	
	return tekst;
}
int main() 
{
/* AT4: Vise razmaka izmedju rijeci */
char s[77] = "Ovdje  izmedju    rijeci ima      po nekoliko   razmaka";
printf("\"%s\"", ubaci_broj(s, 320));
	return 0;
}
