#include <stdio.h>
#include <math.h>

#define PI 3.1415926
int main() 
{
	int n,i,j,sek[500]={0},min[500],step[500];
 	double niz[500],minute;
 	
 	printf ("Unesite broj uglova: ");
 	scanf ("%d",&n);
 	
 	for (i=0;i<n;i++)
 	{
 		scanf ("%lf",&niz[i]);
 		niz[i]*=180/PI;
 	}	
 	
	
	for(i=0;i<n;i++)
	{
		if (fabs((int)(fabs(((((niz[i]-(int)(niz[i]))*60)-((int)((niz[i]-(int)(niz[i]))*60)))*60))+0.5))>30 && fabs((int)(fabs(((((niz[i]-(int)(niz[i]))*60)-((int)((niz[i]-(int)(niz[i]))*60)))*60))+0.5)) != 60 )
		{
			for(j=i;j<n-1;j++)
				niz[j]=niz[j+1];
		n--;
		i--;
		}
		
		step[i]=(int)niz[i];
		minute=fabs(((niz[i]-(int)(niz[i]))*60));
		min[i]=(int)minute;
		sek[i]=(int)(((minute-min[i])*60)+0.5);
		
		if(sek[i]==60)
		{
			sek[i]=0;
			min[i]+=1;
		}
		
	}
	
	for(i=0;i<n;i++) 
	{
	
		if(min[i]==60)	
		{
			if (step[i]<0)
			{
				min[i]=0;
				step[i]-=1;
			}
			else {
				min[i]=0;
				step[i]+=1;
			}
		}
	}
		
		
	
	
	
	printf ("Uglovi su: \n");
 	for (i=0;i<n;i++)
 		printf ("%d stepeni %d minuta %d sekundi\n",step[i],min[i],sek[i])
;

	return 0;
}
