#include <stdio.h>

int daj_prost()
{
	int j,k=1;
	static int i=1;
	do {
		i++;
		if(i==2)
		k=1;
		else
			for(j=2; j<i; j++) {
				if(i%j==0) {
					k=0;
					break;
				} else {
					k=1;
					continue;
				}
			}
	} while(k==0);
	return i;
}

int main()
{
	int a=0,b=0,suma=0;
	int x;
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &a, &b);
	for(;;) {
		if(a<=0) {
			printf("A nije prirodan broj.");
			printf("\nUnesite brojeve A i B: ");
			scanf("%d %d",&a,&b);
			continue;
		}
		if(a>=b) {
			printf("A nije manje od B.");
			printf("\nUnesite brojeve A i B: ");
			scanf("%d %d",&a,&b);
			continue;
		} else
			break;
	}
	for(;;) {
		x=daj_prost();
		if(x>a && x<b)
			suma+=x;
		else if(x>b)
			break;
		else continue;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	return 0;
}
