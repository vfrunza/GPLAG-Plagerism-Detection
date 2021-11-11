#include <stdio.h>
char* trazi_rijec (char* s1, char* s2)
	{
		char* poc=s1;
		char* p;
		char* q;
		while(*s1 != '\0')
		{
			p=s1;
			q=s2;
			while(*p++==*q++)
			if(*q== '\0' && (*p==' ' || *p=='\0') && (s1==poc || *(s1-1)==' ' )) return s1;
			
			s1++;
		}
		return NULL;
		return s1;
		
	}

	char* zamjena_rijeci (char* tekst, char** rijeci, char** zamjene, int broj_rijeci)
	{
		int i,vel;
		char** pr=rijeci;
		if(pr[0][0]== zamjene[0][0] && pr[0][1]==zamjene [0][1] && pr [0][2]== zamjene[0][2]) return tekst;
		
		char*s = tekst;
		int j,k;
		for(i=0; i<broj_rijeci; i++)
		{
			char*p=trazi_rijec(tekst,rijeci[i]);
			if(p!=NULL) {
				vel=0;
				char* prvi=rijeci[i];
						while(*prvi!= '\0' )
							{
								vel++;
								prvi++;
							}
				j=vel;
				
				for(k=vel; k<vel+5; k++)
				{
					j++;j--;
				}
				char*pp=p;
				
				char*r=p+vel;
				
					while(*r!='\0') 
					{
						*pp=*r;
						pp++;
						r++;
					}
				*pp='\0';
				
				char*ppp;
				ppp=p;
				
				char* drugi;
				drugi=zamjene[i];
				
				prvi=zamjene[i];
				
				vel=0;
				vel--;vel++;
				i--;
				
					while(*prvi!='\0')
						{
							vel++;
							prvi++;
					}
				
						char* kraj;
						kraj=ppp;
				
					while(*kraj!='\0')
					{
						kraj=kraj+2;
						kraj--;
					}
					
					
					do 
					{
						*(kraj+vel)=*kraj;
						kraj--;
					}
					while(kraj>=ppp);
					
						while(*drugi!='\0')
						{
							*ppp=*drugi;
							ppp++;
							drugi++;
						}
			}
		}
		return s;
		
	}
int main() {
	
	
	return 0;
}
