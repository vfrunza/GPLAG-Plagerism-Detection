#include <stdio.h>

int main() {
	int mat[20][20]={0};
	int n,i,a,b,j;
	
	printf("Unesite broj tacaka: ");
	scanf("%d",&n);
	for (i=0;i<n;i++)
	if(n<1 || n>10) {
	printf("Pogresan unos\nUnesite broj tacaka: ");
	scanf("%d",&n);
	
}
for(i=0;i<n;i++)
{
printf("Unesite %d. tacku: ",i+1);
scanf("%d %d",&a,&b);

while(a<0 || a>19 || b>19 || b<0 ) {
	
	printf("Pogresan unos\nUnesite %d. tacku: ",i+1);
	scanf("%d %d",&a,&b);
}
mat[b][a]++;
}

for(i=0;i<20;i++) {
for(j=0;j<20;j++) {
	if(mat[i][j]==0)
		printf(" ");
	else 
		printf("*");
	
}
printf("\n");
}
return 0;
}