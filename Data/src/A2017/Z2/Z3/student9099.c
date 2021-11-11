#include <stdio.h>

int main() {
	int mat1[100][100];
	int mat2[100][100];
	int niz1[1000]={0},niz2[1000]={0};
	int i,j;
	int a,b,c,d;
	int br=0,br2=0;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d", &a,&b);
	printf("Unesite clanove matrice A: ");
	for(i=0; i<b; i++){
		for(j=0;j<a;j++){
			scanf("%d", &mat1[i][j]);
		}
	}

	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d", &c,&d);
	printf("Unesite clanove matrice B: ");
	for(i=0; i<d; i++){
		for(j=0; j<c; j++){
			scanf("%d", &mat2[i][j]);
		}
	}
	
	if(b==c && a==d){
		for(i=0; i<b; i++){
			for(j=0; j<a; j++){
				niz1[br]=mat1[i][j];
				br++;
				
			}
		}
		br=0;
		for(j=c-1; j>=0; j--){
			for(i=0; i<d; i++){
				niz2[br]=mat2[i][j];
				br++;
			}
		}
	
	
		for(i=0; i<br; i++){
				if(niz1[i]==niz2[i]) br2++;
			
			}
		
			if(i==br2){ printf("DA");
			printf("\n");
			}
			else {printf("NE");
			printf("\n");
			}
	}
		
	else {printf("NE");
	printf("\n");
	}
	

	

	
	
	
	return 0;
}
