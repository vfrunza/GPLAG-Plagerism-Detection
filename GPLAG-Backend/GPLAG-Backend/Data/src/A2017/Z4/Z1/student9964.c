#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>

bool ididokraja(char *s)
{
	while(*s!='\0')
	{
		if(*s!=' ')
		return 0;
		
		s++;
	}
	
	return true;
	
	
}
int brojcifara(int broj)
{
	int cifra=0;
	if(broj<0)cifra++;
	broj=fabs(broj);
	while(broj!=0)
	{
		broj/=10;
		cifra++;
		
	}
	return cifra;
}
char cifra(int broj,int it)
{
	int rez=0,i=0;
	for(i=0;i<it;i++)
	{
		if(it==i)
		rez=broj%10;
		else broj/=10;
	}
	
	return (char)rez;
}

void ubaci(char* tekst,int broj)
{
	int brojac=0,i=0,razlika=brojcifara(broj);
	char temp;
	while(*tekst!='\0')
	{
		tekst++;
	brojac++;	
	}
	for(i=0;i<brojac;i++)
	{
		temp=*tekst;
		tekst+=razlika;
		*tekst=temp;
		tekst-=razlika;
		tekst--;
		
		
		
	}
	tekst++;
	if(broj<0)
	{*tekst='-';tekst++;}
printf("%d",razlika);
	for(i=0;i<razlika;i++)
	{
		
		*tekst=cifra(broj,razlika-i-1);
		tekst++;
		
	}
	
	
}

char* ubaci_broj(char* tekst, int broj)
{
	int pozicija= &tekst,brojac=0;
//	printf("sex %s %d",tekst,&tekst);


	while(*tekst!='\0')
	{
		if(*tekst==' ')
		{printf("ulaz \n");
		//	if(ididokraja(tekst))
			{
				
				ubaci(tekst,broj);
				
				
			}
		}
		
		
		
		tekst++;
		brojac++;
	}
	
	tekst-=brojac;
	
	
return tekst;
	
}


int main() {
/* AT2: Negativan broj */
char s[65] = "Sada cemo probati sa negativnim brojem";
printf("\"%s\"", ubaci_broj(s, -528));
	return 0;
}
