#include <stdio.h>
#include <math.h>
#define pi 3.1415926

int main() {
	int n, i;
	double a[502], st[502], m[502], sk[502];
	do
	{
		printf("Unesite broj uglova: ");
		scanf("%d", &n);
	}while(n>500);
	
	for(i=0;i<n;i++)
	{
		scanf("%lf", &a[i]);
		st[i]=a[i]*180/pi;
		m[i]=(((int)(st[i])-st[i])*60);
		sk[i]=(((int)(m[i])-m[i])*60);
		if(sk[i]>=0) sk[i]+=0.5; else sk[i]-=0.5;
		sk[i]=(int)(sk[i]);
		st[i]=(int)st[i];
		m[i]=fabs((int)m[i]);
		sk[i]=fabs((int)sk[i]);
		if(sk[i]==60) {sk[i]=0; m[i]++;}
		if(m[i]==60) {m[i]=0; if(st[i]>=0) st[i]++; else st[i]--;}
		if(sk[i]>30){i--; n--;}
	}
	printf("Uglovi su: \n");
	for(i=0;i<n;i++)
	{
		printf("%g stepeni %g minuta %g sekundi\n", st[i], m[i], sk[i]);
	}
	
	return 0;
}
