#include <stdio.h>

int slovo(char c)
{
	if((c<='Z' && c>='A')|| (c<='z' && c>='a')) return 1;
	return 0;
}

int uporedi(char c1,char c2)
{
	if(c1<='Z' && c1>='A') c1+=32;
	if(c2<='Z' && c2>='A') c2+=32;
	if (c1==c2) return 1;
	return 0;
	
}

int provjeri_duzinu(int p,char* pocetni,int* k)//Fja koja radi sve i guess
{
	char* s=pocetni;
	int novi_max=0;
	int i,j;
	int kraj1;
	
	for(i=p;s[i]!='\0';i++)
	if(!slovo(s[i]))//Trazim i od prvog ne slovo clana i stavljam granicu
	break;
	
	kraj1=i;

	for(i=p;i<kraj1;i++)//Kroz sva slova prve rijeci
	{
		
		for(j=i+1;j<kraj1;j++)//Ako se javlja do kraja break
			if(uporedi(s[i],s[j])) break;
		
		if(j<kraj1)//Ako se break smanji se granica
			kraj1=j;
	}
	
	if(kraj1-p>novi_max)//Ako je podstring duzi od najduzeg
	{
				novi_max=kraj1-p;//Duzina postaje nova
				*k=kraj1;//i kraj podstringa
			}
	
	return novi_max;
}

void najduzi_bp(char* s, char* rijec)
{
	int p1=0,k1=0;
	int i=0,tempk=0,j=0;
	int max=0,pmax=0;
	
	for(i=0;s[i]!='\0';i++)
	{
		if((s[i]<='Z' && s[i]>='A')|| (s[i]<='z' && s[i]>='a'))//Ako je doslo do nekog slova
		{
			pmax=provjeri_duzinu(i,s,&tempk);
			if(pmax>max)
			{
				max=pmax;
				k1=tempk;
				p1=i;
				
			}
		}
	}
	for(i=p1;i<k1;i++)
	rijec[j++]=s[i];
	rijec[j]='\0';
}

int main() {

	return 0;
}