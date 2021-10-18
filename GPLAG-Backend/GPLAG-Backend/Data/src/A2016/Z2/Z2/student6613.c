#include <stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI 3.1415926

int main() {
	double niz[500],m1,m2,ss1,ss2,ss3,x;
	int m,s,ss,n,i,j,z=0;
	
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	
	printf("Uglovi su:\n");
	for(i=0;i<n;i++){
		scanf("%lf", &niz[i]);
		
		x=(niz[i]*180)/PI;
		if(x<0){ z=1;
		x=fabs(x);}
		else z=0;
		s=(int)x;
	
		m1=x-s;
		m2=m1*60;
		m=(int)m2;
		if(m==60){s=s+1;
		m=0;}
		
		ss1=m2-m;
		ss2=ss1*60;
		ss3=ss2+0.5;
		ss=(int)ss3;
		if(ss==60){ss=0;
		m=m+1;}
		if(m==60){m=0; s=s+1;}
	
		if(ss>30){
			for(j=i;j<n-1;j++){
				niz[j]=niz[j+1];
			}
			n--;
			i--;
			continue;
		}
		
			if(z==1) {printf("-%d stepeni %d minuta %d sekundi\n",s,m,ss);
			z=0;}
            else {printf("%d stepeni %d minuta %d sekundi\n",s,m,ss);
            z=0;}
		
	}
	
	return 0;
}
