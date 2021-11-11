#include <stdio.h>



int izbroj_element(int mat[100][100], int x, int y, int el){
    
     int br=0,i,j;
     
    for(i=0; i<x; i++)
for(j=0; j<y; j++) {
    
    if(mat[i][j]==el) br++;
}

return br;
    
}

int main() {
	
	 int m,n, i,j;
    int A[100][100], B[100][100], C[100][100];
    
    do {
    printf("Unesite brojeve M i N: ");
    scanf("%d %d", &m, &n);
    } while( m<0 || n<0 || m>100 || n>100);
    
     
 printf("Unesite clanove matrice A: ");
    for(i=0; i<m; i++)
for(j=0; j<n; j++) 
scanf("%d", &A[i][j]);

 printf("Unesite clanove matrice B: ");
    for(i=0; i<m; i++)
for(j=0; j<n; j++) 
scanf("%d", &B[i][j]);

 printf("Unesite clanove matrice C: ");
    for(i=0; i<m; i++)
for(j=0; j<n; j++) 
scanf("%d", &C[i][j]);


/*provjeri A i B*/


int br_elA, br_elB, br_elC;
for(i=0; i<m; i++)
for(j=0; j<n; j++)
{
    br_elA=izbroj_element(A,m,n,A[i][j]);
    br_elB=izbroj_element(B,m,n,A[i][j]);
if(br_elA!=br_elB)  {

printf ("NE");
    return 0;
}
}





/* provjeri A i C*/ 


for(i=0; i<m; i++)
for(j=0; j<n; j++) {
    
 br_elC=izbroj_element(C,m,n,A[i][j]);
    br_elB=izbroj_element(B,m,n,A[i][j]);
if(br_elC!=br_elB)   {

printf ("NE");
    return 0;
}
}


    
printf("DA");





	return 0;
}
