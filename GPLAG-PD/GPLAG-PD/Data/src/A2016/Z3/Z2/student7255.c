#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define duz 10

void ubaci (int *niz, int vel){
	int S,H=0,c,i,j;
	for(j=vel-1; j>=0; j--){
		niz[2*j]=niz[j];
	}
	for(i=0; i<2*vel; i+=2){
		S=abs(niz[i]);
		if(S<10){
			H=S;
		}
		else {
			do{
				c=S%10;
				H=H+c;
				S/=10;
			}while(S!=0);
		}
		niz[i+1]=H;
		H=0;
	}
}

int izbaci (int *niz, int vel){
	int i,j,k,I=0,II=1,III;
	for(i=0; i<vel; i++){
		I=0;
		II=1;
		for(j=1; j<10000; j++){
			if(j==1){
				III=j;
			}
			else{
				III=I+II;
				I=II;
				II=III;
			}
			if(*(niz+i)==III){
				for(k=i; k<vel-1; k++){
					*(niz+k)=*(niz+k+1);
				}
				vel--;
				i--;
				break;
			}
		}
			
		}
	return vel;
}

int main() {
	int niz[2*duz], i, poziv;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<duz; i++){
		scanf("%d", &niz[i]);
		ubaci(niz,duz);
		poziv=izbaci(niz,2*duz);
		printf("Modificirani niz glasi: ");
		for(i=0; i<poziv; i++){
			if(i<poziv-1){
				printf("%d.", niz[i]);
			}
			else{
				printf("%d,", niz[i]);
			}
		}
	}
	return 0;
}
