#include <stdio.h>
#include <math.h>
int izbaci_cifre(int niz_brojevi[], int vel_br, int niz_cifre[], int vel_cf){
	int i, j, histogram[10], brojac=0, br=0, cifra, broj,temp;
	for(i=0; i<vel_cf; i++){
		if(niz_cifre[i]<0 || niz_cifre[i]>9) brojac++;
	}
	if(brojac!=0) return 0;
	
	for(i=0; i<10; i++)
	    histogram[i]=0;
	    
	for(i=0; i<vel_cf; i++)
	   histogram[niz_cifre[i]]++;
	   
	for(i=0; i<10; i++) {
		if(histogram[i]>1) brojac++;
	}
	
	if(brojac!=0) return 0;
	brojac=0;
for(i=0; i<vel_br; i++){
	broj=niz_brojevi[i];
	temp=broj;
	niz_brojevi[i]=0;
	br=0;
	do{
		cifra=fabs(broj%10);
		for(j=0; j<vel_cf; j++){
			if(niz_cifre[j]==cifra) brojac++;
		}
			if(brojac==0){
				niz_brojevi[i]+=(cifra*pow(10,br));
				br++;
			} 
		brojac=0;
		broj/=10;
		} while(broj!=0);
		if(temp<0) niz_brojevi[i]*=-1;
}
return 1;
}
int main() {
	printf("Zadaća 3, Zadatak 3");
	return 0;
}
