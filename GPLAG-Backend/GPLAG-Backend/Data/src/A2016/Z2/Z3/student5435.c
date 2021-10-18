#include <stdio.h>

int main() {
int i,j,n,a,b;
char mat[20][20];



for(i=0;i<20;i++){
	for(j=0;j<20;j++){
		mat[i][j]=1;
	}
}


for(;;){
printf("Unesite broj tacaka: ");
scanf("%d",&n);
if(n>10 || n<=0){printf("Pogresan unos\n");}
else break;
}

for(i=0;i<n;i++){
	printf("Unesite %d. tacku: ",i+1);
	scanf("%d %d",&a,&b);
	if(a<0 || a>19 || b<0 || b>19){printf("Pogresan unos\n");i--;}
	else {mat[b][a]='*';}
	
}
for(i=0;i<20;i++){
	for(j=0;j<20;j++){
	if(mat[i][j]=='*')   	{printf("*");}
	else printf(" ");
}
	printf("\n");
}
	return 0;
}
