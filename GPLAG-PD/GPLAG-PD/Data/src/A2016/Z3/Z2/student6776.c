#include <stdio.h>
#include <math.h>


void ubaci(int *niz,int vel){
	int velicina , i,suma, tmp, j;
	int *p,*pocetak = niz;
	velicina  = vel;
	 p = niz;
	i = 0; 
	while(i < velicina + velicina){
		suma = 0;
			tmp = *p;
			tmp = fabs(tmp);
		while(tmp != 0){
				suma += tmp % 10; 
				tmp /= 10;
	    	}
		j = vel;     
		while(j > i  ){
			*(pocetak + j) = *(pocetak + j - 1);
			j--;
		}
		p++;
		*p = suma;
		p++;
		i+=2;
		vel++;
	}
}

int f(int n){
	int k,niz[500],vel = 50;
	niz[0] = 1; niz[1] = 1;
	for(k = 2; k < vel; k++)niz[k] = niz[k - 1] + niz[k - 2];
	for(k = 0; k < vel; k++)
		if( n == niz[k])return 1;
	return 0;
}

int izbaci(int *niz,int vel){
	int i,j;
	for(i = 0; i < vel; i++){
		if(f(niz[i]) && niz[i] > 0){
			for(j = i; j < vel - 1; j++)
				niz[j] = niz[j + 1];
			i--;
			vel--;
		}
	}
	return vel;
}

int main() {
	int niz[600],i,vel = 10;
	printf("Unesite niz od 10 brojeva: ");
	for(i = 0; i < vel; i++)scanf("%d",&niz[i]);
	ubaci(niz,vel);
	vel += vel;
	vel = izbaci(niz,vel);
	printf("Modificirani niz glasi: ");
	for(i = 0; i < vel - 1; i++) printf("%d, ",niz[i]); printf("%d.",niz[i]);
	return 0;
}
