#include <stdio.h>

int daj_prost(){
	int j;
	static int i=1;
	i++;
	for (j=2; j<i; j++) {
		if (i%j==0) {
			i++;
			j=2;
		}
		
	
	}
	return i;
}

int main() {
	int A,B,y=0,p;
	
	do {
		
	printf ("\nUnesite brojeve A i B: ");
	scanf ("%d %d", &A,&B);
	if (A<=0) 
		printf ("A nije prirodan broj.");
	else if (A>=B) 
		printf ("A nije manje od B.");
		
	} while (A<=0 || A>=B);
	
	do {
		p=daj_prost();
		if(p<=A) 
			continue;
		if(p>=B) 
			break;
		y=y+p;
	} while (p<B);
	
	printf ("Suma prostih brojeva izmedju %d i %d je %d. ", A,B,y);
	
	
	return 0;
}
