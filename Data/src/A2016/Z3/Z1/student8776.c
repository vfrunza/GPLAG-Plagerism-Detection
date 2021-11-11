#include <stdio.h>
#include<math.h>

int daj_prost(){
	int i, prost=1;
	static int n=1;
	do{
		n++;prost=1;
	for(i=2; i<n; i++){
		if(n%i==0)prost=0;
	
	}
 	if	(prost==1)return n;
	else prost=0;
	}while(prost==0);
}

int main() {
	int A, B,tmp=1,l=-1;
	int suma=0;
	do{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A, &B);
	if(A<=0) printf("A nije prirodan broj.\n");
	else if(B<=A) printf("A nije manje od B.\n");
	else tmp=0;
	}while(tmp==1);
	

	while(l<B){
		l=daj_prost();
		if(l+1>B)break;
		else if(A>=l)continue;
		else if(l<=B) suma+=l;
		}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B, suma);
	return 0;
}
