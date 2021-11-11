#include <stdio.h>
#include <math.h>
#define max 500
#define PI 3.1415926
#define g 0.5

int main() {
	int i, j, n=0, k=0;
	double niz[max], stepen, minuta, sekunda;
	int stepen1, minuta1, sekunda1;
	int niz_stepen[max], niz_minuta[max], niz_sekunda[max];
	printf("Unesite broj uglova: ");
	scanf("%d", &n);
	if(n<0 || n>500) return 0;
	for(i=0;i<n;i++){
		scanf("%lf", &niz[i]);
		stepen=niz[i]*180/PI;
		stepen1=stepen;
		niz_stepen[i]=stepen1;
		minuta=fabs((float)(stepen-stepen1)*60);
		minuta1=fabs(minuta);
		niz_minuta[i]=minuta1;
	
		sekunda=fabs(((float)(minuta-minuta1)*60))+g;
		sekunda1=fabs(sekunda);
		
		
		niz_sekunda[i]=sekunda1;
		if((sekunda-sekunda1-g)>g){niz_sekunda[i]++;}
		if(niz_sekunda[i]==60){niz_minuta[i]++; niz_sekunda[i]=0;}
		if(niz_minuta[i]==60){
			niz_minuta[i]=0;
			if(niz_stepen[i]<0)niz_stepen[i]--;
			if(niz_stepen[i]>0)niz_stepen[i]++;
		}
		
		k++;	
		}
		
	for(i=0;i<k;i++){
		if(fabs(niz_sekunda[i])>30){
			for(j=i;j<k-1;j++){
				niz_stepen[j]=niz_stepen[j+1]; niz_minuta[j]=niz_minuta[j+1]; niz_sekunda[j]=niz_sekunda[j+1];
			}
			k--;
			i--;
		}
	}
	printf("Uglovi su: ");
	for(i=0;i<k;i++){
	printf("\n%d stepeni %d minuta %d sekundi", niz_stepen[i], niz_minuta[i], niz_sekunda[i]);
	
	}
	return 0;
}
