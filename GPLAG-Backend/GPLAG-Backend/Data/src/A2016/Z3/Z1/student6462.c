#include <stdio.h>

int daj_prost(){
	static long x=2;
	long i, j, prost=1;
	for(i=x; i<=1000000; i++){
		for(j=2; j<=i/2; j++){
			if(i%j==0){
				prost=0; 
				x++;
				break;
			}
		}
		if(prost==1){
		x++;
		break; }
		prost=1;
		
	}
	return i;
	
}

int main() {
	long a, b, i, j, k, br1=0, br2=0, prost=1 ;
	long suma=0;
	for(k=0; k<1000; k++){
		printf("Unesite brojeve A i B: ");
		scanf("%ld %ld", &a, &b);
		if(a>=b) printf("A nije manje od B.\n");
		else if(a<=0) printf("A nije prirodan broj.\n");
		else if(b<=0) printf("B nije prirodan broj.\n"); 
		else {
			for(i=2; i<=a; i++){
				for(j=2; j<=i/2; j++){
					if(i%j==0){
						prost=0;
						break;
					}
				}
				if(prost==1) br1++;
				prost=1;
			}
	
			for(i=a+1; i<b; i++){
				for(j=2; j<=i/2; j++){
					if(i%j==0){
						prost=0;
						break;
					}
				}
				if(prost==1) br2++;
				prost=1;
			}
	
			for(i=0; i<br1; i++){
				daj_prost();
			}
			for(i=br1; i<br2+br1; i++){
				suma+=daj_prost();
			}
			
			break;
		}
	}	

	printf("Suma prostih brojeva izmedju %ld i %ld je %ld.", a, b, suma);
	return 0;
}
