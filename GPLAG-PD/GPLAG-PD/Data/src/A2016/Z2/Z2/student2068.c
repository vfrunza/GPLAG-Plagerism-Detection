#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
    double a[505], minuteufloatu;
    int n, i, j, st[505], min[505], sec[505], b[505]={0};
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0; i<n; i++) {
	    scanf("%lf", &a[i]);
	    a[i]=a[i]*180/PI;
	    if(a[i]<0) {
	    	b[i]=1;
	    }
	}
	for(i=0; i<n; i++) {
		a[i]=fabs(a[i]);
		st[i]=a[i];
		minuteufloatu=(a[i]-st[i])*60;
		min[i]=minuteufloatu;
		sec[i]=(minuteufloatu-min[i])*60 + 0.5;
		if(b[i]) {
			st[i]=-1*st[i];
			if(sec[i]==60) {
				min[i]++;
				sec[i]=0;
				if(min[i]==60) {
					st[i]=st[i]-1;
					min[i]=0;
				}
			}
		}
		else if(sec[i]==60) {
			min[i]++;
			sec[i]=0;
			if(min[i]==60) {
				st[i]++;
				min[i]=0;
			}
		}
	}
	for(i=0; i<n; i++) {
		if(sec[i]>30) {
			for(j=i; j<n-1; j++) {
				st[j]=st[j+1];
				min[j]=min[j+1];
				sec[j]=sec[j+1];
			}
			i--;
			n--;
		}
	}
	printf("Uglovi su: ");
	for(i=0; i<n; i++) {
		printf("\n%d stepeni %d minuta %d sekundi", st[i], min[i], sec[i]);
	}
	return 0;
}
