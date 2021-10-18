#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main (){
	int x,a,b,y,z,br=0;
    int br1=0;
	int n=0;

	
	printf("Unesite broj: ");
	scanf("%d",&x);
	
	x=abs(x);
	z=x;
	
	while(z!=0)
	{
		z/=10;
		br++;
	}

	br--;

	while(x!=0 && br1!=br){
		
		a=x%10;
		x=x/10;
		b=x%10;
		y=abs(a-b);
		
		n+=y*pow(10,br1);
		br1++;
		
	}
	printf("%d",n);
	return 0;
	
}