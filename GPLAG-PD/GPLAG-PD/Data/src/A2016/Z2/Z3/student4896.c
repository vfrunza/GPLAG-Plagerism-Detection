#include <stdio.h>

int main() {
char mat[20][20];
int n,a,b,i,j,k;
do{
printf("Unesite broj tacaka: ");
scanf("%d",&n);
	if(n<=0 || n>=11)printf("Pogresan unos\n");
}
while(n<=0 || n>=11);
for(i=0;i<20;i++){
for(j=0;j<20;j++){mat[i][j]=' ';}}
for(k=0;k<n;k++){
	printf("Unesite %d. tacku: ",k+1);
	scanf("%d %d",&a,&b);
	if(a>19 || a<0 || b>19 || b<0){printf("Pogresan unos\n");
	k--;continue;}
	mat[b][a]='*';
}
for(i=0;i<20;i++){
for(j=0;j<20;j++){printf("%c",mat[i][j]);}
printf("\n");

}
return 0;}