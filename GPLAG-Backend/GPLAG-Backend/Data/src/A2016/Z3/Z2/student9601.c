#include <stdio.h>
#include <math.h>

void ubaci(int*p,int n){
	int broj,suma=0,x,niz1[10000],i;
	int*q,*s;
	q=p;
	s=p;
		for(i=0;i<2*n;i++){
	   	  broj=*q;
	   	  niz1[i]=*q;
	   	  i++;
	   	  broj=fabs(broj);
		while(broj!=0){
			x=broj%10;
			broj=broj/10;
			suma+=x;
	
		}
		niz1[i]=suma;
		suma=0;
		q++;
	   }
	   for(i=0;i<2*n;i++){
	   		*s=niz1[i];
	   		s++;
	   }
	   
	}
int izbaci(int*p,int n){
	int i,fniz[46],niz2[20],j,k;
	int*q,*s;
	q=p;
	s=p;
	fniz[0]=1;
	fniz[1]=1;
	for(i=2;i<46;i++)
		fniz[i]=fniz[i-1]+fniz[i-2];
	for(i=0;i<n;i++){
		niz2[i]=*q;
		q++;
	}
	for(i=0;i<n;i++){
		for(j=0;j<46;j++){
			if(niz2[i]==fniz[j]){
				for(k=i;k<n-1;k++){
					niz2[k]=niz2[k+1];
				}
				n--;
				i--;
				break;
			}
			
		}
	}
	for(i=0;i<n;i++){
	   		*s=niz2[i];
	   		s++;
	   }

	return n;
}
int main() {
	int i,niz[20],x,n;
	int*p;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++){
		scanf("%d",&niz[i]);
	}
	n=10;
	p=niz;
	ubaci(p,n);
	
	x=izbaci(p,2*n);
	printf("Modificirani niz glasi: ");
		for(i=0;i<x;i++){
			if(i<x-1)
				printf("%d, ",niz[i]);
				else
					printf("%d.",niz[i]);
		}
	
	return 0;
}

