#include <stdio.h>  
#include <stdlib.h> 
#include <math.h>
#define PI 3.1415926

int main() {
	int n, i;
    double  r; 
    int tsek, sek, min, st;
    double mat[500][3];
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0; i<n; i++){  
		scanf("%lf", &r);
		tsek=(int)round(r*360*60*60/(2*PI));
		sek=tsek%60;
		min=(tsek/60)%60;
		st=tsek/(60*60);
	    mat[i][0]=st;
	    mat[i][1]=min; 
	    if(mat[i][1]<0) mat[i][1]*=(-1);
	    mat[i][2]=sek; 
	    if(mat[i][2]<0) mat[i][2]*=(-1);
	    
	} 
	printf("Uglovi su: \n");
	for(i=0; i<n; i++){
			if (mat[i][2]>30) continue; 
			if(mat[i][2]<-30) continue;
			else printf("%.f stepeni %.f minuta %.f sekundi\n", mat[i][0], mat[i][1], mat[i][2]); 
		}
	return 0;
}
