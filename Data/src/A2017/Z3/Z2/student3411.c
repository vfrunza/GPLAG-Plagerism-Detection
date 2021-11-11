#include <stdio.h>

void zaokruzi1(float *niz,int vel){
	int i;
	for(i=0;i<vel;i++){
		niz[i]=niz[i]*100;
		niz[i]=(int)(niz[i]+0.5);
		niz[i]=niz[i]/100;
	}
}



int main() {
	int i;
	double a=12.458;
	float niz[3]={12.36,15.369,45.4785};
	zaokruzi1(niz,3);
	for(i=0;i<3;i++){
		printf("%g ",niz[i]);
	}
	
	return 0;
}
