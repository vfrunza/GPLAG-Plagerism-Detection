#include <stdio.h>
#include <math.h>

int main() {
   int m=0,n=0,A[100][100]={{0}},B[100][100]={{}},C[100][100]={{}},i,j,br1[1000]={0},br2[1000]={0},br3[1000]={0},k=0,niz1[1000]={0},niz2[1000]={0},niz3[1000]={0},max1=0,max2=0,max3=0;
   do{
   	printf("Unesite brojeve M i N: ");
   	scanf("%d %d",&m,&n);
   }while((m>100 || n>100));
   if(m==0 && n==0){
        printf("Unesite clanove matrice A: ");
          printf("Unesite clanove matrice B: ");
            printf("Unesite clanove matrice C: ");
            printf("DA");
            return 0;
   }
   printf("Unesite clanove matrice A: ");
   for(i=0;i<m;i++){
   	for(j=0;j<n;j++){
   		scanf("%d",&A[i][j]);
   		if(A[i][j]>max1){max1=A[i][j];}
   	}
   }
   for(i=0;i<m;i++){
   	for(j=0;j<n;j++){
   		if(A[i][j]>=0) {br1[k++]=(A[i][j]);}
   		if(A[i][j]<0) br1[k++]=max1+1;
   	}
   }
   k=0;
   printf("Unesite clanove matrice B: ");
   for(i=0;i<m;i++){
   	for(j=0;j<n;j++){
   		scanf("%d",&B[i][j]);
   		if(B[i][j]>max2) {max2=B[i][j];}
   	}
   }
   for(i=0;i<m;i++){
   	for(j=0;j<n;j++){
   		if(B[i][j]>=0) {br2[k++]=(B[i][j]);}
   		if(B[i][j]<0) br2[k++]=max2+1;
   	}
   }
   k=0;
   printf("Unesite clanove matrice C: ");
   for(i=0;i<m;i++){
   	for(j=0;j<n;j++){
   		scanf("%d",&C[i][j]);
   		if(C[i][j]>max3) max3=C[i][j];
   	}
   	
   }
   if(m==1 && n==1){
      if(A[0][0]== B[0][0] && B[0][0]==C[0][0]) printf("DA");
      else printf("NE");
      return 0;
   }
   for(i=0;i<m;i++){
   	for(j=0;j<n;j++){
   		if(C[i][j]>=0){br3[k++]=(C[i][j]);}
   		if(C[i][j]<0) br3[k++]=max3+1;
   	}
   	int l=0;
   	for(i=0;i<m*n;i++){
   		niz1[br1[i]]++;
   	}
   	for(i=0;i<m*n;i++){
   		niz2[br2[i]]++;
   	}
   	for(i=0;i<m*n;i++){
   		niz3[br3[i]]++;
   	}
   	
   	for(i=0;i<1000;i++){
   		if(niz1[i]!=niz2[i] && niz2[i]!=niz3[i] ) l++;
   	}
   	if(l!=0) printf("NE");
   	if(l==0) printf("DA");
   
	return 0;
}}
