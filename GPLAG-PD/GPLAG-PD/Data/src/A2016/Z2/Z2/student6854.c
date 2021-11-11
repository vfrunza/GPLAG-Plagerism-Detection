#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main() {
	long int n,i,stepeni,minute,x,j;
	double sekunde,sekundi,niz[500],cijeli,a;
	printf("Unesite broj uglova: ");
	do{
		scanf("%li",&n);
	}while(n>500 && n<0);
	for(i=0;i<n;i++){
		scanf("%lf",&niz[i]);
	}
	printf("Uglovi su: ");
	for(i=0;i<n;i++){
		a=niz[i];
		if(a<0) a=fabs(a);
		sekundi=(a*180/PI); 
		stepeni=(int)sekundi;
		cijeli=(sekundi -stepeni)*60; 
		minute=((int)cijeli)%60;
		sekunde=(cijeli-(int)cijeli)*60; 
		x=(int)(sekunde + 0.5); 
		if(x>30 && x!=60){
			for(j=i; j<(n-1); j++){
				niz[j]=niz[j+1];
			}
			n--;
			i--;
		}
	}
	for(i=0; i<n; i++){
		a=niz[i];
		if(a<0) a=fabs(a);
		sekundi=(a*180)/PI;
		stepeni=(int)sekundi;
		cijeli=(sekundi- stepeni)*60;
		minute=((int)cijeli)%60;
		sekunde=(cijeli- (int)cijeli)*60;
		x=(int)(sekunde + 0.5);
		if(x>=60){
			x=0;
			minute+=1;
		}
		if(minute>=60){
			minute=0;
			stepeni+=1;
		}
		 if(niz[i]>=0) printf("\n%li stepeni %li minuta %li sekundi",stepeni, minute, x);
		 else if(niz[i]<0) printf("\n-%li stepeni %li minuta %li sekundi",stepeni, minute, x);
	}
	return 0;
}
