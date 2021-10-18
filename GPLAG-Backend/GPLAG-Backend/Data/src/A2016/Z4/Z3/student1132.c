#include <stdio.h>


/*Funkcija mijenja sve rijeci iz stringa "tekst" jednake nekoj rijeci iz niza stringova "rijeci" sa njenim parom iz niza zamjene*/

char* zamjena_rijeci(char* tekst, char** rijeci, char** zamjene, int broj_rijeci)
{
		char *pok,*s = tekst;
		int i,j,k,len,eq,h,N,lenz,lenr;

		for(i=0;i<broj_rijeci;i++)
		{
			len=0;
			pok = rijeci[i];
			while(*pok!='\0') {len++; pok++;}

			for(j=0;tekst[j]!='\0';j++)
			{
				if(s[j]==' ') continue;
				eq = 1;
				if(!(j==0) && !(j!=0 && s[j-1]==' ')) eq = 0;
				if(eq==0) continue;		
				for(k=0;k<len;k++)
				{
					if(s[j+k]=='\0')
					{
					eq=0;
					break;
					}
					if(rijeci[i][k]!=s[j+k]) 
					{
					eq=0;
					break;
					}
				}
			 if(!(s[j+k] == '\0') && !(s[j+k]!='\0' && s[j+k]==' ')) eq = 0;
			 if(eq)
			 {
			 	lenz = 0;
				lenr = len;
			 	pok = zamjene[i];
				while(*pok!=0) {lenz++; pok++;}
			 	N = 0;
							
			    				 
				 for(h=j;s[h+lenr-1]!='\0';h++) s[h] = s[h+lenr];
			
			     pok = s;
				 while(*pok!=0) {N++;pok++;}
			 
			 	for(k=N;k>=j;k--)
            	{
				s[k+lenz] = s[k];
			 	}
			 	
			 	for(k=0;k<lenz;k++) s[j+k] = zamjene[i][k];
			 }
			 }
			 
		}
		return s;
}


int main() 
{
	return 0;
}
