#include <stdio.h>
#include <stdlib.h>
int n;

int fibonaciChecker(int elNiz){
	int frst=1, scnd=1, temp;
	if (elNiz==1) return 1;
	while (elNiz!=scnd && scnd<=elNiz){
		temp=frst;
		frst=scnd;
		scnd=temp+frst;
		if (elNiz==scnd){return 1;}
	}
	return 0;
}

void ubaci(int *pNiz, int velicina){
	int sumEl, k, i, vEl;
	
	for(i=velicina-1; i>0; i--){
		*(pNiz+2*i)=*(pNiz+i);
	}
	for(i=0; i<velicina*2; i=i+2){
		sumEl=0;
		vEl=abs(*(pNiz+i));
		while(1){
			if(vEl/10!=0){
				k=vEl%10;
				sumEl+=k;
			}else{
				sumEl=sumEl+vEl;
				break;
			}
			vEl=vEl/10;
		}
		*(pNiz+i+1)=sumEl;
	}
}

int izbaci(int *pNiz, int velicina){
	int i, j;
	n=velicina;
	for(i=0; i<n; i++){
		if (fibonaciChecker(*(pNiz+i))==1){
			for(j=i; j<n-1; j++){
				*(pNiz+j)=*(pNiz+j+1);
			}
		n--; i--;
		}
	}
	return n;
}

int main() {
	int niz[20], i, k;
	
	printf("Unesite niz od 10 brojeva: ");
	for (i=0; i<10; i++){
		scanf("%d,", &niz[i]);
	}
	ubaci(niz,10);
	k=izbaci(niz,20);
	
	printf("Modificirani niz glasi: ");
	for(i=0; i<k; i++){
		if (i<k-1){
			printf("%d, ", niz[i]);
		}else{
			printf("%d.", niz[i]);
		}
	}
	return 0;
}