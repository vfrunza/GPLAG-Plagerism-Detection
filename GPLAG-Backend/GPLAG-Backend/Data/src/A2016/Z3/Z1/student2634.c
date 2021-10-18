#include <stdio.h>


/*Funkcija za proste brojeve*/
 int daj_prost() {
    static int j=1;
    int a;
    j++;
	for(a=2; a<j; a++) {
		if(j%a==0) {
			j++;
			a=1;
			
		}
		
	}
	return j;
}

/*Funckija za sumu ispisanih prostih brojeva*/
/*int suma(int x, int y){
	int suma=0,a=0,i,j;
	for(i=x+1;i<y;i++){
		a=0;
		for(j=2;j<i;j++){
			if(i%j==0) a=1;
			}
		if(a==0) suma=suma+i;
		}
	
	return suma;
}
*/

// int daj_prost();
int main() {
	static int A,B,i,x;
greska:
	printf("Unesite brojeve A i B: ");
	scanf("%d %d", &A, &B);
	if(A<=0) {
		printf("A nije prirodan broj.\n");
		goto greska;
	}
	
	else if (B<0 || B<A) {
		printf("A nije manje od B.\n");
		goto greska;
	}
	else if(A==B) {
		printf("A nije manje od B.\n");
		goto greska;
	}
	/*else printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,daj_prost());*/
/*	else {
		printf("Prosti brojevi između %d i %d su:  ",A,B);
		for(i=A+1;i<B;i++) {
			x=daj_prost(i);
			if(x==1) printf("%d ",i);
		}
	}*/
	while(1) {
		x=daj_prost();
		if(x<=A) {
			continue;
		} 
		if(x>=B) {
			break;
		}
		i=i+x;
	}
	printf("Suma prostih brojeva izmedju %d i %d je %d.",A,B,i);
	return 0;
}
