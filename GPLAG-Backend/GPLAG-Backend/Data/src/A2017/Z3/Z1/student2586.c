#include <stdio.h>

int brisi(int *arr, int size){
	int i,j,k;
	for (i = 0; i < size; i++) {
	for (j = i + 1; j < size;) {
		if (arr[j] == arr[i]){
			for (k = j; k < size; k++){
			arr[k] = arr[k + 1];
		}
			size--;
		} else
			j++;
	}
	}
	return size;
}

int dva_od_tri(int *a, int vela, int *b, int velb, int *c, int velc){
	int velNiza=vela+velb+velc;
	int pomocni[10000]={0};
	int poma[10000];
	int pomb[10000];
	int pomc[10000];
	
	int niz[10000];
	int i;
	int br=0;
	int sizeA, sizeB, sizeC;
	
	for(i=0; i<vela; i++){
		poma[i]=a[i];
	}
	
	for(i=0; i<velb; i++){
		pomb[i]=b[i];
	}
	
	for(i=0; i<velc; i++){
		pomc[i]=c[i];
	}
	sizeA=brisi(poma,vela);
	sizeB=brisi(pomb,velb);
	sizeC=brisi(pomc,velc);
	for(i=0; i<sizeA; i++){
		niz[i]=poma[i];
	}
	for(i=sizeA; i<sizeA+sizeB; i++){
		niz[i]=pomb[i-sizeA];
	}
	for(i=sizeA+sizeB; i<velNiza; i++){
		niz[i]=pomc[i-sizeA-sizeB];
	}
	for(i=0; i<sizeA+sizeB+sizeC; i++){
		pomocni[niz[i]]++;
	}
	for(i=0; i<10000; i++){
		if(pomocni[i]==2){
			br++;
		}
	}
	return br;
}

int main() {
	int niz1[] = {1, 2, 3, 4};
	int niz2[] = {2, 3, 4, 5};
	int niz3[] = {3, 4, 5, 6};
	int niz4[1];
	int rez = dva_od_tri(niz1, 4, niz2, 4, niz4, 0);
	printf("%d ",rez);
	rez = dva_od_tri(niz1, 4, niz4, 0, niz3, 4);
	printf("%d ", rez);
	rez = dva_od_tri(niz4, 0, niz2, 4, niz3, 4);
	printf("%d ", rez);
	rez = dva_od_tri(niz1, 4, niz2, 4, niz3, 4);
	printf("%d ", rez);
	return 0;
}
