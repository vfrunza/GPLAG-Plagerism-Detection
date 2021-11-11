#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	double d[500],m[500],s[500];
	int n=-1, i, j;
	while(1){
		printf("Unesite broj uglova: ");
		scanf("%d", &n);
		if((n>0)&&(n<=500)) break;
		printf("Pogresan unos\n");
	}
	for(i=0;i<n;i++){
		scanf("%lf", &d[i]);
	}
	for(i=0;i<n;i++)
		d[i]=d[i]*(180./PI);
	for(i=0;i<n;i++){
		m[i]=(int) ((fabs(d[i])-((int)(fabs(d[i]))))*60.);
		s[i]= (fabs(d[i])-((int)fabs(d[i]))-(m[i]/60.))*3600.;
		s[i]= (int)(s[i]+0.5);
		d[i]=(int)d[i];
		if(s[i]==60){
			m[i]++;
			s[i]=0;
		}
		if(m[i]==60){
			m[i]=0;
			if(d[i]>=0) d[i]++;
				else d[i]--;
		}
	}
	for(i=0;i<n;i++)
		if(s[i]>30){
			for(j=i;j<n-1;j++){
				s[j]=s[j+1];
				d[j]=d[j+1];
				m[j]=m[j+1];
			}
			n--;
			i--;
		}
	printf("Uglovi su: ");
	for(i=0;i<n;i++){
		printf("\n%g stepeni %g minuta %g sekundi",d[i], m[i], s[i]);
	}
	return 0;
}
