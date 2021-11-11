#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926

int main() {
 int n,i,j;
 double st[500],m[500],s[500];
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	
		for (i=0; i<n; i++){
			scanf("%lf",&st[i]);
			st[i]=st[i]*180/PI;
			m[i]=(fabs(st[i])-abs((int)st[i]))*60;
			s[i]=(m[i]-(int)m[i])*60;
			s[i]=(int)(s[i]+0.5);
			if(s[i]>=60){
				m[i]++;
				s[i]=0;
			}
			if(m[i]>=60){
				if(st[i]>=0){
					st[i]++;
				}else{
				st[i]--;
				}
				m[i]=0;
			}
			if(s[i]>30){
				for(j=i; j<n-1; j++){
					st[j]=st[j+1];
				}
				n--;
				i--;
			}
		}
		printf("Uglovi su: \n");
		for (i=0; i<n; i++){
			printf("%d stepeni %d minuta %d sekundi\n",(int)st[i],(int)m[i],(int)s[i]);
		}
	return 0;
}