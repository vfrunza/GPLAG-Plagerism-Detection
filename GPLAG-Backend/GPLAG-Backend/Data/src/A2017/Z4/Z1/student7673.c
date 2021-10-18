#include <stdio.h>


int PrebrojiCifre(int n)
{    
	int br=0;
	if(n<0){ n*=-1;}
	while(n!=0)
	{
		n/=10;
		br++;
	}
	return br;
}

int ObrniBroj(int n)
{   
	int broj=0;
	if(n<0) n*=-1;
	while(n!=0)
	{
		broj=broj*10+n%10;
		n/=10;
	}
	return broj;
}


char* ProsiriString(char *pom,int n)
{	
	
    char *temp=pom;
	pom++;
    while(*temp!='\0') temp++;
    temp+=n-1;
    
  	
    while(temp!=pom)
    {
    	*temp=*(temp-n);
    	temp--;
    }
  
	return pom;
}

char Umanji(char k)
{
	if(k>='A' && k<='Z') k+=32;
	
	return k;
}

char* ubaci_broj(char* tekst, int broj)
{
	char *pom=tekst;
	int n=PrebrojiCifre(broj);
	int k=broj;
	char *test;

	
	while(*pom!='\0')
	{
	
		if(*pom==' ' && pom!=tekst && (Umanji(*(pom-1))>='a' && Umanji(*(pom-1)<='z')))
		{   
			test=pom;
			while(*test==' ') test++;
			if(*test=='\0') break;
			
			
			
			if(k<0) 
			{
				pom=ProsiriString(pom,n+2);
				k*=-1;
				*pom='-';
				pom+=n;
			}
			else
			{
				pom=ProsiriString(pom,n+1);	
				pom+=n-1;
			}	
			
			while(k!=0)
			{
				*pom=k%10+'0';
				pom--;
				k/=10;
			}
		  	
		    while(*pom==' '){ pom++;}
		    
		   
		} else  pom++;	
		k=broj;
		
	}
	
	return tekst;	
}


int main() {
/* AT7: Razmaci na pocetku i kraju, nema ubacivanja */
char s[19] = "     auto!stop   ";
char s2[22] = "     auto stop   ";
printf("\"%s\"\n", ubaci_broj(s, 9999));
printf("\"%s\"", ubaci_broj(s2, 9));
	return 0;
}
