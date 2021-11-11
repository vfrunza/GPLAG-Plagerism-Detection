#include <stdio.h>

int main() {
int m,n,i,j,s,t,k=0,temp;
int mat[200][200];
int brojac1=0;
int brojac2=0;


printf ("Unesite brojeve M i N: ");
scanf ("%d %d", &m, &n);
/*osiguravanje pravilnog unosa*/

while (m<=0 || n<=0 || m>200 || n>200) {
	printf ("Brojevi nisu u trazenom opsegu.\n");
	printf ("Unesite brojeve M i N: ");
	scanf ("%d %d", &m, &n ); }

/*unos matrice*/
printf ("Unesite elemente matrice: ");
for (i=0;i<m;i++){
	for (j=0;j<n;j++){
		scanf ("%d", &mat[i][j]);
	}
}

/*izbacivanje istih redova*/

for (i=0; i<m; i++){
   for (j=i+1; j<m; j++){
    brojac1=0;
	  for (k=0;k<n;k++){

	    if (mat[i][k]==mat[j][k])  {brojac1++; }
	    else break;
	    
		if (brojac1==n)
			{
				for (s=j+1; s<m;s++){
				for (t=0;t<n;t++){	
                temp=mat[s-1][t];
                mat[s-1][t]=mat[s][t];
                mat[s][t]=temp;}

}m--; j--;}}}}
	
/*izbacivanje istih kolona*/

for (i=0;i<n;i++){

   for (j=i+1; j<n; j++){ 
   brojac2=0;
        for (k=0;k<m;k++){

            if (mat[k][i]==mat[k][j]) {brojac2++; }
            else break;
            
		  if (brojac2==m){
	        for (s=j+1; s<n;s++){
			     	for (t=0;t<m;t++){	
			temp=mat[t][s-1];
			mat[t][s-1]=mat[t][s];	
			mat[t][s]=temp;
				}
	

}n--; j--;}}}}

printf ("Nakon izbacivanja redova/kolona matrica glasi:\n");

for (i=0; i<m; i++)
{
	for (j=0;j<n;j++){ 
	printf ("%5d", mat[i][j]);}
	printf ("\n");
}
	return 0;
}
