#include <stdio.h>

int zbir(int n){
	int suma=0;
	while(n>0){
		suma+=n%10;
		n/=10;
	}
	return suma;
}

void ubaci(int niz[],int vel){
	int ermin[20000]={0},i;
	for(i=0;i<vel;i++){
		ermin[i*2]=niz[i];
	}
	for(i=0;i<vel*2;i++){
		if(i%2!=0) ermin[i]=zbir(ermin[i-1]);
	}
	for(i=0;i<vel*2;i++) niz[i]=ermin[i];
}
int fibonacijev(int x){
	
	int prvi=0,drugi=1,sljedeci,i;
	if(x==1 || x==2 || x==3) return 1;
	for(i=0;i<x;i++){
		if(i<=!1) sljedeci =i;
		else {
			sljedeci=prvi+drugi;
			prvi=drugi;
			drugi=sljedeci;
			if(sljedeci==x) return 1;
		
		}
	}
	return 0;
}

int izbaci(int niz[],int vel){
	int i,j;
	for(i=0;i<vel;i++){
		if(fibonacijev(niz[i])) {
			for(j=i;j<vel-1;j++){
				niz[j]=niz[j+1];
			}
			i--;vel--;
		}
	}
	
}
int main() {
	int niz[20],i;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d",&niz[i]);
	}
	
	ubaci(niz,10);
	int velicina=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<velicina-1;i++) 
	printf("%d, ",niz[i]);
	printf("%d.",niz[i]);
	return 0;
}
