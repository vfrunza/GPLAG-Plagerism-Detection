#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define  GR 500
#define PI 3.1415926
int main()
{
	int i,br_ugl,ukstep,ukmin,sekunde,j;
	double selma[GR]={0};
	long double uksek=0;
	/*unos uglova*/
	
	printf("Unesite broj uglova: ");
	scanf("%d",&br_ugl);
	
	
	for(i=0;i<br_ugl;i++)
	{
		scanf("%lf",&selma[i]);
	}
	
	
	/*izbacivanje ugl>30*/
	
	for(i=0;i<br_ugl;i++)
	{
		uksek=(float)(fabs(selma[i]*180/PI)*3600);
		uksek=(int)(uksek+0.5);
		ukstep=(uksek/3600); 
		
		ukmin=abs((uksek-ukstep*3600)/60);
		sekunde=abs((uksek-ukstep*3600-ukmin*60));
	
		 if(sekunde>30)
		 {
			for(j=i;j<br_ugl-1;j++)
			{
				selma[j]=selma[j+1];
		}
		br_ugl--;
		i--;
		}
	
	}
		
	printf("Uglovi su:\n");
	for(i=0;i<br_ugl;i++)
	{
		uksek=(float)(fabs(selma[i]*180/PI)*3600);
		uksek=((int)(uksek+0.5));
		ukstep=(uksek/3600); 
		
		ukmin=abs((uksek-ukstep*3600)/60);
		sekunde=abs((uksek-ukstep*3600-ukmin*60));
	
		
	
	
	if(sekunde>=60)
	{
		ukmin=ukmin+1;
		sekunde=sekunde-60;
	}
	if(ukmin>=60)
	{
		ukstep=ukstep+1;
		ukmin=ukmin-60;
	}
	if(selma[i]<0)
	{
		printf("-%d stepeni %d minuta %d sekundi\n",ukstep,ukmin,sekunde);
	}
	else
	 {
		printf("%d stepeni %d minuta %d sekundi\n",ukstep,ukmin,sekunde);
	 }
	}
	return 0;
}
