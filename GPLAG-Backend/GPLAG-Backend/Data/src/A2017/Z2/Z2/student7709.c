#include <stdio.h>
#define MAX 10

int main() {
	int a[MAX],b[MAX],c[2*MAX],i,j,suma,suma1;
	
	printf("Unesite elemente niza A: ");
	for(i=0; i<MAX; i++){
		scanf("%d",&a[i]);
		if (a[i]==-1)break;
		c[i]=a[i];
	} 
	suma=i;
	printf("%d\n",suma);
		printf("Unesite elemente niza B: ");
	for(i=0; i<MAX; i++){ 
		scanf("%d",&b[i]);
		if(b[i]==-1)break;
		c[i+suma]=b[i];
	} 
	suma1=i;
	printf("%d\n",suma1);
	printf("Niz C glasi: ");
	for(i=0; i<suma+suma1; i++){
		printf("%d,",c[i]);
	}
		
	return 0;
}