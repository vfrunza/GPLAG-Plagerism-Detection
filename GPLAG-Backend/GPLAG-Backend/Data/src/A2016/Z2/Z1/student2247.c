#include <stdio.h>
#include <math.h>

int main() {
	long i=0, brcfr=0, j=0, stpn=1, a=0, b=0, c=0, k, p=0, a1=0, b1=0, c1=0, x1=0;
	long n, m, x=0, y, z=1;
	printf("Unesite broj: ");
	scanf("%li", &n);
	n=fabs(n);
	m=n;
	while(m!=0) {
		m/=10;
		brcfr++;
	}
	if(n>=1 && n<=9) {printf("0");}
	else {
		k=brcfr;
		for(i=0; i<brcfr-1; i++) {
			j=0;
			k--;
			while(j<k) {
				stpn=10*stpn;
				j++;
			}
			a=(int)n%stpn;
			a=fabs(a);
			b=(int)n/stpn;
			b=fabs(b);
			c=(int)(a*10)/stpn;
			c=fabs(c);
			x=fabs(b-c);
			if(x!=0) {printf("%li", x); p=1;}
			else if(x==0 && p==1) {printf("%li", x);  }
			else if(x==0 && p!=1) {}
			stpn=1;
			n=a;
			a=0;
			b=0;
			c=0;
		}
		if(p!=1) printf("%li", x);
	}

	return 0;
}