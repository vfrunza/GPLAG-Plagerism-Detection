#include <stdio.h>
static int B,A,k;
int daj_prost(){
	int i;
	int niz[1000];
	for (i=2; i<k; i++){
		if (k%i==0){
			break;}
		else if (i==k){
			return k;}}}

int main() {
	int j,s=0,p=0;
	do {
		printf("\nUnesite brojeve A i B: ");
		scanf ("%d %d", &A,&B);
		if (A<=0)
		printf ("A nije prirodan broj.");
		if (A>=B)
		printf ("A nije manje od B.");}
		while (A>=B || A<=0);
		
	for (j=A+1; j<B; j++){
		k=j;
		p=daj_prost();
		s+=p;}
	printf ("Suma prostih brojeva izmedju %d i %d je %d.", A,B,s);
	
	return 0;
}
