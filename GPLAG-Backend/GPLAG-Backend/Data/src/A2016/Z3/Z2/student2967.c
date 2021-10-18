#include <stdio.h>
#include <math.h>

#define N 10

int apsolutna_vrijednost(int n){
	
	if(n>0){
		return n;
	} 
	
	else{
		return -n;
	} 
}
int sumica(int broj){
	int suma=0;
	int a=0;
	do{
		a=apsolutna_vrijednost(broj%10);
		suma=suma+a;
		broj=broj/10;
	} while(broj!=0);
	return suma;
}

int da_li_je_Fibonacijev_broj(int x){

	double root5=sqrt(5);
	
	double phi=(1+root5);
	
	double m=phi/2;
	int idx;
	
	idx=(long)floor(log(x*root5)/log(m)+0.5);
	
	long y = (long)floor(pow(m,idx)/root5+0.5);
	
	if(y!=x){
		return 0;
	} 
	else{
		return 1;
	}
	
}

void ubaci(int niz[]){
	int i=0;
	
	int j=2*N;
	for(i=j-1; i>0; i--){
		if(i%2==0){
			niz[i]=niz[i/2];
		} 
	}
	for(i=1; i<j; i++){
		if(i%2==1){
			niz[i]=sumica(niz[i-1]);
		} 
	}
}

int izbaci(int niz[]){
	int brojEl=2;
	int brojEll=brojEl*N;
	int i=0;
	
	while(i<brojEll){
		if(da_li_je_Fibonacijev_broj(niz[i])==1){
			int j=i;
			while(j<2*N-1){
				niz[j]=niz[j+1];
				j++;
			}
			brojEll--;
			i--;
		
		}
		i++;
	}
	return brojEll;

}

void ispisi_niz(int niz[]){
	printf("\n");
	int i=1;
	
	while(i<11){
		printf("%d",niz[i]);
		i++;
	}
	
}

int main(){
	int i;
	int niz[2*N];
	printf("Unesite niz od 10 brojeva: ");
	for(i=0; i<N; i++){
		scanf("%d",&niz[i]);
	}
	
	ubaci(niz);
	
	int brEl=izbaci(niz);
	
	printf("Modificirani niz glasi: ");
	for(i=0; i<brEl; i++){
		if(i!=brEl-1){
			printf("%d, ",niz[i]);
		}
		else{
			printf("%d.",niz[i]);
		}
	}
	return 0;
}
