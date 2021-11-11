#include <stdio.h>
#define sirina1 100
#define sirina2 100

int main() {
	int i, j, suma1=0, suma2=0, mat1[sirina1][sirina1], mat2[sirina2][sirina2], a, b, c=0, d=0;
	printf("Unesite sirinu i visinu matrice A: ");
	scanf("%d", &a);
	printf("Unesite clanove matrice A: ");
	while(c!=a)
	{
	for(i=0; i<sirina1; i++)
	   for(j=0; j<sirina1; j++)
	    scanf("%d", mat1[sirina1][sirina1]);
	    
	    for(i=0; i<sirina1; i++)
	    suma1+=mat1[sirina1][sirina1];
	 c++;
    }
	   
	printf("Unesite sirinu i visinu matrice B: ");
	scanf("%d", &b);
	printf("Unesite clanove matrice B: ");
	while(d!=b)
	{
	for(i=0; i<sirina2; i++)
	   for(j=0; j<sirina2; j++)
	    scanf("%d", mat2[sirina2][sirina2]);
	    
	    for(i=0; i<sirina2; i++)
	    suma2+=mat2[sirina2][sirina2];
	 d++;
    } 
	
	if(suma1==suma2)
	printf("DA");
	else printf("NE");
	return 0;
}
