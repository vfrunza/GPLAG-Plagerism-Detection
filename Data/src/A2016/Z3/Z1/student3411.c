#include <stdio.h>
int daj_prost(){
	static int a=1;
	int i, prost;
	a++;
	if(a==2) return a;
	else if(a==3) return a;
	else{
		prost=0;
		while(prost==0){
			prost=1;
			for(i=2; i<=(a/2); i++){
				if(a%i==0) {
					prost=0;
					break;
				}
			}
			if(prost==1) return a;
			a++;
		}
	}
	
}
int main() {
	int A=-1,B=-1, i,s=0, prost=0;
	while(A<1 || B<1 || B<=A){
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A,&B);
		if(A<1) printf("A nije prirodan broj.\n");
		else if(B<1 || B<=A) printf("A nije manje od B.\n");
	}
	for(i=1; i<B; i++){
		prost=daj_prost();
		if(prost>A && prost<B){
			s=s+prost;
		}
		if(prost>=B) break;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,s);
	return 0;
}
