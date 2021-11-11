#include <stdio.h>
#include<math.h>
#define pi 3.1415926
#define n 500
#define W 0.000000001
int main() {
	double a[n],st,s,m;
	int p,i,j,b,k,f;
	printf("Unesite broj uglova: ");
	scanf("%d",&p);
	
	if(p<n){
	for(i=0;i<p;i++){
		scanf("%lf",&a[i]);
	}}
	printf("Uglovi su: \n");
	
	for(i=0;i<p;i++){
	st=a[i]*180./pi;
	b=(int)st;
	m=fabs(st-(int)st)*60;
	f=(int)m;
	s=fabs(m-(int)m)*60; 
	k=(int)(s+0.5);
	if(k==60) {k=0;f++;
	if(f==60){f=0;
		if(b<0) b--;
		else b++;
	}}
	
	if(fabs(k)>30 && fabs(k)!=0) {
		for(j=i;j<p-1;j++) {
			a[j]=a[j+1];}
		p--;
		i--;continue;}

	
		printf("%d stepeni %d minuta %d sekundi\n",b,f,k);
	}
		
	
	return 0;
}
