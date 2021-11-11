#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void zaokruzi1(float *niz,int vel){
	int i=0;
	for(i=0;i<vel;++i){
		niz[i]=round(niz[i]*10)/10.;
	}
}

void preslozi(float *niz1,int vel1, int k){
	int i=0,x1=0,x2=0,s1=0,s2=0;
	float temp=0;
	zaokruzi1(niz1,vel1);

	for(i=0;i<vel1-1;i++){
		
		x1=round(niz1[i]*10);
		x2=round(niz1[i+1]*10);
		do{
			s1+=abs(x1%10);
			x1/=10;
		}while(abs(x1)>0);
		do{
			s2+=abs(x2%10);
			x2/=10;
		}while(abs(x2)>0);
		
		if(s1<k && s2>=k){
			temp=niz1[i];
			niz1[i]=niz1[i+1];
			niz1[i+1]=temp;
			i=-1;
		}
		s1=0;
		s2=0;
	}
	
	
}

int main() {
	
	float a[5];
	int i=0;
	for(i=0;i<5;i++){
		scanf("%f",&a[i]);
	}
	
	
	preslozi(a,5,14);
	printf("Niz glasi: ");
	for(i=0;i<5;i++){
		printf("%g ",a[i]);
		
	}
	
	return 0;
}
