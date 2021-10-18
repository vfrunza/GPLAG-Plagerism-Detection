#include <stdio.h>
#include <math.h>

int sumacifara(float a){
	int suma=0, pom;
	pom=(int)((fabs(a)+0.05)*10);
	while(pom>0){
		suma+=pom%10;
		pom/=10;
	}
	return suma;
}
float* zaokruzi1(float niz[],  int d){
	int i;
 	for (i=0;i<d;i++){
 		if(niz[i]>=0){
 			niz[i]=((int)((niz[i]+0.05 )*10))/10.;
 		} else{
 			niz[i]=((int)((niz[i]-0.05 )*10))/10.;
 		}
 	}
 	return niz;
 }
 
 float *preslozi(float niz[], int d, int k){
 	float temp;
 	int i,j,l;
 	niz=zaokruzi1(niz,d);
 	for(i=0;i<d;i++){
 		if(sumacifara(niz[i])<k){
 			for(j=i+1;j<d;j++){
 				if(sumacifara(niz[j])>=k){
 					temp=niz[j];
 					for(l=j;l>i;l--){
 						niz[l]=niz[l-1];
 					}
 					niz[i]=temp;
 					break;
 				}
 				
 				
 			}
 		}
 	}
 	return niz;
 }

int main() {
	float niz[] = { 3.2, -4.301, -123.1999, 1.1, 0.9 };
	int i;
    preslozi(niz, 5, 8);
	
	
	for(i=0; i<5;i++){
		printf("%f  ", niz[i]);
	}

	return 0;
}
