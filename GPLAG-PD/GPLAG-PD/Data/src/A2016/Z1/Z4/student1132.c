#include <stdio.h>

int main() {
	int i,j,N=0,r1,r2;
	while(1)
	{
		printf("Unesite broj n: ");
		scanf("%d",&N);
		if(N<1||N>50) printf("Pogresan unos\n");
		else break;
	}
if(N==1) printf("***");
else
{
	r1 = 2*(N-1)-1;
	r2 = 0;
	for(i = 0;i<N;i++)
	{
		for(j=0;j<r2;j++) printf(" ");
		printf("*");
		if(r1>0) {for(j=0;j<r1;j++) printf(" ");printf("*");}
		if(r2>0) {for(j=0;j<2*r2-1;j++) printf(" ");printf("*");}
			if(r1>0) {for(j=0;j<r1;j++) printf(" ");printf("*");}
			printf("\n");
			r1-=2;
			r2++;
	}
	
}
	
	return 0;
}
