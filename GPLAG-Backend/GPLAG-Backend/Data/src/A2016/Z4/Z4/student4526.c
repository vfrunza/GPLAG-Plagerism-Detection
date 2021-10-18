#include <stdio.h>
#include <math.h>
#define EPS 0.0001

int duzina(char *p)
{
	int brojac=0;
	while(*p!='\0')
	{
		brojac++;
		p++;
	}
	
	return brojac;
}

char *obuhvat(char *tacke, float x1 ,float y1 ,float x2 ,float y2)
{
	float cijeliDio, decimalniDio,prvi,drugi;
	int brojac=0,predznak=1,i;
	char *p1=tacke,*p2,*p3;

	if(*tacke=='\0') return tacke; 
	while(*p1!='\0')
	{
		cijeliDio=0; decimalniDio=0; predznak=1;
		
		if(*p1==',' && p1!=tacke)
		{
			p1++;
			if(*p1!='(') return NULL;
		}
		else if(*p1!='(') return NULL;
		
		p2=p1+1;
		if(*p2=='-')
		{
			predznak=-1;
			p2++;
			
		}

		if(*p2=='.') return NULL;
		else if(!(*p2>='0' && *p2<='9')) return NULL;
		p3=p2;
		
		while(*p3>='0' && *p3<='9') p3++;
		if(*p3!='.' && *p3!=',') return NULL;
		while(p2!=p3)
		{

			cijeliDio+=(*p2-'0')*pow(10,(int)(p3-p2)-1);
			p2++;
		}
		if(*p3!=','){
		p2=p3+1;
		
		if(!(*p2>='0' && *p2<='9') && *p2!=',') return NULL;
		p3=p2;
		
		while(*p3>='0' && *p3<='9') p3++;
		if(*p3!=',') return NULL;
		brojac=-1;
		
		while(p2!=p3)
		{
			decimalniDio+=(*p2-'0')*pow(10,brojac);
			brojac--; p2++;
		}
		} else decimalniDio=0;
		
		prvi=(cijeliDio+decimalniDio)*predznak;

		cijeliDio=0; decimalniDio=0;
		
		p2=p3+1;
		predznak=1;
		if(*p2=='-')
		{
			predznak=-1;
			p2++;
		}
		
		if(*p2=='.') return NULL;
		else if(!(*p2>='0' && *p2<='9')) return NULL;
		p3=p2;
		
		while(*p3>='0' && *p3<='9') p3++;
		if(*p3!='.' && *p3!=')') return NULL;
		while(p2!=p3)
		{
			cijeliDio+=(*p2-'0')*pow(10,(int)(p3-p2)-1);
			p2++;
		}

		if(*p3!=')'){
		p2=p3+1;
		
		if(!(*p2>='0' && *p2<='9') && *p2!=')') return NULL;
		p3=p2;
		
		while(*p3>='0' && *p3<='9') p3++;
		if(*p3!=')') return NULL;
		brojac=-1;
		
		while(p2!=p3)
		{
			decimalniDio+=(*p2-'0')*pow(10,brojac);
			brojac--; p2++;
		}
		} else decimalniDio=0;
		
		drugi=(cijeliDio+decimalniDio)*predznak;
		
		if((prvi>x1 || fabs(prvi-x1)<EPS) && (prvi<x2 || fabs(prvi-x2)<EPS) && (drugi>y1 || fabs(drugi-y1)<EPS) && (drugi<y2 || fabs(drugi-y2)<EPS))
		{
			p1=p3+1;
		}else
		{
			p3++;
			if(*p3=='\0' && *(p1-1)==',') 
			{
				p1--;
				*p1='\0';
			}else{
			for(i=p1-tacke;i<=duzina(tacke)-(p3-p1);i++)
			{
				tacke[i]=tacke[i+(p3-p1)];
				if(tacke[i+(p3-p1)]=='\0') break;
			}
			if(*p1==',')
			{
				for(i=p1-tacke;i<=duzina(tacke);i++)
			{
				tacke[i]=tacke[i+1];
				if(tacke[i+1]=='\0') break;
			}
			}
			}
			
		}
		
		
	}
	
	return tacke;
}
int main() {
/* AT3: Provjera rada sa negativnim brojevima */
char s[] = "(100,-100),(50,50),(70,20),(-1,-1)";
obuhvat(s, -1, -100, 100, 50);
printf("%s", s);
	return 0;
}
