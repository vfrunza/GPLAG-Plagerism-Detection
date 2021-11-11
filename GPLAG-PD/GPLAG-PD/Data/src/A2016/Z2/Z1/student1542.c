#include <stdio.h>
#include <stdlib.h>
int main() {
		int n,x,y,z,suma=0,suma2=0,br0=1,i;
		int tacno=0;
		printf("Unesite broj: ");
		scanf("%d", &n);
		
		if(n>=1 && n<=9) printf("0");
		
		else{
			for(i=1;n!=0;i++){
				
				x=n%10;
				n=n/10;
				if(n!=0){
				y=n%10;
				
				z=abs(x-y);
				if(i==1 && z==0)tacno=1;
				suma=suma*10+z;
				if(z==0)br0*=10;
				
				}
			}
		z=0;
		while(suma!=0){
			z=suma%10;
			suma=suma/10;
			suma2=suma2*10+z;
		}
		if(tacno==1)
		suma2=suma2*br0;
		printf("%d",suma2);
		}

	return 0;
}
