#include <stdio.h>
#include <stdlib.h>

char* kodiraj(char *tekst,char *tabela)
{
	char *pom=tekst;
	int i,j;
	char *temp=tekst;
	int br=0;
	int priv;
	int sort[95];
	int indexi[95];
	int niz[95];
     
     char *help=tabela;
		temp++;
	
	
	for(i=0;i<95;i++)
		niz[i]=0;
	
	
		while(*pom!='\0')
		{	
			temp=pom;
			br=0;
			
			while(*temp!='\0')
			{
				if(*pom==*temp)br++;
				temp++;
			}
			if(niz[*pom-32]==0)niz[*pom-32]=br;
			pom++;
		}
	   
	  	br=0;
		for(i=0;i<95;i++)
		{
			if(niz[i]!=0)
			{
				sort[br]=niz[i];
				indexi[br]=i;
				br++;
				
			}
		}
	
		for(i=0;i<br;i++)
			for(j=i;j<br;j++)
			{
				if(sort[i]<sort[j])
				{
					priv=sort[i];
					sort[i]=sort[j];
					sort[j]=priv;
					
					priv=indexi[i];
					indexi[i]=indexi[j];
					indexi[j]=priv;
				}
				 if(sort[i]==sort[j] && indexi[i]>indexi[j])
				{
					priv=indexi[i];
					indexi[i]=indexi[j];
					indexi[j]=priv;
				}
			}
			
			
		for(i=0;i<br;i++) 
		{
			
			*help=indexi[i]+32;
			help++;
		
		}
		   
	   for(i=0;i<95;i++)
	   {
	   		if(niz[i]==0) {*help=i+32;help++;}
	   }
	   *help='\0';
	   
	   help=tabela;
	   pom=tekst;
	  	
	  	
	  		while(*pom!='\0')
	  		{ 
	  			br=0;help=tabela;
	  				while(*help!='\0')
	  				{	
	  					if(*pom==*help){ *pom=126-br; break;}
	  					br++;
	  					help++;
	  				}
	  			pom++;
	  		}
	  	
	
   return tekst;
	
}

char *dekodiraj(char *tekst,char *tabela)
{
	char *pom=tekst;
	
	               
			while(*pom!='\0')
			{	
			
				*pom=tabela[126-*pom];
				pom++;
				
			}
			
		
		return tekst;
}

int main() {
	
    char tekst[] = "Jeste li dobro kreirali sifrarnik?";
    char sifrarnik[100] = "";
   
    kodiraj(tekst, sifrarnik);
    printf("%s", tekst);
    printf("%s", sifrarnik);

	return 0;
}
