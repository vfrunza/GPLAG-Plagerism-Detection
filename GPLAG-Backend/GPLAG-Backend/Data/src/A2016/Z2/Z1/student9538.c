#include <stdio.h>
#include<stdlib.h>

int main() {
	int n,varijabla1,varijabla2,br=0;
	printf("Unesite broj: ");
	scanf("%d",&n);
	int w=1;
	while(n!=0) {
		varijabla1=abs(n)%10;
		n=abs(n)/10;
		if(n==0) break;
		varijabla2=abs(n)%10;
		br=br+(abs(varijabla1-varijabla2)*w);
		w=w*10;}
		printf("%d",br);
	return 0;
}
