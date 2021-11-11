#include <stdio.h>
#include <string.h>

int fibonaccijev(int broj){
    
    int a,b,c;
    
    a=1; b=1; c=a+b;
    
    while(c<broj){
        a=b; b=c; c=a+b;
        }
            
    if(broj==c || broj==1)
    	return 1;
    	
    return 0;
}

void ubaci(int *niz, int velicina){
	
	int i=0, j, suma=0, niz_temp[10],k=1;
	int *temp;
	
	temp=niz;
	while(i<velicina){
		niz_temp[i]=*niz;
		niz++; i++;
	}
	niz=temp;
	
	for(i=0;i<velicina;i++){
		suma=0;
		while(niz_temp[i]!=0){
		        suma+=niz_temp[i]%10;
		        niz_temp[i]/=10;
		}
	
		for(j=velicina*2-k;j>0;j--){
			*(niz+j)=*(niz+j-1);}
		if(suma<0)suma*=-1;
		niz++;
		*niz=suma;
		niz++; k+=2;
	}
}

int izbaci(int *niz, int velicina){
	
	int i, j, fibo; int * temp;
	
	for(i=1;i<=velicina;i++){
		fibo=0;
		if((fibo=fibonaccijev(*niz))==1){
		
			temp=niz;
			for(j=i;j<velicina;j++){
				*niz=*(niz+1);
				niz++;
			}
			niz=temp;
			velicina--;
			i--;
		}
		if(i==velicina+1)break;
		if(fibo==0)
		niz++;
	}
	
	return velicina;
	
}

int main() {
	
	int niz[20],i, velicina;

	printf("Unesite niz od 10 brojeva: ");
	
	for(i=0;i<10;i++){
		scanf("%d", &niz[i]);
	}
    velicina= sizeof(niz)/sizeof(niz[0]);
    
    ubaci(niz,velicina/2);
    
    velicina=izbaci(niz, velicina);
    
    printf("Modificirani niz glasi:");
    for(i=0;i<velicina;i++){
       if(i==velicina-1){printf(" %d.", niz[i]);break;}
   	printf(" %d,", niz[i]);
    }
    return 0;
}
