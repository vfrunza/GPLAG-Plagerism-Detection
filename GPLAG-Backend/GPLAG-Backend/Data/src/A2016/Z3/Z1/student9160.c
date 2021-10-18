#include <stdio.h>

int daj_prost()
{
	static int a=1;
	int j,prost=1;
	while(1){
	a++;
	if(a==2)return a;
		for(j=2; j<a; j++) {
			if(a%j==0) {
				prost=0;
				break;
			}
		}
		if(prost==1)return a;
		else {
			prost=1;
		}
}
}

int main()
{
	int x=daj_prost();
	int A,B,sum=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d",&A);
		scanf("%d",&B);
		if(A<1)printf("A nije prirodan broj.\n");
		if(A>=B)printf("A nije manje od B.\n");
	} while(A>=B || A<1);

	while(x<=B) {x=daj_prost();if(x>A&&x<B)sum+=x;}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A,B,sum);
	return 0;
}