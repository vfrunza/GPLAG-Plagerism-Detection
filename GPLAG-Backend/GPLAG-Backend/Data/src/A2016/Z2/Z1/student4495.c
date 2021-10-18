#include <stdio.h>
#include <math.h>
int main() {
	int a,suma=0,k=1,x,y;
		
	printf("Unesite broj: ");
	scanf("%d",&a);
	a= fabs(a);
	
	
	
	do{
		if(a<10 && a>0){
		break;
	}
		x=a%10;
		a=a/10;
		y=a%10;
		suma=suma+(fabs(x-y))*k;
		k*=10;
	}while(a>9);
	printf("%d",suma);
		
		
	return 0;
}
