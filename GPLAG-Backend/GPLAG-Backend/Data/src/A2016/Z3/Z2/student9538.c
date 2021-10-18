#include <stdio.h>
int zbir(int x){
	if(x<0) x=x*(-1);
	int Suma=0;
	while( x!=0) {
	int cifra=x%10;
	Suma=Suma+cifra;
	x=x/10;
	
	
	} return Suma;
}
void ubaci(int niz[],int vel) {
	int i,j,cifra;
	for(i=0;i<vel;i++) {
		for(j=vel;j>i;j--) {
			niz[j]=niz[j-1];
		
		} 
		 cifra=zbir(niz[i]);
		 if(cifra>0)
		niz[i+1]=cifra;
		i++;	vel++;
	}
	
}

int fib(int x){
	int prvi=1,drugi=1,sljedeci=1;
	if(x==prvi) return 1;
	if(x==1 || x==2 ||x==3 ||x==5) return 1;
	else{
	while(sljedeci<=x){
		sljedeci=prvi+drugi;
		if(sljedeci==x) return 1;
		prvi=drugi;
		drugi=sljedeci;
	}}
	return 0;
} 
int izbaci(int niz[],int vel) {
	int i,j;
	for(i=0;i<vel;i++){
			if(niz[1]!=0){
			if (fib(niz[i])==1){
				for(j=i;j<vel-1;j++){
					niz[j]=niz[j+1];
					
				}
				i--;	vel--;
			}	}}
		return vel;
	}

int main() {
	int i,niz[20];
	printf("Unesite niz od 10 brojeva: ");

for(i=0;i<10;i++) 	scanf("%d",&niz[i]);
ubaci(niz,10);
int velicina=izbaci(niz,20);
printf("Modificirani niz glasi: ");
for(i=0;i<velicina-1;i++) {
	printf("%d, ",niz[i]);
	
}
printf("%d.",niz[i]);
	
	
	return 0;
}
