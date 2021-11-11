#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main() {
	int i,us,a,l,sek,j;
	double n1[500],st,k,ost,min;
	printf("Unesite broj uglova: ");scanf("%d", &a);
	if(a>=500)return 0;
	for(i=0;i<a;i++){  scanf("%lf", &n1[i]);	}
	printf("Uglovi su: \n");
	for(i=0;i<a;i++){
	st=(n1[i]*180)/PI;
	us=(int)st;
	ost=fabs((st-(int)st)*60);
	min=ost*60;//broj minuta
	l=(int)ost;
	k=fabs((ost-(int)ost)*60);
	sek=(int)(k+0.5);
	if(sek==60){
		sek=0; l++;//povecam minute za 1
		if(l==60){ l=0;  if(us<0) {us--; } else{ us++;}}
	}
	if(fabs(sek)>30 && fabs(sek)!=0){for(j=i;j<a-1;j++){
			n1[j]=n1[j+1];
		}a--;i--;
	}//izbacivanje clana iz niza

	
else{printf("%d stepeni %d minuta %d sekundi\n",us,l,sek);	}
	
}return 0;}
