#include <stdio.h>




int ProvjeriString(char *s)
{
	char *p=s;
	
		while(*p!='\0')
		{
			if(*p!='(') return 0;
			else p++;
				
				if(*p==',') return 0;
				
				while(*p!=',')
				{
					if((*p<'0' || *p>'9') && (*p!='.' && *p!='-')) return 0;
				   	if(*p=='.' && *(p-1)=='(') return 0;
				    p++;
				}
				
				
				if(*p!=',') return 0;
				else p++;
				
				if(*p==')') return 0;
				
				while(*p!=')')
				{
					
					if((*p<'0' || *p>'9') && (*p!='.' && *p!='-')) return 0;
				   	if(*p=='.' && *(p-1)==',') return 0;
				    p++;	
				}
				
				if(*p!=')') return 0;
			    else p++;
				
				if(*p!='\0') p++;
		
				if(*p=='\0' && *(p-1)!=')') return 0;
				
		}
		
return 1;	
}


void DajBroj(char *pt,char *kt,float *x,float *y)
{
	
	char *p=pt;
	int neg;
	float a,b;
	
	*x=0;*y=0;
	
		while(p!=kt)
		{
			p++;neg=0;
			
			if(*p=='-'){neg=1; if(*p=='\0') break; else p++;}
		
			*x=0;
			while(*p>='0' && *p<='9')
			{
				*x=*x*10+(*p-'0');
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
				*x=*x+a;
			}
			if(neg==1) *x*=-1;
			if(*p==',')p++;
			neg=0;
			if(*p=='-'){neg=1;p++;}
			*y=0;
			while(*p>='0' && *p<='9')
			{
				*y=*y*10+(*p-'0');
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
				 b/=10;
				*y=*y+b;
			}
			if(neg==1) *y*=-1;
			
		}
		
	
}


char* obuhvat(char *s,float x1,float y1,float x2,float y2)
{
	char* p=s;
	char *pt,*kt,*izb;
	float x,y;
	
	
	if (ProvjeriString(s)==0) return 0;


		while(*p!='\0')
		{ 
			
			if(*p=='(')
			{
				pt=p;
				while(*p!=')')p++;
				kt=p;
			
			DajBroj(pt,kt,&x,&y);
			
		
			if(x<x1 || x>x2 || y<y1 || y>y2)
			{   
				p++;
				while(*p==',')p++;
				izb=p;
				
				while(*izb!='\0')
				{
					*pt++=*izb++;
				}
				*pt='\0';
				p=p-(izb-pt);
			}
			
		
			}else p++;
				
		}
		
	    if(p!=s) p--;
		if(*p==',') *p='\0';
	
	return s;	
}

int main() {
	
	char s[] = "(0.25,),(-15.09,4),(2.,2),(-1.1,217.12)";
	char* rez = obuhvat(s, -3, -3, 3, 3);
	printf("%s %s\n", rez, s);
	return 0;
}
