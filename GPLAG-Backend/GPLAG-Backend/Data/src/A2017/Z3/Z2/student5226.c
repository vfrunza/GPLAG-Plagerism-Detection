#include <stdio.h>
#include<math.h>

void zaokruzi1 (float *niz, int vel) {
	    int i;
	    float *pok=niz;
	    while(pok<niz+vel) {
	    for(i=0;i<vel;i++)  {
		*pok=round(*pok*10);
		*pok=*pok/10;
		pok++;
	 	}
	 }
}

void preslozi(float niz[],int vel,int k) {
     zaokruzi1(niz,vel);
     int i,j;
     int b1=0,b2=0;
     int suma=0,a;
     float niz1[100],niz2[100];
     float* pok=niz;
        for(i=0;i<vel;i++) { 
        a=(fabs)(*(niz+i)*10);
           while(a>0) {
        	suma+=a%10;
        	a=a/10;
        } 
        if (suma<k) {
            niz1[b1]=*(niz+i);
            b1++;
        }
        else if(suma >=k) {
            niz2[b2]=*(niz+i);
            b2++;
        }
    }
     for(i=0;i<vel;i++) {
         if (i<b2) {
         *(niz+i)=*(niz2+i);
         }
         else {
         *(niz+i)=*(niz1+i-b2);
     }
   }
}
int main () {
    return 0;
}
