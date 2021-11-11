#include <stdio.h>
char* kodiraj(char* tekst, char* tabela)
{
	char *pomocni=tekst;
	char *pomocniTabela;
	int max,j,index;
	int i,temp,brojac=0;
	int pomocniNiz[127]={0};
	
	while(*pomocni!='\0')
	{
		temp=*pomocni;
		pomocniNiz[temp]++;
		pomocni++;
	}
	for(i=0;i<127;i++)
	{
		max=pomocniNiz[i];
		index=i;
		for(j=i;j<127;j++) if(pomocniNiz[j]>max){max=pomocniNiz[j];index=j;}
		if(max!=0)
		{
			tabela[brojac]=index;
			pomocniNiz[index]=-1;
			brojac++;
		}
	}
	
	for(i=32;i<127;i++)
	{
		if(pomocniNiz[i]==0)
		{
			tabela[brojac]=i;
			brojac++;
		}
	}
	tabela[brojac]='\0';
	pomocni=tekst;
	pomocniTabela=tabela;
	brojac=0;
	while(*pomocni!='\0')
	{
		pomocniTabela=tabela;
		brojac=0;
		while(*pomocniTabela!='\0')
		{
			if(*pomocniTabela==*pomocni) break; else brojac++;
			pomocniTabela++;
		}
		*pomocni=126-brojac;
		pomocni++;
	}
	pomocni='\0';
	return tekst;
}

char *dekodiraj(char* tekst,char* tabela)
{
	char* pomocni=tekst;
	while(*pomocni!='\0')
	{
		*pomocni=tabela[126-*pomocni];
		pomocni++;
	}
	return tekst;
}

int main() {
	char tekst[] = "Ovo cemo sifrirati 2 puta";
    char sifrarnik[100] = "";
    char sifrarnik2[100] = "";
    int i;
    kodiraj(tekst, sifrarnik);
    printf("%s", tekst);
    for (i=0; i<10; i++) printf("%c", sifrarnik[i]);
    kodiraj(tekst, sifrarnik2);
    printf("%s", tekst);

	return 0;
}
