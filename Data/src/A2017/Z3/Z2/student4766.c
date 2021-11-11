#include <stdio.h>
#include <stdlib.h>

void zaokruzi1(float niz[], int v) {
	/*zaokruzivanje broja na jedno decimalno mjesto*/
	int i;
	for(i=0;i<v;i++) {
		niz[i]*=10;
		if(niz[i]<0) {
			niz[i]=(int)(niz[i]-0.5);
		}
		else {
			niz[i]=(int)(niz[i]+0.5);
		}
		niz[i]/=10;
	}
}

void preslozi(float niz[], int v, int k) {
	int i,j,suma,n,limit=0;
	float pomoc;
	zaokruzi1(niz,v);
	for(i=v-1;i>limit-1;i--) {
		suma=0;
		n=abs((int)(niz[i]*10));
		/*sabiramo cifre broja, ukljucujuci decimalu*/
		do {
			suma+=n%10;
			n/=10;
		}while(n!=0);
		/*pomjeramo broj na prvo mjesto u nizu, a ostale elemente jedno mjesto udesno, ako je broj veci ili jednak k*/
		if(suma>=k) {
			pomoc=niz[i];
			for(j=i;j>0;j--) {
				niz[j]=niz[j-1];
			}
			niz[0]=pomoc;
			/*pomjeramo granicu kako ne bi ponovo radili sa elementima koje smo pomjerili na prva mjesta*/
			limit++;
			i++;
		}
	}
}

int main() {
	int i,k=14,v=5;
	float niz[50]={13.1, 15.749999, 15.75, 9.222, 78.1};
	preslozi(niz,v,k);
	printf("Niz glasi: ");
	for(i=0;i<v;i++) {
		printf("%g ",niz[i]);
	}
	return 0;
}
