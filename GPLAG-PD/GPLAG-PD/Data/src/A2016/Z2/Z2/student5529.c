#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	int i=0,n,stepen,minuta,sekunda,b[500],bake=0;
	double s,m,a[500],x,y;
	m=(double)180/PI;
	
	printf("Unesite broj uglova: ");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		scanf("%lf",&a[i]);
		if(a[i]<0&&1+a[i]<-0.03){
			a[i]=a[i]*(-1);
		}
		s=m*a[i];
		stepen=(int)s;
		b[stepen] = 0;
		b[i] = 0;
		
		} 
	
	for(i=0;i<n;i++){
		s=m*a[i];
		stepen=(int)s;
		minuta=(int)((s-stepen)*3600)/60;
		sekunda=(int)3600*(s-stepen)-minuta*60+0.5;

		if(a[i] < 1){
			if(sekunda >= 59){ 	minuta = minuta+1; sekunda = 0; }
			if(minuta >= 59){ 	stepen = stepen+1; minuta = 0; }
		}
		
		if(sekunda>30){
			a[i]=a[n-1];
			i--;
			n--;
	}
	
	}
	printf("Uglovi su: ");
	for(i=0;i<n;i++){
		if(a[i]<0&&a[i]>-1){
			y=1+a[i];
			if(y<0.03){
				
				s=m*a[i];
				stepen=(int)s-1;
				printf("\n%d stepeni 0 minuta 0 sekundi",stepen);
				return 0;
			}
		}
		if(a[i]<1){
			x=1-a[i];
			if(x<0.03){
				s=m*a[i];
				stepen=(int)s+1;
				printf("\n%d stepeni 0 minuta 0 sekundi",stepen);
				return 0;
				
			} else if(x>0.03){
			s=m*a[i];
		stepen=(int)s;
		minuta=(int)((s-stepen)*3600)/60;
		sekunda=(int)3600*(s-stepen)-minuta*60+0.5;
		printf("\n%d stepeni %d minuta %d sekundi",stepen,minuta,sekunda);
			}
		}
		
		else{
		s=m*a[i];
		stepen=(int)s;
		minuta=(int)((s-stepen)*3600)/60;
		sekunda=(int)3600*(s-stepen)-minuta*60+0.5;
		printf("\n%d stepeni %d minuta %d sekundi",stepen,minuta,sekunda);
}}
	
	

	 
	return 0;
}
