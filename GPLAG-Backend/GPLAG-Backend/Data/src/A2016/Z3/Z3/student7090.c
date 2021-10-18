#include <stdio.h>
#include <math.h>

int main(){
int matrica[200][200];
int M,N;
int ID=1;
int a,b,c,d,p,r;
do{
	printf("Unesite brojeve M i N: ");
	scanf("%d %d",&M,&N);
	if(M<0 || N<0 || M>200 || N>200){
		printf("Brojevi nisu u trazenom opsegu.\n");
		continue;
	}
	else break;
}	
while (1);
printf("Unesite elemente matrice: ");
a=0;
while(a<M){
	b=0;
	while(b<N){
		scanf("%d",&matrica[a][b]);
		b++;
	}
	a++;
}
a=1;
while(a<M){
	d=0;
	while(d<a){
		ID=1;
		b=0;
		while(b<N){
			if (matrica[a][b]!=matrica[d][b]){
				ID=0;
				break;
			}
			b++;
		}
		if(ID){
			c=a;
			while(c<M-1){
				b=0;
				while(b<N){
					matrica[c][b]=matrica[c+1][b];
					b++;
				}
				c++;
			}
			M--;
			a--;
		}
		d++;
	}
	a++;
}
b=1;
while(b<N){
	r=0;
	while(r<b){
		ID=1;
		p=0;
		while(p<M){
			if(matrica[p][b]!=matrica[p][r]){
				ID=0;
				break;
			}
			p++;
		}
		if (ID){
			a=b;
			while(a<N-1){
				c=0;
				while(c<M){
					matrica[c][a]=matrica[c][a+1];
					c++;
				}
				a++;
			}
			N--;
			b--;
		}
		r++;
	}
	b++;
}
printf("Nakon izbacivanja redova/kolona matrica glasi:\n");
a=0;
while(a<M){
	b=0;
	while(b<N){
		printf("%5d", matrica[a][b]);
		b++;
	}
	printf("\n");
	a++;
}
	return 0;
}