#include<stdio.h>

int daj_prost(){
	
	static int i=1;
	int j;
	i++;
		for(j=2; j<i; j++){
			if(i%j==0){
				j=2;
				i++;
			}
		}
	 return i;
}

int main(){
	
	int A, B, i, r=0, p=0, s=0, g;

	do{
		printf("Unesite brojeve A i B: ");
		
		scanf("%d %d", &A, &B);
		if(A>=B){
			printf("A nije manje od B.\n");
			r=1;
		} else r=0;
	    if(A<1){
			printf("A nije prirodan broj.\n");
			p=1;
		} else p=0;
	} while(r==1 || p==1);
	
	for(i=1; ; i++){
		g=daj_prost();
		
		if(g>=B) break;
		if(g<=A) continue;
		s=s+g;
	
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,s);
	
	return 0;
}