#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int a;
	int cifra;
	int rjes=0;
	int brojac=0;
	printf("Unesite broj: ");
	scanf("%d", &a);
	a=abs(a);
	if(a>=0 && a<=9)printf("0"); else {
		while(a){
			if(brojac!=0){
				rjes+=pow(10, brojac-1)*(abs((a%10)-cifra));
			}
			cifra=a%10;
			a/=10;
			brojac++;
		}
		printf("%d", rjes);
	}
	return 0;
}
