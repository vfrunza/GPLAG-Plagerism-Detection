#include <stdio.h>
#include <math.h>

char* obuhvat(char* s,double x1,double y1,double x2,double y2)
{
	double broj[5000][2]={{0}};
	char* pom=s;
	char* poc;
	char* kraj;
	char* null=0;
 long	int i=0,j,t,step,minusx,nullt=0,minusy;
	//ako je prazan string odmah ga vraca
	if(*s=='\0') return pom;
	//provjerava da li je unos pravilan ako nije vratiti ce null pokazivac 
	while(*s!='\0')
	{
		if(*s!='(')
		{
			nullt=1;
			break;
		}
		s++;
		if(*s=='-') s++;
		if(*s>'9'||*s<'0')
		{
			nullt=1;
			break;
		}
		while(*s>='0'&&*s<='9')
		{
			s++;
		}
		if(*s=='.') s++;
		while(*s>='0'&&*s<='9')
		{
			s++;
		}
		if(*s!=',')
		{
			nullt=1;
			break;
		}
		s++;
		if((*s>'9'||*s<'0')&&*s!='-')
		{
			nullt=1;
			break;
		}
		s++;
		while(*s>='0'&&*s<='9')
		{
			s++;
		}
		if(*s=='.') s++;
		while(*s>='0'&&*s<='9')
		{
			s++;
		}
		if(*s!=')')
		{
			nullt=1;
			break;
		}
		s++;
		if(*s=='\0') break;
		if(*s!=',')
		{
			nullt=1;
			break;
		}
		s++;
		if(*s=='\0')
		{
			nullt=1;
			break;
		}
	}
	if(nullt)
	{
		return null;
	}
	if(nullt==0)
	{
		s=pom;
		while(*s!='\0')
		{
			if(*s=='(')
			{
				j=0;
				s++;
			}
			t=1;
			minusx=1;
			minusy=1;
			//prevodi x i y koordinatu iz stringa u float
			while((*s>='0' && *s<='9')|| *s=='.'|| *s==','|| *s=='-')
			{
				if(*s==',')
				{
					j=1;
					s++;
					t=1;
				}
				else if(*s=='-')
				{
					if(j==0)
						minusx=-1;
					if(j==1)
						minusy=-1;
					s++;
				}
				else if(*s=='.')
				{
					t=0;
					step=1;
					s++;
				}
				else if(t)
				{
					broj[i][j]=broj[i][j]*10+(*s-48);
					s++;
				}
				else if(*s>='0' && *s<='9')
				{
					broj[i][j]+=(*s-48)*pow(10,step*(-1));
					step++;
					s++;
				}
			}
			broj[i][0]*=minusx;
			broj[i][1]*=minusy;
			//printf("%d")
			while(*s!='\0'&&*s!='(') s++;
			//ako je koordinata izvan kvadrata izbacuje ju
			if(broj[i][0]-x1<-0.0001||broj[i][0]-x2>0.0001||broj[i][1]-y1<-0.0001||broj[i][1]-y2>0.0001)
			{
				kraj=s;
				poc=s-1;
				while(*poc!='('&&*poc!=*pom)
				{
					poc--;
				}
				s=poc;
				while(*kraj!='\0')
				{
					*(poc++)=*(kraj++);
				}
				*poc='\0';
			}
			i++;
		}
	}
	//ako je izbacio zadnjeg clana na kraju je ostao zarez koji brise
	if(s!=pom) if(*(s-1)==',') *(s-1)='\0';
	return pom;
}

int main() {char s[] = "(0,00)";
char* rez = obuhvat(s, 0,0, 0,0);

/* Funkcija modificira primljeni string i vraca pokazivac na njegov pocetak */
printf("%s %s", rez, s);
	return 0;
}