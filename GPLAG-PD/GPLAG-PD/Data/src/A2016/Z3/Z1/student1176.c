#include <stdio.h> 

int da_li_je_prost(int a){
	int i;
	for(i=2; i<a; i++){
		if(a%i==0) return 0;
	} 
	return 1;
} 

int daj_prost(){  
	static int a=1; 
	int i;
	for(i=a+1; i<100000; i++){
		if(da_li_je_prost(i)){
			a=i;
			return i;
		}
	}  
}

int main() {
	int A, B, suma=0, x;
	do{
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A>=B){
			printf("A nije manje od B."); 
			printf("\n");
		} 
		if(A<1){
			printf("A nije prirodan broj."); 
			printf("\n");
		} 
	}while(A>=B || A<1);  
    x=daj_prost();
    while(x<=A){
    	x=daj_prost();
    } 
    while(x<B){
    	suma+=x;
    	x=daj_prost();
    }
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}
