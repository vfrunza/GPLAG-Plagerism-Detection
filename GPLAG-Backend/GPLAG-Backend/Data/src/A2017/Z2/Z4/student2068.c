#include <stdio.h>
#define visina 100
#define sirina 100

int main() {
	int M,N,i,j,a=0,b=0,c=0;
	int brojac[visina][sirina];
	int matricaA[visina][sirina],matricaB[visina][sirina],matricaC[visina][sirina];
	do{
	   printf("Unesite brojeve M i N: ");
       scanf("%d %d", &M,&N);
	}while(M>100 || M<0 || N<0 || N>100);
	
	printf("Unesite clanove matrice A: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d",&matricaA[i][j]);
		}
	}
	printf("Unesite clanove matrice B: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d",&matricaB[i][j]);
		}
	}
	printf("Unesite clanove matrice C: ");
	for(i=0; i<M; i++){
		for(j=0; j<N; j++){
			scanf("%d",&matricaC[i][j]);
		}
	}
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(matricaA[0][0]==matricaA[i][j])a++;
			
		}
	}
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			if(matricaA[0][0]==matricaB[i][j])b++;
			
		}
	}
	
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
				if(matricaA[0][0]==matricaC[i][j])c++;
		}
	}
   if(a==b && b==c && a==c)printf("DA");
   else printf("NE");
	
return 0;
}