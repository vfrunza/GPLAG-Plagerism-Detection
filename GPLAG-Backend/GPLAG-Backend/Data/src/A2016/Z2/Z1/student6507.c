#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main() {
	int n, k, i, j, d, z, t, broj=0; 
	printf("Unesite broj: ");
	scanf("%d", &n);
	n=abs(n);
	k=-1;
	t=n;
	if((n/10)==0){
		printf("0");
	}
	else{
		do{
			t=t/10;
			k=k+1;
		}while(t!=0);
		
		for(z=k; z>0; z=z-1){
			i=n/pow(10,z);
			j=(n-i*pow(10,z))/pow(10, z-1);
			
			d=abs(i-j);
			broj=broj+d*pow(10,z-1);
			
			n=(n-i*pow(10,z));
			
			
			
		}
		printf("%d", broj);
	}
	return 0;
}
