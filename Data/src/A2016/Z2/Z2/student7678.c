#include <stdio.h>
#include <math.h>
#define pi 3.1415926

int main() {
	double u[500],a,s[500];
	int n,i,st[500],min[500],sek[500],j,p[500]={0};
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	
	
	for(i=0;i<n;i++)
	{
	    scanf("%lf",&u[i]);
	    if(u[i]<0){ u[i]=fabs(u[i]);p[i]=1;}
	    
	}
	for(i=0;i<n;i++)
	{
	    u[i]=u[i]*180/pi;
	}
	
	for(i=0;i<n;i++)
	{
		st[i]=(int)u[i];
		a=(u[i]-st[i])*60;
		min[i]=(int)a;
		s[i]=(a-min[i])*60;
		sek[i]=(int)(s[i]+0.5);
		if(sek[i]>=60){sek[i]=0;min[i]=min[i]+1;}
		if(min[i]>=60){min[i]=0;st[i]=st[i]+1;}
		
	}
	
	
		for(i=0;i<n;i++)
		{
			if(sek[i]>30)
			{
				for(j=0;j<n;j++){
					for(j=i;j<n-1;j++){st[j]=st[j+1];min[j]=min[j+1];sek[j]=sek[j+1];}
					n--;
					i--;
					
					
				}
			}
		}
	
	
	printf("Uglovi su: \n");
	
	for(i=0;i<n;i++)
	{
		if(p[i]!=1){printf("%d stepeni %d minuta %d sekundi\n",st[i],min[i],sek[i]);}
		else{printf("-%d stepeni %d minuta %d sekundi\n",st[i],min[i],sek[i]);}
		
	}
	
	
	return 0;
}
