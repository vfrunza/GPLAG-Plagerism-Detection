#include <stdio.h>
#include <math.h>

int main() {
	
	int broj;
	printf("Unesite broj: ");
	scanf("%d",&broj);
	if(broj/10==0)  {printf("%d",broj-broj); return 0;}
	if(broj<0) broj*=-1;
	int i=0;
    int z=0;
    while(broj>0)
    {
    	
    	int a=broj%10;
    	broj/=10;
    	i++;
    	int b=broj%10;
    	int k=a-b; 
    	if(k<0) k*=-1;
        z=(z+pow(10,i-1)*k);
    	if(broj/10==0) break;
    }
	
	printf("%d",z);
	return 0;
}
