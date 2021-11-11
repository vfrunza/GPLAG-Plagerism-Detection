#include <stdio.h>
int daj_prost() {
int j=2,broj=0;
static int i=1;
do{
i++;
for(j=2;j<=i;){
        if(i==j){
        broj=i;
        break;}
else if(i%j==0){
        break;}
else if(i%j!=0){
j++;}}
}while(broj!=i);
return broj;}

int main() {
	int A, B, i,  suma=0, b;
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	while(A>=B || A<=0){
	if(A<=0) {
		printf("A nije prirodan broj. ");
		printf("\nUnesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
	}
	else if(A>=B){
		printf("A nije manje od B. ");
		printf("\nUnesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
	}}
			for(i=0; i<B; i++){
				b=daj_prost();
				if(b>A && b<B){
				suma+=b;}
				}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}
