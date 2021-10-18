#include <stdio.h>

int main() {
	int i, j, n, x, y;
	int mat[20][20]={0};
	

	//unos
	do {
		printf("\nUnesite broj tacaka: ");
		scanf("%d", &n);
		if(n<=0 || n>10) {printf("Pogresan unos");}
		
	} while(n<=0 || n>10);  
	
	i=0;
  while(i<n){
        printf("Unesite %d. tacku: ", i+1);
    scanf("%d %d", &x, &y);
    if(x<0 || x>19 || y<0 || y>19 ){		
        printf("Pogresan unos\n");
        i--;
    } else 
    mat[x][y]=42; //matrica koja treba da pamti koordinate
   i++;
  }

  for(i=0; i<20; i++) {
		for(j=0; j<20; j++) {
			if(mat[j][i] == 42)  printf("*"); 
			else printf(" ");
		}
		printf("\n");
	}
	

	return 0;
}
