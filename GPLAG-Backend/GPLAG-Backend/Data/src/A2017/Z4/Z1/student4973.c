#include <stdio.h>
#include <ctype.h>

char* ubaci_broj(char* tekst, int broj)
{
	char* s=tekst, *pt, *kt, *pm,*kraj;
	int n=broj,duzina=0,k=1,n1=0,novibroj=0,dobar=0,br1=0;
	if(n==0)duzina++;  
	while(n!=0) 
		{
			n1=n1*10+n%10;
			n/=10;              
			duzina++;
		}
		
	if(broj<0)duzina+=1;       
	
	while(*s!='\0')  
	{ 
		if((toupper(*s)>='A' && toupper(*s)<='Z') && (*s==*tekst || *(s-1)==' ' || *(s-1)==',')) 
		{
			pt=s; 
			
			
			
			while(toupper(*s)>='A' && toupper(*s)<='Z'){if(*(s+1)=='\0')break; s++;} 
			if(*(s+1)=='\0')return tekst; 
			if(*s==',' || *s==' ')
			{
				kt=s; 
				dobar=0;
				
				kraj=kt; 
				pm=kt; 
				
				while(*kraj!='\0'){if(*kraj!=' ')dobar=1;  kraj++;} 
				
				while(kraj>=kt)
				{
					if(dobar==0)return tekst; 
					if(*(kt+1)==' ') *(kraj+duzina)=*kraj; 
				else  
				 	*(kraj+duzina+1)=*kraj;

				kraj--; 
					
				}
				novibroj=n1;
				pm=kt+1; 
				br1=0;
				if(broj<0){ *pm='-'; pm++; novibroj*=-1;br1+=1;} 
				while(novibroj!=0 || br1<duzina)   
				{	
					*pm=(novibroj%10)+'0'; 
					
					br1++;
					pm++; 
				
				
					novibroj/=10;
					
			
				}
			} 
		}
		s++;
	}
	return tekst;
}

int main() {

char s2[22] = " Johi je   dokotor";
printf("\"%s\"", ubaci_broj(s2, 123));
	return 0;
}