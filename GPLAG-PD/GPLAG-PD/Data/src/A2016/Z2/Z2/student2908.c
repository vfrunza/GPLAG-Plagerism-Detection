#include <stdio.h>
#define PI 3.1415926
#include <math.h>

int main () {
	int s,m;
	double multip,decimas,decimam;
	double x, sec;
	int velicina,i,j;
	float niz[500];
	printf("Unesite broj uglova:");
	scanf("\n%d",&velicina);
	for(i=0;i<velicina;i++){
			scanf("\n%f",&niz[i]);
	}
	 
	printf(" Uglovi su:");
	for(i=0;i<velicina;i++){	
		x=niz[i]*180/PI;
		s=(int)x;
		decimas=fabs(x-s);
		multip=decimas*60;
		m=(int)multip;
		decimam=fabs(multip-m);
		sec=decimam*60;
		if(sec+0.5>60) {
			sec=0;
			m++;
			if(m==60){
				m=0;
				if(s>0) s++;
				if(s<0) s--;
			}
		}
		if(sec<=30) printf("\n%d stepeni %d minuta %.f sekundi",s,m,sec);
		if(sec>30){
			for(j=i;j<velicina-1;j++){
				niz[j]=niz[j+1];
			}
			velicina--;
			i--;
		}
	}
	return 0;
}