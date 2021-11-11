#include <stdio.h>
#include<stdlib.h>
void ubaci(int niz[], int vel){
	int i,s=0,c,r,l;
	for(i=vel-1; i>=0; i--){
		niz[2*i]=niz[i];
	}
	for(i=0; i<2*vel; i++){
	    if(i%2==0){
	    	l=niz[i];
		    r=abs(niz[i]);
	       	do{
			c=r%10;
			r=r/10;
			s=s+c;
		    }while(r!=0);
		    niz[i+1]=s;
		    niz[i]=l;
	    } else continue;
	 	
		s=0;
	}
}

int izbaci(int niz[], int vel){
	int i,max,j,k,n,r;
	max=niz[0];
	n=vel;
	for(i=0; i<n; i++){
		if(niz[i]>max) max=niz[i];
	}
	max=max+1;
	int a=0,b=1,c;
	for(i=0; ; i++){
		c=a+b;
		a=b;
		b=c;
		r=c;
		if(r>max) break;
		for(j=0; j<n; j++){
			if(niz[j]==r){
				
				for(k=j; k<n-1; k++){
					niz[k]=niz[k+1];
				}
				n--;
				j--;
			} else continue;
		}
	}
	return n;
}
int main() {
	int i,niz[20],vel=10,g;
	
	printf("Unesite niz od 10 brojeva: ");
	
	for(i=0; i<10; i++){
		scanf("%d", &niz[i]);
	}
	for(i=10; i<20; i++){
		niz[i]=0;
	}

    printf("Modificirani niz glasi: ");
    ubaci(niz,vel);
    g=izbaci(niz,20);
	for(i=0; i<g-1; i++){
		printf("%d, ", niz[i]);
	}
	printf("%d.",niz[g-1]);
	return 0;
}
