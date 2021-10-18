#include <stdio.h>
#include <math.h>
void zaokruzi1(float niz[], int n){
	int i;
	float temp;
	for(i=0; i<n; i++){
	if(niz[i]>0) temp=(int)(niz[i]*10+0.5)/10.0;
	if(niz[i]<0) temp=(int)(niz[i]*10-0.5)/10.0;
	niz[i]=temp;
	}
}

void preslozi(float niz[], int n, int k){
	int i, broj, suma=0,j, brojac=0;
	float temp;
	
	zaokruzi1(niz,n);
    for(i=0; i<n; i++){
    	broj=fabs(niz[i])*10;
    do{
    	suma+=broj%10;
    	broj/=10;
    } while (broj!=0);
    
    if(suma<k){
        temp=niz[i];
        for(j=i; j<n-1; j++){
    	niz[j]=niz[j+1];
        }
        niz[n-1]=temp;
        i--;
    }
    brojac++;
    if(brojac==n) break;
    suma=0;
    }
}
int main() {
    int i;
float niz[] = { 3.2, -4.301, -123.1999, 1.1, 0.9 };
preslozi(niz, 5, 8);
printf("Niz glasi: ");
for (i=0; i<5; i++)
    printf("%g ", niz[i]);
	return 0;
}
