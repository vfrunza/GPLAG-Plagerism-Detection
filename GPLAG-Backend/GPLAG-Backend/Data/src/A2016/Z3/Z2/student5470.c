#include <stdio.h>
#include<stdlib.h>

int fibonaci(int n) {
	int i,prvi=1,drugi=1,sljed;
	for(i=0;i<100;i++) {
		if(i==0 || i==1) sljed=1;
		else {
			sljed=prvi+drugi;
			prvi=drugi;
			drugi=sljed;
		}
		if(n==sljed) return 1; 
	}
	return 0;
}

int izbaci(int *niz,int n) {
	int i,j,y;
	for(i=0;i<n;i++){
		y=fibonaci(niz[i]);
		if(y==1) {
			for(j=i;j<n-1;j++)
			niz[j]=niz[j+1];
			n--;
			i--;
		}
	}
	return n;
}

void ubaci(int *niz,int n) {
	int i,a,b=0,temp,br=0,br1=1;
	temp=niz[0];
	//br (brojac) pokazuje za koliko mijesta ulijevo pomjeriti svaki od clanova niza(svaki za 1 vise)
	for(i=2*n-1;i>=0;i-=2) {
		niz[i-1]=niz[n-1-br];
		br++;
			//b je zbir cifara clana niza
			while(abs(niz[n-br1])!=0) {
				a=abs(niz[n-br1])%10;
				b+=a;
				niz[n-br1]/=10; 
			}
		niz[i]=b;
		b=0;
		br1++;
	}
	niz[0]=temp;
}

int main() {
	int i,y, niz[20];
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
		scanf("%d",&niz[i]);
	ubaci(niz,10);
	y=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<y; i++) {
		if(y==1) printf("%d.",niz[i]);
		else if(i==y-1) printf("%d.",niz[i]);
		else printf("%d, ",niz[i]);
	}
	return 0;
}
