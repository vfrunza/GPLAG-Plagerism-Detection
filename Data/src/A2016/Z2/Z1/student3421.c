#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int br, posljednjav, ppv, novibr=0,k=0;
	printf("Unesite broj: ");
	scanf("%d",&br);
	
	if(br<0){
		br=abs(br);
	}
	
	while(br>=10)
	{
		posljednjav = br%10;
		ppv = (br/10)%10;
		novibr = abs(posljednjav-ppv)*pow(10, k)+novibr;
		k++;
		br = br/10;
		
	}
	
	printf("%d", novibr);
	
	return 0;
}
