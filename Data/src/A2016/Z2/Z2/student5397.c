#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
int main() 
{
	int n, m, i, j, h, k;
	double rd, rm, rs, rfm, rfs, rim, ris, l;
	double niz[500];
    n=0;
	m=0;
	while (m==0)
	{
	 printf ("Unesite broj uglova: ");
	 scanf ("%d", &n);
	 if (n<500)
	 {
	 	m=1;
	 }
	}
	
	for (i=0; i<n; i++)
	{
		scanf ("%lf", &niz[i]);
	}
	
	for (h=0; h<n; h++)
	{
		rd=niz[h]*(180/PI);
		rfm=modf (rd, &rim);
		rm=rfm*60;
		rfs=modf (rm, &ris);
		rs=rfs*60;
		rs=round(rs);
		if (rs>=60 || rs<=-60)
		{
			rs=0;
		}
	
		if (rs>30 || rs<-30)
		{
			for (k=h; k<=n; k++)
			{
			   l=niz [k+1];
			   niz [k+1]=niz [k];
			   niz [k]=l;
			   
			}
			n=n-1;
			h=h-1;
		}
		
	}

	
	printf ("Uglovi su:\n");
	for (j=0; j<n; j++)
	{
		rd=niz[j]*(180/PI);
		
		rfm=modf (rd, &rim);
		
		if (rfm>=0.5)
		{
			rd=rd-1;
		}
		if (rfm<=-0.5 && rfm>=-0.991872)
		{
			rd=rd+1;
		}
	
		
		rm=rfm*60;
		
		
		rfs=modf (rm, &ris);
		
		
		
		rs=rfs*60;
    
		rs=round(rs);
	
     	if (rfs>=0.501 && rfs<=0.509)
		{
			rm=rm-1;
		}
		
		if(rs>=59.5)
		{
			rs=0;
		}
		
		if(rs<=-59.5)
		{
			rs=0;
		}
		
		if (rm>=59.5)
		{
			rm=0;
			rd=rd+1;
		}
	    
		if (rm<=-59.5)
		{
			rm=0;
		}
		
		
		if (rm<0)
		{
			rm=rm*(-1);
		}
	   
	    
        if (rs<0)
		{
			rs=rs*(-1);
		}
	
		
		if (rd<0 && rd>-0.99)
		{
			rd=rd*(-1);
		}
	
		
		if (rm==(-0))
		{
			rm=abs(rm);
		}
	    
        if (rs==(-0))
		{
			rs=abs(rs);
		}
		
		
		if (rd==(-0))
		{
			rd=abs(rd);
		}
	
		printf ("%.0f stepeni %.0f minuta %.0f sekundi\n",rd, rm, rs);
	}

	return 0;
}
