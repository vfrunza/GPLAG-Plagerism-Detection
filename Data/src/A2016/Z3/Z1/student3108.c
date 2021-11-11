#include <stdio.h>

long int daj_prost() {
	int i;
	static int prost=1;
	prost++;
	for(i=2; i<prost; i++)
	if(prost%i==0) {
		prost++;
		i=1;
		
	}
	return prost;
}

int main() {
	int a, b, suma=0, broj;
	do {
		printf("Unesite brojeve A i B: ");
		scanf("%d %d", &a, &b);
		if(a>=b) {
			printf("A nije manje od B.\n");
			continue;}
		else if(a<=0) {
				printf("A nije prirodan broj.\n");
				continue; }
				else 
				break;
			}
			while(1); {
				for(;;) {
					broj=daj_prost();
					if(broj<=a)
					continue;
					else if(broj>=b)
					break;
					else
					suma += broj;
				}
				
			
			
		}
	
    printf("Suma prostih brojeva izmedju %d i %d je %d.", a,b,suma);  
	return 0;
}
