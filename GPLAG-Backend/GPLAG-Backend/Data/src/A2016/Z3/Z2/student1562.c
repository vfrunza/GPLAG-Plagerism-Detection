#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int suma(int n){
	
	int cifra,s=0;
	while(n!=0){
		
		cifra=n%10;
		s=s+cifra;
		n=n/10;
	}
    s=abs(s);
	return s;
}
int kvadrat(long int x){
	long int s=sqrt(x);
	if(s*s==x)return 1;
	else return 0;
	
}
int Fibonaci(long int n){
	if(n<1)return 0;
	else if (kvadrat(5*n*n+4)==1|| kvadrat(5*n*n-4)==1) return 1;
	else return 0;
}
void ubaci(int niz[],long int n){

  long int a[10000],i;
  long int b[10000];
   for(i=0;i<n;i++){
   	 a[i]=niz[i];
   	 b[i]=suma(niz[i]);
   }
   
   n=n*2;
   int k=0,j=0;
   for(i=0;i<n;i++){
   
     if(i==0 || i%2==0){niz[i]=a[j];j++;}
     else {niz[i]=b[k];k++;}
   }
   
}

long int izbaci(int niz[], int n){
	long int i,j;

	for(i=0;i<n;i++){
		
		if(Fibonaci(niz[i])==1){
			
			for(j=i;j<n-1;j++){
				niz[j]=niz[j+1];
			}
			n=n-1;
			i--;
		}
	}
	
	return n;
}

int main() {
	
	int niz[20];
	
	int i;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d",&niz[i]);
	}
	
	ubaci(niz,10);

	int vel;
	vel=izbaci(niz,20);
  
	printf("Modificirani niz glasi: ");
	for(i=0;i<vel;i++){
		if(i!=vel-1){
		printf("%d, ",niz[i]);}
		else printf("%d.",niz[i]);
	}
	
	return 0;
}
