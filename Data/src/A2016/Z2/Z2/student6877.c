#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	double niz[500],a,c,e;
	int n,b,d,i,f;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	
	for (i=0;i<n;i++)
	{
		scanf("%lf",&niz[i]);
	}
	printf("Uglovi su: ");
	for (i=0;i<n;i++)
	{
        a=niz[i]*180/PI;
        b=(int)a;
        c=a-b;
        c=c*60;
       
        d=(int)c;
        e=c-d;
        e=e*60;
        f=round(e); 
        if(f==-60) { f=0; d=d-1; }
        if(d==-60) { d=0; b=b-1; }
        if(f==60) { f=0; d=d+1; }
        if(d==60) { d=0; b=b+1; }
        
        d=fabs(d);
        f=fabs(f);
          
     
       if (fabs(f)<31 )
	   printf("\n%d stepeni %d minuta %d sekundi",b,d,f); 
       
        
	}


	return 0;
}
