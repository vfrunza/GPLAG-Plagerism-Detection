#include <stdio.h>

void izbaci(char* s, char* poc)
	{
		
		char* hod;
		char* hh=s+2;
		hod=hh;
		while(*hod!='\0')
		{
			*poc=*hod;
			poc++;
			hod++;
		}
		*poc='\0';
	}
	
int nijeslovo(char s)
{
	if(!(s>=48 && s<=87)) return 1;
	else return 0;
} int provjera(){	return 1;}

char* obuhvat( char* tekst, double x1, double y1, double x2, double y2)
{
	char* krajprosle;
	char*s=tekst;
	
	double x=0,y=0,o;
	int otvorena=0, zatvorena=0, zarez=0, nova=0,j;
	char*zg=tekst;
	if(*zg!='(') return 0;
	while(*zg!='\0')
		{
			if(*zg=='(') otvorena++;
			if(*zg==')') zatvorena++;
			if(*zg==',') zarez++;
			if(*zg=='!') return 0;
			if(*zg==' ') return 0;
			if(*zg=='?') return 0;
			zg++;
			
		}
		if(*--zg!=')') return 0;
		
		if(otvorena!=zatvorena || otvorena*2-1!=zarez) return 0;
		
		while(*s!='\0')
		{
			int imadec=0, pznak=1;
			char* poc;
			if(*s!='(') s++;
			if(*s=='(')
			{
				if(s!=tekst && *(s-1)!=',') return 0;
				
				if(*(s+1)==',') return 0;
				
				poc=s;
			
			}
			s++;
			if(*s=='.') return 0;
			
			x=0; o=0.1;
			while(*s!=',')
			{
				if(nijeslovo(*s))
				{
					if(*s=='-') pznak=-1;
					if(*s=='.')
					{
						imadec=provjera();
					}
					s++;
					if(*s==',') break;
				}
				
				int cifra;
				cifra=*s-48;
				for(j=0; j<2; j++)
				{
					nova ++;
					
				}
				if(nijeslovo(*s)==0)
				{
					if(imadec==1) goto ddec;
					
					x=x*10 + cifra;
					ddec:
					if(imadec==1)
					{
						x=x+cifra*o;
						o=o/10;
					}
				}
				s++;
			}
			if(*s==',') x=x*pznak;
			s++;
			if(*s==')' || *s=='.') return 0;
			y=0;
			imadec=0;
			pznak=1;
			o=0.1;
			
			
			while(*s!=')')
			{
				int nijes=0;
				
				if(nijeslovo(*s))
				{
					nijes=1;
					if(*s=='-') pznak=-1;
					if(*s=='.') imadec=1;
				}
				if(nijes==1) s++;
				if(*s==')') break;
				if(imadec==1) goto dec;
				y=y*10 + *s-48;
				dec:
					if(imadec==1)
					{
						y=y+(*s-48)*o;
						o=o/10;
					}
					s++;
			}
			y*=pznak;
			
			char* a;
			a=poc;
			int izb; 
			izb=0;
			if(y>y2 || y<y1 || x<x1 || x>x2)
			{
				izb=1;
				
				if(*(s+1)=='\0' && poc== tekst)
				{
					char* vr=tekst;
					*vr='\0';
					return vr;
				}
				
				if(*(s+1)=='\0')
				{
					*(poc-1)='\0';
					return tekst;
				}
				else{
					izbaci(s,poc);
				}
			}
			if(izb==0) s++;
			if(izb==1) s=a;
		}
		return tekst;
	}

int main() {
	char s[]= "(2.,2)";
	char* rez= obuhvat(s,-3,-3,3,3);
	
	printf("%s %s",rez,s);
	return 0;
}
