#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
int isprime(int n) {
	int i, root;
	root=(int)sqrt(n);
	if(n==2) return TRUE;
	for(i=3; i<=root; i+=2) {
		if((n%i)==0) {
			return FALSE;
		}
	}
	return TRUE;
}
int daj_prost() {
	int n;
	static int last_prime=0;
	if(!last_prime) {
		last_prime=1;
		return 2;
	}
	for(n=last_prime+2; !isprime(n); n+=2);
	last_prime=n;
	return n;
}
int main() {
int i,sum=0, a=3, b=140;
do {
	printf("\nUnesite brojeve A i B: ");
	scanf("%d %d",&a,&b);
	if(a<=0) printf("A nije prirodan broj.");
else if(a>=b) printf("A nije manje od B.");
}
while(a<=0 || b<=0 || a>=b);
while((i=daj_prost())<b) {
	if(i>a) {
		sum+=i;
	}
}
printf("Suma prostih brojeva izmedju %d i %d je %d.\n", a,b,sum);
	return 0;
}
