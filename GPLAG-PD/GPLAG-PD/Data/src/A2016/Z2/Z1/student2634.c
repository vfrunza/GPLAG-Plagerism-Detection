#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	printf("Unesite broj: ");
	int i,n,m,p,rez,br;
	br=0;
	i=0;
	rez=0;
	scanf("%d",&n);
	if(n<0) {
		p=abs(n);
	}
	else p=n;
	m=p;
	if(p/10==0) {
		m=0;
		printf("%d",m);
	}
	else {
		int a,b;
		while(1) {
			if(p!=0) {
				br++;
				p/=10;
			}
			else break;
		}
		for(i;i<br-1;i++) {
			a=m%10;
			b=(m%100)/10;
			rez=rez+(abs(a-b)*pow(10,i));
			m=m/10;
			if(m<10) break;
		}
		printf("%d",rez);
	}
	return 0;
}