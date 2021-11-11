#include <stdio.h>

int main() {
	int M,N,mat1[100][100],mat2[100][100],mat3[100][100];
	int niz1[50],niz2[50],niz3[50];
	int nizBr1[50],nizBr2[50],nizBr3[50];
	int prekidac,pogodak;
	int ogranicenje1=0,ogranicenje2=0,ogranicenje3=0;
	int i,j,k,ima;
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
	}while(M>100 || N>100);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++)
		scanf("%d",&mat1[i][j]);
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++)
		scanf("%d",&mat2[i][j]);
	}
	printf("Unesite clanove matrice C: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++)
		scanf("%d",&mat3[i][j]);
	}
	prekidac=1;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(prekidac){
				prekidac=0;
				niz1[0]=mat1[i][j];
				ogranicenje1=1;
				nizBr1[0]=1;
			}else{
				pogodak=0;
				for(k=0;k<ogranicenje1;k++){
					if(mat1[i][j]==niz1[k]){
						nizBr1[k]++;
						pogodak=1;
					}
				}
				if(!pogodak){
					ogranicenje1++;
					niz1[k]=mat1[i][j];
					nizBr1[k]=1;
				}
			}
		}
	}
	prekidac=1;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(prekidac){
				prekidac=0;
				niz2[0]=mat2[i][j];
				ogranicenje2=1;
				nizBr2[0]=1;
			}else{
				pogodak=0;
				for(k=0;k<ogranicenje2;k++){
					if(mat2[i][j]==niz2[k]){
						nizBr2[k]++;
						pogodak=1;
					}
				}
				if(!pogodak){
					ogranicenje2++;
					niz2[k]=mat2[i][j];
					nizBr2[k]=1;
				}
			}
		}
	}
	prekidac=1;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(prekidac){
				prekidac=0;
				niz3[0]=mat3[i][j];
				ogranicenje3=1;
				nizBr3[0]=1;
			}else{
				pogodak=0;
				for(k=0;k<ogranicenje3;k++){
					if(mat3[i][j]==niz3[k]){
						nizBr3[k]++;
						pogodak=1;
					}
				}
				if(!pogodak){
					ogranicenje3++;
					niz3[k]=mat3[i][j];
					nizBr3[k]=1;
				}
			}
		}
	}
	if(ogranicenje1==ogranicenje2 && ogranicenje2==ogranicenje3);
	else {
		printf("NE");
		return 0;
	}
	for(i=0;i<ogranicenje1;i++){
		ima=0;
		for(j=0;j<ogranicenje2;j++){
			if(niz1[i]==niz2[j] && nizBr1[i]==nizBr2[j]){
				ima=1;
			}
		}
		if(ima);
		else {
			printf("NE");
			return 0;
		}
	}
	for(i=0;i<ogranicenje2;i++){
		ima=0;
		for(j=0;j<ogranicenje3;j++){
			if(niz2[i]==niz3[j] && nizBr2[i]==nizBr3[j]){
				ima=1;
			}
		}
		if(ima);
		else {
			printf("NE");
			return 0;
		}
	}
	for(i=0;i<ogranicenje1;i++){
		ima=0;
		for(j=0;j<ogranicenje3;j++){
			if(niz1[i]==niz3[j] && nizBr1[i]==nizBr3[j]){
				ima=1;
			}
		}
		if(ima);
		else {
			printf("NE");
			return 0;
		}
	}
	printf("DA");
	return 0;
}