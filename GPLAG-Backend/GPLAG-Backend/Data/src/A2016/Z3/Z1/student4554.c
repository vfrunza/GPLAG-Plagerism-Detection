#include <stdio.h>
int daj_prost ();
int main() {
	int a, b, y, suma=0, j, i;
	do {
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &a, &b);
	if(a>=b) printf("A nije manje od B.\n");
	if(a<=0) printf("A nije prirodan broj. \n");
    } while(a>=b || a<=0);
    for(;;) {
       y=daj_prost();
      	if(y>=b) break;
	    if(y>a) suma+=y;
        }
    printf("Suma prostih brojeva izmedju %d i %d je %d.", a, b, suma);
	return 0;
    }

    int daj_prost() {
	static int i=2;
	int j;
	if(i==2) {
		i++;
		return 2;
	}
	for(j=2; j<i; j++)
	    if(i%j==0) {
		  i++;
		  j=1;
        }
       {
   i++;
   return (i-1);
}}

