#include <stdio.h>
#include <math.h>
int daj_prost ()
{
	static int j=2;
	int x=1; /*logicka varijabla preko koje se vrsi provjera djeljivosti broja*/
	while(x) {
		int i;
		x=0;
		for(i=2; pow(i,2)<=j;++i)
			if(j%i==0){
				x=1;}
		j++;

	}

	return j-1;
}
int main()
{
	int A, B, sum=0;
	do {
		printf("\nUnesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A>=B) {
			printf("A nije manje od B.");
		}
		if(A<=0) {
			printf("A nije prirodan broj.");
		}
	} while(A<=0||B<=0||A==B);

	int gr=daj_prost ();
	while(gr<B){
		if(gr>A)
		sum=sum+gr;
		gr=daj_prost();
}


	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, sum);

	return 0;

}
