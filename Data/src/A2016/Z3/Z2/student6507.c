#include <stdio.h>
#include <stdlib.h>

void ubaci (int* niz, int vel){
	int *p=niz;
	int i, a, suma;
	
	for(i=1; i<=vel; i++){
		*(p+2*vel-2*i)=*(p+vel-i); 
	}
	
	for(i=0; i<2*vel; i+=2){
		suma=0;
		a=abs(*(p+i));
		while(a!=0){
			suma+=(a-((a/10)*10));
			a=a/10;
		}
		*(p+i+1)=suma;
	}
}

int izbaci(int* niz, int vel){
	int *p=niz;
	int i, j, x, y, z;
	for(i=0; i<vel; i++){
		x=0;
		y=1;
		do{		
			z=x+y;
			x=y;
			y=z;
			if(z==*(p+i)) break;
		}while(z<*(p+i));
		
		if(z==*(p+i)){
			for(j=i; j<vel-1; j++){
				*(p+j)=*(p+j+1);
			}
			i--;
			vel--;
		}
	}
	return vel;
}


int main() {
	int niz[20];
	int  i, y;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10; i++){
		scanf("%d", &niz[i]);
	}
	for(i=10; i<20; i++){
		niz[i]=0;
	}
	ubaci(niz,10);
	y=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	
	for(i=0; i<y; i++){
		if(i<y-1) 	printf("%d, ", niz[i]);
		if(i==y-1)  printf("%d.", niz[i]);
	}
	return 0;
}
