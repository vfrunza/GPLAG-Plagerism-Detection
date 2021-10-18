#include <stdio.h>

#define limit 10

int main() {
	
	int br_kol, br_red, kol_w;
	
	/*Unos*/
	do{
		printf("Unesite broj redova: ");
		scanf("%d", &br_red);
	}while(br_red <= 0 || br_red > limit);
	
	do{
		printf("Unesite broj kolona: ");
		scanf("%d", &br_kol);
	}while(br_kol <= 0 || br_kol > limit);
	
	do{
		printf("Unesite sirinu jedne kolone: ");
		scanf("%d", &kol_w);
	}while(kol_w <= 0 || kol_w > limit);
	
	int width = br_kol * (kol_w + 1) + 1;
	int height = br_red * 2 + 1;
	
	int i, j, br;
	
	for(i = 0; i < height; i++){
		
		br = 0;
		
		for(j = 0; j < width; j++){
			if(br == kol_w + 1) br = 0;
			
			if(br == 0){
				if(i%2==0) printf("+");
				else printf("|");
			}
			else{
				if(i%2==0) printf("-");
				else printf(" ");
			}
			
			br += 1;
			
		}
		
		printf("\n");
		
	}
	
	return 0;
}
