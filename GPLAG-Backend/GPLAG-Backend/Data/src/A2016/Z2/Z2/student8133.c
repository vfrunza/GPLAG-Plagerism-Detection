#include <stdio.h>
#include <math.h>
#define max 500
#define pi 3.1415926

int main() {
	int n, i, j; 
	double a[max], b[3];
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){
	    scanf("%lf", &a[i]);
	}
	for(i=0; i<n; i++){
	    b[0]=a[i]*(180./pi);
	    b[1]=(b[0]-(int)b[0])*60;
	    b[2]=round((b[1]-(int)b[1])*60);
	    if(fabs(b[2])>59.5){
	        b[2]=0;
	    }
	    if(fabs(b[2])>30){
	        for(j=i; j<n-1; j++){
	            a[j]=a[j+1];
	        } 
	        n--;
	        i--;
	    }
	}
	printf("Uglovi su: \n");
	for(i=0; i<n; i++){
	    b[0]=a[i]*(180./pi);
	    b[1]=(b[0]-(int)b[0])*60;
	    b[2]=round((b[1]-(int)b[1])*60);
	    b[0]=(int)b[0];
	    b[1]=(int)b[1];
	    if((b[2])>59.5){
	        b[2]=0;
	        b[1]++;
	    } else if (b[2]<-59.5){
	        b[2]=0;
	        b[1]--;
	    }
	    if((b[1])>59.5){
	        b[1]=0;
	        b[0]++;
	    } else if (b[1]<-59.5){
	        b[1]=0;
	        b[0]--;
	    }
	    
	    b[1]=fabs(b[1]);
	    b[2]=fabs(b[2]);
	    printf("%.lf stepeni %.lf minuta %.lf sekundi\n", b[0], b[1], b[2]);
	}
	return 0;
}
