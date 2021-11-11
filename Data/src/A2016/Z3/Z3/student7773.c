#include <stdio.h>

int main() {
	int M,N,mat[200][200],i,j,k,y,z,var;
	do{
      printf("Unesite brojeve M i N: ");
      scanf("%d %d",&M,&N);
       if(M>200 || M<1 || N>200 || N<1){
    	  printf("Brojevi nisu u trazenom opsegu.\n");
    	  continue;
    }
}while (M>200 || N>200 || M<1 || N<1);


printf("Unesite elemente matrice: ");
for(i=0;i<M;i++){
  for(j=0;j<N;j++){
     scanf("%d", &mat[i][j]);
     
  }
}

	
i=0;
while(i<M) {
	j=i+1;
	while(j<M) {
		var=1;
		for(k=0; k<N; k++) {
			if(mat[i][k]!=mat[j][k]) 
			var=0;
		}
		if(var==1) {
			for(z=j; z<M-1; z++) {
				for(y=0; y<N; y++) {
					mat[z][y]=mat[z+1][y];
				}
			}
			M--;
			j--;
		}
		j++;
	}
	i++;
}
  for(i=0; i<N; i++)
    {
        for(j=i+1; j<N; j++)
        {
            var=1;
            for(k=0; k<M; k++)
            {
                if(mat[k][i]!=mat[k][j])
                    var=0;
            }
            if(var==1)
            {
                for(z=j; z<N-1; z++)
                {
                    for(y=0; y<M; y++)
                    {
                        mat[y][z]=mat[y][z+1];
                    }
                }
                N--;
                k--;
            }
        }
    }
  for(i=0; i<N; i++)
    {
        for(j=i+1; j<N; j++)
        {
            var=1;
            for(k=0; k<M; k++)
            {
                if(mat[k][i]!=mat[k][j])
                    var=0;
            }
            if(var==1)
            {
                for(z=j; z<N-1; z++)
                {
                    for(y=0; y<M; y++)
                    {
                        mat[y][z]=mat[y][z+1];
                    }
                }
                N--;
                k--;
            }
        }
    }


printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
for (i=0; i<M; i++) {
  for (j=0; j<N; j++) {
      printf("%5d", mat[i][j]);
   }
   printf("\n");
}


	return 0;
}
