#include <stdio.h>


int max(int matrica[100][100], int visina, int sirina){
	int x,y,Max,temp,count,A,z,t;
	count = 0;
	temp = 0;
	Max = 0;
	for (x = 0; x<visina;x++){
		for(y=0;y<sirina;y++){
			temp = 0;
			A = matrica[x][y];
			for(z = 0;z<visina;z++){
				for (t=0;t<sirina;t++){
					if(A == matrica [z][t]){
						temp++;
					}
				}
			}
			if (temp > count){
				Max = A;
				count = temp;
			} else if (temp == count){
				if (A < Max){
					Max = A;
					count = temp;
				}
		}
	}
	}
return Max;
}

int izbaci_kolone(int matrica[100][100], int visina, int sirina, int N){
	int j,y;
	int tempsirina = sirina;
	int(*prow)[100], (*ptemprow)[100];
	for(prow = matrica; prow != matrica + visina;prow++){
		for(y=0;y<tempsirina;y++){
			if((*prow)[y] == N){
				if (y == tempsirina - 1){
					;
				} else {
				for(ptemprow = matrica;ptemprow != matrica + visina;ptemprow++){
					for (j = y;j<tempsirina - 1;j++){
						(*ptemprow)[j] = (*ptemprow)[j + 1];
					}
				}
				y--;
			}
			tempsirina--;
		}
	}
}
return tempsirina;
}

int main() {
	int s,v,A[100][100],n,N,temp,x,a,y;
	n =0;
	printf ("Unesite sirinu i visinu matrice: ");
	scanf("%d %d",&s,&v);
	temp = s;
	for (y=0;y < v;y++){
		printf ("Unesite elemente %d""."" reda: ", y + 1);
		for (x=0;x<s;x++){
			scanf("%d",&a);
			A[y][x] = a;
		}
	}
	printf ("\n");
	do {
		n++;
		N = max(A,v,temp);
		temp = izbaci_kolone(A,v,temp,N);
		if (temp == 0){
			printf ("\nNakon %d""."" prolaza matrica je prazna!",n);
		} else {
		printf ("Nakon %d""."" prolaza matrica glasi: \n",n);
		for (y=0;y<v;y++){
			for(x=0;x<temp;x++){
				if (A[y][x] >= 10){
					printf("   %d", A[y][x]);
				} else {
					printf("    %d", A[y][x]);
				}
				if (x == temp - 1){
					printf("\n");
				}
			}
		}
		}
	} while (temp != 0);

	return 0;
}
