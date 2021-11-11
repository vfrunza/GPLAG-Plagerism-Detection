#include <stdio.h>

int main() {
	int i,j,n;
	do{
		printf("Unesite broj N: ");
		scanf("%d", &n);
		if(!(n%4==0 && n>=8)) {
			printf("Neispravno N!");
		}
		printf("\n");
	} while (!(n%4==0 && n>=8));
	

	for(i=0;i<n/2;i++) {
// X
	if(i<(n/4)) {
//		printf("\n");
	for(j=0;j<i;j++) {
printf(" ");
	}
	printf("\\");
	for(j=n/4-1;j>i;j--) {
		printf("  ");
	}
	printf("/");
	for(j=0;j<i;j++) {
		printf(" ");
	}
	} else {
	//	printf("\n");
		for(j=n/2-1;j>i;j--) {
			printf(" ");
		}
		printf("/");
		for(j=n/4;j<i;j++) {
			printf("  ");
		}
		printf("\\");
		for(j=n/2-1;j>i;j--) {
			printf(" ");
		}
	}

// kv

	if(i==0 || i == n/2-1) {
		printf("+");
		for(j=0;j<n/2-2;j++) {
			printf("-");
		}
		if(n!=1) {
			if(i!=n/2-1) { printf("+\n"); }else{ printf("+");}
		} else {
			printf("\n");
		}
	} else {
		printf("|");
		for(j=0;j<n/2-2;j++) {
			printf(" ");
		}
		if(n!=1){printf("|\n");} else {printf("\n");
	}
}
}
printf("\n");
for(i=0;i<n/2;i++) {
//kv
if(i==0 || i == n/2-1) {
	printf("+");
	for(j=0;j<n/2-2;j++) {
		printf("-");
	}
	printf("+");
}else{
	printf("|");
	for(j=0;j<n/2-2;j++) {
		printf(" ");
	}
	printf("|");
}
//+
if(i==n/4 || i==n/4-1) {
	for(j=0;j<n/4-1;j++) {
		printf("-");
	}
	printf("++");
	for(j=0;j<n/4-1;j++) {
		printf("-");
	} 
	}else {
		for(j=0;j<n/4-1;j++) {
			printf(" ");
		}
		printf("||");
		for(j=0;j<n/4-1;j++) {
			printf(" ");
		}
	}
printf("\n");
//end
}




	return 0;
}
