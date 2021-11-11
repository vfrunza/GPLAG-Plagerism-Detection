#include <stdio.h>
int daj_prost(){
	static int n=1;
	int i,j=0;
	while (j==0){
		n++;
	j=1;
		for(i=2;i<n;i++){
			if(n%i==0)
			{
				j=0;
				break;
			}
		}
		if (j==1)

		return n;
	}
}
int main() {
	int a,b,suma=0,x;
	do {
		suma=0;
	printf("Unesite brojeve A i B: ");
	scanf("%d %d",&a,&b);
	if(a>=b){suma=1; printf("A nije manje od B.\n");}
		else if ((a<1 || b<1)){suma=1; printf("A nije prirodan broj.\n");}
	}
	while (suma==1);
	x=daj_prost();
	suma=0;
	while(x<b){
		if(x>a&&x<b){
		suma+=x;}
		x=daj_prost();
		if(x>=b) break;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}
