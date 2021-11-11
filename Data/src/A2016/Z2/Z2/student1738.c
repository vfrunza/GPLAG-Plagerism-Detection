#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
#define eps 0.001

int main() 
{
	double rad[500],step[500],minn[500],sekn[500];
	double min1,sek,stp1,stp;
	int i=0,u,j=0,predznak[500];
	
	printf ("Unesite broj uglova: ");
	scanf ("%i",&u);
	
	
	for (i=0;i<u;i++)
	{
		scanf ("%lf",&rad[i]);
		
		if (rad[i]<0)
		{
			
			predznak[i]=-100;
			rad[i]=-rad[i];
		}
		else if (rad[i]>=0)
		{
			predznak[i]=100;
			
		}
		
		/************pretvaranje iz radijanau stepene*/
		stp=rad[i]*(180/PI);
		stp1=abs(stp);
		min1=stp-stp1;
		
		min1=min1*60;
		
		sek=(abs(min1));
		/*printf ("\nsekunde %f\n",sek);*/
		sek=min1-sek;
		/*printf ("\nsekunde %f\n",sek);*/
		sek=sek*60;
		/*printf ("\nsekunde %f\n",sek);*/
		sek=(int) (sek+0.50);
		/*printf ("\nsekunde %f\n",sek);*/
		min1=(int)min1;
		stp=(int)stp;
		
		/*printf ("\n3.min1 %g ddd",min1);
		printf ("\nsek %g ddd",sek);*/
		if (sek>=60)
		{
			sek=0;
			min1++;
		}
		if (min1>=60)
		{
			min1=0;
			stp++;
		}
		/*printf ("\nsekunde %i\n",sek);*/
		step[i]=stp;
		minn[i]=min1;
		sekn[i]=sek;
	/******************************************************/
		
			
		
		
	}
	/*********izbacivanje nizova sa vise od 30 sekundi************/
	printf ("Uglovi su:");
	for (i=0;i<u;i++)
	{
		if (sekn[i]>30)
		{
			for (j=i;j<u-1;j++)
			{
				sekn[j]=sekn[j+1];
			}
			for (j=i;j<u-1;j++)
			{
				step[j]=step[j+1];
			}
			for (j=i;j<u-1;j++)
			{
				minn[j]=minn[j+1];
			}
			for (j=i;j<u-1;j++)
			{
				predznak[j]=predznak[j+1];
			}
			
			u--;
			i--;
		}
		else if (sekn[i]<=30)
		{
			
	 		if (predznak[i]<0 )
				{
				
				if ((step[i]-eps)==0)
				{
					
					printf ("\n%.0f stepeni -%.0f minuta %.0f sekundi",step[i],minn[i],sekn[i]);
				}
				else if ((step[i]-eps)!=0)
				{
					
					printf ("\n-%.0f stepeni %.0f minuta %.0f sekundi",step[i],minn[i],sekn[i]);
				}
				
			}
			else if (predznak[i]==100)
			{
				printf ("\n%.0f stepeni %.0f minuta %.0f sekundi",step[i],minn[i],sekn[i]);
			}
		}
 
	 
	 
	/*******************************************************************/
		}
	
	
	
	return 0;
}
