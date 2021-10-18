#include <stdio.h>

int main() {
int M,N,mat1[100][100],mat2[100][100],mat3[100][100],i,j,min,temp,t,niz1[200],niz2[200],niz3[200];
do {
	printf("Unesite brojeve M i N: ");
	scanf("%d%d",&M,&N);
} while ((M>100 || M<0) || (N>100 || N<0));

	printf("Unesite clanove matrice A: ");
for(i=0;i<M;i++){
	for(j=0;j<N;j++){
		scanf("%d",&mat1[i][j]);
	}
}
	printf("Unesite clanove matrice B: ");
for(i=0;i<M;i++){
	for(j=0;j<N;j++){
		scanf("%d",&mat2[i][j]);
	}
}
	printf("Unesite clanove matrice C: ");	
for(i=0;i<M;i++){
	for(j=0;j<N;j++){
		scanf("%d",&mat3[i][j]);
	}
}
for(i=0;i<M;i++){
 for(j=0;j<N;j++){
  niz1[i*N+j]=mat1[i][j];
  niz2[i*N+j]=mat2[i][j];
  niz3[i*N+j]=mat3[i][j];
 }
}
for(i=0;i<M*N;i++){
 min=i;
 for(j=i+1;j<M*N;j++){
  if(niz1[min]>niz1[j]){
   min=j;
  }
 }
 temp=niz1[min];
 niz1[min]=niz1[i];
 niz1[i]=temp;
}
for(i=0;i<M*N;i++){
 min=i;
 for(j=i+1;j<M*N;j++){
  if(niz2[min]>niz2[j]){
   min=j;
  }
 }
 temp=niz2[min];
 niz2[min]=niz2[i];
 niz2[i]=temp;
}
for(i=0;i<M*N;i++){
 min=i;
 for(j=i+1;j<M*N;j++){
  if(niz3[min]>niz3[j]){
   min=j;
  }
 }
 temp=niz3[min];
 niz3[min]=niz3[i];
 niz3[i]=temp;
}

 t=1;
 for(i=0;i<M*N;i++){
  if(t==-1){
   break;
  }
  for(j=0;j<N;j++){
   if(niz1[i]!=niz2[i] || niz2[i]!=niz3[i]) {
    t=-1;
    break;
   }
  }
 }
if(t==-1) {
 printf("NE");
}
else {
 printf("DA");
}
	return 0;
}
