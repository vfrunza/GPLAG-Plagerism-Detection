#include <stdio.h>

int izbaci_cifre(int *niz,int vel1,int *cifre,int vel2){
	int i,j,negativan,cs,suma,izbaci,cifra,k;
	for(i = 0; i < vel2; i++) 	if(cifre[i] < 0 || cifre[i]>9)return 0;

	for(i = 0; i < vel2; i++){
		for(j = i + 1;j < vel2; j++ )
			if(cifre[i] == cifre[j])return 0;
	}
	
	for(i = 0; i < vel1; i++){
	cs = niz[i];
	negativan=0;
	if(cs < 0) {cs=-cs;negativan =1;}
		suma = 0;
		k = 1;
		while (cs!=0) {
			izbaci = 0;
			cifra = cs %10;
			for(j = 0; j < vel2; j++)if(cifre[j] == cifra){izbaci = 1;break;}
			
			if(!izbaci){
					suma = suma + cifra*k;
					k*=10;
			}
			cs/=10;
		}
		if(negativan)niz[i] = -suma; 
		else niz[i] = suma;
	}
	return 1;
}

int main() {
	int i,niz[100] = {12345,-12345};
	int niz2[100]={3,5};
	izbaci_cifre(niz,2,niz2,2);
	for(i = 0; i < 2;i++)printf("%d ",niz[i]);
	return 0;
}
