#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main() {
	double niz[500],a,b;
	int i,j,n,step,min,sec;
	for(;;){
		printf("Unesite broj uglova: ");
		scanf("%d",&n);
		if(n>0 && n<=500) break;
	}
	for(i=0;i<n;i++)
		scanf("%lf",&niz[i]);
		for(i=0;i<n;i++){
			a=(fabs)(niz[i]*180/PI);
			step=(int)a;
			a=a-step;
			a=a*60;
			min=(int)a;
			a=a-min;
			sec=(int)(a*60+0.5);
			if(sec==60){ sec=0;
			min++;
			}
			if(min==60){min=0;step++;} 
			if(niz[i]==0) {step=0;min=0;sec=0;}
			if(niz[i]<0){step=step*(-1);}
			if(sec>30){
				for(j=i;j<n-1;j++){
					niz[j]=niz[j+1];
				}
				n--;
				i--;
			}
		}
		printf("Uglovi su:\n");
		for(i=0;i<n;i++){
		
			b=(fabs)(niz[i]*180/PI);
			step=(int)b;
			b=b-step;
			b=b*60;
			min=(int)b;
			b=b-min;
			sec=(int)(b*60+0.5);
			if(sec==60){sec=0;min++;}
			if(min==60){min=0;step++;}
			if(niz[i]==0){step=0;min=0;sec=0;}
			if(niz[i]<0){step=step*(-1);}
			printf("%d stepeni %d minuta %d sekundi\n",step,min,sec);
		}
		
	return 0;
}
