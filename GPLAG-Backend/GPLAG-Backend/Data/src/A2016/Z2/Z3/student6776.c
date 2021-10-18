#include <stdio.h>
#define SIRINA 20

int main() {
	char mat[SIRINA][SIRINA]={{0}};
	int i,j,n,a,b;		/*n- unesen broj	 a i b tacke gdje ce ispisati zvjezicu u zavisnosti od "i" i "j";
								i,j prazna horizontala i vertikala matrice/

/*Otvaran praznu matricu*/	
	for(i=0;i<SIRINA;i++){
		for(j=0;j<SIRINA;j++){
			mat[j][i]=' ';
		}
	}
	
/*Unosimo broj tacaka*/
	do{
	printf("Unesite broj tacaka: ");
	scanf("%d", &n);
	if(n<1 || n>10)	{printf("Pogresan unos\n");}
	
	}while(n<1 || n>10);

/*Unosimo zeljene tacke*/	
for(i=0;i<n;i++){
	do{
	printf("Unesite %d. tacku: ", i+1);	
	scanf("%d %d", &a, &b);
	if(a<0 || a>=SIRINA || b<0 || b>=SIRINA){
		printf("Pogresan unos\n");
	}
	}while(a<0 || a>=SIRINA || b<0 || b>=SIRINA);
	mat[a][b]='*';
}
	for(i=0;i<SIRINA;i++){
		for(j=0;j<SIRINA;j++){
			printf("%c",mat[j][i]);
		}
	printf("\n");	
	}
	return 0;
}