#include <stdio.h>

int suma_cifara(int n){
	int suma=0,c;
	if(n<0) n=-1*n;
	while(n!=0){
		c=n%10;
		suma+=c;
		n/=10;
	}
	return suma;
}
void ubaci(int niz[],int vel){
	int *p=niz;
	int *q=niz;
	int i,broj, c=vel-1;
	for(i=0;i<vel;i++) {
		q=p;
		q=q+c;
		while(q!=p) {
			*(q+1)=*q;
			q--;
		}
		broj=*p;
		p++;
		*p=suma_cifara(broj);
		c--;
		p++;
	}
}


int Fibonaci(int n) {
	int a=0,prvi=1,drugi=1;
	if(n==1) return 1;
	while(a<n)
	{
		drugi=a+prvi;
		a=prvi;
		prvi=drugi;
		
	}
	if(a!=n) return 0;
	else return 1;
}
int izbaci(int niz[],int velicina) {
	int i,j;
	for(i=0;i<velicina;i++) {
	 if(niz[i]>0){
		if(Fibonaci(niz[i])==1) {
			for(j=i;j<velicina-1;j++) {
				niz[j]=niz[j+1];
				}
			velicina--;
			i--;
			}
			
		}
		else continue;
			
			
		
	}
	
	return velicina;
}
int main () {
	int i, vel;
	int niz[20] ;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++) 
		scanf("%d",&niz[i]);
	ubaci(niz,10);
	vel = izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	for (i=0; i<vel; i++){
	   
	   if(i==vel-1){
	   	printf("%d.",niz[vel-1]); 
	   	break;
	   	
	   }
	   	
	   	printf("%d, ",niz[i]);
	}

	return 0;
}