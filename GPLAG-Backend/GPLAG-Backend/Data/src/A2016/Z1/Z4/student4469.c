#include <stdio.h>
#include <math.h>

int main() {
	
	int a,b,c;
	printf("Unesite broj n: ");
    scanf("%d", &a);

while (a<=0 || a>50 ) {
	printf("Pogresan unos");
	printf("\nUnesite broj n: ");
	scanf("%d", &a);
}

if (a==1) {
	printf("***");
}

else {
	
	for (b=0;b<a;b++)
	{
		for (c=0;c<4*a-3;c++) {
			if (b==c)
			printf("*");
			
			else if(b==((2*a)-2-c))
			printf("*");
			
			else if(b==(c-(2*a)+2))
			printf("*");
			
			else if(b==(4*a)-4-c)
			printf("*");
			
			else {
				printf(" ");
			}
		}
		
		printf("\n");
	}
	
	
	
}



	
	return 0;
}
