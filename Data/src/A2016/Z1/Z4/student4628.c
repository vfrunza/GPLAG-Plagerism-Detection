#include <stdio.h>

int main() {
int i, j, n;

do{
    printf("\nUnesite broj n: ");
    scanf("%d", &n);
    if(n<=0 || n>50)
    printf("Pogresan unos");
   
}while(n<=0 || n>50);

 
if(n==1)
printf("***");

else{

int a=0, sredina=2*n-1, kraj=4*n-3;
for(i=0; i<n; i++){
    for(j=0; j<4*n-3; j++){
        if(j==a || j==sredina-a-1 || j==sredina+a-1 || j==kraj-a-1)
        printf("*");
        else 
        printf(" ");
    }
printf("\n");
a++;

}
}
	return 0;
}
