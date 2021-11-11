#include <stdio.h>

int daj_prost()
{
	int j,prost=1;
	static int i=1;
	i++;
	if(i==2)
	return i;
	else{
	for(j=2;j<i;j++)
	if(i%j==0){
		prost--;
		break;
	}
	}
	if(prost)
	return i;
	else
	daj_prost();
}
int main() {
	int A,B,i,x,suma=0;
	do{
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&A,&B);
	if(A>=B)
	printf("A nije manje od B.\n");
	else if(A<1)
	printf("A nije prirodan broj.\n");
	else if(B<1)
	printf("B nije prirodan broj.\n");
	}
	while(A<1 || B<1 || A>=B);
	for(i=0;i<B;i++){
	x=daj_prost();
	if(x>B)
	break;
	if(x>A && x<B)
	suma=suma+x;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,suma);
	return 0;
}
