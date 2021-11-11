#include <stdio.h>
#include <math.h>
#define EPS 0.0001

char* obuhvat(char *s, float x1, float y1, float x2, float y2)
{
	float a=0, b=0;
	int br=0;
	char* poc, *temp, *izbaci, *minus;
	poc=s;
	
	
	while(*s!='\0')
	{
		/*prvi znak (*/
		if(*s=='(')
			s++;
		else
			return NULL;
		
		if(*s=='-')
			s++;
		if(!(*s>='0' && *s<='9'))
			return NULL;
			
		/*broj*/
		while(*s>='0' && *s<='9')
			s++;
		/*mora biti prije tacke broj; ako nema tacke mora ,*/
		if(*s=='.' && *(s-1)>='0' && *(s-1)<='9')
			s++;
		else if(*s!=',')
			return NULL;
		
		if(*s=='-')
			s++;
		
		/*poslije tacke mozda ima brojva*/
		while(*s>='0' && *s<='9')
			s++;
		
		if(*s==',')
			s++;
		else
			return NULL;
			
		if(*s=='-')
			s++;
			
		/*broj*/
		if(!(*s>='0' && *s<='9'))
			return NULL;
			
		while(*s>='0' && *s<='9')
			s++;
		/*mora biti prije tacke broj; ako nema tacke mora ,*/
		if(*s=='.' && *(s-1)>='0' && *(s-1)<='9')
			s++;
		else if(*s!=')')
			return NULL;
			
		if(*s=='-')
			s++;
			
		/*poslije tacke mozda ima brojva*/
		while(*s>='0' && *s<='9')
			s++;
		/*zavrsava zatvorenom zagradom*/	
		if(*s==')')
			s++;
		else
			return NULL;
		/*poslije zagrade ili zarez ili kraj*/
		if(*s==',' && *(s+1)=='(')
			s++;
		else if(*s=='\0')
			break;
		else
			return NULL;
	}
	s=poc;
	while(*s!='\0')
	{
		a=0;
		b=0;
		izbaci=s;
		while(*s!='.' && *s!=',')
			s++;/*postavljanje pokazivaca na JEDINICU*/
			/*prva koordinata*/
		if(*s==',')
		{
			temp=s;
			s--;
			br=0;
			while(*s>='0' && *s<='9')
			{
				a+=(*(s--)-48)*(pow(10, br++));
			}
			if(*s=='-')
				a*=(-1);
			s=temp;
		}
		else if(*s=='.')
		{
			temp=s;
			s--;
			br=0;
			while(*s>='0' && *s<='9')
				a+=(*(s--)-48)*(pow(10, br++));
			minus=s;
			s=temp;
			s++;
			br=0;
			while(*s>='0' && *s<='9')
				a+=(*(s++)-48)*(pow(10, --br));
			if(*minus=='-')
				a*=(-1);
		}
			/*druga koordinata*/
		s++;/*pokazivac na pocetak druge koo.*/
		while(*s!=')' && *s!='.')
			s++;/*postavljanje pokazivaca na JEDINICU*/
		br=0;
		
		if(*s==')')
		{
			temp=s;
			s--;
			br=0;
			
			while(*s>='0' && *s<='9')
				b+=(*(s--)-48)*(pow(10, br++));
				
			if(*s=='-')
				b*=(-1);
			s=temp;
		}
		else if(*s=='.')
		{
			temp=s;
			s--;
			br=0;
			while(*s>='0' && *s<='9')
				b+=(*(s--)-48)*(pow(10, br++));
			minus=s;
			s=temp;
			s++;
			br=0;
			while(*s>='0' && *s<='9')
				b+=(*(s++)-48)*(pow(10, --br));
			if(*minus=='-')
				b*=(-1);
		}
		s++;
		if(*s==',')/*ako nije posljednja koordinata, postavi pok na narednu*/
			s++;
		temp=s;
		if(!((a-x1>=EPS || ((a-x1)>=0 && (a-x1)<=EPS)) && (a-x2<=EPS || ((a-x2)>=0 && (a-x2)<=EPS)) && (b-y1>=EPS || ((b-y1)>=0 && (b-y1)<=EPS)) && (b-y2<=EPS || ((b-y2)>=0 && (b-y2)<=EPS))))
		{
			if(*s=='\0')
			{	
				*izbaci='\0';
				*(izbaci-1)='\0';
			}
			else
			{
				s=izbaci;
				while(*temp!='\0')
					*izbaci++=*temp++;
				*izbaci='\0';
			}
		}
	}
	s=poc;
	return s;
}

int main() {
	char s[]="(0,-3.1)";
	printf("%s", obuhvat(s, -3, -3, 3, 3));
	
	return 0;
}
	