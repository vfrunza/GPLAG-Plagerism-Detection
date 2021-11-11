#include <stdio.h>
#include <stdlib.h>
void ubaci(int *niz,int vel){
	int i;
	int C1,suma=0; 
	int prob;
	for(i=vel-1;i>=0;i--){
		*(niz+2*i)=*(niz+i);
	} for(i=0;i<vel*2;i++){
		if(i%2==1){
			prob=*(niz+i-1);
			while(prob!=0){
				C1=prob%10;
				suma+=C1;
				prob/=10;
			} suma=abs(suma); 
			*(niz+i)=suma;
			suma=0;
		}
	} 
}

int fibon_fun (int br){
	int fibon_br=1 , fibon_br2=2,temp;
	if(br==1) 
	return 1;
	while(1){
		temp=fibon_br+fibon_br2;
		fibon_br=fibon_br2;
		fibon_br2=temp;
		if(br==fibon_br || br==fibon_br2){
			return 1;
			break;
		} else if(br<fibon_br || br<fibon_br2){
			return 0;
			break;
		}
	}
}

int izbaci(int *niz,int vel){
	int temp,i,j;
	for(i=0;i<vel;i++){
		if(niz[i]>0 && fibon_fun(*niz)){
			for(j=i;j<vel-1;j++){
				temp=niz[j];
				niz[j]=niz[j+1];
				niz[j+1]=temp;
			}
			vel--;
			i--;
		}
	}
	return vel;
}

int main() {
	int niz[20];
	int vel=10;
	int k,i;
	printf("Unesite niz od 10 brojeva :");
	for(k=0;k<10;k++){
		scanf("%d",&niz[k]);
	} 
	ubaci(niz,vel);
	izbaci(niz,vel);
	printf("Modificirani niz glasi: ");
	for(i=0;i<20;i++){
	printf("%d, ",niz[i]);}
	
	
	return 0;
}
