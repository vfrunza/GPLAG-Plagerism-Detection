#include <stdio.h>

void ubaci(int *niz, int n) {
	int a,i,j,suma=0,br=0;
		for(i=0;i<n;i+=2){ 
			suma=0;
			a=niz[i];
			if(a<0) a*=-1;
			while(a>0) {
				suma+=(a%10);
				a/=10;
			} 
				for(j=i+9-br;j>i;j--){
				niz[j+1]=niz[j];
		}
				niz[i+1]=suma;
				br++; 
	}
} 

int Fibonaci(int x) {
int broj=1,prethodni=1,temp=0;
while(1){
	if(x==1) return 1;
	else if(x==broj) return 1;
	else if(x!=broj && x<broj) return 0;
	
	temp=broj;
	broj+=prethodni;
	prethodni=temp;
}
	
}

int izbaci(int *niz, int n){
	int i,j,DA;
    for(i=0;i<n;i++) { DA=Fibonaci(niz[i]);
    if(DA==1){ 
    	for(j=i;j<n-1;j++) niz[j]=niz[j+1];
    	n--;
    	i--;
    	if(n==0) return n;
    }
    }
return n;	
}

int main() {
	int niz[20],i,vel;
	printf("Unesite niz od 10 brojeva: ");
	for(i=0;i<10;i++) scanf("%d",&niz[i]);
    
    ubaci(niz,20);
    vel=izbaci(niz,20);
    
    if(vel==0) printf("Prazan niz.");
    else{	
	printf("Modificirani niz glasi: ");
	for(i=0;i<vel;i++){
		if(i==vel-1) printf("%d.",niz[i]);
    	else printf("%d, ",niz[i]);
	} }
	return 0;
}
