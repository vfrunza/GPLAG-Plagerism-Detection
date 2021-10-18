#include <stdio.h>

int main() {
	int mat[200][200],i=0,j=0,m=0,n=0,redovi=0,kolone=0,isto=0,k=0,isto1=0,u=0, v=0, r=0;
	do {
		printf ("Unesite brojeve M i N: ");
		scanf ("%d%d",&m,&n);
		if (m>200 || n>200 || m<=0 || n<=0) {
			printf ("Brojevi nisu u trazenom opsegu.\n");
		}
	}
	while (m>200 || m<=0 || n>200 || n<=0);
	printf ("Unesite elemente matrice: ");
	
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			scanf ("%d",&mat[i][j]);
		}
	}
for (i=0; i<m; i++) {
	for (j=i+1; j<m; j++) {
		isto=1;
		for (k=0; k<n; k++){		
		if (mat[i][k]!=mat[j][k]) { 
				isto=0; 
				break;
			}
		}
	
	if (isto==1) {
		for (redovi=j; redovi<m-1; redovi++) {
			for (kolone=0; kolone<n; kolone++) {
				mat[redovi][kolone]=mat[redovi+1][kolone];
			}
		}
		m--; i--; break;
	}}}
/* za kolone */
for (u=0; u<n; u++) {
	for (v=u+1; v<n; v++) {
		isto1=1;
		for (r=0; r<m; r++) {
			if (mat[r][u]!=mat[r][v]) { 
				isto1=0;  
				break; 
	}}
	
	if (isto1==1) {
		for (kolone=v; kolone<n-1; kolone++) {
			for (redovi=0; redovi<m; redovi++) {
				mat[redovi][kolone]=mat[redovi][kolone+1];
			}
		}
		n--; u--; 	break;
	}
}} 

	printf ("Nakon izbacivanja redova/kolona matrica glasi:");
	printf ("\n");
	
	for (i=0; i<m; i++) {
		for (j=0; j<n; j++) {
			printf ("%5d",mat[i][j]);
		}
		printf ("\n");
       
		
	}
	return 0;
}
