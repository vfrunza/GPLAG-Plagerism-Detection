#include <stdio.h>

int main() {
	int br, bk, sk, i, j, k;
	do { 
	printf("Unesite broj redova: ");
	scanf ("%d", &br);
	printf("Unesite broj kolona: ");
	scanf("%d", &bk);
	printf("Unesite sirinu jedne kolone: ");
	scanf("%d", &sk);
	} 
	while ((br<=0 || br> 10) && (bk<=0 || bk> 10) && (sk<=0 || sk> 10));
	for (i=0; i<br; i++) 
	{
		if(i==0)
		{
	for (j=0; j<bk; j++) 
	{
		if(j==0)
    printf("+");
	
	for(k=0; k<sk; k++) 
	{
	printf("-"); 
	}
	printf ("+");
	}
	printf("\n");
	}
	for (j=0; j<bk; j++) 
	{
		if (j==0)
	printf ("|");
	for(k=0; k<sk; k++)
	{
		printf (" ");
	}
	printf ("|");
	}
    printf("\n");
    for (j=0; j<bk; j++) {
    if (j==0)
  printf("+");
  for (k=0; k<sk; k++)
	{
	printf("-");
	}
	printf ("+");
    }
    printf ("\n");
	}
	return 0;
}
