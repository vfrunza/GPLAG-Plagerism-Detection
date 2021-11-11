#include <stdio.h>

int prost(int a)
{
	int temp=0,i;
	if(a==2) return 1;
	for(i=2;i<a;i++) { if(a%i==0) {temp=0; break;} else temp=1; }
	return temp;
}
int daj_prost()
{
	static int br=2;
	int i=1;
	while(i){
		if(prost(br)==1){ return br++; i=0;}
		else br++;
		
	}
	for(i=br;;i++) {if(prost(i)==1) {return i;
	return br++;} continue;}
}
int main() {
	int A,B; int br=0;
	for(;;){
		if(br==0)printf("Unesite brojeve A i B: ");
		if(br>0)printf("\nUnesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A<=0) printf("A nije prirodan broj.");
		if(A>=B) printf("A nije manje od B.");
		if(A<B && A>0) break;
		br++;
	}
	int suma=0;
	while(1){
		int j=daj_prost();
		if(j<B && j>A) suma+=j;
		if(j>B) break;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,suma);
	

	
	return 0;
}
