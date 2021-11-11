#include <stdio.h>
#include <math.h>
	
	int br(int i){
		int suma=0;
		while(i!=0){
			i=fabs(i);
			suma+=i%10;
			i/=10;
		}
		return suma;
	}
	
	int f(int b){
		
		int a=1, c=1, d;
		if(b==1){
			return 1;
		}
		while(2){
			d=a+c;
			if(d==b)return 1;
			if(d>b) return 0;
			a=c;
			c=d;
		}
	}
	
	
	
	int izbaci(int* n, int v){
		int i, y, j;
		for(i=0;i<v;i++){
			y=f(n[i]);
			if(y){
				for(j=i;j<v-1;j++){
					n[j]=n[j+1];
					
				}
				v--;
				i--;
			}
		}
		return v;
		
	}
	
	
	void ubaci(int* niz, int  velicina){
		int niz2[20];
		int niz3[20];
		int i;
		for(i=0; i<velicina;i++){
			niz2[i]=br(niz[i]);
		}
		int b=0;
		for(i=0;i<2*velicina;i+=2){
			niz3[i]=niz[b];
			niz3[i+1]=niz2[b];
			b++;
			if(b==velicina)break;
		}
		for(i=0;i<2*velicina;i++){
			niz[i]=niz3[i];
		}
	}
	
int main() {
			int niz[20];
			int i,broj;
			printf("Unesite niz od 10 brojeva: ");
			for(i=0;i<10;i++){
				scanf("%d",&niz[i]);
				
			}
			
			ubaci(niz, 10);
			broj=izbaci(niz,20);
				printf("Modificirani niz glasi: ");
				printf("%d", niz[0]);
				for(i=1;i<broj;i++){
					printf(", %d", niz[i]);
					
				}
				printf(".");
	return 0;
}
