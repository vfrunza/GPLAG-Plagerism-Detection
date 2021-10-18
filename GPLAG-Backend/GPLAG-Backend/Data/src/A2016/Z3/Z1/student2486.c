#include <stdio.h>
int daj_prost(){/*funkcija za nalazenje prostih brojeva*/
long int k;
static long int a=1;a++;/*staticka promjenjiva zadrzava svoju vrijednost*/
	for(k=2;k<a;k++){
		if(a%k==0){
			a++;
		k=2;	}}return a;}/*vracamo vrijednost a */
int main() {
long int A,B,suma=0,broj,i;
do{printf("\nUnesite brojeve A i B: ");scanf("%ld %ld", &A, &B);
if(A>=B){printf("A nije manje od B.");}
else if(A<=0){printf("A nije prirodan broj.");}}
while(A<=0 || A>=B);


for(i=0;i<B;i++){broj=daj_prost();if(broj>A && broj<B){suma=suma+broj;}}/*racunanje svih prostih brojeva
između brojeva unesenih između A i B*/
printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B, suma);
	return 0;
}
