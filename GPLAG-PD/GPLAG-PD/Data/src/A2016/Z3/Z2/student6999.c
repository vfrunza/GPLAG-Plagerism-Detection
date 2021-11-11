#include <stdio.h>
#include <stdlib.h>
void ubaci(int *niz, int vel){
    int i,suma=0,broj,niz1[20]={0};
    int p;
    int *q;
    q=niz;
    /*petlja prosirenja niza*/
for(i=0;i<=vel*2-1;i+=2){
	/*Novi niz dobija vrijednost na pozicijama 0,2,4,6,8,10... a 1,3,5,7,9... ostaju 0.*/
    niz1[i]=*(q);
    q++;
}
	/*Vracanje pointera na pocetak originalnog niza.*/
	q=niz;
for(i=0;i<=vel*2-1;i++){
    *q=niz1[i];
    q++;
    /*Originalni niz, dakle poprima vrijednosti npr 1 0 2 0 3 0*/
}
    
q=niz;
	for(i=1;i<=vel*2-1;i+=2){
		suma=0;
		broj=abs(*(q+i-1));
		while(broj!=0){
			p=broj%10;
			suma+=p;
			broj/=10;
		}
		*(q+i)=suma;
	}
}

int izbaci(int *niz, int vel){
	int i,j,k,pr,dr,slj;
	int *q;
	q=niz;
	for(i=0;i<vel;i++){
		pr=0;
		dr=1;
		/*Fibonacijev niz prekoracuje int na 37-om clanu*/
		for(j=1;j<37;j++){
			if(j==1) slj=j;
			else{
				slj=pr+dr;
				pr=dr;
				dr=slj;
			}
		if(*(q+i)==slj){
			for(k=i;k<vel-1;k++){
					*(q+k)=*(q+k+1);	
				}
			vel--;
			i--;
			break;
			}
		}
	}
return vel;
}

int main() {
	int niz[20]={0},velicina;
	int i;
	printf("Unesite niz od 10 brojeva: ");
		for(i=0;i<10;i++){
			scanf("%d",&niz[i]);
		}
ubaci(niz,10);
velicina=izbaci(niz,20);
	printf("Modificirani niz glasi: ");
		for(i=0;i<velicina;i++){
			if(i<(velicina-1))
				printf("%d, ",niz[i]);
		
			else printf("%d. ",niz[i]);
		}
	return 0;
}