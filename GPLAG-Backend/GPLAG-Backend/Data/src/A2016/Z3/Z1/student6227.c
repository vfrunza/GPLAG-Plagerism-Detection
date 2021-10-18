#include <stdio.h>

int daj_prost () {
    static int n=1;
    int i=0;
    n++;
    for(i=2;i<n;i++) {
        if (n%i==0) {n++; i=2;}    
    }
    return n;
}

int main() {
	int a, b, n, sum=0;
	do{
		printf("Unesite brojeve A i B: ");
		scanf ("%d %d", &a, &b);
		if (a<=0) {printf ("A nije prirodan broj.\n");continue;}
		if (a>b || a==b)  {printf ("A nije manje od B.\n");continue;}
		if (b<=0) {printf ("B nije prirodan broj.\n");continue;}
	}while (a<=0 || b<=0 || a>b || a==b);
	n=daj_prost();
	
	
	do{
	   n=daj_prost();     
	}while(n<=a);
	sum+=n;
	if (n>=b) sum-=n;
	
	for (n=0;n<=b;n++){
	    n=daj_prost();
	    sum+=n;
	    if (n>=b) sum-=n;
	}
	
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, sum);
	return 0;
}
