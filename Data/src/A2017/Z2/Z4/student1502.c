#include <stdio.h>
#define vis 100
#define sir 100

int main() {

	int i,j,a[vis][sir], b[vis][sir], c[vis][sir],m,n;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d", &m,&n);
		
	}while((m<0||m>100)||(n<0||n>100));
	
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d", &a[i][j]);
			
		}
	}
	
	
	
	printf("Unesite clanove matrice B: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d", &b[i][j]);
		}
	}
	
	
	printf("Unesite clanove matrice C: ");
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d", &c[i][j]);
		}
	}
	
/*	
	for(i=0;i<m;i++){
		for(j=0;j<sir;j++){
			if(mat[i+1][j+1]==mat[i][j]) count++;
		}
	}


*/
















	return 0;
}
