#include <stdio.h>
#include <math.h>
int main() {
	int n,niz[100],niz2[1000];
	int i,w,j=0,broj1=0,broj2=0,n_broj=0,k=0,brojac=1,t,q;
	int cifra1,cifra2,vel_niza=1,brojac1=0;
	printf("Unesite velicinu niza: ");
	scanf("%d",&n);
	do{
		if(n<0 || n>100){
			printf("Unesite velicinu niza: ");
			scanf("%d",&n);
		}
	}while(n<0 || n>100);
	
	printf("Unesite clanove niza: ");
	for(t=0;t<n;t++){
		scanf("%d",&niz[t]);
	}
	
	for(i=0;i<n;i++){
		broj1=niz[i];
		do{
		   cifra1=broj1%10;
		   k++;
		   broj1=broj1/10;
		}while(broj1 != 0);
		cifra1=0;
		broj2=niz[i];
		do{
			cifra1=broj2%10;
			n_broj+=cifra1*pow(10,k-1);
			k--;
			broj2=broj2/10;
		}while(broj2 != 0);
		cifra1=0;
		do{
		
			if(j==0){
				j++;
                cifra1=n_broj%10;
				for(q=0;q<1;q++){
					niz2[q]=cifra1;
					vel_niza++;
				}
			}else{
				cifra1=n_broj%10;
				if(cifra1 != cifra2){
					for(q=j;q<j+2;q++){
						if(q==j){
							niz2[q]=brojac;
						}else{
							niz2[q]=cifra1;
						}
						vel_niza++;
					}
				j+=2;
				brojac=1;
				brojac1++;
				}else if(cifra1 == cifra2){
					brojac++;
				}
			}
			cifra2=cifra1;
			n_broj=n_broj/10;
			if(n_broj==0){
				niz2[vel_niza-1]=1;
			}
			if(brojac1==0){
				niz2[1]=brojac;
			}
		}while(n_broj != 0);
	}	
		printf("Finalni niz glasi:\n");
		
		for(w=0;w<vel_niza;w++){
			printf("%d ",niz2[w]);
		}
	
	return 0;
}
