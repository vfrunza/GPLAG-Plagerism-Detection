#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int broj_cifara(int x){
	int br=0;
	x=abs(x);
	while(x!=0){
		br++;
		x/=10;
	}
	return br;
}

int izbaci_cifre(int *a, int vela, int* b, int velb){
	int i,j;
	for(i=0; i<velb; i++){
		if(b[i]>9 || b[i]<0){
			return 0;
		}
	}
	if (velb==0) return;
	for(i=0; i<velb; i++){
		for(j=i+1; j<velb; j++){
			if(b[i]==b[j]){
				return 0;
			}
		}
	}
	int nizCifara[10000];
	int pomocniBroj[1000];
	int brojacCifara=0;
	int cifra, broj, suma=0, postoji=0;
	for(i=0; i<vela; i++){
		nizCifara[i]=broj_cifara(a[i]);
	}
	for (i=0; i<vela; i++){
		broj=a[i];
		brojacCifara=0;
		if(broj<0){
			broj=abs(broj);
			while(broj!=0){
				cifra=broj%10;
				postoji=0;
				for(j=0; j<velb; j++){
					if (cifra==b[j]){
						postoji=1;
						break;
					}
				}
				if (postoji==0){
					pomocniBroj[brojacCifara]=cifra;
					
					brojacCifara++;
				}
				else{
					nizCifara[i]--;
				}
				broj/=10;
			}
			if (nizCifara[i]==0){
				a[i]=0;
			}
			else{
				a[i]=0;
				for(j=0; j<brojacCifara; j++){
					a[i]+=pomocniBroj[j]*pow(10, j);
				}
				a[i]*=-1;
			}
		}
		else{
			while(broj!=0){
				cifra=broj%10;
				postoji=0;
				for(j=0; j<velb; j++){
					if(cifra==b[j]){
						postoji=1;
						break;
					}
				}
				if (postoji==0){
					pomocniBroj[brojacCifara]=cifra;
					brojacCifara++;
					nizCifara[i]--;
				}
				broj/=10;
			}
			if(nizCifara[i]==0){
				a[i]=0;
			}
			else {
				a[i]=0;
				for(j=0; j<brojacCifara; j++){
					a[i]+=pomocniBroj[j]*pow(10, j);
				}
			}
		}
	}
	return 1;
}


int main() {int brojevi[] = {-4481};
	int cifre[] = {2, 3, 5, 7, 9};
	int i;
	izbaci_cifre(brojevi, 1, cifre, 5);
	
	return 0;
}
