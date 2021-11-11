#include <stdio.h>
#include <math.h>

int main() {
	int k=0, i, br, br1, br2, n;
	printf("Unesite broj: ");
	scanf("%d", &n);
	if(n<0){
	n=fabs(n);
	}
	if(n<10){
		n=0;
	}
	for(i=0; i<100; i++){
		br1=n%10;
		br2=(n/10)%10;
		br=br1-br2;
		if(br<0){
			br=fabs(br);
		}
		k+=br*pow(10,i);
		n/=10;
		if(n<10)
		break;
		}
		printf("%d", k);
	return 0;
}
