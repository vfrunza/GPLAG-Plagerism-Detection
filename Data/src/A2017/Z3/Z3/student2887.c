#include <stdio.h>
#include <math.h>
int izbaci_cifre(int niz[], int vel, int niz1[], int vel1){
	int niz2[100],p=0,br=0,brojac=0,broj2=0,brojac1=0,isti_el=1;
	int i,k,z,j,broj,cifra,h;
	for(i=0;i<vel1;i++){
		br=0;
		for(j=0;j<vel1;j++){
			if(niz1[i]==niz1[j]){
				br++;
			}
		}//elementi niza1 moraju biti sastavljeni od cifara 0-9  
		if(niz1[i]<0 || niz1[i]>9 || br>1){
			return 0;
		}
	}
	
		for(j=0;j<vel;j++){
			brojac=0;brojac1=0;p=0;broj2=0;
			broj=fabs(niz[j]);
			//rastavljamo elemente niza na cifra sve dok je broj razlicit od nule
			do{
				cifra=broj%10;
				for(h=p;h<(p+1);h++){
					niz2[h]=cifra;
				}
				broj=broj/10;
				p+=1;
			}while(broj !=0);
			//trazimo cifru iz niza1
			for(k=0;k<p;k++){
				for(i=0;i<vel1;i++){
				if(niz2[k]==niz1[i]){
					brojac+=1;
					break;
				}
			}
		}
			brojac1=p-brojac-1;
			for(z=(p-1);z>=0;z--){
				isti_el=1;
				for(i=0;i<vel1;i++){
				if(niz2[z]==niz1[i]){
					isti_el=0;
					break;
				}
			}
			if(isti_el){
				broj2+=niz2[z]*pow(10,brojac1);
				brojac1--;
			}
		}
		if(niz[j]<0){
			niz[j]=-broj2;
		}else{
			niz[j]=broj2;
		}
		}
	
	return 1;
}
int main() {
	int niz[]={1234, 12345};
	int niz1[]={3, 5};
	printf("%d",izbaci_cifre(niz,2,niz1,2));
	return 0;
}
