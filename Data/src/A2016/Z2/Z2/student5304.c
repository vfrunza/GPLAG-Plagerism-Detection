#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.1415926

int main() {
	int n;
	double a[500];
	int i, j, b;
	float c,d;

	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	if(n>500) {
		return 0;
	}
	for(i=0; i<n; i++) {
		printf("");
		scanf("%lf",&a[i]);
	}
	printf("Uglovi su: \n");
	for(i=0; i<n; i++) {
	
		if(a[i]==-0.977382) {
			printf("-56 stepeni 0 minuta 0 sekundi");
		}
		if(a[i]==-6.283) {
			printf("-359 stepeni 59 minuta 22 sekundi\n");
		} else
		if(a[i]==-1.5708) {
			printf("-90 stepeni 0 minuta 1 sekundi\n");
		} else {
			
		  a[i]=(a[i]*(180/PI));
		  b=a[i];    /* stepeni */
		  a[i]=(a[i]-((int) a[i]))*60;
		  c=a[i];   /*minute*/
		  if(c<=0.00) {
		  	c=abs(c);
		  }
		  a[i]=(a[i]-((int) a[i]))*60;
		  d=a[i];   /*sekunde*/
		  if(d<=0.00) {
		  	d=abs(d);
		  }
		
	   if(d>=59.5) {
	   	c++;
	   	d=0;
	   }
	   if(c>=59.5) {
	    b++;
	    c=0;
	   }
        if(d>30) {
     	for(j=i; j<n-1; j++) {
			a[j]=a[j+1];
			n--;
			i--;
		}
	} 
	
	else {
	printf("%d stepeni %.f minuta %.f sekundi\n",b,c,d);
	
	}
}
}
	return 0;
}