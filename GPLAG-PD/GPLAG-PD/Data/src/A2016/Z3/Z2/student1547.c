#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void ubaci (int*niz, int br){
	int i, *p=niz, br1, *q=niz, sumacif=0, broj;
	br1=(br)-1;
	for(i=br1; i>0; i--){
		*(p+(2*i))=*(p+i);
	}
	p=niz;
	for(i=1; i<2*br; i+=2){
		broj=*q;
		sumacif=0;
		while(broj!=0){
			sumacif+=(broj)%10;
			broj=broj/10;
		}
		*(p+i)=(abs)(sumacif);
		q+=2;
	}
}
int fibonacci (int x){
	int fib[100], i;
	fib[0]=1;
	fib[1]=1;
	for(i=2; i<100; i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	for(i=0; i<100; i++){
		if(x==fib[i]) return 1;
	}
	return 0;
	}

int izbaci (int*niz,int br){
	int*p=niz, i, j, *q;
	for(i=0; i<br;i++){
		q=p;
		if(fibonacci(*p)==1){
			for(j=i; j<br-1; j++){
				*q=*(q+1);
				*q++;
			}
		*p--;
		br--;
		i--;
		}
	*p++;
	}
	return br;
}

int main() {
	int niz[20], i, br=0, brc;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++){
		scanf("%d", &niz[i]);
		br++;
	}
	ubaci(niz, br);
	br=br*2;
	brc=izbaci(niz, br);
	printf("Modificirani niz glasi: ");
	for(i=0; i<brc; i++){
		if(i==brc-1) printf("%d.", niz[i]);
		else printf("%d, ", niz[i]);
	}
	
	return 0;
}
