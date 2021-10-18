#include <stdio.h>
#define broj 100


int main() {
int m,n,cirkularna=1,teplicova=1, i=0,j=0;
double matrica[100][100];
do {
printf("Unesite M i N: ");
scanf("%d %d",&m , &n);
if(m<=100 && m>0 && n<=100 && n>0)
break;
printf("Pogresan unos!\n");}
while(m>100||m<1 || n>100 || n<1);


printf("Unesite elemente matrice: ");
for(i=0;i<m;i++){
	for(j=0;j<n;j++){
		scanf("%lf", &matrica[i][j]);
	}
}
for(i=1;i<m;i++){
	for(j=0;j<n;j++){
		if(j!=0){
			if(matrica[i][j]!=matrica[i-1][j-1]){
			cirkularna=0;
			teplicova=0;
		}
	}

	else {
	if(matrica[i][j]!=matrica[i-1][n-1])
	cirkularna=0;
}
}}

if(cirkularna==1)
printf("Matrica je cirkularna");
else if (teplicova==1 && cirkularna ==0)
printf("Matrica je Teplicova");
else if (teplicova==0 && cirkularna==0)
printf("Matrica nije ni cirkularna ni Teplicova");
return 0;
	
}



