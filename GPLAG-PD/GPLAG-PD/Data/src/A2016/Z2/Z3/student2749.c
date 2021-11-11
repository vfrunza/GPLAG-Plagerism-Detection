#include <stdio.h>

int main() {
	int n, i, j,tacke_x[20]={0},tacke_y[20]={0};
	int matrica[20][20];
	for(i = 0; i <= 19; i++){
		for(j = 0;j <= 19; j++){
			matrica[i][j] = 32;
		}
	}

	/*scanf("%d",&n);*/
	do{
		printf("Unesite broj tacaka: ");
		scanf("%d",&n);
		if(n <= 0 || n > 10){
			printf("Pogresan unos\n");
			continue;
		}else{
			break;
		}
	}while(1);
	if(n <= 0 || n > 10) printf("Pogresan unos");
		for(i = 0; i < n; i++){
			printf("Unesite %d. tacku: ",i+1);			
			scanf("%d %d",&tacke_y[i],&tacke_x[i]);
			if(tacke_y[i] < 0 || tacke_x[i] < 0 || tacke_y[i] >= 20 || tacke_x[i] >= 20){
				printf("Pogresan unos\n");
				i--;
				continue;
			}
		}
		for(i = 0; i < n; i++) {
			matrica[tacke_y[i]][tacke_x[i]] = 42;
		}
		/*	for(k =0; k <= 19; k++){	
					for(i = 0; i <= 19; i++){
						for(j = 0; j <= 19; j++){
							if(i == tacke_x[i] || j == tacke_y[j]) matrica[i][j] = '*';
							else  matrica[i][j] = 'k';
						}
						printf("\n");
					}
				}*/
				for(i = 0; i <= 19; i++){
					for(j = 0;j <= 19; j++){
						printf("%c", matrica[j][i]);
					}
					printf("\n");
				}
	
	return 0;
}
