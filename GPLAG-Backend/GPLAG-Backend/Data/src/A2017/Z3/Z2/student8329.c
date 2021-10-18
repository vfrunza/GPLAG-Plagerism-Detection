#include <stdio.h>
#include<math.h>
void zaokruzi1(float* niz, int vel){
	int i;
	for(i=0;i<vel;i++){
		niz[i]=round(niz[i]*10)/10;
		
	}
}
void preslozi(float* niz,int vel,int k){
	
	int i;
	double suma=0;
	int temp[100];
	float temp2[100],temp3[100];
	int br=0;
	int j=0,l=0;
	zaokruzi1(niz,vel);
	
	for(i=0;i<vel;i++){
		temp[i]=fabs(niz[i]*10);
	}
	for(i=0;i<vel;i++){
		suma=0;
		while(temp[i]>0){
			suma+=temp[i]%10;
			temp[i]/=10;
		}
		if(suma>=k){
			temp2[j]=niz[i];
			br++;
			j++;
		}
		if (suma<k) {
			temp3[l]=niz[i];
			l++;
		}
	}
	l=0;
	j=0;
	for(i=0;i<br;i++){
	niz[i]=temp2[j];
	j++;
	}
	for(i=br;i<vel;i++){
	niz[i]=temp3[l];
	l++;
	}
}
int main() {
	float a[100];
	int n,i,k;
	scanf("%d",&n);
	scanf("%d",&k);
	for(i=0;i<n;i++){
		scanf("%f",&a[i]);
	}
	preslozi(a,n,k);
	for(i=0;i<n;i++){
		printf("%.1f ",a[i]);
	}
	return 0;
}
