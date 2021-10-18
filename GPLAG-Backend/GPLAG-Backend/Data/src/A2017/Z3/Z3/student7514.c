#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int izbaci_cifre(int*brojevi, int bb , int*cifre, int bc){
	int i,j,k=0,m,t,pomocnicifre[10]={0,1,2,3,4,5,6,7,8,9}, brojacicifara[10]={0}, cifrebroja[100]={0},l=0,konacni[100]={0},stepen=0;
	for(i=0; i<bc; i++){
		if (cifre[i]>9 || cifre[i]<0) return 0;
		for(j=0; j<10; j++){
			if(pomocnicifre[j]==cifre[i]) brojacicifara[cifre[i]]++;
	}
	}
	for(i=0; i<10; i++)
		if (brojacicifara[i]>1) return 0;
		
	for(i=0; i<bb; i++){
		while(brojevi[i]){
			m=brojevi[i]%10;
			cifrebroja[l]=m;
			l++;
			brojevi[i]=brojevi[i]/10;
		}
    	for(j=0; j<l; j++){
				for(t=0; t<10; t++){
					if(brojacicifara[t]==0){
					if((abs(cifrebroja[j]))==t) {
						konacni[k]=konacni[k]+cifrebroja[j]*pow(10,stepen);
						stepen++;
					}
				}
    		}
    	}
    k++;	
	l=0;
	stepen=0;
	}
	for(i=0; i<k; i++)
		brojevi[i]=konacni[i];
	return 1;
}
	
int main() {
	int brojevi[100], cifre[20],i, bb=0, bc=0;
	printf("Unesite niz brojeva: ");
	for(i=0; i<100; i++){
		scanf("%d", &brojevi[i]);
		if(brojevi[i]==-1) break;
		bb++;
	}
	printf("Unesite niz cifara: ");
	for(i=0; i<20; i++){
		scanf("%d", &cifre[i]);
		if (cifre[i]==-1) break;
		bc++;
	}
	izbaci_cifre(brojevi,bb,cifre,bc);
	for (i=0; i<bb; i++)
	printf("%d ", brojevi[i]);
	return 0;
}
