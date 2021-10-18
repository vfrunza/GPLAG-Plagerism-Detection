#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ubaci (int *p, int velicina)
{
	int i, x, z, zbir=0;
	int *k;
	k=p;
	for(i=velicina-1;i>=0;i--){
		*(k+(i*2))=*(k+i);
	}
	for (i=0;i<2*velicina;i++){
		if (i%2!=0){
			x=*(k+i-1);
		while (x!=0){
			z=x%10;
			zbir=zbir+z;
			x=x/10;
		}
		zbir=abs(zbir);
		*(k+i)=zbir;
		zbir=0;
		}
	}
}




int fibonacijev(int r){
	int prvi_br=0, drugi_br=1, treci_br=0, broj=0;
	while (1){
		treci_br=prvi_br+drugi_br;
		prvi_br=drugi_br;
		drugi_br=treci_br;
		if(r==treci_br){
			broj++;
			break;
		}
		else if(r<treci_br)
		break;
	}
	if(broj>0)
	return 1;
	else
	return 0;
}

int izbaci(int *t, int velicina){
	int *b,i,j;
	b=t;
	for(i=0;i<velicina;i++){
		if(fibonacijev(*(b+i))==1){
			for(j=i;j<velicina-1;j++){
				*(b+j)=*(b+j+1);
			}
			velicina--;
			i--;
	}
}
return velicina;
}



int main() {
	
	int niz[10], i,velicina=0;
	int  *l=&niz[10];
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
	scanf("%d", &niz[i]);}
	
	ubaci(niz,10);
	velicina=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
	


	
	return 0;
}
