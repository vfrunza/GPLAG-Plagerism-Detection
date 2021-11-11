#include <stdio.h>
#include <stdlib.h>
int main()
{
  int n,i,j;
 unos:
	printf("Unesite broj n: ");
	scanf("%d",&n);
	if(n<1){
	  printf("Pogresan unos\n"); goto unos;
	}
  for(i=0;i<n;i++){
    for(j=0;j<4*n;j++){
       if(i==j || j==2*n-2-i || j==2*n-2+i || j==4*n-4-i)
            printf("*");
        else printf(" ");
    }

    printf("\n");
  }
  return 0;
}
