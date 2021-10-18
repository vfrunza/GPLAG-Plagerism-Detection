#include <stdio.h>
#include <stdlib.h>

int sumabroja(int a){
	int suma=0,b,c;
	b=abs(a);
	while(b!=0){
		c=b%10;
		b=b/10;
		suma=suma+c;
	}
	
	return suma;
}

void ubaci(int *niz, int vel){
	int i, *a;
	a=niz;
	for(i=vel-1;i>0;i--){
		*(a+2*i)=*(a+i);
	}
	
	for(i=0;i<2*vel-1;i++){
		if(i%2==0){
			*(a+i+1)=sumabroja(*(a+i));
		}
	}
}

int fibonaccijevbroj(int n){
	int a=1,b=1,c;
	if(n<0) return 0;
	if(n==1) return 1;
	while(1){
		c=a+b;
		if(n==c) return 1;
		else if(c>n) return 0;
		a=b;
		b=c;
	}
}

int izbaci(int *niz, int vel){
	int i,j,*a,b;
	a=niz;
	for(i=0;i<vel;i++){
		b=fibonaccijevbroj(*(a+i));
		
		if(b==1){
			for(j=i;j<vel-1;j++) {
				*(a+j)=*(a+j+1);
			}
			vel--;
			i--;
		}
	}
	return vel;
}

int main() {
	int niz[20],i,s;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d", &niz[i]);
	}
	ubaci(niz,10);
	s=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<s;i++){
		if(i==s-1) printf("%d.", niz[i]);
		else printf("%d, ",niz[i]);
	}
	return 0;
}
