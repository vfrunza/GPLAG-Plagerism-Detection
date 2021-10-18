#include <stdio.h>
int daj_prost()   {
	int j;
	static int i=1;
	i++;
	for(j=2;j<i;j++) {
		if(i%j==0) {
			i++;
			j=2;
		}
	}
	return i;
}
	int main () {
		int a,b,i,x=0,p;
		do {
			printf ("\nUnesite brojeve A i B: ");
			scanf("%d %d",&a,&b);
			if(a<=0) {
				printf("A nije prirodan broj.\n");
			}
			else if (a>=b) {
				printf("A nije manje od B.\n");
			}
		}while (a<=0 || a>=b);
		
		for (i=0;i<b;i++) {
			p=daj_prost();
			if(p>a && p<b) {
				x=x+p;
			}
		}
		printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,x);
		return 0;
	}

