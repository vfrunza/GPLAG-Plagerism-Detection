#include <stdio.h>

int jeLiKarakter(char c)
{
	if(c!=' ')
		return 1;
	else
		return 0;
}
char* ubaci_broj (char* tekst, int broj)
{
	int brojac=0;
	int t=1,i=0, k=0;
	int j=0;
	int znak = 0;
	int tempBroj = broj;
	int tempT = 0;
	
	
	if(broj<0)
	{
		brojac++;
		broj*=-1;
		znak=1;
	}
	tempBroj = broj;
	while(t<=broj) t*=10;
	t/=10;
	
	tempT = t;
	
	while(broj>=0)
	{
brojac++;
broj=broj-((broj/t)*t);
		t/=10;
		if(t==0) break;
	}

			t=tempT;
broj = tempBroj;

	
	while(jeLiKarakter(tekst[i])==0) i++;
	
	while(tekst[i]!='\0')
	{
				j=i;
	while(jeLiKarakter(tekst[j])==0) j++;
	if(tekst[j] == '\0') break;
	
		
		if(jeLiKarakter(tekst[i])==0)
		{
			tekst[i]=' ';
			j=i;
			while(tekst[j+1]!='\0')
			{
				j++;
			}
			k=0;
			if(tekst[i+1]==' ') k=1;
			while(j>=i){
			tekst[j+brojac+1-k]=tekst[j];
			j--;
			}
			
			j=0;
if(znak == 1)
{
	tekst[i+1+j]='-';
	j++;
	
}
	tempBroj = broj;
	tempT = t;

		while(tempBroj>=0)
	{
		tekst[i+1+j] = tempBroj/tempT + '0';
		tempBroj=tempBroj-((tempBroj/tempT)*tempT);
		tempT/=10;
		j++;
		if(tempT==0) break;
	}

			i=i+brojac+1;
			while(jeLiKarakter(tekst[i])==0)
			{
				i++;
			}
			i--;
		
			
		}

	i++;
	}
	
	return tekst;
}
int main() {
	

char s[66] = "a sada i primjer koji se zavrsava razmacima       ";
printf("\"%s\"", ubaci_broj(s, 5544));


	
		return 0;
}
