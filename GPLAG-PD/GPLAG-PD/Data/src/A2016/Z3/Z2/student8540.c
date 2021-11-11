#include <stdio.h>
#include <math.h>
void ubaci(int* niz, int vel){
	int i,j,a,b,c,d=10, temp, suma=0, k=1;
	for(i=vel; i<2*vel;i++){
		niz[i]=0;
	}
	for(i=vel; i<2*vel;i++){
		for(j=i;j>k;j--){
			temp=niz[j-1];
			niz[j-1]=niz[j];
			niz[j]=temp;
		}
		k=k+2;
	}
	a=vel;
	for(i=0;i<2*a;i+=2){
		b=niz[i];
		
		suma=0;
		do{
			c=fabs(b%d);
			b=b/d;
			suma=suma+c;
		}while(b!=0);
		niz[i+1]=suma; vel++;
	}
}

int izbaci(int* niz, int vel){
	int a=1, b, p=1, dp=1, i, j, max;
	
	max=niz[0];
	for(i=0;i<vel;i++){
		if(niz[i]>max){
			max=niz[i];
		}
	}
	do{
		b=0;
		a=p+dp;
		for(i=0;i<vel;i++){
			if(niz[i]==a){
				b=1;
				break;
			}
			else if(niz[i]==1){
				b=1;
				break;
			}
		}
			if(b){
				for(j=i;j<vel-1;j++){
					niz[j]=niz[j+1];
				}	
				vel--;
				continue;
			}
			dp=p;
			p=a;
		
	}while(a<=max);
		return vel;
}

int main() {
	int N[20]={0}, i, vel=10;
	
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<10;i++){
		scanf("%d", &N[i]);
	}
	ubaci(N, vel);
	vel= izbaci(N, 20);
	printf("Modificirani niz glasi: ");
	for(i=0;i<vel;i++){
		if(i!=(vel-1)){
			printf("%d, ", N[i]);
		}
		else{
			printf("%d.", N[i]);
		}
	}
	return 0;
}