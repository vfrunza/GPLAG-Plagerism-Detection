//Z2
//zadatak1
#include <stdio.h>

int main() {
    int n,i,j;
	
 do{
     printf("Unesite broj N: ");
     scanf("%d",&n);
     if(!(n>0 && n%4==0 && n>=8)) printf("Neispravno N!\n");
 }while (!(n>0 && n%4==0 && n>=8)); 
 
 printf("\n");
 /*
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i<n/2+1 ){
            if(i==j) printf("\\");
             else if(i+j==n/2+1) printf("/");
             else if((i==0 || i==n/2-1) && (j==n/2 | j==n-1)) printf("+");
             else if(j>n/2 && (i<n/2-1 || i>0))  printf("-");
             else if(j==n/2 || j==n-1) printf("|");
            else printf(" ");
        }
    }
        printf("\n");
    }
     */
 
	
	
    for(i=0;i<n/2;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j) printf("\\");
            else if(i+j==n/2-1) printf("/");
           
            else if((i==0 && (j==n/2 || j==n-1))||(i==n/2-1 && (j==n/2 || j==n-1))) printf("+");
            else if((i==0 || i==n/2-1)&& j>n/2) printf("-");
            else if(j==n/2 || j==n-1) printf("|");
            else printf(" ");
        }
        printf("\n");
    }
	
	
	for(i=0;i<n/2;i++)
    {
        for(j=0;j<n;j++)
        {
            if((i==0 && (j==0 || j==n/2-1))||(i==n/2-1 && (j==0 || j==n/2-1))) printf("+");
            else if((i==0 || i==n/2-1)&& j<n/2) printf("-");
            else if(j==0|| j==n/2-1) printf("|");
            else if((i==j-n/2 && i>=n/4-1 && i<n/4+1)||(i+j==n-1 && i>=n/4-1 && i<n/4+1))printf("+");
            else if(j>=n/2+n/4-1 && j<n/2+n/4+1) printf("|");
            else if(i>=n/4-1 && i<n/4+1 && j>=n/2) printf("-");
            
            else printf(" ");
        }
        printf("\n");
    }
	
	
	
	
	return 0;
}




//zadatak2
#include <stdio.h>

int main() {
	int niz[100],vel,vel2=0,i=0,niz2[100],niz3[100],vel3=0,j=0,br1=0;
	int pom,k=1,suma=0,br=0;
	
	
	
		
	do{
	printf ("Unesite velicinu niza: ");
	scanf("%d",&vel);
	}while(vel<=0 || vel >100);
	
	
	printf("Unesite clanove niza: ");
	for(i=0;i<vel;i++){
		scanf("%d,",&niz[i]);
		if(niz[i]<=0) i--;
	}
	
	for(i=0;i<vel;i++){
		pom=niz[i];
		k=1;
		suma=0;
		br=0;
		while(pom!=0){
			br++;
			pom/=10;
		}
		while(br!=1){
			k*=10;
			br--;
		}
		while(niz[i]!=0){
			suma+=(niz[i]%10)*k;
			k/=10;
			niz[i]/=10;
			
		}
		niz[i]=suma;
	}
	for(i=0;i<vel;i++){
	while(niz[i]!=0){
		niz2[vel2]=niz[i]%10;
		vel2++;
		niz[i]/=10;
	}
}

	vel3=0; 
	for(i=0;i<vel2;i++){
		niz3[vel3]=niz2[i];
		j=i;
		while(j!=vel2 && niz2[i]==niz2[j]) { br1++; j++;}
		niz3[vel3+1]=br1;
		vel3+=2;
		br1=0;
		i=j-1;
	}
 	printf("Finalni niz glasi:\n");
	for(i=0;i<vel3;i++){
		if(i!=vel3-1) printf("%d ",niz3[i]);
		else printf("%d",niz3[i]);
	}
	
	return 0;
}




// zadatak3
#include <stdio.h>

int main() {
	int i,j,visina1,sirina1,visina2,sirina2,A[100][100],B[100][100],pom[100][100];
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d %d",&sirina1,&visina1);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<visina1;i++){
		for(j=0;j<sirina1;j++){
			scanf("%d",&A[i][j]);
		}
	}
	
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d %d",&sirina2,&visina2);
	printf("Unesite clanove matrice B: ");
	for(i=0;i<visina2;i++){
		for(j=0;j<sirina2;j++){
			scanf("%d",&B[i][j]);
		}
	}
		if(sirina1!=visina2 || visina1!=sirina2){
		printf("NE"); return 0;
	}
	
	for(i=0;i<sirina1;i++){
		for(j=0;j<visina1;j++){
		
		   pom[i][j]=A[visina1-j-1][i];
		}
	}

	for(i=0;i<visina2;i++){
		for(j=0;j<sirina2;j++){
			if(B[i][j]!=pom[i][j] ){
				printf("NE");
				return 0;
			}
		}
	}
	printf("DA");
	
	
	

	return 0;
}




//zadatak4

#include <stdio.h>

int main() {
	
	int A[100][100],B[100][100],C[100][100],i,j,M,N,niz1[1000],niz2[1000],niz3[1000],br=0,pom;
	
	
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&M,&N);
	}while(M<0 || M>100 || N<0 || N>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&A[i][j]);
		
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&B[i][j]);
		}
	}
	
	printf("Unesite clanove matrice C: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			scanf("%d",&C[i][j]);
		}
	}

	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			niz1[br]=A[i][j];
			br++;
		}
	}
	 for(i=0;i<br;i++){
	 	for(j=i;j<br;j++){
	 		if(niz1[i]>niz1[j]){
	 			pom=niz1[i];
	 			niz1[i]=niz1[j];
	 			niz1[j]=pom;
	 		}
	 	}
	 }
	 br=0;
	 for(i=0;i<M;i++){
	 	for(j=0;j<N;j++){
	 		niz2[br]=B[i][j];
	 		br++;
	 	}
	 }
	 for(i=0;i<br;i++){
	 	for(j=i;j<br;j++){
	 		if(niz2[i]>niz2[j]){
	 			pom=niz2[i];
	 			niz2[i]=niz2[j];
	 			niz2[j]=pom;
	 		}
	 	}
	 }
	br=0;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			niz3[br]=C[i][j];
			br++;
		}
	}
	
	for(i=0;i<br;i++){
		for(j=i;j<br;j++){
			if(niz3[i]>niz3[j]){
				pom=niz3[i];
				niz3[i]=niz3[j];
				niz3[j]=pom;
			}
		}
	}
	
	for(i=0;i<br;i++){
		if(niz1[i]!=niz2[i] || niz1[i]!=niz3[i] ) {printf("NE"); return 0; }
	
		
	}
	printf("DA");
	
	
	
	
	
	
	
	
	return 0;
}






// An Inplace function to rotate a N x N matrix
// by 90 degrees in anti-clockwise direction
void okreni_redove(int mat[][N], int broj_redova, int broj_kolona) {
    int i = 0;
    for (; i < broj_redova; ++i) {
        int j = 0;
        int k = broj_kolona - 1;
        for (; j < k; ++j) {
            int tmp = mat[i][j];
            mat[i][j] = mat[i][k];
            mat[i][k] = tmp;
            --k;
        }
    }
}




void okreni_kolone(int mat[][N], int broj_redova, int broj_kolona) {
    int i = 0;
    for (; i < broj_kolona; ++i) {
        int j = 0;
        int k = broj_redova - 1;
        for (; j < k; ++j) {
            int tmp = mat[j][i];
            mat[j][i] = mat[k][i];
            mat[k][i] = tmp;
            --k;
        }
    }
}