#include <stdio.h>

int main() {
	int matricaA[100][100],matricaB[100][100],matricaC[100][100];
	int pm1[10000],pm2[10000],pm3[10000],minpm1,minpm2,minpm3;
	int pomoc1,pomoc2,pomoc3;
	int M,N;
	int i,j,k=0,z,k1=0,k2=0,z1,z2;
	
	do{
	    printf("Unesite brojeve M i N: ");
	scanf("%d %d",&M,&N);
	}while(M>100 || M<0  || N>100 || N<0);
	printf("Unesite clanove matrice A: ");
	for(i=0;i<M;i++){
		for(j=0;j<N;j++,k++){
			scanf("%d",&matricaA[i][j]);
			pm1[k]=matricaA[i][j];
			
		}
	}
    for(k=0;k<M*N;k++){
    	minpm1=k;
    	for(z=k+1;z<M*N;z++){
    		if(pm1[z]<pm1[minpm1]) minpm1=z;
    	}
    	pomoc1=pm1[k];
    	pm1[k]=pm1[minpm1];
    	pm1[minpm1]=pomoc1;
    }

    
    printf("Unesite clanove matrice B: ");
    for(i=0;i<M;i++){
    	for(j=0;j<N;j++,k1++){
    		scanf("%d",&matricaB[i][j]);
    		pm2[k1]=matricaB[i][j];
    	}
    }
    for(k1=0;k1<M*N;k1++){
    	minpm2=k1;
    	for(z1=k1+1;z1<M*N;z1++){
    		if(pm2[z1]<pm2[minpm2]) minpm2=z1;
    	}
    	pomoc2=pm2[k1];
    	pm2[k1]=pm2[minpm2];
    	pm2[minpm2]=pomoc2;
    }
    
    printf("Unesite clanove matrice C: ");
    for(i=0;i<M;i++){
    	for(j=0;j<N;j++,k2++){
    		scanf("%d",&matricaC[i][j]);
    		pm3[k2]=matricaC[i][j];
    	}
    }
    
    for(k2=0;k2<M*N;k2++){
    	minpm3=k2;
    	for(z2=k2+1;z2<M*N;z2++){
    		if(pm3[z2]<pm3[minpm3]) minpm3=z2;
    	}
    	pomoc3=pm3[k2];
    	pm3[k2]=pm3[minpm3];
    	pm3[minpm3]=pomoc3;
    }
   
   for(k=0;k<M*N;k++){
       if((pm1[k]!=pm2[k])||(pm2[k]!=pm3[k])|| (pm1[k]!=pm3[k])){
           printf("NE");
           return 0;
       }
   }
   printf("DA");
    
	return 0;
}
