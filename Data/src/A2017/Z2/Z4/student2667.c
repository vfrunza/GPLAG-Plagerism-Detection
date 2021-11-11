#include <stdio.h>

int main() {

   int i,j,M,N,A[100][100],B[100][100],C[100][100],k=0,nizA[100],m=0,n=0,nizB[100],nizC[100];
   int da=1,temp1,temp2,temp3,min1,min2,min3;
   do {
   	printf("Unesite brojeve M i N: ");
   	scanf("%d %d", &M, &N);
   }while(M>100 || N>100);
   
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

      nizA[k]=A[i][j];
      k++;
     } }
    
   for(i=0;i<M;i++){
    for(j=0;j<N;j++){

      nizB[m]=B[i][j];
      m++;
     }
    
   }for(i=0;i<M;i++){
    for(j=0;j<N;j++){

      nizC[n]=C[i][j];
      n++;
     }
    
   }
   for(i=0;i<k;i++){
       min1=i;
       for(j=i+1;j<k;j++){
           if(nizA[j]<nizA[min1]) min1=j;}
       temp1=nizA[i];
       nizA[i]=nizA[min1];
       nizA[min1]=temp1;
   }
      for(i=0;i<m;i++){
       min2=i;
       for(j=i+1;j<m;j++){
           if(nizB[j]<nizB[min2]) min2=j;}
       temp2=nizB[i];
       nizB[i]=nizB[min2];
       nizB[min2]=temp2;
   }
      for(i=0;i<n;i++){
       min3=i;
       for(j=i+1;j<n;j++){
           if(nizC[j]<nizC[min3]) min3=j;}
       temp3=nizC[i];
       nizC[i]=nizC[min3];
       nizC[min3]=temp3;
   }
   for(i=0;i<k;i++){
       if(nizA[i]!=nizB[i] || nizB[i]!=nizC[i] || nizC[i]!=nizA[i]){
           da=0;
       }
   }
   if(da==1) printf("DA");
   else printf("NE");
	return 0;
}
