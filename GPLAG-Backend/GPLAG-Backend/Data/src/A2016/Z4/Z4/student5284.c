#include <stdio.h>
#include <string.h>


char* obuhvat(char* s,float x1,float y1,float x2,float y2)
{
	char *p=s;
	int neg=0;
	char *pt,*kt;
	float x,y;
	float a,b;
    char *pom=p;


		if(*pom=='\0') return 0;


	        while(*pom!='\0')
	        {

	    		if(*pom!='(') return 0;
	    		else pom++;

	    		if(*pom==',') return 0;

				 while(*pom!=',')
				 {
				 	if((*pom<'0' || *pom>'9') && (*pom!='.' && *pom!='-')){ return 0;}
				 	if(*pom=='.' && *(pom-1)=='(') return 0;
				    pom++;
				 }

			   	if(*pom!=',') return 0;
			   	else pom++;

			   	if(*pom==')') return 0;

			   	while(*pom!=')')
			   	{
			   		if((*pom<'0' || *pom>'9') && (*pom!='.' && *pom!='-')){return 0;}
				   	if(*pom=='.' && *(pom-1)==',') return 0;
				    pom++;
			   	}

			 	if(*pom!=')'){return 0;}
				else pom++;

			 	if(*pom!='\0') pom++;

				if(*pom=='\0' && *(pom-1)!=')') return 0;

	    }


		while(*p!='\0')
		{
			if(*p=='(')
			{

				pt=p;
				p++;

			neg=0;

			if(*p=='-')
				{neg=1;p++;}

			x=0;
			while(*p>='0' && *p<='9')
			{

				x=x*10+(*p-'0');
				p++;
			}


			if(*p=='.')
			{
				p++;a=0;
				while(*p>='0' && *p<='9')
			    {
					a=a*10+(*p-'0');
					p++;
			    }
			    while(a>=1)
			     	a/=10;

			    x=x+a;
			}

			if(neg==1) x*=-1;

			if(*p==',') p++;
			neg=0;
			if(*p=='-')
				{neg=1;p++;}

			y=0;
			while(*p>='0' && *p<='9')
			{
				y=y*10+(*p-'0');
				p++;
			}

			if(*p=='.')
			{
				p++;b=0;
				while(*p>='0' && *p<='9')
			    {
				b=b*10+(*p-'0');
				p++;
			    }
			    while(b>=1)
			     	b=b/10;
			    y=y+b;
			}

			if(neg==1) y*=-1;


			if(x<x1 || x>x2 || y<y1 || y>y2)
			{
			   p++;
			   if(*p==',') p++;

			   kt=p;

				while(*kt!='\0')
				{
					*pt++=*kt++;
				}
			    *pt='\0';
				p=p-(kt-pt);

			}
		}else
			p++;

		}
		if(p!=s) p--;
		if(*p==',') *p='\0';


   return s;
}


int main() {
char s[] = "(-15,-30)";
char pom[100];

strcpy(pom,s);
obuhvat(pom, -15, -30, -14, -29);
printf("'%s' ", pom);

strcpy(pom,s);
obuhvat(pom, -30, -30, -15, -15);
printf("'%s' ", pom);

strcpy(pom,s);
obuhvat(pom, -32, -31, -16, -15);
printf("'%s' ", pom);

strcpy(pom,s);
obuhvat(pom, -15, -30, -15, -30);
printf("'%s' ", pom);

strcpy(pom,s);
obuhvat(pom, 14, 29, 16, 31);
printf("'%s' ", pom);

return 0;
}
