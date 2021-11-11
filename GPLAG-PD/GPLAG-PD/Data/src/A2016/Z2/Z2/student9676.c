#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define BROJ_EL 500

int main() {
	
	int n, i, j, z;
	double a[BROJ_EL],s,m,sec;
	
	printf("Unesite broj uglova: ");
	scanf ("%d", &n);
	printf("Uglovi su: ");
	
	for (i=0; i<n; i++){
		scanf("%lf", &a[i]);
		a[i]=a[i]*180/PI;
		s=(int)a[i];
		m=(a[i]-s)*60;
		z=(int)m;
		sec=(m-z)*60;
		 	if (sec>0){
		 		sec=(int)(sec+0.5); 
		 	} else if (sec<0){
		 		sec=(int)(sec-0.5);
		 	}
	
			
			if ((int)sec==60){
				sec=0;
				m++;
			} else if((int)sec==-60){
				sec=0;
				m--;
			}
					if ((int)m==60){
						m=0;
						s++;
					} else if((int)m==-60){
						m=0;
						s--;
					}
			if (s<0){
				m=fabs(m);
				sec=fabs(sec);
			} else if ((int)s==0 && m<0){
				sec=fabs(sec);
			}
			
			if (fabs(sec)>30){
			
			for (j=i; j<n-1; j++){
				a[j]=a[j+1];
			}
			n--;
			i--;
		} else {
			printf("\n%g stepeni %d minuta %g sekundi", s, (int)m , round (sec));
		}
	}
	
	
	return 0;
}
