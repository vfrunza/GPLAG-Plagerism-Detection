#include <stdio.h>
#include <math.h>
#define E 0.0001

char* obuhvat (char *c, float x1, float y1, float x2, float y2)
{
	float x,X,y,Y;
	
	int i=0, temp1, temp2, z;
	
	char* pom=c, *p, *k;
	
	
	while (*c!='\0')
	{
		
		if (*c=='-')
		{
			z=-1;
			c++;
		}
	
		
		if (*c=='.')
		{
			c++;
			if (*c==' ')
			{
				return 0;
			}
			
			while(*c>='0' && *c<='9')
			{
				X=X*10+(*c-'0');
				temp1++;
				c++;
				
				if (*c==',')
				{
					i=0;
					while (i<temp1)
					X=X/10;
					x=x+z*X;
					z=1;
					i++;
				}
			}
		}
		z=1;
			
		if (*c=='(')
		{
			if (c==pom)
				p=c;
			x=0; y=0;
			X=0; Y=0;
			temp1=0; temp2=0;
			z=1;
			c++;
		}
		else return 0;
		
	
		if (*c<'0' || *c>'9')
		{
			return 0;
		}
		
		while (*c>='0' && *c<='9')
		{
			x=x*10+z*(*c-'0');
			c++;
		}
			
		if (*c==',')
		{
			c++;
		}
		else return 0;
			
		if (*c=='-')
		{
			z=-1;			
			c++;
		}
			
		if (*c<'0' || *c>'9')
		{
			return 0;
		}
			
		while (*c>='0' && *c<='9')
		{
			y=y*10+z*(*c-'0');
			c++;
		}
			
		if (*c=='.')
			{
				c++;
				
				if (*c==' ')
					return 0;
				
				while (*c>='0' && *c<='9')
				{
					Y=Y*10+(*c-'0');
					temp2++;
					c++;
					
					if (*c==')')
					{
						i=0;
						while (i<temp2)
						{
							Y=Y/10;
							y=y+z*Y;
							i++;
						}
					}
				}
				if (*c==')')
				{
					c++;
					k=c;
				}
				else return 0;
			}
			
				if (*c==',')
			{
				p=c;
				c++;
				x=0; y=0;
				X=0; Y=0;
				temp1=0; temp2=0;
				z=1;
				
				if (*c=='\0')
				return 0;
			}
			
			if (x<x1 || x>x2 || y<y1 || y>y2)
			{
				while (*k!='\0')
				{
					*p=*k;
					p++;
					k++;
				}
				*p=*k;
				c=c-(k-p);
			}
		
		}
		
		c=pom;
		if (*c==',')
		{
			while (*c!='\0')
			{
				*c=*(c+1);
				c++;
			}
			*c=*(c+1);
		}
		c=pom;
	
		return c;
}

int main() 
{
	printf ("Zadaća 4, Zadatak 4");
	return 0;
}
