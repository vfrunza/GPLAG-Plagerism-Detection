#include <stdio.h>
#include <math.h>
void zaokruzi1(float niz[],int br){
	int niz1[1000],i;
	for(i=0;i<br;i++){
		if(niz[i]>0){
			niz[i]=(niz[i]+0.05)*10;
			niz1[i]=niz[i];
			niz[i]=niz1[i]/10.;
		}
		else{
			niz[i]=(niz[i]-0.05)*10;
			niz1[i]=niz[i];
			niz[i]=niz1[i]/10.;
		}
	}
	
}
void preslozi(float niz[],int br,int k){
	int cifra,i,j,suma,brojac=0;
	float temp;
	zaokruzi1(niz,br); 
	for(i=br-1;i>=brojac;i--){
		cifra=niz[i]*10;
		suma=0;
		while(cifra!=0){
			suma+=cifra%10;
			cifra/=10;
		}
		if(fabs(suma)>=k){
			temp=niz[i];
			for(j=i;j>0;j--){
				niz[j]=niz[j-1];
			}
			niz[0]=temp;
			i++;
			brojac++;
		}
	}
}
int main() {

	return 0;
}
