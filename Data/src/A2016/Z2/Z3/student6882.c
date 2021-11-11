
	
	#include <stdio.h>

int main() 
{
	int nema;
	int n=0;

	int i,j,k;
	int x[10], y[10];
 while (1)
 {
  		printf ("Unesite broj tacaka: ");
  		scanf ("%d",&n); 
  	if (n>0 && n<=10)	break;
else	printf ("Pogresan unos\n");
}
  



	for (i=0; i<n;i++)
	{
		 while (1)
 {	printf ("Unesite %d. tacku: ",i+1);
	scanf ("%d %d",&x[i],&y[i]);
  	 
  	if (x[i]>=0 && x[i]<=19 && y[i]<=19 && y[i]>=0)	break;
else	printf ("Pogresan unos\n");
}

	}
for (i = 0; i < 20; ++i) {
    for (j = 0; j < 20; ++j) {
      nema = 1;
      for (k = 0; k < n; ++k) {
        if (j == x[k] && i == y[k]) {
          printf("*");
          nema = 0;
          break;
        }
      }
      if (nema) printf(" ");
    }
    printf("\n");
}
	return 0;
}


	
	

