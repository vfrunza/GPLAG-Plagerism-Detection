#include <stdio.h>
#include <math.h>
int slovo(char c);
void jedan_razmak(char* tekst);
int obrnuti(int broj);
char* ubaci_broj (char* tekst, int broj);

int main()
{
	char tekst[100]="   Ovdje   bas ima     svega   ";
	int broj=-987654320;
	printf("|%s|",ubaci_broj(tekst,broj));
	return 0;
}

char* ubaci_broj (char* tekst, int broj)
{
	int i;
	int znak=1;
	char* p1=tekst;
	char* p2;
	int neslovo=1,kraj;
	int temp,duzina;
	int dbr=0;
	znak=broj<0?-1:1;
	broj=znak*broj;
	if(broj==0)duzina=1;
	else duzina=log10(broj)+1;
	dbr=duzina;
	if(znak==-1)duzina++;

	while(*p1!='\0')
	{

		if(!slovo(*p1))
		{
			//nalazimo se na razmaku poslije rijeci
			if(!neslovo)
			{
				kraj=1;
				p2=p1;
				
				while(*p2!='\0')
				{
					if(slovo(*p2))kraj=0;
					p2++;
				}
				if(kraj==0)
				{
					while(p2>p1)
					{
						*(p2+duzina)=*p2;
						p2--;
					}
					if(znak==-1)*(p2+1)='-';
					p2+=duzina;
					temp=broj;
					for(i=0; i<dbr; i++)
					{
						*p2='0'+temp%10;
						temp/=10;
						p2--;
					}
					p1=p2;
					p1+=dbr;p1++;
					
					if(*p1!=' ')
					{
						p2=tekst;
						while(*p2!='\0')
						{
							p2++;
						}
						while(p1<=p2)
						{
							*(p2+1)=*p2;
							p2--;
						}
						*p1=' ';
					}
				}
			}
			neslovo=1;

		}
		else
		{
			neslovo=0;
		}

		p1++;
	}
	return tekst;
}



int slovo(char c)
{
	if(c==' '||c=='\0')return 0;
	else return 1;
}
