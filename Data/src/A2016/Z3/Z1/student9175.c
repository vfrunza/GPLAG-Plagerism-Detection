#include <stdio.h>

int daj_prost() {
	static int a=1;
	int i;
     a++;
	for(i=2;i<a;i++){
		if(a%i==0) {
			a++;i=2;
			}
	}
	return a;
}

int main() {
	int A,B,i,s=0,a;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&A,&B);
		if(A<=0){
			printf("A nije prirodan broj.\n");
		}
		if(A>=B){
			printf("A nije manje od B.\n");
		}
	}while(A>=B || A<=0 || B<=0);
	i=A+1;
	while(i<B){
	 a=daj_prost();
		while(a>i)i++;
		if(i>=B)break;
		if(a==i)s+=a;
	}
	
 printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,s);
	
		
		
			return 0;
}
