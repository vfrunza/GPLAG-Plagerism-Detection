#include <stdio.h>

int main() {
	int Z;
	int m, n;
	do {
		printf("Unesite broj N:");
		scanf("%d", &Z);
		if (Z<8 || Z%4!=0){printf("Neispravno N!\n");}
	} while (Z%4!=0 || Z<=7);
	printf("\n");
	for(m=1;m<=Z;m++){
		for(n=1;n<=Z;n++){
			if((m==(Z/2)+1 && n==1) || (m==Z && n==1) || (n==Z && m==1) || (n==(Z/2)+1 && m==1) || (m==(Z/2) && n==(Z/2)+1) || (m==(Z/2)&& n==Z) || (m==(Z/2)+1 && n==(Z/2)) || (m==Z && n==(Z/2))){
				printf("+");
			}
			else if (m<=Z/2 && n<=Z/2 && m==n){
				printf("\\");
			}
			else if (m<=Z/2 && n<=Z/2 && (m+n)==(Z/2)+1){
				printf("/");
			}
			else if ((n>(Z/2) && m==1) || (n>(Z/2) && m==Z/2) || (n<Z/2 && m==(Z/2)+1) || (n<Z/2 && m==Z)){
				printf("-");
			}
			else if((m>(Z/2) && n==1) || (m>(Z/2) && n==Z/2) || (n==(Z/2)+1 && m<Z/2) || (n==Z && m==Z/2)){
				printf("|");
			}
			else if((m==Z/2+Z/4 && n==Z/2+Z/4) || (m==Z/2+Z/4 && n==Z/2+Z/4+1) || (m==Z/2+Z/4+1 && n==Z/2+Z/4) || (m==Z/2+Z/4+1 && n==Z/2+Z/4+1)){
				printf("+");
			}
			else if ((m>=Z/2+1 && n==Z/2+Z/4) || (m>=Z/2+1 && n==Z/2+Z/2+1)){
				printf("|");
			}
			else if ((m==Z/2+Z/4 && n>Z/2) || (m==Z/2+Z/4+1 && n>Z/2)){
				printf("-");
			}
			else printf(" ");
		}
		printf("\n");
	}
	
	
	return 0;
}
