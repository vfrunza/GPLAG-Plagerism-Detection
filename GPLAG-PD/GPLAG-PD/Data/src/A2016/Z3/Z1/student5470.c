#include <stdio.h>

int daj_prost(){
	int i,x;
	/*staticka promjenjiva, jer je potrebno zadrzati vrijednost 
	da bi f-ija sljedecim pozivom vratila sljedeci prost broj*/
	int static temp=2;
	for(x=temp;x<100000;x++) {
		for(i=2;i<x;i++)
			if(x%i==0) {
				break;
			} 
		if(i==x) {temp=(x+1); return x;}
	}
	return 0;	
}
int main() {
	int A,B,s=0,br=0,br1=0,i,j;
		do{
			printf("Unesite brojeve A i B: ");
			scanf("%d %d",&A,&B);
			if(A<=0) {printf("A nije prirodan broj.\n");continue;}
			if(A>=B) {printf("A nije manje od B.\n"); continue;}
			if(B<=0) {printf("B nije prirodan broj.\n");continue;}

		} while(A>=B || A<=0 || B<=0);

	//racunanje prostih brojeva do broja A
	for(i=0;i<=A;i++) {
		for(j=2;j<i;j++)
			if(i%j==0) break;
	if(j==i) {br++; daj_prost();}
	}
	//racunanje prostih brojeva od broja A do broja B
	for(i=(A+1);i<B;i++) {
		for(j=2;j<i;j++)
			if(i%j==0) break;
	if(j==i) br1++;
	}
	//sumiranje prostih brojeva izmedju A i B
	for(j=0;j<br1;j++)
		s+=(daj_prost()); 
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,s);
	return 0;
}
