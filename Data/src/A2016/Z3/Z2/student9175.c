#include <stdio.h>

int suma(int n){
	int s=0,c;
	while(n!=0){
		c=n%10;
		s+=c;
		n/=10;
	}
	return s;
}


void ubaci(int*niz,int velicina){
 	int i,j;
 	for(i=0;i<velicina;i++){
 		velicina++;
 		for(j=velicina;j>i;j--){
 			niz[j]=niz[j-1];
 		}
 		niz[i+i]=suma(niz[i]);
 		i++;
 	}
 }
 
 void fibonacci(int*niz,int velicina){
 	int i;
 	niz[0]=1;
 	niz[1]=1;
 	for(i=2;i<velicina;i++){
 		niz[i]=niz[i-1]+niz[i-2];
 	}
 }
 
 int izbaci(int*niz,int velicina){
 	int niz1[50];
 	int i,j,k;
 	niz1[0]=1;
 	niz1[1]=1;
 
 	for(i=2;i<50;i++){
 		niz1[i]=niz1[i-1]+niz1[i-2];
 	}
 	
 	for(i=0;i<velicina;i++){
 		for(j=0;j<50;j++){
 			if(niz[i]==niz1[j]){
 				for(k=i;k<velicina-1;k++){
 					niz[k]=niz[k+1];
 				}
 				velicina--;
 				i--;
 			}
 		}
 	}
 	return velicina;
 }

int main() {
	int i;
	int niz[100];
	int v;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d",&niz[i]);
	}
	
	ubaci(niz,10);
	
	v=izbaci(niz,20);
	
	
	printf("Modificirani niz glasi: ");
	for(i=0;i<v;i++){
		if(i+1!=v)printf("%d, ",niz[i]);
		else printf("%d.",niz[i]);
	}
	

	return 0;
}
