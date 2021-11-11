#include <stdio.h>
#include<math.h>
#include<stdlib.h>

int main() {
	int n;
	int rezultat=0;
	int x,y;
	int brojac=0;
	printf("Unesite broj: ");
	scanf("%d", &n);
	
	n=abs(n);
	
	if(n<10)
	{
		printf("%d", rezultat);
		return 0;
	}
	   while(n>10){
	   	x=n%10;
	   	n/=10;
	   	y=n%10;
	   	rezultat+=abs(x-y)*pow(10,brojac);
	   	brojac++;
	   }
	   printf("%d", rezultat);
	   
	    return 0;
}
