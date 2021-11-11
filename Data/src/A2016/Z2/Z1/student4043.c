#include <stdio.h>
#include <stdlib.h>

int main() {
	int br,c1,c2,br2=0,temp=0;
	printf("Unesite broj: ");
	scanf("%d", &br);
	br=abs(br);
	while(br!=0){
		c1=br%10;
		/*printf("%d\n", c1);*/
		c2=(br/10)%10;
		/*printf("%d\n", c2);*/
		br/=10;
		br2+=abs(c1-c2);
		br2*=10;
	}
	br2/=100;
	while(br2!=0){
		c1=br2%10;
		temp+=c1;
		temp*=10;
		br2/=10;
	}
	br2=temp/10;
	printf("%d", br2);
	/*printf("Zadaća 2, Zadatak 1");*/
	return 0;
}
