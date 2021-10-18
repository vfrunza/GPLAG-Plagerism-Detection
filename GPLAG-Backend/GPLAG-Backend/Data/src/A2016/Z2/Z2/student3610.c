#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define BMAX 500
int main() {
	int a,b;
	double NSTEPENI[BMAX],NMINUTA[BMAX],NSEKUNDI[BMAX],C[BMAX];
	do 
	{
		printf("Unesite broj uglova: ");
		scanf("%d",&b);
		
	}
	while(b<0 || b>500);
	for(a=0;a<b;a++)
	{
		printf("",a+1);
		scanf("%lf",&NSTEPENI[a]);
		
	}
	for(a=0;a<b;a++)
	{
		NSTEPENI[a]=NSTEPENI[a]*(180/PI);
		if(NSTEPENI[a]>360)
		{
			NSTEPENI[a]=(NSTEPENI[a]-((int)(NSTEPENI[a]/360)*360));
			
		}
		NMINUTA[a]=((NSTEPENI[a]*60)-(int)NSTEPENI[a]*60);
		NSEKUNDI[a]=(NMINUTA[a]*60)-(int)NMINUTA[a]*60;
		NSEKUNDI[a]=(floor(NSEKUNDI[a]+0.5));
		if((NSEKUNDI[a]>30 && NSEKUNDI[a]<=59.49) || (NSEKUNDI[a]<-30 && NSEKUNDI[a]>=-59.49))
		{
			C[a]=0;
			
		}
		else
		{ C[a]=1;
			
		}
		if(NSEKUNDI[a]>59.5)
		{
			NMINUTA[a]=NMINUTA[a]+1;
			NSEKUNDI[a]=0;
			
		}
		else if(NSEKUNDI[a]<-59.5)
		{
			NMINUTA[a]=NMINUTA[a]-1;
			NSEKUNDI[a]=0;
			
		}
		if(NMINUTA[a]>59.5)
		{
			NSTEPENI[a]=NSTEPENI[a]+1;
			NMINUTA[a]=0;
		}
		else if(NMINUTA[a]<-59.5)
		{
			NSTEPENI[a]=NSTEPENI[a]-1;
			NMINUTA[a]=0;
		}
		
	}
	printf("Uglovi su:\n");
	for(a=0;a<b;a++)
	{
		if(C[a]==1)
		{
			NMINUTA[a]=fabs(NMINUTA[a]);
			NSEKUNDI[a]=fabs(NSEKUNDI[a]);
			printf("%d stepeni %d minuta %d sekundi",(int)NSTEPENI[a],(int)NMINUTA[a],(int)NSEKUNDI[a]);
			printf("\n");
			
		}
		
	}
	return 0;
}
		
	
