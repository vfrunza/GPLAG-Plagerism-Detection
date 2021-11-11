#include <stdio.h>
int daj_prost() {
  static int a=1;
  int i;
  a++;
  for(i=2; i<a; i++) 
 	if(a%i==0) {
 	return 0;
 	} 
 	return a;
 }
int main() {
	int a,b, i;
	int z=0;
	int c;
	pocetak:
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &a,&b);
	if(a<=0) {
		printf("A nije prirodan broj.\n");
		goto pocetak;
	}
	if(a>=b) {
		printf("A nije manje od B.\n");
		goto pocetak;
	}
	for(i=2; i<b; i++) {
		c=daj_prost();
		if(c>a && c<b) {
			daj_prost();
			z+=c;
			
		}
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.", a,b,z);

	return 0;
}