#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define Pi 3.1415926
int main() {
	int n;
	double niz[500]={0};
	int i,j,G=0,H=0,J=0;
	double S,K,m,s,x,y,s1;
	printf("Unesite broj uglova: ");
	printf("Uglovi su:");
	scanf("%d",&n);

	for(i=0; i<n ; i++)
	{

	
	scanf("%lf", &niz[i]);
		 S=( ( niz[i]*180)/ Pi );
	
	
	
	
	

	 S=( ( niz[i]*180)/ Pi );
	 G=S;
	 x=S-(int)(S);
	 m=fabs(x*60);
	 H=m;
	 y=m-(int)(m);
	 s=fabs(y*60);
	 s1=s-(int)(s);
	 J=s;
		if(s1>0.5)
		{
			J=J+1;
		}
		else
		{
			J=s;
		}
		if(niz[i]>0 && J==60)
		{	J=0;
			H++;
		}
		if(niz[i]>0 &&H==60)
		{	H=0;
			G++;
		}
		if(niz[i]<0 && J==60)
		{	J=0;
			H++;
		}
		if(niz[i]<0 && H==60)
		{
			H=0;
			G--;
		}
		
		if(J>30)
	{
		for(j=i; j<n-1; j++)
		{
			niz[j]=niz[j+1];
		}
		n--;
		i--;
		continue;
	
	}
	
	printf("\n%d stepeni %d minuta %d sekundi",G,H,J);	
	}
	


	

	return 0;
}
