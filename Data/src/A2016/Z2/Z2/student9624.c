#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main() {
	
	int n,i,j;
	double min[500]={0},sec[500]={0},st[500]={0},niz[500];
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	 
    for(i=0 ; i<n ; i++) {
    	
    			scanf("%lf",&niz[i]);
    		
     }
    
     for(i=0 ; i<n ; i++) {
     	
     	niz[i]=niz[i]*(180/PI);
     	st[i]=(int)niz[i];
     	niz[i]=(niz[i]-st[i])*60;
      min[i]=(int)fabs(niz[i]);
      if(st[i]>=0)
      niz[i]=((niz[i]-min[i])*60)+0.5;
       sec[i]=(int)fabs(niz[i]);
       if(st[i]<0)
        niz[i]=((niz[i]-min[i])*60)-0.5;
       sec[i]=(int)fabs(niz[i]);
     }
   
     for(i=0 ; i<n ; i++)  {
      				
      				if (st[i] >= 0) {
      					while(sec[i]>=60) { min[i]++; sec[i]-=60; }
          	while(min[i]>=60 ){  st[i]++; min[i]-=60; }	
      				}
      				else {
      					while(sec[i]>=60) { min[i]--; sec[i]-=60; }
          	while(min[i]>=60) {  st[i]--; min[i]-=60; }	
      				}	
      				min[i] = fabs(min[i]);
     					
     }
    
    for(i=0 ; i<n ; i++) {
             if((int)sec[i]>30)  {
                    for(j=i ; j<=n-1 ; j++)  {
           
            st[j]=st[j+1];
             min[j]=min[j+1];
            sec[j]=sec[j+1];
              }
         
     	n--;
     	i--;
         }
    }
    
        printf("Uglovi su: ");
     for(i=0 ; i<n; i++)  {
   
        printf("\n%g stepeni %g minuta %g sekundi",st[i],min[i],sec[i]);
    
    }
     
    
   
     
	return 0;
}
