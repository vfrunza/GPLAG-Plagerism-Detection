#include <stdio.h>
#include <math.h>
#define PI 3.141592

int main() {
    double temp;
    int stepeni,minute,sekunde,n,i,j;
    
    double niz[500];
	do
	{
	    printf("Unesite broj uglova: ");
	    scanf("%d",&n);
	    if(n<=0 || n>500) printf("Pogresan unos");
	}
	while(n<=0 || n>500);
	for(i=0;i<n;i++)
	{
	    scanf("%lf",&niz[i]);
	}
	for(i=0;i<n;i++)
	{
		temp=niz[i];
		temp=fabs((temp*180/PI)*3600);
		temp=(int)(temp+0.5);
        stepeni=temp/3600;
        minute=(temp-stepeni*3600)/60;
        sekunde=(temp-stepeni*3600-minute*60);
        if(sekunde>=60){minute++;sekunde-=60;}
        if(minute>=60){stepeni++;minute-=60;}
        if(sekunde>30)
        {
        	for(j=i;j<n-1;j++)
        	{
        		niz[j]=niz[j+1];
        	}
        	n--;
        	i--;
        }
		
	}
	printf("Uglovi su:\n");
	for(i=0;i<n;i++)
	{
		if(niz[i]<0)
		{
			niz[i]=fabs((niz[i]*180/PI)*3600);
        niz[i]=(int)(niz[i]+0.5);
        stepeni=niz[i]/3600;
        minute=(niz[i]-stepeni*3600)/60;
        sekunde=(niz[i]-stepeni*3600-minute*60);
        if(sekunde>=60){minute++;sekunde-=60;}
        if(minute>=60){stepeni++;minute-=60;}
        if(sekunde>=60){minute++;sekunde-=60;}
        if(minute>=60){stepeni++;minute-=60;}
        
        printf("-%d stepeni %d minuta %d sekundi\n",stepeni,minute,sekunde);
        continue;
		}
		niz[i]=(niz[i]*180/PI)*3600;
        niz[i]=(int)(niz[i]+0.5);
        stepeni=niz[i]/3600;
        minute=(niz[i]-stepeni*3600)/60;
        sekunde=(niz[i]-stepeni*3600-minute*60);
        if(sekunde>=60){minute++;sekunde-=60;}
        if(minute>=60){stepeni++;minute-=60;}
        if(sekunde>=60){minute++;sekunde-=60;}
        if(minute>=60){stepeni++;minute-=60;}
        
        printf("%d stepeni %d minuta %d sekundi\n",stepeni,minute,sekunde);
	}
	return 0;
}
