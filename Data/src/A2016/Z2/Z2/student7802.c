#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main() {
	int ugao60,n,umm1,us1,i=0,uss1,j,k[500];
	double m[500],us,um,uss,umm;
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%lf", &m[i]);
	}
	printf("Uglovi su:\n");
	for(i=0;i<n;i++){
			us=m[i]*180/PI;
			us1=us;
			um=(us/0.01)-(us1*100);
			if(um<0){um=fabs(um);}
			umm1=um*60/100;
			ugao60=umm1+ 0.5;
			umm=um*60/100;
			uss=(umm/0.01)-(umm1*100);
			uss1=((uss*60)/100 + 0.5);
			if(uss1==60){uss1=0; umm1=umm1+1;}
			if((ugao60==60 || umm1==60)&& us<0){umm1=0; us1=us1-1;}
			else if	(ugao60==60 || umm1==60){umm1=0; us1=us1+1;}
		if(uss1<=30){printf("%d stepeni %d minuta %d sekundi\n", us1, umm1, uss1);
		}else continue;
			if(uss1>30){
				for(j=i;j<n-1;j++){
					k[j]=k[j+1];
				}
				n--;
				i--;
			}
	}
	return 0;
}
