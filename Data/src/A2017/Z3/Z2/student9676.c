#include <stdio.h>
#include <math.h>

int zaokruzi1(float niz_brojeva[1000]) {
    int i;
    
    for(i=0; i<1000; i++) {
        niz_brojeva[i]*=100;
        niz_brojeva[i]+=5;
        niz_brojeva[i]/=10;
        niz_brojeva[i]/=10.;
        printf(%f,niz_brojeva[i]);
    }
    
    
}

int main() {
	
	return 0;
}
