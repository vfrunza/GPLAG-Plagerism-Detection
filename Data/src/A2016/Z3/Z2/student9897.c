#include <stdio.h>

void napraviRazmake(int *niz, int e){
	int i;
	for(i=e-1;i>0;i--){
		niz[i*2] = niz[i];
	}
}
int dajSumu(int i){
	if(i<=0) i*=(-1);
	int suma;
	suma = 0;
	while(i != 0){
		suma+=(i%10);
		i/=10;
	}
	return suma;
}

void ubaci(int *niz, int br_elemenata){
	int i;
	napraviRazmake(niz, br_elemenata);
	for(i=1;i<br_elemenata*2;i+=2){
		niz[i] = dajSumu(niz[i-1]);
	}
}


int fibonnaci(int broj){
	int i=0;
	int prvi=1, drugi=1, treci=0;
	if(broj == 1 || broj == 2 || broj == 3) return 1;
	for(i=2;i<=100000000;i++){
		treci = prvi + drugi;
		prvi = drugi;
		drugi = treci;
		if(broj == treci){
			return 1;
		}
	}
	return 0;
}



int izbaci(int *niz,int br_elemenata){
	int i,j;
	for(i=0;i<br_elemenata;i++){
		if(fibonnaci(niz[i])){
			for(j=i;j<br_elemenata;j++){
				if(j+1 < br_elemenata){
					niz[j] = niz[j+1];
				}
			}br_elemenata--;
			if(fibonnaci(niz[i]))i--;
		}
	}
	return br_elemenata;
}

int main() {
	int i,niz[40],br_elemenata;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d", &niz[i]);
	}
	ubaci(niz, 10);
	br_elemenata  = izbaci(niz, 20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<br_elemenata;i++){
		if(i != br_elemenata -1){
			printf("%d, ", niz[i]);
		}else printf("%d.", niz[i]);
	}
	return 0;
}
