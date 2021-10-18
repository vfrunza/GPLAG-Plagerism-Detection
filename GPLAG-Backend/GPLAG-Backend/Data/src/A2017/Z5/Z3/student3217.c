#include <stdio.h>

int main() {
	float niz[13]={0.4,0.8,1,1.4,1.8,2,4,6,8,10,12,14,16};
	float struja[13]={0};
	int i=0;
	float If, napon_diode;
	
	
	for(i=0; i<13; i++){
		If=niz[i]/1200;
		struja[i]=If*1200;
		printf("%g\n", struja[i]);
		
		
	}
	return 0;
}
