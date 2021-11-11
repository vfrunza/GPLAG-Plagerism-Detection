#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main() 
{
	int n,i,bc=0,j,c;
	printf ("Unesite broj: ");
	scanf ("%i",&n);
	i=n;
	while (i!=0)
	{
	i=i/10;
	++bc;
	}
	int l,k,h,s,ya;
	if (bc>=9)
	{
		l=pow(10,bc-1);
		if (l%2!=0)
		l++;
		if (n<0)
		{
			n=-n;
		}
		for (k=0;k<bc;k++)
		{
			s=n/l;
			s=s%10;
			l=l/10;
			if(k==0)
			{
				ya=s;
				continue;
			}
			h=abs(ya-s);
			printf ("%i",h);
			ya=s;
		}
	}
	else
	{
		bc=0;
		if (n<0)
		{
			n=-n;
			n=n*10;
		}
		else if (n<10)
		{
			printf ("0"); 
		}
		else 
		{
			n=n*10;
		}
		i=n;
		while (i!=0)
		{
		i=i/10;
		++bc;
		}
		int m,v,temp,brp=-1,br0=0;
		m=pow (10,bc+1);
		if (bc<10)
		{
			for (m=pow (10,bc);  m>=100      ;   m=m/10       )
			{
				brp++;
				j=m;
				{
					v=((n-((n/j)*j)) / (j/10) );
				}
				if (brp==0)
				{
					temp=v;
					continue;
				}
				else if (temp>=v)
				{
					c=temp-v;
					if (c==0)
					br0++;
				}
				else if (temp<v)
				{
					c=v-temp;
					if (c==0)
					br0++;
				}
				if ((brp==br0)&&m==100) 
				{
					printf ("0");
				}
				else if ((br0==brp)&&c==0)         
				{
					
				}
				else if ((brp!=br0)&&c==0)   
				{
					printf ("0");
				}
				else if (c!=0)
				{
					printf ("%i",c);
				}
				temp=v;
			}
		}
	}
	return 0;
}