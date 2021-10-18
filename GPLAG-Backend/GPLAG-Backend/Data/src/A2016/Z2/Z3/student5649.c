#include <stdio.h>
#define maxE 10
#define maxK 20
int main() {
	int E,i,j,e=0,r,f,T=1,pu=0,z=0,a,b;
	char mat[20][20];
	
	for(a=0;a<20;a++){
		for(b=0;b<20;b++){
     mat[a][b]=' ';
		}
	}
	do {
	if(e>0){printf("Pogresan unos\n");}
	printf("Unesite broj tacaka: ");
	scanf("%d", &E);
	e++;
	}while(E<0 || E>10);
	for(i=0;i<E;i++){
	do{
			printf("Unesite %d. tacku: ", T);
			scanf("%d %d", &r, &f);
			if(r<0 || r>=20 || f<0 || f>=20) {
				pu++;
			}
			if(pu>0){
				printf("Pogresan unos\n");}
			}while(r<0 || r>=20 || f<0 || f>=20);
			
		
		pu=0;
		mat[r][f]='*';
        	T++;
	}
		for(j=0;j<19;j++){
			for(z=0;z<19;z++){
				printf("%c", mat[z][j]);
			}
			printf("\n");
		}
	

	
	return 0;
}


