#include <stdio.h>
long daj_prost(){
	static long prost_broj = 2;
	int i,flag;
while(prost_broj){
flag = 1;
for(i = 2;i < prost_broj;i++){
if(prost_broj%i==0){
	flag = 0;
	break;
}
}
if(flag)
	return prost_broj++;
prost_broj++;
}
}	
int main() {
long A,B,j;
long suma;
suma = 0;
do{
	printf("Unesite brojeve A i B: ");
	scanf("%ld %ld", &A,&B);
	if(A < 1)
		printf("A nije prirodan broj.\n");
	else if(A >= B)
		printf("A nije manje od B.\n");
	}while(A < 1  || A >= B);
	
do{
	j=daj_prost();
	if(j > A &&  j < B)
		suma+=j;
}while(j < B);
printf("Suma prostih brojeva izmedju %ld i %ld je %ld.",A,B,suma);
return 0;
}

