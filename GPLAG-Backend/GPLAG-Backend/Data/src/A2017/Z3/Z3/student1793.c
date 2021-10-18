#include <stdio.h>
#include <math.h>

int izbaci_cifre(int brojevi[],int vel1,int cifre[],int vel2){
	int i,j,k=1,broj,cifra,pomocna,temp,niz[100];
	for(i=0;i<vel2;i++){
		if(cifre[i]<0 || cifre[i]>9) return 0;
		niz[i]=cifre[i];
		for(j=0;j<i;j++){
			if(niz[j]==cifre[i]) return 0;
		}
	}
	
	for(i=0;i<vel1;i++){
		for(j=0;j<vel2;j++){
			broj=fabs(brojevi[i]);
			while(broj>0){
				cifra=broj%10;
				broj/=10;
				k*=10;
				if(cifra==cifre[j]){
					pomocna=fabs(brojevi[i]);
					temp=fabs(brojevi[i]);
					temp=(temp/k);
					temp*=k/10;
					temp+=(pomocna%k)%(k/10);
					k/=10;
					if(brojevi[i]<0){
					brojevi[i]=-temp;
				}
				else brojevi[i]=temp;
			}
			}
			k=1;
		}
	}
	return 1;
}

int main() {
	int brojevi[] = {225};
int cifre[] = {2, 3, 5};
int i;
izbaci_cifre(brojevi, 5, cifre, 3);
for (i=0; i<5; i++)
  printf("%d ", brojevi[i]);
	return 0;
}
