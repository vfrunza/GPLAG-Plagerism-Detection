#include <stdio.h>
int daj_prost()  {
	static int i=2,pr_br=0;
	int j,m,n;
	
	for(i;;i++) {
		if (i==2) {
				i++;
				m=i-1;
				return m;
		}
		for(j=2; j<i; j++) {
			if(i%j==0) {
			pr_br=0;
			break;
		}
		else 
				pr_br=1;
	}
	if(pr_br==1) {
		i++;
		n=i-1;
		return n;
	   }
	}
}

int main() {
	int a,b,x=0,suma,i;
	suma=0;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d",&a,&b);
		if (a<=0)
			printf("A nije prirodan broj.\n");
		else if (a>=b)
			printf("A nije manje od B.\n");
		} while (a<=0 || a>=b);
	
	do {
	x=daj_prost();
	} while (x<a);
		
	for (i=a; i<b; i++)  {
		if((x>a) && (x<b))
		suma+=x;
		x=daj_prost();
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",a,b,suma);
	
	return 0;
}
