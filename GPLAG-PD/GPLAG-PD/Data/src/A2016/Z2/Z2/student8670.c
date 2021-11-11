#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926
int main() {
	int n;
double niz[500];
double temp,minuti,sekundi;
int k,l;
printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(k=0;k<n;k++) {
	    scanf("%lf", &niz[k]);
	}
	for(k=0;k<n;k++) {
	     temp=fabs((180 * niz[k]) / PI);
	  minuti=(temp-(int)temp)*60;
	   sekundi=round ((minuti-(int)minuti) * 60);
	    if(sekundi==60) { sekundi=0; minuti++; }
	 if(sekundi>30) {
	  for(l=k;l<n-1;l++) {
	          niz[l]=niz[l+1];
	      }
	      n--; k--;
	  } 
	    }
	printf("Uglovi su:\n");
	for(k=0;k<n;k++) {
	    temp=(180 * niz[k]) / PI;
	   minuti=fabs((temp-(int)temp) * 60);
 sekundi= round((minuti-(int)minuti) * 60);
temp=(int)temp;
 minuti=(int)minuti;
 sekundi=round(sekundi);
	    if(temp>=0) {
	    	if(sekundi==60) { sekundi=0; minuti++;}
	    	if(minuti==60) { minuti=0; temp++;}
	    }
	    if(temp<0) {
	    	if(sekundi==60) { sekundi=0; minuti++;}
	    	if(minuti==60) { minuti=0;temp--;}
	    }
        printf("%.f stepeni %.f minuta %.f sekundi\n",temp,minuti,sekundi);
	}
	return 0;
}
