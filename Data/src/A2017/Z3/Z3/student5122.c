#include <stdio.h>
#include <math.h>

int izbacicifru(int broj, int cifra){
	int novi=0,k=1,c,neg=0;
	if(broj<0){
		          neg=1; 
		          broj=(fabs)(broj);
		          }
		          
	while(broj!=0){
		          
				c=broj%10;
				if(c!=cifra){ novi=novi+c*k; 
				          k*=10;
				         
				          }
				          broj=broj/10;
			
	}
	if(neg==1) return(-1*novi);
	return novi;
}

int izbaci_cifre(int brojevi[], int vel1, int cifre[], int vel2){
	int i,j,broj,brojac=0,a;
    for(i=0; i<vel2; i++)
		if(cifre[i]<0 || cifre[i]>9)return 0;
		
		for(i=0;i<vel2;i++) {
			a=cifre[i];
		for(j=i+1;j<vel2;j++){
			if(a==cifre[j]) brojac++;
		    }
		    if(brojac>0)return 0;
}
    for(i=0;i<vel1;i++){
    	broj=brojevi[i];
    	for(j=0;j<vel2;j++){
    		broj=izbacicifru(broj,cifre[j]);
    		brojevi[i]=broj;
    	}
    	
    }
	
	return 1;
	
	
}
int main() {
	int i,niz1[100],niz2[100],x,y;
	int *a;
	int *b;
	printf("Unijeti velicinu niza 1:");
	scanf("%d",&x);
	for(i=0;i<x;i++) scanf("%d",&niz1[i]);
	printf("Unijeti velicinu niza 2: ");
	scanf("%d",&y);
	for(i=0;i<y;i++) scanf("%d",&niz2[i]);
    a=&niz1[0];
    b=&niz2[0];
	izbaci_cifre(a,x,b,y);
    return 0;
}
