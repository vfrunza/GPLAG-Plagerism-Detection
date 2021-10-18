#include <stdio.h>
#include <stdlib.h>
#define PI 3.1415926
#define n 500

int main() {
	double A[n], a, b, c;
	int i, j, s, m, se, x, y;
	printf("Unesite broj uglova: ");
	scanf("%d", &x);
	for(i=0; i<x; i++){
		scanf("%lf", &A[i]);
		
	}
	y=x;
	printf("Uglovi su: \n");
	for(i=0; i<x; i++){
		b=A[i]*(180/PI);
		s=(int)b;
		a=(b-s)*60;
		m=(int)a;
		c=(a-m)*60;
		if(c<0) se=(abs)(c-0.5);
		else if(c>0) se=(int)(c+0.5);
		else se=0;
		if(se==60){
			se=0;
			m=(abs)(m);
			m++;
	
		if(m==60){
			m=0;
		
		if(s<0)
			s--;
		
		else if(s>0)
			s++;
		}
			
		}
		m=(abs)(m);
		if(se<=30 && se>=-30){
			printf("%d stepeni %d minuta %d sekundi\n", s, m, se);
		}
		if(se>30 || se<-30){
			for(j=i; j<y-1; i++){
				A[j]=A[j+1];
				i--;
				y--;
			}
		}
		
	}
			
	
	
	return 0;
}
