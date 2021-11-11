#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define BROJ_EL 500

int main() {
	int i,j,n,k,p;
		double niz[BROJ_EL], step, min, sec;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0; i<n; i++) scanf("%lf", &niz[i]);
	printf("Uglovi su:\n");
	for(i=0;i<n;i++){
	    step=niz[i]*180/PI;
	    j=step;
	    min=(step-j)*60;
	    if(min<0) min=-min;
	    p=min;
	      sec=(min-p)*60;
	    if(sec<0) sec=-sec;
	    sec=(int)(sec+0.5);
	   if((sec-59)>0){ sec=0;
	   p++;
	   if(p-59>0) p=0; j++;}
	    else if(sec>30 || sec<-30){
	        for(k=0;k<n-1;k++){
	            niz[k]=niz[k+1];
	        }
	        n--;
	        i--;
	    }
	   else {
	        printf("%d stepeni %d minuta %g sekundi\n", j, p, sec);
	        
	    }
	        
	}
	
	return 0;
}
