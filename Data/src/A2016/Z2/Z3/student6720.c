#include <stdio.h>
int main() {

int n, i, j, k, x[20], y[20], mat[20][20]={{0}};

do{
printf("Unesite broj tacaka: ");
scanf("%d", &n);
if(n<=0 || n>10)
printf("Pogresan unos\n");
}while(n<=0 || n>10);


for(k=0; k<n; k++){
printf("Unesite %d. tacku: ",k+1);
scanf("%d %d",&x[k],&y[k]);
if((x[k]<0 || x[k]>19) || (y[k]<0 || y[k]>19)){
printf("Pogresan unos\n"); 
k--;
}
} 

for(k=0; k<n; k++){
    for(i=0; i<20; i++){
        for(j=0; j<20; j++){
            if(i==y[k] && j==x[k])
            mat[i][j]=1;
       }
   }
}

for(i=0; i<20; i++){
    for(j=0; j<20; j++){
        if(mat[i][j]==1)
        printf("*");
        else 
        printf(" ");
    }
    printf("\n");
}
	return 0;
}
