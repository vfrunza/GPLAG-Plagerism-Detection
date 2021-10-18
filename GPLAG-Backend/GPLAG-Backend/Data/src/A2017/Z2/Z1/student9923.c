#include <stdio.h>
#include <stdlib.h>
int main() { 
	int e,d,br=0,broj1,broj2,zbir=0,kon=0,i;
	printf("Unesite broj: ");
	scanf("%d", &e);
	if(e>0 && e<10) {
		printf("0");
		return 0;
	}
	d=e;
	while(e!=0) {
		e/=10;
		br++;
	}
	
for(i=0;i<br-1;i++) {
	broj1=d%10;
	d/=10;
	broj2=d%10;
	zbir+=abs(broj1-broj2);
	zbir*=10;
}
zbir/=10;
for(i=0;i<br-1;i++) {
	kon+=zbir%10;
	kon*=10;
	zbir/=10;
}
kon/=10;
	printf("%d",kon);

	return 0;
}
