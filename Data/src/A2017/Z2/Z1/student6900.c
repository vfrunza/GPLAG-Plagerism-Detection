#include <stdio.h>

int main() {
	int n,i,j,k,br=0;
	
	do
	{
		printf("Unesite broj N: ");
		scanf("%d",&n);
		if ((n%4!=0)||(n<8))
		printf("Neispravno N!");
		printf("\n");
	}while((n%4!=0)||(n<8));
	
	for (j = 0; j < n/4; j++) {
		//  \  /
		for (k = 0; k < j; k++) {
			printf(" ");
		}
		printf("\\");
		
		for (k = br; k < (n/2)-2 ; k++) {
			printf(" ");
		}
		br+=2;
		printf("/");
		
		
		for (k = 0; k < j; k++) {
			printf(" ");
		}
		
		//  +---+
		for (k = 0; k < n/2; k++) {
			if((j==0) &&((k==0)||(k==(n/2)-1)))
			printf("+");else
			if ((j!=0)&&((k==0)||(k==(n/2)-1)))
			printf("|");else
			if (j==0)
			printf("-");else
			printf(" ");
		}
		
		printf("\n");
		
	}
			br=(n/2)-2;
	for (j = 0; j < n/4; j++) {
		
		
		//  \  /
		for (k = j; k < (n/4)-1; k++) {
			printf(" ");
		}
		
		printf("/");
	
		
		for (k = br; k < (n/2)-2 ; k++) {
			printf(" ");
		}
		br-=2;
		printf("\\");
		
		
		for (k = j; k < (n/4)-1; k++) {
			printf(" ");
		}
		
	
		//  +---+
			for (k = 0; k < n/2; k++) {
			if((j==(n/4)-1) &&((k==0)||(k==(n/2)-1)))
			printf("+");else
			if ((j!=(n/4)-1)&&((k==0)||(k==(n/2)-1)))
			printf("|");else
			if (j==((n/4)-1))
			printf("-");else
			printf(" ");
		}
		
		printf("\n");
		
	}
	
	for (i = 0; i < n/2; i++) {
		for (k = 0; k < n; k++) {
			if (((i==0)&&((k==0)||(k==(n/2)-1)))||((i==(n/2)-1)&&((k==0)||(k==(n/2)-1)))||((i==(n/4)-1)&&((k==(3*n/4)-1)||(k==(3*n/4))))||((i==(n/4))&&((k==(3*n/4)-1)||(k==(3*n/4)))))
			printf("+");
			else
			if (((i==0)&&(k>0)&&(k<(n/2)-1))||((i==(n/2)-1)&&(k>0)&&(k<(n/2)-1))||((i==(n/4)-1)&&(k!=(3*n/4)-1)&&((k>(n/2)-1)&&(k!=(3*n/4))))||((i==(n/4))&&((k!=(3*n/4)-1)&&(k>(n/2)-1)&&(k!=(3*n/4)))))
			printf("-");
			else
			if (((((i<(3*n/8)-1))||(i>(n/4)-1))&&((k==((3*n)/4)-1)||(k==((3*n)/4))))||(((i!=0)&&(i!=(n/2)-1))&&(k==0)||(k==(n/2)-1)))
			printf("|");
			else
			printf(" ");
			
		}
		printf("\n");
	}
	
	return 0;
}
