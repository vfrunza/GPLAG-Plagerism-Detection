#include <stdio.h>
#include <math.h>

int izbaci_cifre(int *niz, int  vel, int *cifre,int vel1) {
	
		
	int i,j,c,suma=0;
	int k=1, neg=0,n;
	
	for(i=0; i<vel1; i++) 
		if(cifre[i]<0 || cifre[i]>9) return 0;
	
	for(i=0; i<vel1; i++) 
		for(j=i+1; j<vel1; j++) 
			if(cifre[i]==cifre[j]) return 0;
	
	
	for(i=0; i<vel; i++) {
		if(niz[i]<0) neg=1;
		
		n=fabs(niz[i]);
		
		while(n!=0) {
			c=n%10;
			for(j=0; j<vel1; j++) 
				if(c==cifre[j]) c=0;
				
			suma+=c*k;
			n/=10;
			if(c!=0) k*=10;
		}
	
		if(neg==1) suma*=-1;
		niz[i]=suma;
		suma=0;
		neg=0;
		k=1;
	}
	
	return 1;
	
}

int main() {
	
	
	
int i,br;
int niz1[1000], niz2[1000];
int vel1,vel2;

printf("Uneiste velicinu prvog niza: ");
scanf("%d", &vel1);

printf("Unesite elemente prvog niza: ");
for(i=0; i<vel1; i++) {
	scanf("%d", &niz1[i]);
}

printf("Uneiste velicinu drugog niza: ");
scanf("%d", &vel2);

printf("Unesite elemente drugog niza: ");
for(i=0; i<vel2; i++) {
	scanf("%d", &niz2[i]);
}



br=izbaci_cifre(niz1,vel1, niz2, vel2);

printf("%d", br);


	return 0;
}
