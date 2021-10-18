#include <stdio.h>
#include <math.h>

int izbaci_cifre(int niz[], int veln, int cifre[], int velc){
	int i, j, a, z, broj, trazenibroj=0;
	for (i=0;i<velc;i++){
		if (cifre[i]<0 || cifre[i]>9)
		return 0;
	}
	int his[10]={0};
	for(i=0; i<velc; i++){
		his[cifre[i]]++;
	}
	for(i=0;i<10; i++){
		if(his[i]>1) 
		return 0;
	}
	
	int brojac1=0;
	int brojac2=0;
	for(i=0;i<veln;i++){
		z=niz[i];
		niz[i]=fabs(niz[i]);
		broj=0;
		while(niz[i]!=0){
			for(j=0;j<velc;j++){
				if(niz[i]%10==cifre[j]){
					a=1;
					brojac1++;
					break;
				} else a=0;
			}
			if(a==0){
				trazenibroj+=(niz[i]%10)*10;
				
			}
			niz[i]=niz[i]/10;
			brojac2++;
		}
		if (brojac2==brojac1)
		niz[i]=0;
		else {
			broj=broj/10;
			niz[i]=broj;
			broj=0;
			while(niz[i]%10!=0) {
				broj+=(niz[i]%10)*10;
				niz[i]/10;
			}
			broj=broj/10;
			if(z>0){
				niz[i]=broj;
			} else niz[i]=-broj;
		}
	}
	
	return 1;
}
int main() {
	return 0;
}
