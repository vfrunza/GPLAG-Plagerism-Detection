#include <stdio.h>
#define VISINA 100
#define SIRINA 100

int main() {
	
	int min_a,min_b,min_c,temp_a,temp_b,temp_c,a=0,b=0,c=0,p=1,A[VISINA][SIRINA],B[VISINA][SIRINA],C[VISINA][SIRINA],i,j,m,n,A2[VISINA*SIRINA],B2[VISINA*SIRINA],C2[VISINA*SIRINA];
	
	do{
		printf("Unesite brojeve M i N: ");
		scanf("%d %d",&m,&n);
	}while(m<0 || m>100 || n<0 || n>100);
	
	printf("Unesite clanove matrice A: ");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			scanf("%d",&A[i][j]);
			A2[a]=A[i][j];
			a++;
		}
	}   
	
	printf("Unesite clanove matrice B: ");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			scanf("%d",&B[i][j]);
			B2[b]=B[i][j];
			b++;
		}
	}
	
	printf("Unesite clanove matrice C: ");
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			scanf("%d",&C[i][j]);
			C2[c]=C[i][j];
			c++;
	       }
	}
	
	
	for(i = 0; i < m*n; i++){
		min_a=i;
		min_b=i;
		min_c=i;
		for(j = i+1; j < m*n; j++){
			if(A2[j]<A2[min_a])
			min_a=j;
			if(B2[j]<B2[min_b])
			min_b=j;
			if(C2[j]<C2[min_c])
			min_c=j;
		}
		temp_a=A2[i];
		A2[i]=A2[min_a];
		A2[min_a]=temp_a;
		
		temp_b=B2[i];
		B2[i]=B2[min_b];
		B2[min_b]=temp_b;
		
		temp_c=C2[i];
		C2[i]=C2[min_c];
		C2[min_c]=temp_c;
		
		}
		
		for(i = 0; i < m*n; i++){
			if(A2[i]!=B2[i] || A2[i]!=C2[i]){
			p=0;
			break;}
		}
		
	if(p)
	printf("DA");
	else
	printf("NE");
	
	return 0;
}
