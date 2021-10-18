#include <stdio.h>
#define PI 3.1415926
#include <math.h>
#define EP 0.001

int main() {
	int n, i, j;
	double niz[500];
	double s, m, se, se1, s1, m1;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0; i<n; i++) { 
		scanf("%lf", &niz[i]);
	}
	printf("Uglovi su:\n");
	for(i=0; i<n; i++) {
		s=niz[i]*180/PI;
		s1=(int)(s);
	
		m=fabs(s-s1)*60;
		m1=(int)fabs(m);
		
		se=(m-m1)*60;
		se1=(int)(fabs(se)+0.5);
		
		if (fabs(se1)-60<EP && (int)fabs(se1)-60>=0) {
			se1=0;
			m1=(m1)+1;
			
			if(fabs(m1)-60<EP && fabs(m1)-60>=0) {
				m1=0;
				if (s1<0)  s1=s1-1; else s1=s1+1;
			}
		}
		if (fabs(se1)-0>EP  && fabs(m1)-60<EP && fabs(m1)-60>=0) {
			m1=0;
			s1=s1+1;
		}
		if (fabs(se1)<=30) printf("%.f stepeni %.f minuta %.f sekundi\n", s1, m1, se1);
		if(fabs(se1)>30) {
			for(j=i; j<=n-1; j++)
			niz[j]=niz[j+1];
		n--;
		i--;
		}
	}
	
	return 0;
}
