#include <stdio.h>
int main() {
int i,j,n;
unos: printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n<1 || n>50)
	{
		printf("Pogresan unos\n");
		goto unos;
	}
if(n==1){
	printf("**");
}

for (i=0; i<n; i++) {
for(j=0;j<=4*n-4;j++){
if(i==j || j==2*n-2-i || j==2*n-2+i || j==4*n-4-i){
printf("*");}

	else {
		printf(" ");
}}
	printf("\n");
}
return 0;
}
