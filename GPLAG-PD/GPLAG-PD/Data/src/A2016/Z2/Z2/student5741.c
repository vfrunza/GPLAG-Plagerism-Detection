#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	double a[500],stepeni,minute,sekunde,p;
	int n,i,j;
	printf("Unesite broj uglova: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%lf",&a[i]);
	}
	printf("Uglovi su:\n");
	for(i=0;i<n;i++){
		p=a[i];
		a[i]=fabs(a[i]);
		stepeni=(a[i])*180/PI;
		minute=(stepeni-(int)stepeni)*60;
		sekunde=(minute-(int)minute)*60;
		if(sekunde+0.5>=60){
			minute=minute+1;
			sekunde=0;
			if(minute+0.5>60){
				stepeni=stepeni+1;
				minute=0;
			}
		}
		stepeni=(int) stepeni;
		minute=(int) minute;
		if(sekunde>30.5){
			for(j=i;j<n-1;j++){
				a[j]=a[j+1];
			}
			i--;
			n--;
		}
		else{
			if(p>=0){
				printf("%.0f stepeni %.0f minuta %.0f sekundi\n",stepeni,minute,sekunde);
			}
			else if(p<0){
				printf("%.0f stepeni %.0f minuta %.0f sekundi\n",-stepeni,minute,sekunde);
			}
		}
	}
	return 0;
}
