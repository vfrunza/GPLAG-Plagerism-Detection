#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
    int i,j,n;
    double a[500],s,m,sek,o,o1;

    printf("Unesite broj uglova: ");
    scanf("%d",&n);
    
	printf("Uglovi su:\n");
	for(i=0;i<n;i++)
	{
	    scanf("%lf",&a[i]);
	}

 for (i=0; i<n; i++) 
    {   
    	s=a[i]*180/PI;
    	s=fabs(s);
    	o=s-(int)s;
    	s=s-o;
    	m=o*60;
    	o1=m-(int)m;
    	m=m-o1;
    	sek=o1*60;
    	sek=(int)(sek+0.5);
    	if(sek>59){
    		m=m+1;
    		sek=0;
    	}
    	if(m>59){
    		s=s+1;
    		m=0;
    	}
    	
    	if (sek>30) 
    {
 	    for (j=i; j<n-1; j++) 
 	{ 
 		a[j] = a[j+1]; 
 	} 
 		n--; 
 		i--;
 	}
 	
    }
   
   for(i=0;i<n;i++)
   {
   	    s=a[i]*180/PI;
    	s=fabs(s);
    	o=s-(int)s;
    	s=s-o;
    	m=o*60;
    	o1=m-(int)m;
    	m=m-o1;
    	sek=o1*60;
    	sek=(int)(sek+0.5);
    	if(sek>59){
    		m=m+1;
    		sek=0;
    	}
    	if(m>59){
    		s=s+1;
    		m=0;
    	}
    	if(a[i]<0)
    	{
    		printf("-%g stepeni %g minuta %g sekundi\n",s,m,sek);
    		
    	}
    	else{
    	printf("%g stepeni %g minuta %g sekundi\n",s,m,sek);
   			}
   }
   
	return 0;
}
