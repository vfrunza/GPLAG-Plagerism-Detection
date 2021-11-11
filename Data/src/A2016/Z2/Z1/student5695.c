#include <stdio.h>
#include <math.h>
int main() {
	int i,j=-1,k,l=0,m,n;
	printf("Unesite broj: ");
	scanf("%d",&n);
	if(n<0) n=fabs(n);
	if(n/10==0) {
		printf("0");
		return 0;
	}
	else {
	m=n;
	while(m>0) {
		m/=10;
		j++;
	}
	for(i=0;i<j;i++) {
		k=n%10-((n%100-n%10)/10);
		if(k<0) k=fabs(k);
		l+=k*pow(10,i);
		n/=10;
	}
	printf("%d",l);
	}
	return 0;
}
