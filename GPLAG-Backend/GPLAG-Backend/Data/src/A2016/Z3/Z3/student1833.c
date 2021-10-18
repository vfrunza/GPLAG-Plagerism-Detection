#include <stdio.h>
int br_redova=1, br_kolona=5;
//int mat[200][200] = {{1,2,1,2,3}};
int mat[200][200];
void ispisi(int mat[][sizeof(mat[0])/sizeof(*mat[0])], int br_redova){
	int i,j;
	for(i=0;i<br_redova;i++){
        for(j=0;j<br_kolona;j++){
        	if(mat[i][j]<-1000){
        		printf("%d", mat[i][j]);
        	}else if(mat[i][j]<-100){
        		printf(" %d", mat[i][j]);
        	}else if(mat[i][j]<-10){
        		printf("  %d", mat[i][j]);
        	}else if(mat[i][j]<0){
        		printf("   %d", mat[i][j]);
        	}


        	else if(mat[i][j]<10){
        		printf("    %d", mat[i][j]);
        	}else if(mat[i][j]<100){
        		printf("   %d", mat[i][j]);
        	}else if(mat[i][j]<1000){
        		printf("  %d", mat[i][j]);
        	}else if(mat[i][j]<10000){
        		printf(" %d", mat[i][j]);
        	}
        }
        printf("\n");
	}
}
int jesuLiIsti(int *niz1, int *niz2){
    int i;
    for(i=0;i<br_kolona;i++){
        if(niz1[i] != niz2[i]){
            return 0;
        }
    } return 1;
}

void izbaciRed(int mat[][sizeof(mat[0])/sizeof(*mat[0])], int broj){
    int i,j,k;
    for(i=0;i<br_redova;i++){
        if(i == broj){
            for(k=i;k<br_redova;k++){
                for(j=0;j<br_kolona;j++){
                    mat[k][j] = mat[k+1][j];
                }
            }return;
        }
    }
}



int jesuLiIste(int mat[][sizeof(mat[0])/sizeof(*mat[0])], int prva, int druga){
    int j;
    for(j=0;j<br_redova;j++){
        if(mat[j][prva] != mat[j][druga]) return 0;
    }return 1;
}


int izbaciRedove(int mat[][sizeof(mat[0])/sizeof(*mat[0])], int br_redova){
    int i,j,k;
    for(i=0;i<br_redova;i++){
        for(j=i+1;j<br_redova;j++){
            if(jesuLiIsti(mat[i], mat[j])){
                izbaciRed(mat, j);
                br_redova--;
                if(jesuLiIsti(mat[i], mat[j]) && br_redova > 1){
                    //printf("Broj redova : %d \n", br_redova);
                    j--;
                }
            }
        }
    }return br_redova;
}


void izbaciKolonu(int mat[][sizeof(mat[0])/sizeof(*mat[0])], int broj){
    int i,j;
    for(i=broj;i<br_kolona;i++){
        for(j=0;j<br_redova;j++){
            //printf("mat[%d][%d](%d) = mat[%d][%d](%d)\n", j,i,mat[j][i],j,i+1,mat[j][i+1]);
            mat[j][i] = mat[j][i+1];
        }
    }
}

void izbaciKolone(int mat[][sizeof(mat[0])/sizeof(*mat[0])], int br_redova){
    int i,j,k;
    for(i=0;i<br_kolona;i++){
        for(j=i+1;j<br_kolona;j++){
            if(jesuLiIste(mat, i, j)){
                izbaciKolonu(mat, j);
                br_kolona--;
                if(jesuLiIste(mat, i , j)){
                    j--;
                }
            }
        }
    }
}

int main() {
    int m,n,i,j;
    while(1){
        printf("Unesite brojeve M i N: ");
        scanf("%d %d", &m, &n);
        if(m < 0 || m> 200){
            printf("Brojevi nisu u trazenom opsegu.\n");
            continue;
        }else if(n< 0 || n > 200){
            printf("Brojevi nisu u trazenom opsegu.\n");
            continue;
        }else break;
    }
    printf("Unesite elemente matrice: ");
	br_redova = m;
	br_kolona = n;
	for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d", &mat[i][j]);
        }
	}
	printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
	br_redova = izbaciRedove(mat, br_redova);
	izbaciKolone(mat, br_redova);
	ispisi(mat, br_redova);
	return 0;
}
