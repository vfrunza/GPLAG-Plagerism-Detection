#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 100


void zaokruzi1(float niz[], int vel) {
    int i;
    for (i=0; i<vel; i++) {
        niz[i]=(round(10*niz[i]))/10;
    }
}


void preslozi(float niz[], int vel, int k) {
    zaokruzi1(niz, vel);
    
    int i, j, preuredjen, sumacifara, brojac=0;
    float apsolutna, temp;
    
    for (i=0; i<vel; i++) {
        apsolutna=fabs(niz[i]*10);  /*Uzimanje apsolutne vrijednosti broja jer je lakse raditi sa pozitivnim brojevima, mnozenje sa 10 jer ima jednu decimalu*/
        preuredjen=(int)apsolutna;  /*"Pretvaranje" realnog broja u cijeli zbog cjelobrojnog dijeljenja i ostatka kod trazenja sume cifara*/
        sumacifara=0;
        
        while (preuredjen!=0) {
            sumacifara+=preuredjen%10;
            preuredjen/=10;
        }
        
        if (sumacifara>=k) {
            temp=niz[i];
            for (j=i-1; j>=brojac; j--) {
                niz[j+1]=niz[j];  /*Pomjeranje svih ostalih clanova za jedan udesno da bi se ocuvao redoslijed*/
            }
            niz[brojac++]=temp;  /*Stavljanje clana sa sumom cifara vecom ili jednakom k tamo gdje on treba biti*/
        }
        /*Nakon ovoga oni preostali clanovi (oni sa sumom cifara manjom od k) ce vec biti poredani ondje gdje trebaju biti*/
    }
}


int main() {
    int i;
	float niz[]={-1.23, 3.45, 5.0, 7.999, 8.627};
	
	zaokruzi1(niz, 5);
	for (i=0; i<5; i++) {
	    printf("%g ", niz[i]);
	}
	
	printf("\n");
	
	preslozi(niz, 5, 8);
	for (i=0; i<5; i++) {
	    printf("%g ", niz[i]);
	}
	
	return 0;
}
