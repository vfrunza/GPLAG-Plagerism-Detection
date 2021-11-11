#include <stdio.h>
#define vel 200
int main() {
 int  i, j, n,m,k,kk, drugapret, pretp,e, mat[vel][vel]; 
 do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d", &m, &n); 
	if(n<=0 || n>200|| m<=0 || m>200 )
		printf("Brojevi nisu u trazenom opsegu.\n");
	}
	while(m>200 || m<=0 || n<=0 || n>200);
    printf("Unesite elemente matrice: ");
	for(i=0; i<m; i++)
	 for(j=0; j<n; j++)
	  scanf("%d", &mat[i][j]);
    for(i=0; i<n; i++) {
     for(k=i+1; k<n; k++) {	
      pretp=1; 
	  for(j=0; j<m; j++) 
		if(mat[j][i]!=mat[j][k])
		pretp=0; 
	  if(pretp==1) {
	  	for(kk=k; kk<n-1; kk++) 
	     for(e=0; e<m; e++) 
			mat[e][kk]=mat[e][kk+1];
		k--;
		n--;
	}
    }
}
for(i=0; i<m; i++) {
 for(k=i+1; k<m; k++) {	
  drugapret=1; 
  for(j=0; j<n; j++) 
	if(mat[i][j]!=mat[k][j])
      drugapret=0; 
    if(drugapret==1) {
     for(kk=k; kk<m-1; kk++) 
		for(e=0; e<n; e++) 
		mat[kk][e]=mat[kk+1][e];
	m--; 
	k--;
    }
	}
}
printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
for(i=0; i<m; i++) {
 for(j=0; j<n; j++)
 printf("%5d", mat[i][j]);
 printf("\n");
}
return 0;
}