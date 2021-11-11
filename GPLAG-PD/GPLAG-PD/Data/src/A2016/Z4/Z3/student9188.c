#include <stdio.h>
#include <string.h>


int ProvjeriRijecnik(char **rijeci,char** zamjene,int broj_rijeci)
{
	int jeste=1;
	int i;
	char *temp,*temp1;
	
		for(i=0;i<broj_rijeci;i++)
		{   
			temp=rijeci[i];
			temp1=zamjene[i];
			while(*temp!='\0' || *temp1!='\0')
			{
				if(*temp!=*temp1){jeste=0;break;}
				temp++;
				temp1++;
			}
			if(jeste==0) break;
		}
	
		return jeste;
}


char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci)
{   

	char *pom=tekst;
	int i,br;
	char *pt,*kt,*ht,*temp;
	int isti;
	
	if(ProvjeriRijecnik(rijeci,zamjene,broj_rijeci)) return tekst;
	

	
	while(*pom!='\0')
	{
		if(pom==tekst || *(pom-1)==' ')	
		{	
			while(*pom==' ')pom++;
			pt=pom;
			
				for(i=0;i<broj_rijeci;i++)
					{  
						br=0;
						
						pom=pt;
					
					
						isti=1;temp=rijeci[i];
						
						while(*temp!='\0')
						{   
							if(*pom!=*temp || (*(temp+1)=='\0' && (*(pom+1)!=' ' && *(pom+1)!='\0'))){isti=0; break;}
							
							pom++;
							temp++;
						}
						
					
						if(isti==1)
						{  
							kt=pt;
							if(*pom!='\0') pom++;
							
							while(*pom!='\0')
							{
								*kt=*pom;
								kt++;
								pom++;
							}
							*kt='\0';
							pom=pt;
							
							temp=zamjene[i];
							
							while(*temp!='\0')
							{
								br++;
								temp++;
							}
							br++;
							
						    ht=kt+br;
						    pom--;
						    
						    while(kt!=pom)
						    {
						    	*ht=*kt;
						    	ht--;
						    	kt--;
						    }
						    
						   if(*(ht+1)!='\0')
						   	*ht=' ';
						   else *ht='\0';
						    
						    
						    temp=zamjene[i];
						    while(*temp!='\0' )
						    {
						    	*pt=*temp;
						    	pt++;
						    	temp++;
						    }
						 	pt++;
						}
					}
				}
			pom++;
			
		}
		
	
return tekst;
}


int main() {

char* rijeci[2] = {"test", "test"};
char* zamjene[2] = {"test", "test"};
char tekst[] = "test testiranje test";
printf("'%s'", zamjena_rijeci(tekst, rijeci, zamjene, 2));

return 0;
}
