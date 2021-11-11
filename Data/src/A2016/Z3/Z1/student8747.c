#include <stdio.h>

int daj_prost() {
		static int k=1;
		int i;
		k++;
		if(k==2)
			return 2;
		while(k>2){
			for(i=2;i<k;i++){
				if(k%i==0) 
					break;
			}
			if(i==k)
				return k;
			k++;
		}
}
int main() {
	int A,B;
	int suma=0,c;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d%d",&A,&B);
		if(A<=0){
			printf("A nije prirodan broj.\n");
			continue;
		}
		if(A>=B){
			printf("A nije manje od B.\n");
			continue;
		}
	}
	
	while(A<=0 || A>=B);
	do{
		c=daj_prost();
		if(c>A && c<B)
			suma += c;
	}while(c<B);
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	
	return 0;
}