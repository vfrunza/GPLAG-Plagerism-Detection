#include <stdio.h>

int Fibonaci(int x){
	long int niz[100];
	niz[0]=1;
	niz[1]=1;
	int i;
	if(x==1) return 1;
	for(i=2;i<=100;i++){
		niz[i]=niz[i-2]+niz[i-1];
		if(niz[i]==x) return 1;
		if(niz[i]>x) return 0;
	}
	return 0;}
	
int izbaci(int niz[],int velicina){
	int i,j,br;
	
	for(i=0;i<velicina;i++){
		br=i;
		/*ISPITIVANJE DA LI JE FINONACIJEV BROJ*/
		if(Fibonaci(niz[i])==1){
			for(j=i+1;j<velicina;j++){
				niz[i]=niz[j];
				i++;
			}
			velicina--;
			i=--br;
			}
		}
		return velicina;
}
int suma_cifara(int x){
if(x<0) x*=-1;
	int cifra;
	int suma=0;
	while(x!=0){
		cifra=x%10;
		x/=10;
		suma+=cifra;
	}
	return suma;
}

void ubaci(int niz[],int velicina){
	int i;
	int k=0;
	int niz2[100];
	for(i=0;i<velicina;i++)
	niz2[i]=niz[i];
	//for(i=0;i<2*velicina;i++)
	i=0; 
	while (k<velicina){
		niz[i]=niz2[k];
		k++;
		i++;
		niz[i]=suma_cifara(niz[i-1]);
		i++;
	}
}


int main() {
	int i;
	int niz[100];
	int x;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++)
	scanf("%d",&niz[i]);
	ubaci(niz,10);
	x= izbaci(niz,20);
	
	printf("Modificirani niz glasi: ");
	for(i=0;i<x;i++){
	if(i==x-1)printf("%d.",niz[i]);
	else{	printf("%d, ",niz[i]);}
	}
		return 0;
}
