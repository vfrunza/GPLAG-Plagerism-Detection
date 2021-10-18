#include <stdio.h>

int daj_duzinu(char* niz)
{
	int duzina=0;
	while(*niz!='\0')
	{
		duzina++;
		niz++;
	}
	return duzina;
}

char* kodiraj(char* tekst, char* tabela)
{
	char* pok_na_tekst=tekst;
	char* pok_na_tabelu=tabela;
	int ascii[95]={0};
	int i;
	int br=0;
	

	int slovo;
	while(*tekst!='\0')
	{
		ascii[*tekst-32]++;
		tekst++;
	}

	while(1)
	{
		int ima=0;
		for(i=0; i<95; i++)
		{
			if(ascii[i]>0) {ima=1; break;}
		}
		if(ima==1)
		{
		int max=0;
		for(i=0; i<95; i++)
			{
				if(ascii[i]>max)
				{
					max=ascii[i];
					slovo=i;
				}
			}
		ascii[slovo]=-1;
		br++;
		
		
		*tabela=slovo+32;
		
		tabela++;
		
		}
		else break;
	}
	/*tabela++;*/
	*tabela=' ';
	/*tabela++;*/
	
	for(i=0; i<95; i++)
	{
		if(ascii[i]==0)
		{
		*tabela=i+32;
		tabela++;
		}
	}
	tabela++;
	tabela='\0';
	tekst=pok_na_tekst;
	tabela=pok_na_tabelu;
	
	
	while(*tekst)
	{
		int pozicija;
		for(i=0; i<br; i++)
		{
			if(*tekst==tabela[i]) {pozicija=i; break;}
			
		}
		*tekst=126-pozicija;
		tekst++;
	
	}
	return pok_na_tekst;
}
char* dekodiraj(char* tekst, char* tabela)
{
	char* pok_na_tekst=tekst;
	while(*tekst)
	{
		int pozicija=126-*tekst;
		*tekst=tabela[pozicija];
		tekst++;
	}
	return pok_na_tekst;
}

int main() {
	
char tekst[] = "LLMLNLNMONM";
char sifrarnik[100] = "";
int i;
kodiraj(tekst, sifrarnik);

for (i=0; i<10; i++) printf("%c", sifrarnik[i]);
printf("\n");
for(i=0; i<11; i++) printf("%c", tekst[i]);
dekodiraj(tekst,sifrarnik);
printf("\n");
for(i=0; i<11; i++) printf("%c", tekst[i]);


	
	return 0;
}
