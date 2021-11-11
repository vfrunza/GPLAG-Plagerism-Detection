#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	double ugao[500];
	int n,i,j,k,t=2;
	int d,m,s,pamti=0;

	double a;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lf",&ugao[i]);
	}	
	
	for(i=0;i<n;i++){
		k=0;
		pamti=0;
		if(ugao[i]<0){ugao[i]=ugao[i]*(-1);pamti=1;}
		a=fabs(a);
		a=(ugao[i]*180/PI)*3600;
		a=(int)(a+0.5);
		d=a/3600;
		m=(a-d*3600)/60;
		s=a-d*3600-m*60;
		
		if(s>=60){m++;s-=60;}
		
		if(m>=60){d++;m-=60;}
		
		if(s>30){
			k=1;
			for(j=i;j<n-1;j++){
				ugao[j]=ugao[j+1];
			}
			n--;
			i--;
		}
		if(k==0){	
if(i==0){	printf("Uglovi su:\n");}

		a=(ugao[i]*180/PI)*3600;
		a=(int)(a+0.5);
		d=a/3600;
		if(pamti==1){printf("%d stepeni ",-d);}
		else if(pamti==0){printf("%d stepeni ",d);}
		m=(a-d*3600)/60;
		printf("%d minuta ",m);
		s=a-d*3600-m*60;
		printf("%d sekundi",s);
		printf("\n");
		pamti=0;
	}
	else if (k==1){continue;}
}

	
	
	return 0;
}