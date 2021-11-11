#include <stdio.h>
int da_li_je_prost (int n) {
	int brojac=0, i;
	for(i=1; i<=n; i++) {
		if(n%i==0)
		brojac++;
	}
	if(brojac==2)
	return 1;
	else 
	return 0;
}
int daj_prost () {
static int s=1;
int i=s+1;
while(!da_li_je_prost(i)) {
	i++;
}
s=i;
return i;
}
int main() {
	int A, B, suma=0,x,y=1;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &A, &B);
		if(A<1)
		printf("A nije prirodan broj.\n");
		if(B<=A)
		printf("A nije manje od B.\n");
	}
	while(A<1 || A>=B);
	x=A+1;
	if(A>=2) {
		while(y<=A) {
				y=daj_prost();
			}
	}
	if(y>A && y<B)
		suma+=y;
	while(x>A && x<B) {
	x=daj_prost();
	if(x<B)
		suma+=x;

	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", A, B, suma);
	return 0;
}
