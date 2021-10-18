/*#include <stdio.h>

int main() {

int n,i,j;

do{
	printf("Unesite broj N: ");
	scanf("%d",&n);
	if(n<8 || n%4!=0)
	printf("Neispravno N!");
	printf("\n");
}
while(n<8 || n%4!=0);

for(i=0; i<n/2; i++){
	for(j=0; j<n/2; j++){
		if(j==i)
		printf("\\");
		else if(j==n/2-1-i)
		printf("/");
		else
		printf(" ");
	}
	for(j=0; j<n/2; j++){
		if(i==0 || i==n/2-1){
			if(j==0 || j==n/2-1)
			printf("+");
			else printf("-");}

		else if(j==0 || j==n/2-1){
			printf("|");
		}
		else printf(" ");
		}
		printf("\n");
	}

for(i=0; i<n/2; i++){
	for(j=0; j<n/2; j++){
		if(i==0 || i==n/2-1){
			if(j==0 || j==n/2-1)
			printf("+");
			else printf("-");}

		else if(j==0 || j==n/2-1){
			printf("|");
		}
		else printf(" ");
		}

		for(j=0; j<n/2; j++) {
			if(i==n/4 || i==n/4-1){
				if(j==n/4 || j==n/4-1)
				printf("+");
				else printf("-");}
			else if(i!=n/4 || i!=n/4-1){
				if(j==n/4 || j==n/4-1)
				printf("|");
				else printf(" ");}
			}
		printf("\n");
}
	return 0;
}*/
#include <stdio.h>
int main()
{
	int n, i, j;
	do {
		printf("Unesite broj N: ");
		scanf("%d", &n);
		if(n % 4 != 0 || n < 8) printf("Neispravno N!\n");
	} while(n % 4 != 0 || n < 8);
	printf("\n");

	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(i < n / 2 && j < n / 2) {
				if(i == j) printf("\\");
				else if(j == n / 2 - i - 1) printf("/");
				else printf(" ");
			}

			if(i < n / 2 && j >= n / 2) {
				if((i == 0 && (j == n / 2 || j == n - 1)) || (i == n / 2 - 1 && (j == n / 2 || j == n - 1))) printf("+");
				else if(i == 0 || i == n / 2 - 1 ) printf("-");
				else if(j == n / 2 || j == n  - 1) printf("|");
				else printf(" ");
			}
			if(i >= n / 2 && j < n / 2) {
				if((i == n / 2 && (j == 0 || j == n / 2 - 1)) || (i == n - 1 && (j == 0 || j == n / 2 - 1))) printf("+");
				else if(i == n / 2 || i == n - 1 ) printf("-");
				else if(j == 0 || j == n / 2  - 1) printf("|");
				else printf(" ");
			} else if(i >= n / 2 && j >= n / 2) {
				if(((i == n / 2 + n / 4 && (j == n / 2 + n / 4 || j == n / 2 - 1 + n / 4)) || (i == n / 2 - 1 + n / 4 && (j == n / 2 + n / 4 || j == n / 2 - 1+ n / 4)))) printf("+");
				else if(j == n / 2 + n / 4 || j == n / 2 - 1 + n / 4) printf("|");
				else if(i == n / 2 - 1 + n / 4 || i == n /2 + n / 4) printf("-");
				else printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
