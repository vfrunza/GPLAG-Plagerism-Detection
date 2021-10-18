#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
int main() {
	int n,fin=0;
	int k=1;
	printf("Unesite broj: ");
	scanf("%d",&n);
	n=abs(n);
	while(n!=0){
		int temp,temp2;
		if(n==0) continue;
		temp=n%10;
		n/=10;
		if(n==0) break;
		temp2=n%10;
		fin+=abs(temp-temp2)*k;
		k*=10;
		
	}
	printf("%d",fin);
	return 0;
}
