#include <stdio.h>
int daj_prost(){
	int i;
	static int n=1;
	do{
		n++;
	for (i=2;i<n;i++){
			if(n%i==0){
			break;
		}}
	
	}while (n!=i);
	return n;
}

int main() {
	int broj1,broj2,prostbr,i,Suma=0;
	printf("Unesite brojeve A i B: ");
	scanf("%d%d",&broj1,&broj2);
	while (broj1<=0||broj1>=broj2){
	if (broj1<=0){
		printf ("A nije prirodan broj.");
		printf("\nUnesite brojeve A i B: ");
		scanf ("%d%d",&broj1,&broj2);
	}
	if (broj1>=broj2){
		printf("A nije manje od B.");
		printf("\nUnesite brojeve A i B: ");
		scanf ("%d%d",&broj1,&broj2);
	}
}
for (i=0;i<broj2;i++){
	prostbr=daj_prost();
	if (prostbr>broj1&&prostbr<broj2){
		Suma=Suma+prostbr;
	}
}
printf ("Suma prostih brojeva izmedju %d i %d je %d.",broj1,broj2,Suma);
	return 0;
}
