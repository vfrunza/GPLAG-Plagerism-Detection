#include <stdio.h>
#include <math.h>
#define PI 3.1415926
#define broj 500
int main() {
int i,n,j;
double rad[broj];
double totsec;
int deg[broj],min[broj],sec[broj];
do{
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
}while(n<1 || n>500);
 for(i=0;i<n;i++){
 	scanf("%lf", &rad[i]);
  
totsec=(rad[i]*180/PI)*3600;
if(totsec<0)
totsec=(int)(totsec-0.5);
else if (totsec>0)
totsec=(int)(totsec+0.5);
deg[i]=totsec/3600;
min[i]=((fabs(totsec)-fabs(deg[i])*3600)/60);
sec[i]=(fabs(totsec)-fabs(deg[i])*3600-min[i]*60);

 if (sec[i]>=60){
	min[i]++;
	sec[i]-=60;
}
if(min[i]>=60){
	deg[i]++;
	min[i]-=60;
}


	if(sec[i]>30){
		for(j=i;j<n-1;j++){
			sec[j]=sec[j+1];
		}
		n--;
		i--;
	}
}
printf("Uglovi su: ");
for(i=0;i<n;i++) {
	printf("\n%d stepeni %d minuta %d sekundi",deg[i],min[i],sec[i]);
}
return 0;
}
