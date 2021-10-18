#include <stdio.h>
	
/* funkcija prebrojavanja rijeci*/
int br_rijeci(char *c)
	{
		int br=0;
		int v=0;
		while(*c)
		{
			if(*c==' ' || *c=='-')
				{
				 while(*c==' ' || *c=='-') c++;
				 v=0;
				}
			else
				{
				 if(v==0)
				 	{
				   	 br++; 
				 	 v=1;
				 	}
				c++;
				}
		}
	return br;
    }
 
 /*funkcija provjere duzine*/
 int provjera_duzine(char *c,int *niz,int duzina)
 {
 	int b=0;
 	int i=0;
 	if(duzina!=br_rijeci(c)) return 0;
	while(1)
 		{
 			while(*c!='\0')
 			{
 			if((*c>='A' && *c<='Z') || (*c>='a' && *c<='z')) b++;
			if(*c=='-' || *c==' ')break;
			c++;
 			}
 		if(b!=niz[i])return 0;
 		b=0;
 		i++;
 		if(i>duzina) return 0;
 		c++;
 		}
 	return 1;
  }
  
/* main*/
int main()
{
	return 0;
	
}
 